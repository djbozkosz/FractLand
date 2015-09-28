//------------------------------------------------------------------------------
#include "models.h"

//------------------------------------------------------------------------------
CModel::CModel() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CModel::CModel(CContext *context, const SModel &model, SSceneObject *sceneObject) : CEngineBase(context), model(model)
{
  update(sceneObject);
}
//------------------------------------------------------------------------------
CModel::~CModel()
{
}
//------------------------------------------------------------------------------
void CModel::update(SSceneObject *sceneObject)
{
  updateVirtual();

  sceneObject->mw = SMatrix::composeTransformation(sceneObject->position, sceneObject->rotation, sceneObject->scale);
  sceneObject->meshes.clear();

  /*const float *m = sceneObject->mw.constData();
  qDebug(QString("%1 %2 %3 %4").arg(m[0]).arg(m[1]).arg(m[2]).arg(m[3]).toStdString().c_str());
  qDebug(QString("%1 %2 %3 %4").arg(m[4]).arg(m[5]).arg(m[6]).arg(m[7]).toStdString().c_str());
  qDebug(QString("%1 %2 %3 %4").arg(m[8]).arg(m[9]).arg(m[10]).arg(m[11]).toStdString().c_str());
  qDebug(QString("%1 %2 %3 %4").arg(m[12]).arg(m[13]).arg(m[14]).arg(m[15]).toStdString().c_str());*/

  for(auto mesh = model.meshes.begin(); mesh != model.meshes.end(); mesh++)
  {
    sceneObject->meshes.push_back(SShaderTechnique());
    SShaderTechnique *t = &sceneObject->meshes.back();
    t->mw = sceneObject->mw * mesh->transformation;
    t->mwnit = t->mw.inverted().transposed().normalMatrix();
    context->getModels()->createVbo(&(*mesh));
  }
}
//------------------------------------------------------------------------------
void CModel::updateVirtual()
{
}
//------------------------------------------------------------------------------
void CModel::computeNormals(int32 mesh)
{
  int32 meshIndex = 0;

  for(auto m = model.meshes.begin(); m != model.meshes.end(); m++)
  {
    if((meshIndex == mesh) || (mesh == -1))
    {
      for(auto f = m->faces.begin(); f != m->faces.end(); f++)
        computeNormals(m->vertices, f->faces);
    }

    if(mesh != -1)
      break;

    meshIndex++;
  }
}
//------------------------------------------------------------------------------
void CModel::computeNormals(QVector<SVertex> &vertices, const QVector<SFace> &faces)
{
  for(int32 v = 0; v < vertices.size(); v++)
  {
    /*if(!(v % 10000))
      qDebug(QString("%1").arg(v).toStdString().c_str());*/
    vertices[v].normal = QVector3D(0.0, 1.0, 0.0);
    uint32 found = 0;

    for(auto f = faces.constBegin(); f != faces.constEnd(); f++)
    {
      if(f->contains(v))
      {
        QVector3D n = QVector3D::normal(vertices[f->vertex0].position, vertices[f->vertex1].position, vertices[f->vertex2].position);
        if(!found)
          vertices[v].normal = n;
        else
          vertices[v].normal += n;
        found++;
      }
    }

    vertices[v].normal.normalize();
  }
}
//------------------------------------------------------------------------------
void CModel::render(const SSceneObject *sceneObject) const
{
  if((!sceneObject) || (sceneObject->meshes.size() != model.meshes.size()))
    return;

  auto soMesh = sceneObject->meshes.constBegin();
  for(int32 i = 0; i < model.meshes.size(); i++, soMesh++)
  {
    const SMesh *mesh = &model.meshes[i];
    uint32 faceStart = 0;

    for(int32 j = 0; j < mesh->faces.size(); j++)
    {
      const SFaces *faces = &mesh->faces[j];
      uint32 facesCount = faces->faces.size();

      const SCamera *c =context->getCamera()->getCamera();
      soMesh->mvp = c->viewProjection * soMesh->mw;
      soMesh->cam = c->position.toVector3D() * QVector3D(-1.0, 1.0, -1.0);
      soMesh->fbSize = QVector4D(c->width, c->height, 1.0f / c->width, 1.0f / c->height);
      context->getRenderer()->addMesh(SRenderMesh(mesh->vboVertices, mesh->vboIndices, faceStart, facesCount, &(*soMesh), mesh->faces[j].material));
      faceStart += facesCount;
    }
  }
}
//------------------------------------------------------------------------------
CTerrain::CTerrain() : CModel()
{
}
//------------------------------------------------------------------------------
CTerrain::CTerrain(CContext *context, const SModel &model, const STerrain &terrain, SSceneObject *sceneObject) : CModel(context, model, sceneObject), terrain(terrain)
{
  update(sceneObject);
}
//------------------------------------------------------------------------------
CTerrain::~CTerrain()
{
}
//------------------------------------------------------------------------------
void CTerrain::updateVirtual()
{
  const uint32 stepX = 1 << terrain.stepX; // edges count (vertices: step + 1)
  const uint32 stepZ = 1 << terrain.stepZ;
  const uint32 divStepX = 1 << terrain.divStepX; // count of chunks
  const uint32 divStepZ = 1 << terrain.divStepZ;
  const uint32 stepMeshX = stepX / divStepX; // number of edges in chunk
  const uint32 stepMeshZ = stepZ / divStepZ;

  QVector<SVertex> vx((stepX + 1) * (stepZ + 1));
  QVector<float> heightMap((stepX + 1) * (stepZ + 1), 0.0f);
  QVector<bool> usedHeightMap((stepX + 1) * (stepZ + 1), false);
  QVector<int32> heightMapLayer((stepX + 1) * (stepZ + 1), -1);
  float depth = 1.0f;

  srand(terrain.seed);

  // compute heightmap
  if(!terrain.landBorder)
  {
    heightMap[0] = rndHeight();
    heightMap[stepX] = rndHeight();
    heightMap[(stepX + 1) * stepZ] = rndHeight();
    heightMap[(stepX + 1) * stepZ + stepX] = rndHeight();
  }
  usedHeightMap[0] = true;
  usedHeightMap[stepX] = true;
  usedHeightMap[(stepX + 1) * stepZ] = true;
  usedHeightMap[(stepX + 1) * stepZ + stepX] = true;

  fractalGrid(&heightMap[0], &usedHeightMap[0], stepX, stepZ, stepX, stepZ, 0, depth);

  // compute positions
  float x = 0.0f;
  float z = 0.0f;
  const float xInc = 1.0f / stepX;
  const float zInc = 1.0f / stepZ;

  for(uint32 i = 0; i <= stepX; i++, x += xInc)
  {
    for(uint32 j = 0; j <= stepZ; j++, z += zInc)
    {
      const uint32 k = ((stepX + 1) * i + j);
      vx[k].position = QVector3D(x - 0.5f, heightMap[k] * terrain.heightMultiplier, z - 0.5f);
      vx[k].normal = QVector3D(0.0, 1.0, 0.0);
      vx[k].texCoord = QVector2D(-x * 10, z * 10);
      vx[k].color = QVector3D(1.0, 0.0, 0.0);
      vx[k].color2 = QVector3D(0.0, 0.0, 0.0);
    }
    z = 0.0f;
  }

  // compute normals, tangents, bitangents
  for(int32 v = 0; v < vx.size(); v++)
  {
    uint32 x = v % (stepX + 1);
    uint32 z = v / (stepX + 1);

    if((x > 0) && (x < stepX) && (z > 0) && (z < stepZ))
    {
      QVector3D &vC = vx[v].position;
      QVector3D &vL = vx[v - 1].position;
      QVector3D &vR = vx[v + 1].position;
      QVector3D &vT = vx[v - stepX - 1].position;
      QVector3D &vB = vx[v + stepX + 1].position;
      vx[v].normal  = QVector3D::normal(vC, vL, vT);
      vx[v].normal += QVector3D::normal(vC, vT, vR);
      vx[v].normal += QVector3D::normal(vC, vR, vB);
      vx[v].normal += QVector3D::normal(vC, vB, vL);
      vx[v].normal.normalize();
      vx[v].normalTangent = QVector3D(vx[v].normal.y(), -vx[v].normal.x(), -vx[v].normal.z());
      vx[v].normalBitangent = QVector3D(-vx[v].normal.x(), -vx[v].normal.z(), vx[v].normal.y());
    }
  }

  // compute colors by layers
  for(int32 v = 0; v < vx.size(); v++)
  {
    for(int32 l = 0; l != terrain.layers.size(); l++)
    {
      const SMaterialLayer *layer = &terrain.layers[l];
      if(!(((layer->useHeightLimit) && ((vx[v].position.y() < layer->minHeight) || (vx[v].position.y() > layer->maxHeight))) ||
         ((layer->useSlopeLimit) && (((1.0f - vx[v].normal.y()) < layer->minSlope) || ((1.0f - vx[v].normal.y()) > layer->maxSlope)))))
      {
        vx[v].color = layer->color.toVector3D() * layer->color.w();
        heightMapLayer[v] = l;
      }
    }
  }

  /*for(int32 v = 0; v < vx.size(); v++)
    qDebug(QString("y %1, x %2: %3").arg(v / (stepX + 1)).arg(v % (stepX + 1)).arg(heightMapLayer[v]).toStdString().c_str());*/

  // divide to meshes, fill model meshes
  /*model.materials.clear();
  model.materials.push_back(SMaterial(context->getShaders()->getShaderProgram(NShader::PROGRAM_TERRAIN),
    context->getMaps()->addMap(SMap(":/maps/data/maps/rocks00n.png")),
    context->getMaps()->addMap(SMap(":/maps/data/maps/rocks00n.png")),
    context->getMaps()->addMap(SMap(":/maps/data/maps/rocks00n.png"))));*/

  /*model.meshes.clear();
  for(uint32 m = 0; m < (divStepX * divStepZ); m++)
  {
    model.meshes.push_back(SMesh());
    SMesh *mesh = &model.meshes.back();

    mesh->transformation = SMatrix::composeTransformation(mesh->position, mesh->rotation, mesh->scale);

    mesh->faces.push_back(SFaces());
    SFaces *faces = &mesh->faces.back();

    mesh->vertices.resize((stepMeshX + 1) * (stepMeshZ + 1));
    faces->faces.resize(stepMeshX * stepMeshZ * NTerrain::FACE_BLOCK_SIZE);

    uint32 offset = (m / divStepZ) * stepMeshZ * (stepX + 1) + (m % divStepX) * stepMeshX;

    uint32 mCol2 = 0;
    for(uint32 mRow = 0; mRow <= stepMeshZ; mRow++, offset += (stepX + 1))
    {
      for(uint32 mCol = 0; mCol <= stepMeshX; mCol++, mCol2++)
      {
        mesh->vertices[mCol2] = vx[offset + mCol];
        if((mRow == stepMeshZ) || (mCol == stepMeshX))
          mesh->vertices[mCol2].color = QVector3D(0.8, 0.2, 0.2);
      }
    }

    for(uint32 i = 0; i < stepMeshX; i++)
    {
      for(uint32 j = 0; j < stepMeshZ; j++)
      {
        const uint32 k = (stepMeshX * i + j) * NTerrain::FACE_BLOCK_SIZE;
        const uint32 l0 = (stepMeshX + 1) * i + j + 0;
        const uint32 l1 = (stepMeshX + 1) * i + j + 1;
        const uint32 l2 = (stepMeshX + 1) * (i + 1) + j + 0;
        const uint32 l3 = (stepMeshX + 1) * (i + 1) + j + 1;
        faces->faces[k + 0] = SFace(l0, l1, l2);
        faces->faces[k + 1] = SFace(l2, l1, l3);
      }
    }
  }*/

  model.materials.clear();
  const CMap *noMap = context->getMaps()->getMap(NMap::DEFAULT_NORMAL); // default map
  model.meshes.clear();
  for(uint32 gz = 0; gz < divStepZ; gz++)
  {
    for(uint32 gx = 0; gx < divStepX; gx++)
    { // sub mesh
      //const uint32 groupBase = gz * divStepZ + gx;
      const uint32 vxGroupBase = gz * stepMeshZ * (stepX + 1) + gx * stepMeshX;

      //qDebug("new mesh");
      model.meshes.push_back(SMesh());
      SMesh *mesh = &model.meshes.back();
      mesh->transformation = SMatrix::composeTransformation(mesh->position, mesh->rotation, mesh->scale);

      for(uint32 ez = 0; ez < stepMeshZ; ez++)
      {
        for(uint32 ex = 0; ex < stepMeshX; ex++)
        { // two faces block
          const uint32 vx0 = vxGroupBase + ez * (stepX + 1) + ex;
          const uint32 vx1 = vx0 + 1;
          const uint32 vx2 = vx0 + (stepX + 1);
          const uint32 vx3 = vx2 + 1;

          for(uint8 v = 0; v < NTerrain::FACE_BLOCK_SIZE; v++)
          { // one face
            const uint32 face[NModel::FACE_SIZE] = { (!v) ? vx0 : vx2, (!v) ? vx1 : vx1, (!v) ? vx2 : vx3 };

            // material signature
            QSet<int32> faceSet;
            faceSet.insert(heightMapLayer[face[0]]);
            faceSet.insert(heightMapLayer[face[1]]);
            faceSet.insert(heightMapLayer[face[2]]);
            QVector<int32> faceMats = faceSet.toList().toVector();
            qSort(faceMats.begin(), faceMats.end());
            //qDebug(QString("%1 %2 %3 : %4 %5 %6 : %7").arg(face[0]).arg(face[1]).arg(face[2]).arg(heightMapLayer[face[0]]).arg(heightMapLayer[face[1]]).arg(heightMapLayer[face[2]]).arg(faceMats.size()).toStdString().c_str());
            /*for(int32 i : faceMats)
              qDebug(QString("%1").arg(i).toStdString().c_str());*/

            SFaces *faces = NULL;
            for(auto f = mesh->faces.begin(); f != mesh->faces.end(); f++)
            { // find faces group by material signature
              if(!f->material)
              {
                //qDebug("chyba mat chybi");
                break;
              }
              else if(f->material->layerVx == faceMats)
              {
                //qDebug("nasel");
                faces = &(*f);
                break;
              }
            }

            if(!faces)
            {
              SMaterial *material = NULL;
              for(auto m = model.materials.begin(); m != model.materials.end(); m++)
              { // find previous used material
                if(m->layerVx == faceMats)
                {
                  //qDebug("nenasel, ale predchozí mat ano");
                  material = &(*m);
                  break;
                }
              }
              if(!material)
              {
                //qDebug("nenasel");
                const CMap *maps[NModel::FACE_SIZE];
                for(int32 i = 0; static_cast<uint32>(i) < NModel::FACE_SIZE; i++)
                {
                  maps[i] = (faceMats.size() > i) ? ((faceMats[i] != -1) ? terrain.layers[faceMats[i]].detailTexture : noMap) : NULL;
                  /*if(maps[i])
                    qDebug(maps[i]->getMap()->file.toStdString().c_str());
                  else
                    qDebug("no map");*/
                }

                model.materials.push_back(SMaterial(context->getShaders()->getShaderProgram(NShader::PROGRAM_TERRAIN), NULL, NULL, NULL, maps[0], NULL, NULL, NULL, NULL, NULL, maps[1], maps[2], faceMats));
                material = &model.materials.back();
              }
              mesh->faces.push_back(SFaces(material));
              faces = &mesh->faces.back();
            }

            uint16 newFace[NModel::FACE_SIZE];
            SVertex newVx[NModel::FACE_SIZE] = { vx[face[0]], vx[face[1]], vx[face[2]] };

            for(uint32 i = 0; i < NModel::FACE_SIZE; i++)
            { // set texture using multiplier
              if(heightMapLayer[face[i]] == faceMats[0])
                newVx[i].color2.setX(1.0f);
              else if(heightMapLayer[face[i]] == faceMats[1])
                newVx[i].color2.setY(1.0f);
              else if(heightMapLayer[face[i]] == faceMats[2])
                newVx[i].color2.setZ(1.0f);
              //qDebug(QString("face %1: %2 %3 %4").arg(i).arg(newVx[i].color2.x()).arg(newVx[i].color2.y()).arg(newVx[i].color2.z()).toStdString().c_str());

              bool found = false;
              for(int32 v = 0; v < mesh->vertices.size(); v++)
              { // find same vertex
                if((mesh->vertices[v].position == newVx[i].position) && (mesh->vertices[v].color2 == newVx[i].color2))
                {
                  //qDebug("same vx found");
                  found = true;
                  newFace[i] = v;
                  break;
                }
              }
              if(!found)
              {
                //qDebug("same vx not found");
                newFace[i] = mesh->vertices.size();
                mesh->vertices.push_back(newVx[i]);
              }
            }
            faces->faces.push_back(SFace(newFace[0], newFace[1], newFace[2]));
          }
        }
      }
      //qDebug(QString("-------- face groups: %1").arg(mesh->faces.size()).toStdString().c_str());
    }
  }
  //qDebug(QString("-------- meshes: %1").arg(model.meshes.size()).toStdString().c_str());
}
//------------------------------------------------------------------------------
float CTerrain::rndHeight()
{
  return rand() % 1000 * 0.001f - 0.5f;
}
//------------------------------------------------------------------------------
void CTerrain::fractalGrid(float *heightMap, bool *usedHeightMap, const uint32 sizeX, const uint32 sizeZ, const uint32 defSizeX, const uint32 defSizeZ, const uint32 startCorner, const float depth)
{
  const uint32 sizeX2 = sizeX >> 1;
  const uint32 sizeZ2 = sizeZ >> 1;
  const float heightLT = heightMap[startCorner];
  const float heightRT = heightMap[startCorner + sizeX];
  const float heightLB = heightMap[startCorner + (defSizeX + 1) * sizeZ];
  const float heightRB = heightMap[startCorner + (defSizeX + 1) * sizeZ + sizeX];
  const float heightModifier = (depth == 1.0f) ? terrain.heightModifier0 : ((depth == terrain.depthMultiplier) ? terrain.heightModifier1 : 0.0f);

  if(!usedHeightMap[startCorner + sizeX2])
  { // center top
    if((!terrain.landBorder) || (startCorner / (defSizeX + 1)))
      heightMap[startCorner + sizeX2] = 0.5f * (heightLT + heightRT) + rndHeight() * depth + heightModifier;
  }
  if(!usedHeightMap[startCorner + (defSizeX + 1) * sizeZ2])
  { // left center
    if((!terrain.landBorder) || (startCorner % (defSizeX + 1)))
      heightMap[startCorner + (defSizeX + 1) * sizeZ2] = 0.5f * (heightLT + heightLB) + rndHeight() * depth + heightModifier;
  }
  if(!usedHeightMap[startCorner + (defSizeX + 1) * sizeZ2 + sizeX])
  { // right center
    if((!terrain.landBorder) || ((startCorner % (defSizeX + 1) + sizeX) != defSizeX))
      heightMap[startCorner + (defSizeX + 1) * sizeZ2 + sizeX] = 0.5f * (heightRT + heightRB) + rndHeight() * depth + heightModifier;
  }
  if(!usedHeightMap[startCorner + (defSizeX + 1) * sizeZ + sizeX2])
  { // center bottom
    if((!terrain.landBorder) || ((startCorner / (defSizeX + 1) + sizeZ) != defSizeZ))
      heightMap[startCorner + (defSizeX + 1) * sizeZ + sizeX2] = 0.5f * (heightLB + heightRB) + rndHeight() * depth + heightModifier;
  }
  if(!usedHeightMap[startCorner + (defSizeX + 1) * sizeZ2 + sizeX2])
  { // center center
    heightMap[startCorner + (defSizeX + 1) * sizeZ2 + sizeX2] = 0.25f * (heightLT + heightRT + heightLB + heightRB) + rndHeight() * depth + heightModifier;
  }

  usedHeightMap[startCorner + sizeX2] = true;
  usedHeightMap[startCorner + (defSizeX + 1) * sizeZ2] = true;
  usedHeightMap[startCorner + (defSizeX + 1) * sizeZ2 + sizeX] = true;
  usedHeightMap[startCorner + (defSizeX + 1) * sizeZ + sizeX2] = true;
  usedHeightMap[startCorner + (defSizeX + 1) * sizeZ2 + sizeX2] = true;

  if((sizeX2 <= 1) || (sizeZ2 <= 1))
    return;

  fractalGrid(heightMap, usedHeightMap, sizeX2, sizeZ2, defSizeX, defSizeZ, startCorner, depth * terrain.depthMultiplier);
  fractalGrid(heightMap, usedHeightMap, sizeX2, sizeZ2, defSizeX, defSizeZ, startCorner + sizeX2, depth * terrain.depthMultiplier);
  fractalGrid(heightMap, usedHeightMap, sizeX2, sizeZ2, defSizeX, defSizeZ, startCorner + (defSizeX + 1) * sizeZ2, depth * terrain.depthMultiplier);
  fractalGrid(heightMap, usedHeightMap, sizeX2, sizeZ2, defSizeX, defSizeZ, startCorner + (defSizeX + 1) * sizeZ2 + sizeX2, depth * terrain.depthMultiplier);
}
//------------------------------------------------------------------------------
CWater::CWater() : CModel()
{
}
//------------------------------------------------------------------------------
CWater::CWater(CContext *context, const SModel &model, const SWater &water, SSceneObject *sceneObject) : CModel(context, model, sceneObject), water(water)
{
  update(sceneObject);
}
//------------------------------------------------------------------------------
CWater::~CWater()
{
}
//------------------------------------------------------------------------------
void CWater::updateVirtual()
{
  model.materials.clear();
  model.meshes.clear();

  // ground
  model.materials.push_back(SMaterial(context->getShaders()->getShaderProgram(NShader::PROGRAM_TERRAIN), NULL, NULL, NULL,
    water.detailGroundTexture, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL));

  model.meshes.push_back(SMesh());
  SMesh *mesh = &model.meshes.back();
  mesh->transformation = SMatrix::composeTransformation(mesh->position, mesh->rotation, mesh->scale);

  mesh->faces.push_back(SFaces(&model.materials.back()));
  SFaces *faces = &mesh->faces.back();
  faces->material = &model.materials.back();

  mesh->vertices.resize(NWater::VERTICES_COUNT);
  mesh->vertices[0].position = QVector3D(-0.5, water.depth,  0.5);
  mesh->vertices[1].position = QVector3D( 0.5, water.depth,  0.5);
  mesh->vertices[2].position = QVector3D(-0.5, water.depth, -0.5);
  mesh->vertices[3].position = QVector3D( 0.5, water.depth, -0.5);
  mesh->vertices[0].texCoord = QVector2D(-0.0, 100.0);
  mesh->vertices[1].texCoord = QVector2D(-100.0, 100.0);
  mesh->vertices[2].texCoord = QVector2D(-0.0, 0.0);
  mesh->vertices[3].texCoord = QVector2D(-100.0, 0.0);
  for(uint32 i = 0; i < NWater::VERTICES_COUNT; i++)
  {
    mesh->vertices[i].color = water.color.toVector3D() * water.color.w();
    mesh->vertices[i].color2 = QVector3D(1.0, 0.0, 0.0);
  }

  faces->faces.resize(NWater::FACE_BLOCK_SIZE);
  faces->faces[0] = SFace(0, 1, 2);
  faces->faces[1] = SFace(2, 1, 3);

  // level
  model.materials.push_back(SMaterial(context->getShaders()->getShaderProgram(NShader::PROGRAM_WATER), NULL,
    water.windTexture,
    NULL,
    water.detailTexture,
    water.environmentTexture,
    NULL, NULL, NULL, NULL, NULL, NULL, QVector<int32>(), true, true));

  model.meshes.push_back(SMesh());
  mesh = &model.meshes.back();
  mesh->transformation = SMatrix::composeTransformation(mesh->position, mesh->rotation, mesh->scale);

  mesh->faces.push_back(SFaces(&model.materials.back()));
  faces = &mesh->faces.back();
  faces->material = &model.materials.back();

  mesh->vertices.resize(NWater::VERTICES_COUNT);
  mesh->vertices[0].position = QVector3D(-0.5, 0.0,  0.5);
  mesh->vertices[1].position = QVector3D( 0.5, 0.0,  0.5);
  mesh->vertices[2].position = QVector3D(-0.5, 0.0, -0.5);
  mesh->vertices[3].position = QVector3D( 0.5, 0.0, -0.5);
  mesh->vertices[0].texCoord = QVector2D(-0.0, 100.0);
  mesh->vertices[1].texCoord = QVector2D(-100.0, 100.0);
  mesh->vertices[2].texCoord = QVector2D(-0.0, 0.0);
  mesh->vertices[3].texCoord = QVector2D(-100.0, 0.0);

  faces->faces.resize(NWater::FACE_BLOCK_SIZE * 2);
  faces->faces[0] = SFace(0, 1, 2);
  faces->faces[1] = SFace(2, 1, 3);

  // under level
  model.materials.push_back(SMaterial(context->getShaders()->getShaderProgram(NShader::PROGRAM_UNDER_WATER), NULL,
    water.windTexture,
    NULL,
    water.detailTexture,
    water.environmentTexture,
    NULL, NULL, NULL, NULL, NULL, NULL, QVector<int32>(), true, true));

  model.meshes.push_back(model.meshes.back());
  mesh = &model.meshes.back();
  faces = &mesh->faces.back();
  faces->material = &model.materials.back();
  faces->faces[0] = SFace(1, 0, 2);
  faces->faces[1] = SFace(1, 2, 3);
}
//------------------------------------------------------------------------------
CSky::CSky() : CModel()
{
}
//------------------------------------------------------------------------------
CSky::CSky(CContext *context, const SModel &model, const SSky &sky, SSceneObject *sceneObject) : CModel(context, model, sceneObject), sky(sky)
{
  update(sceneObject);
}
//------------------------------------------------------------------------------
CSky::~CSky()
{
}
//------------------------------------------------------------------------------
void CSky::updateVirtual()
{
  model.materials.clear();
  model.materials.push_back(SMaterial(context->getShaders()->getShaderProgram(NShader::PROGRAM_BASIC), sky.diffuseTexture, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, QVector<int32>(), false));

  model.meshes.clear();
  model.meshes.push_back(SMesh());
  SMesh *mesh = &model.meshes.back();
  mesh->transformation = SMatrix::composeTransformation(mesh->position, mesh->rotation, mesh->scale);

  mesh->vertices.resize(NSky::VERTICES_SPHERE2 * NSky::VERTICES_ROUND2);
  mesh->faces.push_back(SFaces(&model.materials.back()));
  SFaces *face = &mesh->faces.back();
  face->faces.resize(NSky::VERTICES_SPHERE * NSky::VERTICES_ROUND2 * NSky::FACE_BLOCK_SIZE);

  for(uint32 h = 0; h < NSky::VERTICES_SPHERE2; h++)
  {
    //qDebug("___");
    const float y = static_cast<float>(h) / static_cast<float>(NSky::VERTICES_SPHERE);
    const float yRad = y * NMath::PI;
    //qDebug(QString("%1 %2 %3").arg(y).arg(yRad).arg(cosf(yRad)).toStdString().c_str());

    for(uint32 r = 0; r < NSky::VERTICES_ROUND2; r++)
    {
      const uint32 v = h * NSky::VERTICES_ROUND2 + r;
      const float x = static_cast<float>(r) / static_cast<float>(NSky::VERTICES_ROUND);
      const float xRad = x * NMath::PI_2;
      //qDebug(QString("%1").arg(v).toStdString().c_str());

      mesh->vertices[v].position = QVector3D(sinf(xRad) * sinf(yRad), cosf(yRad), cosf(xRad) * sinf(yRad));
      mesh->vertices[v].texCoord = QVector2D(x, (y - 0.5f) * ((y < 0.5f) ? 1.0f : -1.0f) * 2.0f);

      if((h) && (r))
      {
        const uint32 vv = (v - NSky::VERTICES_ROUND2 - 1) * NSky::FACE_BLOCK_SIZE;
        //qDebug(QString("%1 %2 %3").arg(vv).arg(v).arg(v - NSky::VERTICES_ROUND).toStdString().c_str());
        face->faces[vv + 0].vertex0 = v - 1;
        face->faces[vv + 0].vertex1 = v - NSky::VERTICES_ROUND2 - 1;
        face->faces[vv + 0].vertex2 = v;
        face->faces[vv + 1].vertex0 = v;
        face->faces[vv + 1].vertex1 = v - NSky::VERTICES_ROUND2 - 1;
        face->faces[vv + 1].vertex2 = v - NSky::VERTICES_ROUND2;
      }
      /*else
        qDebug("ne");*/
    }
  }
}
//------------------------------------------------------------------------------
CModels::CModels() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CModels::CModels(CContext *context) : CEngineBase(context)
{
}
//------------------------------------------------------------------------------
CModels::~CModels()
{
}
//------------------------------------------------------------------------------
void CModels::createRect()
{
  rect.vertices.resize(NHudRect::VERTICES_COUNT);
  rect.vertices[0].position = QVector3D( 0.5,  0.5, 0.0);
  rect.vertices[1].position = QVector3D(-0.5,  0.5, 0.0);
  rect.vertices[2].position = QVector3D(-0.5, -0.5, 0.0);
  rect.vertices[3].position = QVector3D( 0.5, -0.5, 0.0);
  rect.vertices[0].texCoord = QVector2D(1.0, 0.0);
  rect.vertices[1].texCoord = QVector2D(0.0, 0.0);
  rect.vertices[2].texCoord = QVector2D(0.0, 1.0);
  rect.vertices[3].texCoord = QVector2D(1.0, 1.0);

  rect.faces.push_back(SFaces());
  SFaces *faces = &rect.faces.back();
  faces->faces.resize(NHudRect::FACE_BLOCK_SIZE);
  faces->faces[0] = SFace(1, 0, 2);
  faces->faces[1] = SFace(3, 2, 0);
  createVbo(&rect);
}
//------------------------------------------------------------------------------
void CModels::createVbo(SMesh *mesh)
{
  QVector<float> vx(mesh->vertices.size() * NModel::VERTEX_PNTBTCC_SIZE);
  QVector<uint16> in;

  uint32 i = 0;
  for(auto v = mesh->vertices.begin(); v != mesh->vertices.end(); v++)
  {
    vx[i++] = v->position.x();
    vx[i++] = v->position.y();
    vx[i++] = v->position.z();
    vx[i++] = v->normal.x();
    vx[i++] = v->normal.y();
    vx[i++] = v->normal.z();
    vx[i++] = v->normalTangent.x();
    vx[i++] = v->normalTangent.y();
    vx[i++] = v->normalTangent.z();
    vx[i++] = v->normalBitangent.x();
    vx[i++] = v->normalBitangent.y();
    vx[i++] = v->normalBitangent.z();
    vx[i++] = v->texCoord.x();
    vx[i++] = v->texCoord.y();
    vx[i++] = v->color.x();
    vx[i++] = v->color.y();
    vx[i++] = v->color.z();
    vx[i++] = v->color2.x();
    vx[i++] = v->color2.y();
    vx[i++] = v->color2.z();
  }

  i = 0;
  for(auto faces = mesh->faces.begin(); faces != mesh->faces.end(); faces++)
  {
    in.resize(in.size() + faces->faces.size() * NModel::FACE_SIZE);

    for(auto f = faces->faces.begin(); f != faces->faces.end(); f++)
    {
      in[i++] = f->vertex0;
      in[i++] = f->vertex1;
      in[i++] = f->vertex2;
    }
  }

  if(mesh->vboVertices)
    context->getOpenGL()->deleteBuffers(1, &mesh->vboVertices);
  if(mesh->vboIndices)
    context->getOpenGL()->deleteBuffers(1, &mesh->vboIndices);

  context->getOpenGL()->genBuffers(1, &mesh->vboVertices);
  context->getOpenGL()->genBuffers(1, &mesh->vboIndices);

  context->getOpenGL()->bindBuffer(NOpenGL::ARRAY_BUFFER, mesh->vboVertices);
  context->getOpenGL()->bufferData(NOpenGL::ARRAY_BUFFER, vx.size() * sizeof(float), &vx[0], NOpenGL::STATIC_DRAW);
  context->getOpenGL()->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);

  context->getOpenGL()->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, mesh->vboIndices);
  context->getOpenGL()->bufferData(NOpenGL::ELEMENT_ARRAY_BUFFER, in.size() * sizeof(uint16), &in[0], NOpenGL::STATIC_DRAW);
  context->getOpenGL()->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, 0);
}
//------------------------------------------------------------------------------
void CModels::renderRectHud(const SSceneHud *sceneHud) const
{
  sceneHud->mesh.mvp = context->getCamera()->getCamera()->projection * sceneHud->mesh.mw;
  context->getRenderer()->addMesh(SRenderMesh(rect.vboVertices, rect.vboIndices, 0, NHudRect::FACE_BLOCK_SIZE, &sceneHud->mesh, &sceneHud->material));
}
//------------------------------------------------------------------------------

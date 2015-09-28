//------------------------------------------------------------------------------
#include "scene.h"

//------------------------------------------------------------------------------
CSceneObject::CSceneObject() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CSceneObject::CSceneObject(CContext *context, const SSceneObject &sceneObject) : CEngineBase(context), sceneObject(sceneObject)
{
  update();
}
//------------------------------------------------------------------------------
CSceneObject::CSceneObject(CContext *context, const SSceneObject &sceneObject, const STerrain &terrain) : CEngineBase(context), sceneObject(sceneObject)
{
  context->getModels()->addTerrain(SModel(), terrain, &this->sceneObject);
  update();
}
//------------------------------------------------------------------------------
CSceneObject::CSceneObject(CContext *context, const SSceneObject &sceneObject, const SWater &water) : CEngineBase(context), sceneObject(sceneObject)
{
  context->getModels()->addWater(SModel(), water, &this->sceneObject);
  update();
}
//------------------------------------------------------------------------------
CSceneObject::CSceneObject(CContext *context, const SSceneObject &sceneObject, const SSky &sky) : CEngineBase(context), sceneObject(sceneObject)
{
  context->getModels()->setSky(SModel(), sky, &this->sceneObject);
  update();
}
//------------------------------------------------------------------------------
CSceneObject::~CSceneObject()
{
}
//------------------------------------------------------------------------------
void CSceneObject::update(NScene::ESceneUpdateType type)
{
  UNUSED(type);

  const SScene *s = context->getScene()->getScene();

  for(auto t = sceneObject.meshes.begin(); t != sceneObject.meshes.end(); t++)
  {
    const float h = cosf(s->sunHeight * NMath::DEG_2_RAD);
    t->lightAmb = s->ambColor.toVector3D() * s->ambColor.w();
    t->lightPos = QVector3D(cosf(s->sunDir * NMath::DEG_2_RAD) * h, sinf(s->sunHeight * NMath::DEG_2_RAD), sinf(s->sunDir * NMath::DEG_2_RAD) * h) * 1000000.0f;
    t->lightColor = s->sunColor.toVector3D() * s->sunColor.w();
    t->lightSpeColor = QVector4D(s->sunSpec.toVector3D() * s->sunSpec.w(), s->sunPow);
    t->fogDist = QVector2D(s->fogDist, s->fogHeight);
    t->fogColor = s->fogColor.toVector3D() * s->fogColor.w();
    t->fogWaterDist = QVector2D(s->fogWaterDist, s->fogWaterHeight);
    t->fogWaterColor = s->fogWaterColor.toVector3D() * s->fogWaterColor.w();
    t->fogStart = QVector2D(s->fogStart, s->fogWaterStart);
  }
}
//------------------------------------------------------------------------------
CScene::CScene() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CScene::CScene(CContext *context) : CEngineBase(context)
{
  updateScene(SScene());
}
//------------------------------------------------------------------------------
CScene::~CScene()
{
}
//------------------------------------------------------------------------------

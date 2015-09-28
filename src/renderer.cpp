//------------------------------------------------------------------------------
#include "renderer.h"

//------------------------------------------------------------------------------
CRenderer::CRenderer() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CRenderer::CRenderer(CContext *context) : CEngineBase(context)
{
  meshes.resize(NShader::SHADERS_COUNT);
}
//------------------------------------------------------------------------------
CRenderer::~CRenderer()
{
}
//------------------------------------------------------------------------------
void CRenderer::addMesh(const SRenderMesh &mesh)
{
  if((!mesh.material) || (!mesh.material->program))
    return;

  meshes[mesh.material->program->getShaderProgram()->name].push_back(mesh);
}
//------------------------------------------------------------------------------
void CRenderer::runBatch() const
{
  for(uint32 i = 0; i < NShader::SHADERS_COUNT; i++)
  {
    const CShaderProgram *prog = context->getShaders()->getShaderProgram(static_cast<NShader::EProgram>(i));

    if((context->getCamera()->getCamera()->renderMode == NCamera::RENDER_MODE_REFLECTION) && ((prog->getShaderProgram()->name == NShader::PROGRAM_WATER) || (prog->getShaderProgram()->name == NShader::PROGRAM_UNDER_WATER)))
      continue;

    prog->bind();

    for(auto mesh = meshes[i].constBegin(); mesh != meshes[i].constEnd(); mesh++)
    {
      if(!mesh->technique)
        continue;

      context->getOpenGL()->bindBuffer(NOpenGL::ARRAY_BUFFER, mesh->vboVertices);
      context->getOpenGL()->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, mesh->vboIndices);

      mesh->technique->material = mesh->material;
      prog->begin(mesh->technique);
      context->getOpenGL()->drawElements(NOpenGL::TRIANGLES, mesh->facesCount * NModel::FACE_SIZE, NOpenGL::UNSIGNED_SHORT, reinterpret_cast<uint16 *>(sizeof(uint16) * mesh->faceStart * NModel::FACE_SIZE));
      prog->end(mesh->technique);

      context->getOpenGL()->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
      context->getOpenGL()->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, 0);
    }

    //prog->forceEnd();
  }
}
//------------------------------------------------------------------------------
void CRenderer::clearGroups()
{
  for(auto group = meshes.begin(); group != meshes.end(); group++)
    group->clear();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#ifndef RENDERER_H
#define RENDERER_H

#include "shaders.h"
#include "headers/rendererTypes.h"
#include "headers/sceneTypes.h"

//------------------------------------------------------------------------------
class CRenderer : public CEngineBase
{
  private:
    QVector<QVector<SRenderMesh> > meshes;

  public:
    CRenderer();
    CRenderer(CContext *context);
    ~CRenderer();

    void addMesh(const SRenderMesh &mesh);
    void runBatch() const;
    void clearGroups();
};
//------------------------------------------------------------------------------
#endif // RENDERER_H

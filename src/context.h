//------------------------------------------------------------------------------
#ifndef CONTEXT_H
#define CONTEXT_H

#include <QString>
#include <QVector>
#include <QList>

#include "headers/types.h"

//-----------------------------------------------------------------------------
class CEngine;
class CScene;
class CModels;
class CRenderer;
class CShaders;
class CCamera;
class CMaps;
class COpenGL;

//-----------------------------------------------------------------------------
class CContext
{
  private:
    CEngine *engine;
    CScene *scene;
    CModels *models;
    CRenderer *renderer;
    CShaders *shaders;
    CCamera *camera;
    CMaps *maps;
    COpenGL *opengGL;

  public:
    inline CContext() : engine(NULL), scene(NULL), models(NULL), renderer(NULL), shaders(NULL), camera(NULL), maps(NULL), opengGL(NULL) {}
    inline CContext(CEngine *engine, CScene *scene, CModels *models, CRenderer *renderer, CShaders *shaders, CCamera *camera, CMaps *maps, COpenGL *opengGL) : engine(engine), scene(scene), models(models), renderer(renderer), shaders(shaders), camera(camera), maps(maps), opengGL(opengGL) {}
    inline ~CContext() {}

    inline void setContext(CEngine *engine, CScene *scene, CModels *models, CRenderer *renderer, CShaders *shaders, CCamera *camera, CMaps *maps, COpenGL *opengGL) { this->engine = engine; this->scene = scene; this->models = models; this->renderer = renderer; this->shaders = shaders; this->camera = camera; this->maps = maps; this->opengGL = opengGL; }

    inline CEngine *getEngine() { return engine; }
    inline CScene *getScene() { return scene; }
    inline CModels *getModels() { return models; }
    inline CRenderer *getRenderer() { return renderer; }
    inline CShaders *getShaders() { return shaders; }
    inline CCamera *getCamera() { return camera; }
    inline CMaps *getMaps() { return maps; }
    inline COpenGL *getOpenGL() { return opengGL; }
};
//------------------------------------------------------------------------------
class CEngineBase
{
  protected:
    CContext *context;

  public:
    inline CEngineBase() : context(NULL) {}
    inline CEngineBase(CContext *context) : context(context) {}
    inline ~CEngineBase() {}

    inline CContext *getContext() { return context; }
};
//------------------------------------------------------------------------------
#endif // CONTEXT_H

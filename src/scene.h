//------------------------------------------------------------------------------
#ifndef SCENE_H
#define SCENE_H

#include "models.h"

//------------------------------------------------------------------------------
class CSceneObject : public CEngineBase
{
  private:
    SSceneObject sceneObject;

  public:
    CSceneObject();
    CSceneObject(CContext *context, const SSceneObject &sceneObject);
    CSceneObject(CContext *context, const SSceneObject &sceneObject, const STerrain &terrain);
    CSceneObject(CContext *context, const SSceneObject &sceneObject, const SWater &water);
    CSceneObject(CContext *context, const SSceneObject &sceneObject, const SSky &sky);
    ~CSceneObject();

    void update(NScene::ESceneUpdateType type = NScene::UPDATE_ALL);

    inline void render() const { sceneObject.model->render(&sceneObject); }

    inline const SSceneObject *getSceneObject() const { return &sceneObject; }
    inline CModel *getSceneModel() { return sceneObject.model; }
};
//------------------------------------------------------------------------------
class CScene : public CEngineBase
{
  private:
    SScene scene;
    QList<CSceneObject> sceneObjects;

  public:
    CScene();
    CScene(CContext *context);
    ~CScene();

    inline CSceneObject *addSceneObject(const SSceneObject &sceneObject) { sceneObjects.push_back(CSceneObject(context, sceneObject)); return &sceneObjects.back(); }
    inline CSceneObject *addSceneObjectTerrain(const SSceneObject &sceneObject, const STerrain &terrain) { sceneObjects.push_back(CSceneObject(context, sceneObject, terrain)); return &sceneObjects.back(); }
    inline CSceneObject *addSceneObjectWater(const SSceneObject &sceneObject, const SWater &water) { sceneObjects.push_back(CSceneObject(context, sceneObject, water)); return &sceneObjects.back(); }

    inline CSceneObject *updateSceneObject(uint32 index, const SSceneObject &sceneObject) { *(&sceneObjects[index]) = CSceneObject(context, sceneObject); return &sceneObjects[index]; }
    inline CSceneObject *updateSceneObjectTerrain(uint32 index, const SSceneObject &sceneObject, const STerrain &terrain) { *getSceneObject(index, NScene::OBJECT_TYPE_TERRAIN) = CSceneObject(context, sceneObject, terrain); return &sceneObjects[index]; }
    inline CSceneObject *updateSceneObjectWater(uint32 index, const SSceneObject &sceneObject, const SWater &water) { *getSceneObject(index, NScene::OBJECT_TYPE_WATER) = CSceneObject(context, sceneObject, water); return &sceneObjects[index]; }
    inline void updateScene(const SScene &scene) { this->scene = scene; for(auto s = sceneObjects.begin(); s != sceneObjects.end(); s++) s->update(); }

    inline void removeSceneObject(const CSceneObject *sceneObject) { for(auto s = sceneObjects.begin(); s != sceneObjects.end(); s++) { if(&(*s) == sceneObject) { sceneObjects.erase(s); return; } } }

    inline void clearScene() { sceneObjects.clear(); }

    inline void render() const { for(auto s = sceneObjects.begin(); s != sceneObjects.end(); s++) s->render(); }

    inline const SScene *getScene() const { return &scene; }
    inline uint32 getSceneObjectsCount() { return sceneObjects.size(); }
    CSceneObject *getSceneObject(uint32 index, NScene::ESceneObjectType type = NScene::OBJECT_TYPE_NONE);
};
//------------------------------------------------------------------------------
inline CSceneObject *CScene::getSceneObject(uint32 index, NScene::ESceneObjectType type)
{
  if(type == NScene::OBJECT_TYPE_NONE)
    return &sceneObjects[index];

  uint32 c = 0;
  for(int32 i = 0; i < sceneObjects.size(); i++)
  {
    if(sceneObjects[i].getSceneObject()->type == type)
      c++;
    if((c - 1) == index)
      return &sceneObjects[i];
  }

  return NULL;
}
//------------------------------------------------------------------------------
#endif // SCENE_H

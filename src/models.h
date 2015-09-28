//------------------------------------------------------------------------------
#ifndef MODELS_H
#define MODELS_H

#include "renderer.h"

//------------------------------------------------------------------------------
class CModel : public CEngineBase
{
  protected:
    SModel model;

  public:
    CModel();
    CModel(CContext *context, const SModel &model, SSceneObject *sceneObject);
    ~CModel();

    void update(SSceneObject *sceneObject);
    virtual void updateVirtual();

    void computeNormals(int32 mesh = -1);
    static void computeNormals(QVector<SVertex> &vertices, const QVector<SFace> &faces);

    void render(const SSceneObject *sceneObject) const;

    inline const SModel *getModel() const { return &model; }
};
//------------------------------------------------------------------------------
class CTerrain : public CModel
{
  private:
    STerrain terrain;

    void fractalGrid(float *heightMap, bool *usedHeightMap, const uint32 sizeX, const uint32 sizeZ, const uint32 defSizeX, const uint32 defSizeZ, const uint32 startCorner, const float depth);

  public:
    CTerrain();
    CTerrain(CContext *context, const SModel &model, const STerrain &terrain, SSceneObject *sceneObject);
    virtual ~CTerrain();

    virtual void updateVirtual();

    //static inline float rndHeight() { return rand() % 1000 * 0.001f - 0.5f; }
    static float rndHeight();

    inline const STerrain *getTerrain() const { return &terrain; }
};
//------------------------------------------------------------------------------
class CWater : public CModel
{
  private:
    SWater water;

  public:
    CWater();
    CWater(CContext *context, const SModel &model, const SWater &water, SSceneObject *sceneObject);
    virtual ~CWater();

    virtual void updateVirtual();

    inline const SWater *getWater() const { return &water; }
};
//------------------------------------------------------------------------------
class CSky : public CModel
{
  private:
    SSky sky;

  public:
    CSky();
    CSky(CContext *context, const SModel &model, const SSky &sky, SSceneObject *sceneObject);
    virtual ~CSky();

    virtual void updateVirtual();

    inline const SSky *getSky() const { return &sky; }
};
//------------------------------------------------------------------------------
class CModels : public CEngineBase
{
  private:
    SMesh rect;

    QList<CTerrain> terrains;
    QList<CWater> waters;
    CSky sky;

  public:
    CModels();
    CModels(CContext *context);
    ~CModels();

    void createRect();

    inline CTerrain *addTerrain(const SModel &model, const STerrain &terrain, SSceneObject *sceneObject) { terrains.push_back(CTerrain(context, model, terrain, sceneObject)); sceneObject->model = &terrains.back(); return &terrains.back(); }
    inline CWater *addWater(const SModel &model, const SWater &water, SSceneObject *sceneObject) { waters.push_back(CWater(context, model, water, sceneObject)); sceneObject->model = &waters.back(); return &waters.back(); }
    inline CSky *setSky(const SModel &model, const SSky &sky, SSceneObject *sceneObject) { this->sky = CSky(context, model, sky, sceneObject); sceneObject->model = &this->sky; return &this->sky; }

    inline void removeTerrain(const CTerrain *terrain) { for(auto i = terrains.begin(); i != terrains.end(); i++) { if(&(*i) == terrain) { terrains.erase(i); return; } } }
    inline void removeWater(const CWater *water) { for(auto i = waters.begin(); i != waters.end(); i++) { if(&(*i) == water) { waters.erase(i); return; } } }

    void createVbo(SMesh *mesh);

    void renderRectHud(const SSceneHud *sceneHud) const;

    inline const SMesh *getRect() const { return &rect; }
    inline CTerrain *getTerrain(uint32 index) { return &terrains[index]; }
    inline CWater *getWater(uint32 index) { return &waters[index]; }
};
//------------------------------------------------------------------------------
#endif // MODELS_H

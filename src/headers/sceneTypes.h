//-----------------------------------------------------------------------------
#ifndef SCENETYPES_H
#define SCENETYPES_H

#include "shadersTypes.h"

//-----------------------------------------------------------------------------
namespace NScene
{
  enum ESceneObjectType
  {
    OBJECT_TYPE_NONE = 0,
    OBJECT_TYPE_TERRAIN,
    OBJECT_TYPE_WATER,
    OBJECT_TYPE_SKY,
    OBJECT_TYPE_OBJECT,
    OBJECT_TYPE_LIGHT
  };

  enum ESceneUpdateType
  {
    UPDATE_ALL = 0,
    UPDATE_MODEL,
    UPDATE_TRANSFORMATION,
    UPDATE_LIGHTING
  };
}
//-----------------------------------------------------------------------------
class CModel;

struct SSceneObject
{
  NScene::ESceneObjectType type;
  CModel *model;
  QString name;
  QVector3D position;
  QQuaternion rotation;
  QVector3D scale;
  QMatrix4x4 mw;
  QMatrix3x3 mwnit;
  QList<SShaderTechnique> meshes;

  inline SSceneObject() : type(NScene::OBJECT_TYPE_OBJECT), model(NULL), scale(1.0, 1.0, 1.0) {}
  inline SSceneObject(NScene::ESceneObjectType type, QString name, QVector3D position = QVector3D(), QQuaternion rotation = QQuaternion(), QVector3D scale = QVector3D(1.0, 1.0, 1.0)) : type(type), model(NULL), name(name), position(position), rotation(rotation), scale(scale) {}
};

struct SSceneHud
{
  SMaterial material;
  QVector3D position;
  QQuaternion rotation;
  QVector3D scale;
  SShaderTechnique mesh;

  inline SSceneHud() : scale(1.0, 1.0, 1.0) {}
  inline SSceneHud(SMaterial material, QVector3D position, QQuaternion rotation, QVector3D scale, SShaderTechnique mesh) : material(material), position(position), rotation(rotation), scale(scale), mesh(mesh) {}
};

struct SScene
{
  float sunDir;
  float sunHeight;
  SSceneObject sun;
  QVector4D sunColor;
  QVector4D sunSpec;
  float sunPow;
  QVector4D skyColor;
  QVector4D ambColor;
  float fogDist;
  float fogHeight;
  float fogStart;
  QVector4D fogColor;
  float fogWaterDist;
  float fogWaterHeight;
  float fogWaterStart;
  QVector4D fogWaterColor;

  inline SScene() : sunDir(-20.0f), sunHeight(30.0f), sunColor(1.0, 1.0, 1.0, 1.0), sunSpec(1.0, 1.0, 1.0, 100.0), sunPow(2048.0f), skyColor(0.5, 0.6, 0.7, 1.0), ambColor(0.5, 0.6, 0.7, 1.0), fogDist(1024.0f), fogHeight(100.0f), fogStart(0.0f), fogColor(0.5, 0.6, 0.7, 1.0), fogWaterDist(128.0f), fogWaterHeight(10.0f), fogWaterStart(0.0f), fogWaterColor(0.5, 0.6, 0.7, 0.2) {}
  inline SScene(float sunDir, float sunHeight, SSceneObject sun, QVector4D sunColor, QVector4D sunSpec, float sunPow, QVector4D skyColor, QVector4D ambColor, float fogDist, float fogHeight, float fogStart, QVector4D fogColor, float fogWaterDist, float fogWaterHeight, float fogWaterStart, QVector4D fogWaterColor) : sunDir(sunDir), sunHeight(sunHeight), sun(sun), sunColor(sunColor), sunSpec(sunSpec), sunPow(sunPow), skyColor(skyColor), ambColor(ambColor), fogDist(fogDist), fogHeight(fogHeight), fogStart(fogStart), fogColor(fogColor), fogWaterDist(fogWaterDist), fogWaterHeight(fogWaterHeight), fogWaterStart(fogWaterStart), fogWaterColor(fogWaterColor) {}
};
//-----------------------------------------------------------------------------
#endif // SCENETYPES_H

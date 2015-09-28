//-----------------------------------------------------------------------------
#ifndef MODELSTYPES_H
#define MODELSTYPES_H

#include <QVector>
#include <QList>
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>
#include <QQuaternion>
#include <QMatrix3x3>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QSet>

#include "openGLTypes.h"

//-----------------------------------------------------------------------------
namespace NModel
{
  static const uint32 VERTEX_PNT_SIZE = 8;
  static const uint32 VERTEX_PNTBTCC_SIZE = 20;
  static const uint8 VBO_OFFSET_POSITION = 0;
  static const uint8 VBO_OFFSET_NORMAL = 3;
  static const uint8 VBO_OFFSET_NORMAL_TANGENT = 6;
  static const uint8 VBO_OFFSET_NORMAL_BITANGENT = 9;
  static const uint8 VBO_OFFSET_TEX_COORD = 12;
  static const uint8 VBO_OFFSET_COLOR = 14;
  static const uint8 VBO_OFFSET_COLOR2 = 17;

  static const uint32 FACE_SIZE = 3;
}
//-----------------------------------------------------------------------------
namespace NTerrain
{
  static const uint32 FACE_BLOCK_SIZE = 2;
  static const uint32 FACE_BLOCK_FACE_SIZE = 6;
}
//-----------------------------------------------------------------------------
namespace NWater
{
  static const uint32 VERTICES_COUNT = 4;
  static const uint32 FACE_BLOCK_SIZE = 2;
}
//-----------------------------------------------------------------------------
namespace NSky
{
  static const uint32 VERTICES_ROUND = 12;
  static const uint32 VERTICES_ROUND2 = VERTICES_ROUND + 1;
  static const uint32 VERTICES_SPHERE = 12;
  static const uint32 VERTICES_SPHERE2 = VERTICES_SPHERE + 1;
  static const uint32 FACE_BLOCK_SIZE = 2;
}
//-----------------------------------------------------------------------------
namespace NHudRect
{
  static const uint32 VERTICES_COUNT = 4;
  static const uint32 FACE_BLOCK_SIZE = 2;
}
//-----------------------------------------------------------------------------
class CShaderProgram;
class CMap;

struct SMaterial
{
  const CShaderProgram *program;
  const CMap *diffuseTexture;
  const CMap *alphaTexture;
  const CMap *specularTexture;
  const CMap *normalTexture;
  const CMap *environmentTexture;
  const CMap *diffuseTexture1;
  const CMap *diffuseTexture2;
  const CMap *specularTexture1;
  const CMap *specularTexture2;
  const CMap *normalTexture1;
  const CMap *normalTexture2;
  QVector<int32> layerVx;
  bool depth;
  bool blend;

  inline SMaterial() : program(NULL), diffuseTexture(NULL), alphaTexture(NULL), specularTexture(NULL), normalTexture(NULL), environmentTexture(NULL), diffuseTexture1(NULL), diffuseTexture2(NULL), specularTexture1(NULL), specularTexture2(NULL), normalTexture1(NULL), normalTexture2(NULL), depth(true), blend(false) {}
  inline SMaterial(const CShaderProgram *program, const CMap *diffuseTexture, const CMap *alphaTexture, const CMap *specularTexture, const CMap *normalTexture, const CMap *environmentTexture, const CMap *diffuseTexture1 = NULL, const CMap *diffuseTexture2 = NULL, const CMap *specularTexture1 = NULL, const CMap *specularTexture2 = NULL, const CMap *normalTexture1 = NULL, const CMap *normalTexture2 = NULL, QVector<int32> layerVx = QVector<int32>(), bool depth = true, bool blend = false) : program(program), diffuseTexture(diffuseTexture), alphaTexture(alphaTexture), specularTexture(specularTexture), normalTexture(normalTexture), environmentTexture(environmentTexture), diffuseTexture1(diffuseTexture1), diffuseTexture2(diffuseTexture2), specularTexture1(specularTexture1), specularTexture2(specularTexture2), normalTexture1(normalTexture1), normalTexture2(normalTexture2), layerVx(layerVx), depth(depth), blend(blend) {}
};
//-----------------------------------------------------------------------------
struct SMaterialLayer
{
  QVector4D color;
  const CMap *baseTexture;
  const CMap *detailTexture;
  bool useHeightLimit;
  float minHeight;
  float maxHeight;
  bool useSlopeLimit;
  float minSlope;
  float maxSlope;

  inline SMaterialLayer() : color(1.0, 0.0, 0.0, 1.0), baseTexture(NULL), detailTexture(NULL), useHeightLimit(false), minHeight(-0.5f), maxHeight(0.5f), useSlopeLimit(false), minSlope(0.0f), maxSlope(1.0f) {}
  inline SMaterialLayer(QVector4D color, const CMap *baseTexture, const CMap *detailTexture, bool useHeightLimit, float minHeight, float maxHeight, bool useSlopeLimit, float minSlope, float maxSlope) : color(color), baseTexture(baseTexture), detailTexture(detailTexture), useHeightLimit(useHeightLimit), minHeight(minHeight), maxHeight(maxHeight), useSlopeLimit(useSlopeLimit), minSlope(minSlope), maxSlope(maxSlope) {}
};
//-----------------------------------------------------------------------------
struct STerrain
{
  uint32 seed;
  uint32 stepX;
  uint32 stepZ;
  uint32 divStepX;
  uint32 divStepZ;
  bool landBorder;
  float heightMultiplier;
  float depthMultiplier;
  float heightModifier0;
  float heightModifier1;
  QVector<SMaterialLayer> layers;

  inline STerrain() : seed(132), stepX(10), stepZ(10), divStepX(4), divStepZ(4), landBorder(true), heightMultiplier(0.3f), depthMultiplier(0.4f), heightModifier0(-0.1f), heightModifier1(0.2f) {}
  inline STerrain(uint32 seed, uint32 stepX, uint32 stepZ, uint32 divStepX, uint32 divStepZ, bool landBorder, float heightMultiplier, float depthMultiplier, float heightModifier0, float heightModifier1, const QVector<SMaterialLayer> &layers) : seed(seed), stepX(stepX), stepZ(stepZ), divStepX(divStepX), divStepZ(divStepZ), landBorder(landBorder), heightMultiplier(heightMultiplier), depthMultiplier(depthMultiplier), heightModifier0(heightModifier0), heightModifier1(heightModifier1), layers(layers) {}
};
//-----------------------------------------------------------------------------
struct SWater
{
  const CMap *detailTexture;
  const CMap *windTexture;
  const CMap *environmentTexture;
  float depth;
  QVector4D color;
  const CMap *detailGroundTexture;

  inline SWater() : detailTexture(NULL), windTexture(NULL), environmentTexture(NULL), depth(-0.001), color(1.0, 1.0, 1.0, 1.0), detailGroundTexture(NULL) {}
  inline SWater(const CMap *detailTexture, const CMap *windTexture, const CMap *environmentTexture, float depth, QVector4D color, const CMap *detailGroundTexture) : detailTexture(detailTexture), windTexture(windTexture), environmentTexture(environmentTexture), depth(depth), color(color), detailGroundTexture(detailGroundTexture) {}
};
//-----------------------------------------------------------------------------
struct SSky
{
  const CMap *diffuseTexture;

  inline SSky() {}
  inline SSky(const CMap *diffuseTexture) : diffuseTexture(diffuseTexture) {}
};
//-----------------------------------------------------------------------------
struct SFace
{
  uint16 vertex0;
  uint16 vertex1;
  uint16 vertex2;

  inline SFace() : vertex0(0), vertex1(0), vertex2(0) {}
  inline SFace(uint16 vertex0, uint16 vertex1, uint16 vertex2) : vertex0(vertex0), vertex1(vertex1), vertex2(vertex2) {}

  inline bool contains(uint16 vertex) const { if((vertex == vertex0) || (vertex == vertex1) || (vertex == vertex2)) return true; return false; }
};
//-----------------------------------------------------------------------------
struct SFaces
{
  QVector<SFace> faces;
  const SMaterial *material;

  inline SFaces() : material(NULL) {}
  inline SFaces(const SMaterial *material) : material(material) {}
};
//-----------------------------------------------------------------------------
struct SVertex
{
  QVector3D position;
  QVector3D normal;
  QVector3D normalTangent;
  QVector3D normalBitangent;
  QVector2D texCoord;
  QVector3D color;
  QVector3D color2;

  inline SVertex() : normal(0.0, 1.0, 0.0), normalTangent(1.0, 0.0, 0.0), normalBitangent(0.0, 0.0, 1.0), color(1.0, 1.0, 1.0) {}
  inline SVertex(QVector3D position, QVector3D normal, QVector3D normalTangent, QVector3D normalBitangent, QVector2D texCoord, QVector3D color, QVector3D color2) : position(position), normal(normal), normalTangent(normalTangent), normalBitangent(normalBitangent), texCoord(texCoord), color(color), color2(color2) {}
};
//-----------------------------------------------------------------------------
struct SMesh
{
  QVector3D position;
  QQuaternion rotation;
  QVector3D scale;
  QMatrix4x4 transformation;
  QVector<SVertex> vertices;
  QVector<SFaces> faces;
  GLuint vboVertices;
  GLuint vboIndices;

  inline SMesh() : scale(1.0, 1.0, 1.0), vboVertices(0), vboIndices(0) {}
};
//-----------------------------------------------------------------------------
struct SModel
{
  QList<SMaterial> materials;
  QList<SMesh> meshes;
};
//-----------------------------------------------------------------------------
#endif // MODELSTYPES_H

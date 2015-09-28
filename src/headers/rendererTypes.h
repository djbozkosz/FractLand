//------------------------------------------------------------------------------
#ifndef RENDERERTYPES_H
#define RENDERERTYPES_H

#include "shadersTypes.h"

//------------------------------------------------------------------------------
namespace NRenderer
{
}

struct SRenderMesh
{
  GLuint vboVertices;
  GLuint vboIndices;
  uint32 faceStart;
  uint32 facesCount;
  const SShaderTechnique *technique;
  const SMaterial *material;

  inline SRenderMesh() : vboVertices(0), vboIndices(0), faceStart(0), facesCount(0), technique(NULL), material(NULL) {}
  inline SRenderMesh(GLuint vboVertices, GLuint vboIndices, uint32 faceStart, uint32 facesCount, const SShaderTechnique *technique, const SMaterial *material) : vboVertices(vboVertices), vboIndices(vboIndices), faceStart(faceStart), facesCount(facesCount), technique(technique), material(material) {}
};
//------------------------------------------------------------------------------
#endif // RENDERERTYPES_H

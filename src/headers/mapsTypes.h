//-----------------------------------------------------------------------------
#ifndef MAPSTYPES_H
#define MAPSTYPES_H

#include <QString>
#include <QFile>
#include <QVector4D>

#include "openGLTypes.h"

//-----------------------------------------------------------------------------
namespace NMap
{
  static const char STR_DEFAULT_NORMAL[] = ":/maps/data/maps/defaultNormal00.png";

  enum EMapDefault
  {
    DEFAULT_NORMAL = 0
  };
}

struct SMap
{
  QString file;
  GLuint texture;
  QVector4D color;
  bool framebuffer;
  uint32 width;
  uint32 height;

  inline SMap() : texture(0), framebuffer(false), width(0), height(0) {}
  inline SMap(QString file, QVector4D color) : file(file), texture(0), color(color), framebuffer(false), width(0), height(0) {}
  inline SMap(uint32 width, uint32 height) : texture(0), framebuffer(true), width(width), height(height) {}
};

class CMap;

struct SFramebuffer
{
  GLuint fboColor;
  GLuint rboDepth;
  const CMap *fboColorTexture;
  bool color;
  bool depth;
  uint32 width;
  uint32 height;

  inline SFramebuffer() : fboColor(0), rboDepth(0), fboColorTexture(NULL), color(false), depth(false), width(1), height(1) {}
  inline SFramebuffer(bool color, bool depth, uint32 width, uint32 height) : fboColor(0), rboDepth(0), fboColorTexture(NULL), color(color), depth(depth), width(width), height(height) {}
};
//-----------------------------------------------------------------------------
#endif // MAPSTYPES_H

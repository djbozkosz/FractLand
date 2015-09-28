//------------------------------------------------------------------------------
#include "maps.h"

//------------------------------------------------------------------------------
CMap::CMap() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CMap::CMap(CContext *context, const SMap &map) : CEngineBase(context), map(map)
{
  load();
}
//------------------------------------------------------------------------------
CMap::~CMap()
{
}
//------------------------------------------------------------------------------
void CMap::load()
{
  if(map.framebuffer)
  {
    QImage i(map.width, map.height, QImage::Format_ARGB32);
    context->getOpenGL()->genTextures(1, &map.texture);
    context->getOpenGL()->bindTexture(NOpenGL::TEXTURE_2D, map.texture);
    context->getOpenGL()->texImage2D(NOpenGL::TEXTURE_2D, 0, NOpenGL::RGBA, i.width(), i.height(), 0, NOpenGL::RGBA, NOpenGL::UNSIGNED_BYTE, i.constBits());
    context->getOpenGL()->bindTexture(NOpenGL::TEXTURE_2D, 0);
  }
  else
  {
    QImage i(map.file);
    context->getOpenGL()->genTextures(1, &map.texture);
    context->getOpenGL()->bindTexture(NOpenGL::TEXTURE_2D, map.texture);
    if(!i.isNull())
    {
      //i = i.convertToFormat(QImage::Format_RGBA8888);
      QVector<uint8> data(i.width() * i.height() * 4);
      memcpy(&data[0], i.constBits(), sizeof(uint8) * i.width() * i.height() * 4);
      for(int32 j = 0; j < (i.width() * i.height() * 4); j += 4)
      {
        uint8 b = data[j + 0];
        data[j + 0] = data[j + 2];
        data[j + 2] = b;
      }
      //qDebug(QString("Texture loaded: "+map.file).toStdString().c_str());
      context->getOpenGL()->texImage2D(NOpenGL::TEXTURE_2D, 0, NOpenGL::RGBA, i.width(), i.height(), 0, NOpenGL::RGBA, NOpenGL::UNSIGNED_BYTE, &data[0]);
    }
    else
    {
      qDebug(QString("Unable to load texture: "+map.file).toStdString().c_str());
      const uint8 color[4] = { static_cast<uint8>(map.color.x() * 255.0f), static_cast<uint8>(map.color.y() * 255.0f), static_cast<uint8>(map.color.z() * 255.0f), static_cast<uint8>(map.color.w() * 255.0f) };
      context->getOpenGL()->texImage2D(NOpenGL::TEXTURE_2D, 0, NOpenGL::RGBA, 1, 1, 0, NOpenGL::RGBA, NOpenGL::UNSIGNED_BYTE, color);
    }
    context->getOpenGL()->generateMipmap(NOpenGL::TEXTURE_2D);
    context->getOpenGL()->bindTexture(NOpenGL::TEXTURE_2D, 0);
  }
}
//------------------------------------------------------------------------------
CFramebuffer::CFramebuffer()
{
}
//------------------------------------------------------------------------------
CFramebuffer::CFramebuffer(CContext *context, const SFramebuffer &framebuffer) : CEngineBase(context), framebuffer(framebuffer)
{
  create();
}
//------------------------------------------------------------------------------
CFramebuffer::~CFramebuffer()
{
}
//------------------------------------------------------------------------------
void CFramebuffer::create()
{
  if(framebuffer.color)
  {
    framebuffer.fboColorTexture = context->getMaps()->addFbo(framebuffer.width, framebuffer.height);
    context->getOpenGL()->genFramebuffers(1, &framebuffer.fboColor);
    context->getOpenGL()->bindFramebuffer(NOpenGL::FRAMEBUFFER, framebuffer.fboColor);
    context->getOpenGL()->framebufferTexture2D(NOpenGL::FRAMEBUFFER, NOpenGL::COLOR_ATTACHMENT0, NOpenGL::TEXTURE_2D, framebuffer.fboColorTexture->getMap()->texture, 0);
  }
  if(framebuffer.depth)
  {
    context->getOpenGL()->genRenderbuffers(1, &framebuffer.rboDepth);
    context->getOpenGL()->bindRenderbuffer(NOpenGL::RENDERBUFFER, framebuffer.rboDepth);
    context->getOpenGL()->renderbufferStorage(NOpenGL::RENDERBUFFER, NOpenGL::DEPTH_COMPONENT24, framebuffer.width, framebuffer.height);
    context->getOpenGL()->framebufferRenderbuffer(NOpenGL::FRAMEBUFFER, NOpenGL::DEPTH_ATTACHMENT, NOpenGL::RENDERBUFFER, framebuffer.rboDepth);
  }

  context->getOpenGL()->bindRenderbuffer(NOpenGL::RENDERBUFFER, 0);
  context->getOpenGL()->bindFramebuffer(NOpenGL::FRAMEBUFFER, 0);
  context->getOpenGL()->bindTexture(NOpenGL::TEXTURE_2D, 0);
}
//------------------------------------------------------------------------------
CMaps::CMaps() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CMaps::CMaps(CContext *context) : CEngineBase(context)
{
}
//------------------------------------------------------------------------------
void CMaps::loadDefaultMaps()
{
  addMap(SMap(NMap::STR_DEFAULT_NORMAL, QVector4D(0.5, 0.5, 1.0, 1.0)));
}
//------------------------------------------------------------------------------
CMaps::~CMaps()
{
}
//------------------------------------------------------------------------------

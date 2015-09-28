//------------------------------------------------------------------------------
#ifndef MAPS_H
#define MAPS_H

#include <QImage>

#include "camera.h"
#include "headers/mapsTypes.h"

//------------------------------------------------------------------------------
class CMap : public CEngineBase
{
  private:
    SMap map;

  public:
    CMap();
    CMap(CContext *context, const SMap &map);
    ~CMap();

    void load();

    void bind(GLuint uniform = 0, uint8 sampler = 0, bool mipmap = true, bool edge = false) const;

    inline const SMap *getMap() const { return &map; }
};
//------------------------------------------------------------------------------
class CFramebuffer : public CEngineBase
{
  private:
    SFramebuffer framebuffer;

  public:
    CFramebuffer();
    CFramebuffer(CContext *context, const SFramebuffer &framebuffer);
    ~CFramebuffer();

    void create();

    inline void bind() const { context->getOpenGL()->bindFramebuffer(NOpenGL::FRAMEBUFFER, framebuffer.fboColor); context->getOpenGL()->viewport(0, 0, framebuffer.width, framebuffer.height); }
    inline void unbind() const { context->getOpenGL()->bindFramebuffer(NOpenGL::FRAMEBUFFER, 0); context->getOpenGL()->viewport(0, 0, context->getCamera()->getCamera()->width, context->getCamera()->getCamera()->height); }

    inline const SFramebuffer *getFrameBuffer() const { return &framebuffer; }
};
//------------------------------------------------------------------------------
class CMaps : public CEngineBase
{
  private:
    QList<CMap> maps;

  public:
    CMaps();
    CMaps(CContext *context);
    ~CMaps();

    void loadDefaultMaps();

    CMap *addMap(const SMap &map);
    inline CMap *addFbo(uint32 width, uint32 height) { maps.push_back(CMap(context, SMap(width, height))); return &maps.back(); }

    inline void finishBind() const { context->getOpenGL()->activeTexture(NOpenGL::TEXTURE0); }
    inline void unbind(GLuint uniform = 0, uint8 sampler = 0) const { context->getOpenGL()->activeTexture(NOpenGL::TEXTURE0 + sampler); context->getOpenGL()->bindTexture(NOpenGL::TEXTURE_2D, 0); context->getOpenGL()->uniform1i(uniform, sampler); }

    inline const CMap *getMap(uint32 index) const { return &maps.at(index); }
};
//------------------------------------------------------------------------------
inline void CMap::bind(GLuint uniform, uint8 sampler, bool mipmap, bool edge) const
{
  context->getOpenGL()->activeTexture(NOpenGL::TEXTURE0 + sampler);
  context->getOpenGL()->bindTexture(NOpenGL::TEXTURE_2D, map.texture);
  context->getOpenGL()->texParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_MAG_FILTER, NOpenGL::LINEAR);
  context->getOpenGL()->texParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_MIN_FILTER, mipmap ? NOpenGL::LINEAR_MIPMAP_LINEAR : NOpenGL::LINEAR);
  /*context->getOpenGL()->texParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_MIN_FILTER, NOpenGL::LINEAR_MIPMAP_LINEAR);
  if(mipmap)
    context->getOpenGL()->texParameterf(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_MAX_ANISOTROPY, 1.0f);
  else
    context->getOpenGL()->texParameterf(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_MAX_ANISOTROPY, 8.0f);*/
  context->getOpenGL()->texParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_WRAP_S, edge ? NOpenGL::CLAMP_TO_EDGE : NOpenGL::REPEAT);
  context->getOpenGL()->texParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_WRAP_T, edge ? NOpenGL::CLAMP_TO_EDGE : NOpenGL::REPEAT);
  context->getOpenGL()->uniform1i(uniform, sampler);
}
//------------------------------------------------------------------------------
inline CMap *CMaps::addMap(const SMap &map)
{
  for(auto m = maps.begin(); m != maps.end(); m++)
  {
    if(map.file == m->getMap()->file)
      return &(*m);
  }

  maps.push_back(CMap(context, map));

  return &maps.back();
}
//------------------------------------------------------------------------------
#endif // MAPS_H

//------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#include <QElapsedTimer>

#include "openGL.h"
#include "headers/cameraTypes.h"

//------------------------------------------------------------------------------
class CCamera : public CEngineBase
{
  private:
    SCamera camera;
    QElapsedTimer timer;

  public:
    inline CCamera() : CEngineBase() { timer.start(); }
    inline CCamera(CContext *context) : CEngineBase(context) { timer.start(); }
    inline ~CCamera() {}

    void updateMatrices();

    inline void setActive(bool active) { camera.active = active; }

    inline void setTouchMode(bool mode) { camera.touchMode = mode; }
    inline void setTouchMoveId(int32 id) { camera.touchMoveId = id; }

    inline void setCamera(SCamera camera) { this->camera = camera; updateMatrices(); }
    inline void setSize(float width, float height) { camera.width = width; camera.height = height; updateMatrices(); }
    inline void setRange(float clipNear, float clipFar) { camera.clipNear = clipNear; camera.clipFar = clipFar; updateMatrices(); }
    inline void setFov(float fov) { camera.fov = fov; updateMatrices(); }

    inline void setPosition(const QVector3D &position) { camera.position.setX(position.x()); camera.position.setY(position.y()); camera.position.setZ(position.z()); updateMatrices(); }
    bool setMove();
    inline void setRotation(const QVector3D &rotation) { camera.rotation.setX(rotation.x()); camera.rotation.setY(rotation.y()); camera.rotation.setZ(rotation.z()); updateMatrices(); }
    void setRotate(int32 x, int32 y, bool active);
    inline void setKeys(const bool *keys) { memcpy(camera.keys, keys, sizeof(bool) * NCamera::KEYS_COUNT); }
    inline void setSpeed(float speed = NCamera::MOVEMENT_SPEED) { camera.position.setW(speed); }
    inline void setSensitivity(float sensitivity = NCamera::SENSITIVITY_SPEED) { camera.rotation.setW(sensitivity); }

    void updateTicks();
    inline void incDrawCalls() { camera.drawCalls++; }
    inline void clearDrawCalls() { camera.drawCalls = 0; }

    inline void setRenderMode(NCamera::ERenderMode renderMode = NCamera::RENDER_MODE_NORMAL) { camera.renderMode = renderMode; }

    inline const SCamera *getCamera() const { return &camera; }
    inline const QElapsedTimer *getTimer() const { return &timer; }
};
//------------------------------------------------------------------------------
inline void CCamera::updateMatrices()
{
  camera.view.setToIdentity();
  camera.view.rotate(camera.rotation.x(), 1.0, 0.0, 0.0);
  camera.view.rotate(camera.rotation.y(), 0.0, 1.0, 0.0);
  camera.view.translate(camera.position.x() * NCamera::SCALE_X, camera.position.y() * -NCamera::SCALE_Y, camera.position.z() * NCamera::SCALE_Z);
  camera.view.scale(NCamera::SCALE_X, NCamera::SCALE_Y, NCamera::SCALE_Z);
  camera.projection.setToIdentity();
  camera.projection.perspective(camera.fov, camera.width / camera.height, camera.clipNear, camera.clipFar);
  camera.viewProjection = camera.projection * camera.view;
}
//------------------------------------------------------------------------------
inline bool CCamera::setMove()
{
  bool ret = false;

  if(camera.keys[NCamera::KEY_F])
  {
    camera.position.setX(camera.position.x() + camera.position.w() * camera.simulationStep * sinf(camera.rotation.y() * NMath::DEG_2_RAD) * cosf(camera.rotation.x() * NMath::DEG_2_RAD));
    camera.position.setY(camera.position.y() - camera.position.w() * camera.simulationStep * sinf(camera.rotation.x() * NMath::DEG_2_RAD));
    camera.position.setZ(camera.position.z() + camera.position.w() * camera.simulationStep * cosf(camera.rotation.y() * NMath::DEG_2_RAD) * cosf(camera.rotation.x() * NMath::DEG_2_RAD));
    ret = true;
  }
  if(camera.keys[NCamera::KEY_B])
  {
    camera.position.setX(camera.position.x() - camera.position.w() * camera.simulationStep * sinf(camera.rotation.y() * NMath::DEG_2_RAD) * cosf(camera.rotation.x() * NMath::DEG_2_RAD));
    camera.position.setY(camera.position.y() + camera.position.w() * camera.simulationStep * sinf(camera.rotation.x() * NMath::DEG_2_RAD));
    camera.position.setZ(camera.position.z() - camera.position.w() * camera.simulationStep * cosf(camera.rotation.y() * NMath::DEG_2_RAD) * cosf(camera.rotation.x() * NMath::DEG_2_RAD));
    ret = true;
  }
  if(camera.keys[NCamera::KEY_L])
  {
    camera.position.setX(camera.position.x() - camera.position.w() * camera.simulationStep * cosf(camera.rotation.y() * NMath::DEG_2_RAD));
    camera.position.setZ(camera.position.z() + camera.position.w() * camera.simulationStep * sinf(camera.rotation.y() * NMath::DEG_2_RAD));
    ret = true;
  }
  if(camera.keys[NCamera::KEY_R])
  {
    camera.position.setX(camera.position.x() + camera.position.w() * camera.simulationStep * cosf(camera.rotation.y() * NMath::DEG_2_RAD));
    camera.position.setZ(camera.position.z() - camera.position.w() * camera.simulationStep * sinf(camera.rotation.y() * NMath::DEG_2_RAD));
    ret = true;
  }
  if(camera.keys[NCamera::KEY_D])
  {
    camera.position.setX(camera.position.x() - camera.position.w() * camera.simulationStep * sinf(camera.rotation.x() * NMath::DEG_2_RAD) * sinf(camera.rotation.y() * NMath::DEG_2_RAD));
    camera.position.setY(camera.position.y() - camera.position.w() * camera.simulationStep * cosf(camera.rotation.x() * NMath::DEG_2_RAD));
    camera.position.setZ(camera.position.z() - camera.position.w() * camera.simulationStep * sinf(camera.rotation.x() * NMath::DEG_2_RAD) * cosf(camera.rotation.y() * NMath::DEG_2_RAD));
    ret = true;
  }
  if(camera.keys[NCamera::KEY_U])
  {
    camera.position.setX(camera.position.x() + camera.position.w() * camera.simulationStep * sinf(camera.rotation.x() * NMath::DEG_2_RAD) * sinf(camera.rotation.y() * NMath::DEG_2_RAD));
    camera.position.setY(camera.position.y() + camera.position.w() * camera.simulationStep * cosf(camera.rotation.x() * NMath::DEG_2_RAD));
    camera.position.setZ(camera.position.z() + camera.position.w() * camera.simulationStep * sinf(camera.rotation.x() * NMath::DEG_2_RAD) * cosf(camera.rotation.y() * NMath::DEG_2_RAD));
    ret = true;
  }

  if(ret)
    updateMatrices();

  return ret;
}
//------------------------------------------------------------------------------
inline void CCamera::setRotate(int32 x, int32 y, bool active)
{
  QVector2D v(static_cast<float>(x), static_cast<float>(y));

  if(active)
  {
    camera.cursor = camera.cursorOld - v;
    camera.rotation.setX(camera.rotation.x() - camera.cursor.y() * camera.rotation.w());
    camera.rotation.setY(camera.rotation.y() - camera.cursor.x() * camera.rotation.w());
    if(camera.rotation.x() > NMath::PI_RAD)
      camera.rotation.setX(camera.rotation.x() - NMath::PI_2_RAD);
    if(camera.rotation.x() < -NMath::PI_RAD)
      camera.rotation.setX(camera.rotation.x() + NMath::PI_2_RAD);
    if(camera.rotation.y() > NMath::PI_RAD)
      camera.rotation.setY(camera.rotation.y() - NMath::PI_2_RAD);
    if(camera.rotation.y() < -NMath::PI_RAD)
      camera.rotation.setY(camera.rotation.y() + NMath::PI_2_RAD);
    camera.rotation.setZ(0.0);

    updateMatrices();
  }

  camera.cursorOld = v;
}
//------------------------------------------------------------------------------
inline void CCamera::updateTicks()
{
  camera.tickNew = static_cast<uint32>(timer.elapsed());

  if(!camera.tickOld)
    camera.tickOld = camera.tickNew;

  if((camera.tickNew != camera.tickOld) && (!camera.fpsCounter))
  {
    camera.simulationStep = static_cast<float>(camera.tickNew - camera.tickOld) * NCamera::FPS_MS / NCamera::FPS_COUNTER_MAX;
    camera.fps = 1.0f / camera.simulationStep;
    camera.tickOld = camera.tickNew;
  }
  camera.fpsCounter++;
  if(camera.fpsCounter == NCamera::FPS_COUNTER_MAX)
    camera.fpsCounter = 0;
}
//------------------------------------------------------------------------------
#endif // CAMERA_H

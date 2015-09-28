//-----------------------------------------------------------------------------
#ifndef CAMERATYPES_H
#define CAMERATYPES_H

#include <QVector2D>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>

#include "math.h"

//------------------------------------------------------------------------------
namespace NCamera
{
  static const float CLIP_NEAR = 0.1f;
  static const float CLIP_FAR = 1000.0f;
  static const float CLIP_BACKDROP_NEAR = 10.0f;
  static const float CLIP_BACKDROP_FAR = 10000.0f;
  static const float FOV = 60.0f;

  static const float SCALE_X = -1.0f;
  static const float SCALE_Y = 1.0f;
  static const float SCALE_Z = 1.0f;

  static const uint8 CURSOR_COUNTER_MAX = 3;

  static const uint8 KEYS_COUNT = 6;
  static const float MOVEMENT_SPEED = 1.0f;
  static const float SENSITIVITY_SPEED = 1.0f;

  static const uint32 REDRAW_TIMER_MS = 17;
  static const float FPS_MS = 0.001f;
  static const uint8 FPS_COUNTER_MAX = 10;

  static const int32 TOUCH_MOVE_ID_NONE = -1;

  enum ERenderMode
  {
    RENDER_MODE_NORMAL = 0,
    RENDER_MODE_REFLECTION
  };

  enum ECameraKeys
  {
    KEY_F = 0,
    KEY_B,
    KEY_L,
    KEY_R,
    KEY_D,
    KEY_U
  };
}
//-----------------------------------------------------------------------------
struct SCamera
{
  bool keys[NCamera::KEYS_COUNT];
  bool active;

  QVector4D position;
  QVector4D rotation;

  float width;
  float height;
  bool touchMode;
  int32 touchMoveId;

  QVector2D cursor;
  QVector2D cursorOld;
  QVector2D cursorDir; // normalized
  int32 cursorCounter;

  uint32 tickOld;
  uint32 tickNew;
  float simulationStep;
  float fps;
  uint32 fpsCounter;

  uint32 drawCalls;

  NCamera::ERenderMode renderMode;

  float clipNear;
  float clipFar;
  float fov;

  QMatrix4x4 projection;
  QMatrix4x4 view;
  QMatrix4x4 viewProjection;

  SCamera() : active(false), position(0.0, 0.0, 0.0, NCamera::MOVEMENT_SPEED), rotation(0.0, 0.0, 0.0, NCamera::SENSITIVITY_SPEED), width(1.0), height(1.0), touchMode(false), touchMoveId(NCamera::TOUCH_MOVE_ID_NONE), cursorCounter(0), tickOld(0), tickNew(0), simulationStep(1.0), fps(0.0), fpsCounter(0), drawCalls(0), renderMode(NCamera::RENDER_MODE_NORMAL), clipNear(NCamera::CLIP_NEAR), clipFar(NCamera::CLIP_FAR), fov(NCamera::FOV)
  {
    memset(keys, 0, sizeof(bool) * NCamera::KEYS_COUNT);
  }
};
//-----------------------------------------------------------------------------
#endif // CAMERATYPES_H

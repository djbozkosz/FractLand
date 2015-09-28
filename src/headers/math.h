//------------------------------------------------------------------------------
#ifndef MATH_H
#define MATH_H

#include <QtGlobal>
#include <QVector>
#include <QVector4D>
#include <QQuaternion>
#include <QMatrix3x3>
#include <QMatrix4x4>
#include <cmath>
#include "types.h"

//------------------------------------------------------------------------------
namespace NMath
{
  static const float PI = 3.1415926535897932384626433832795f;
  static const float PI_2 = 6.283185307179586476925286766559f;
  static const float DIV_2_PI = 0.63661977236758134307553505349006f;
  static const float PI_RAD = 180.0f;
  static const float PI_2_RAD = 360.0f;
  static const float RAD_2_DEG = PI_RAD / PI;
  static const float DEG_2_RAD = PI / PI_RAD;
  static const uint8 MAT3 = 9;
  static const uint8 MAT4 = 16;
}
//------------------------------------------------------------------------------
struct SQuaternion
{
  static inline QVector3D quat2angle(QQuaternion q)
  {
    float x = q.x();
    float y = q.y();
    float z = q.z();
    float w = q.scalar();
    QVector3D vec(0.0, 0.0, 0.0);

    float qx2 = x * x;
    float qy2 = y * y;
    float qz2 = z * z;
    float test = x * y + z * w;

    if(test > 0.49999f)
    {
      vec.setX(0.0);
      vec.setY(NMath::RAD_2_DEG * 2.0f * atan2f(x, w));
      vec.setZ(90.0);
    }
    else if(test < -0.49999f)
    {
      vec.setX(0.0);
      vec.setY(- NMath::RAD_2_DEG * 2.0f * atan2f(x, w));
      vec.setZ(-90.0);
    }
    else
    {
      float h = atan2f(2.0f * y * w - 2.0f * x * z, 1.0f - 2.0f * qy2 - 2.0f * qz2);
      float a = asinf(2.0f * x * y + 2.0f * z * w);
      float b = atan2f(2.0f * x * w - 2.0f * y * z, 1.0f - 2.0f * qx2 - 2.0f * qz2);
      vec.setX(b * NMath::RAD_2_DEG);
      vec.setY(h * NMath::RAD_2_DEG);
      vec.setZ(a * NMath::RAD_2_DEG);
    }

    return vec;
  }
};
//------------------------------------------------------------------------------
struct SMatrix
{
  static inline QVector<float> toFloat(const QMatrix4x4 &mat)
  {
    QVector<float> out(NMath::MAT4);

#if QT_VERSION >= 0x050000 || defined(Q_OS_SYMBIAN)
      memcpy(&out[0], mat.constData(), sizeof(float) * NMath::MAT4);
#else
      const double *inDouble = mat.constData();
      for(uint8 i = 0; i < NMath::MAT4; i++)
        out[i] = static_cast<float>(inDouble[i]);
#endif

    return out;
  }
//------------------------------------------------------------------------------
  static inline QVector<float> toFloat(const QMatrix3x3 &mat)
  {
    QVector<float> out(NMath::MAT3);

#if QT_VERSION >= 0x050000 || defined(Q_OS_SYMBIAN)
      memcpy(&out[0], mat.constData(), sizeof(float) * NMath::MAT3);
#else
      const double *inDouble = mat.constData();
      for(uint8 i = 0; i < NMath::MAT3; i++)
        out[i] = static_cast<float>(inDouble[i]);
#endif

    return out;
  }  
//------------------------------------------------------------------------------
  static inline QMatrix4x4 composeTransformation(const QVector3D &position, const QQuaternion &rotation, const QVector3D &scale)
  {
    QMatrix4x4 m;

    m.translate(position);
    m.rotate(rotation);
    m.scale(scale);

    return m;
  }
};
//------------------------------------------------------------------------------
#endif //MATH_H

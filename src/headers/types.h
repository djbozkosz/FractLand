//-----------------------------------------------------------------------------
#ifndef TYPES_H
#define TYPES_H

#include <QtGlobal>
#if !defined(NO_STD_TYPES) && !defined(Q_OS_SYMBIAN)
#include <cstdint>
#endif

//-----------------------------------------------------------------------------
#define UNUSED(X) ((void) (X))

#if !defined(NO_STD_TYPES) && !defined(Q_OS_SYMBIAN)
typedef          int8_t    int8;
typedef          uint8_t   uint8;
typedef unsigned char      uchar;
typedef          int16_t   int16;
typedef          uint16_t  uint16;
typedef unsigned short     ushort;
typedef          int32_t   int32;
typedef          uint32_t  uint32;
typedef unsigned int       uint;
typedef unsigned long      ulong;
typedef          int64_t   int64;
typedef          long long llong;
typedef          uint64_t  uint64;
typedef unsigned long long ullong;
#else
typedef          char      int8;
typedef unsigned char      uint8;
typedef unsigned char      uchar;
typedef          short     int16;
typedef unsigned short     uint16;
typedef unsigned short     ushort;
typedef          int       int32;
typedef unsigned int       uint32;
typedef unsigned int       uint;
typedef unsigned long      ulong;
typedef          long long int64;
typedef          long long llong;
typedef unsigned long long uint64;
typedef unsigned long long ullong;
#endif
//-----------------------------------------------------------------------------
#endif // TYPES_H

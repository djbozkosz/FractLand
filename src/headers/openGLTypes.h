//-----------------------------------------------------------------------------
#ifndef OPENGLTYPES_H
#define OPENGLTYPES_H

#include <QtGlobal>
//#include <QGLFunctions>
#ifndef QT_OPENGL_ES_2
#include <windef.h>
#include <wingdi.h>
#include <GL/gl.h>
#else
#include <GLES2/gl2.h>
//#include "C:\QtSDK\Symbian\SDKs\Symbian3Qt474\epoc32\include\GLES2\gl2.h"
#endif

#include "types.h"

//-----------------------------------------------------------------------------
#ifndef QT_OPENGL_ES_2
typedef void            GLvoid;
typedef uint32          GLenum;
typedef uint8           GLboolean;
typedef uint32          GLbitfield;
#endif
typedef char            GLchar;
#ifndef QT_OPENGL_ES_2
typedef int8            GLbyte;
typedef int16           GLshort;
typedef int32           GLint;
typedef int32           GLsizei;
typedef uchar           GLuchar;
typedef uint8           GLubyte;
typedef uint16          GLushort;
typedef uint32          GLuint;
typedef float           GLfloat;
typedef float           GLclampf;
typedef double          GLdouble;
typedef double          GLclampd;
typedef int32           GLfixed;
typedef int32           GLclampx;
typedef int32           GLintptr;
typedef int32           GLsizeiptr;
#endif
//-----------------------------------------------------------------------------
namespace NOpenGL
{
  // ClearBufferMask
  static const GLuint DEPTH_BUFFER_BIT               = 0x00000100;
  static const GLuint STENCIL_BUFFER_BIT             = 0x00000400;
  static const GLuint COLOR_BUFFER_BIT               = 0x00004000;

  // Boolean
#undef FALSE
  static const GLint  FALSE                          = 0;
#undef TRUE
  static const GLint  TRUE                           = 1;
  static const GLint  NONE                           = 0;

  // BeginMode
  static const GLuint POINTS                         = 0x0000;
  static const GLuint LINES                          = 0x0001;
  static const GLuint LINE_LOOP                      = 0x0002;
  static const GLuint LINE_STRIP                     = 0x0003;
  static const GLuint TRIANGLES                      = 0x0004;
  static const GLuint TRIANGLE_STRIP                 = 0x0005;
  static const GLuint TRIANGLE_FAN                   = 0x0006;

  // AlphaFunction
  static const GLuint NEVER                          = 0x0200;
  static const GLuint LESS                           = 0x0201;
  static const GLuint EQUAL                          = 0x0202;
  static const GLuint LEQUAL                         = 0x0203;
  static const GLuint GREATER                        = 0x0204;
  static const GLuint NOTEQUAL                       = 0x0205;
  static const GLuint GEQUAL                         = 0x0206;
  static const GLuint ALWAYS                         = 0x0207;

  // BlendingFactorDest
  static const GLuint ZERO                           = 0;
  static const GLuint ONE                            = 1;
  static const GLuint SRC_COLOR                      = 0x0300;
  static const GLuint ONE_MINUS_SRC_COLOR            = 0x0301;
  static const GLuint SRC_ALPHA                      = 0x0302;
  static const GLuint ONE_MINUS_SRC_ALPHA            = 0x0303;
  static const GLuint DST_ALPHA                      = 0x0304;
  static const GLuint ONE_MINUS_DST_ALPHA            = 0x0305;

  // BlendingFactorSrc
  static const GLuint DST_COLOR                      = 0x0306;
  static const GLuint ONE_MINUS_DST_COLOR            = 0x0307;
  static const GLuint SRC_ALPHA_SATURATE             = 0x0308;
  //static const GLuint SRC_ALPHA                      = 0x0302;
  //static const GLuint ONE_MINUS_SRC_ALPHA            = 0x0303;
  //static const GLuint DST_ALPHA                      = 0x0304;
  //static const GLuint ONE_MINUS_DST_ALPHA            = 0x0305;

  // BlendEquationSeparate
  static const GLuint FUNC_ADD                       = 0x8006;
  static const GLuint BLEND_EQUATION                 = 0x8009;
  static const GLuint BLEND_EQUATION_RGB             = 0x8009;
  static const GLuint BLEND_EQUATION_ALPHA           = 0x883D;

  // BlendSubtract
  static const GLuint FUNC_SUBTRACT                  = 0x800A;
  static const GLuint FUNC_REVERSE_SUBTRACT          = 0x800B;

  // Separate Blend Functions
  static const GLuint BLEND_DST_RGB                  = 0x80C8;
  static const GLuint BLEND_SRC_RGB                  = 0x80C9;
  static const GLuint BLEND_DST_ALPHA                = 0x80CA;
  static const GLuint BLEND_SRC_ALPHA                = 0x80CB;
  static const GLuint CONSTANT_COLOR                 = 0x8001;
  static const GLuint ONE_MINUS_CONSTANT_COLOR       = 0x8002;
  static const GLuint CONSTANT_ALPHA                 = 0x8003;
  static const GLuint ONE_MINUS_CONSTANT_ALPHA       = 0x8004;
  static const GLuint BLEND_COLOR                    = 0x8005;

  // Buffer Objects
  static const GLuint ARRAY_BUFFER                   = 0x8892;
  static const GLuint ELEMENT_ARRAY_BUFFER           = 0x8893;
  static const GLuint ARRAY_BUFFER_BINDING           = 0x8894;
  static const GLuint ELEMENT_ARRAY_BUFFER_BINDING   = 0x8895;

  static const GLuint STREAM_DRAW                    = 0x88E0;
  static const GLuint STATIC_DRAW                    = 0x88E4;
  static const GLuint DYNAMIC_DRAW                   = 0x88E8;

  static const GLuint BUFFER_SIZE                    = 0x8764;
  static const GLuint BUFFER_USAGE                   = 0x8765;

  static const GLuint CURRENT_VERTEX_ATTRIB          = 0x8626;

  // CullFaceMode
  static const GLuint FRONT                          = 0x0404;
  static const GLuint BACK                           = 0x0405;
  static const GLuint FRONT_AND_BACK                 = 0x0408;

  // DepthFunction
  //static const GLuint NEVER                          = 0x0200;
  //static const GLuint LESS                           = 0x0201;
  //static const GLuint EQUAL                          = 0x0202;
  //static const GLuint LEQUAL                         = 0x0203;
  //static const GLuint GREATER                        = 0x0204;
  //static const GLuint NOTEQUAL                       = 0x0205;
  //static const GLuint GEQUAL                         = 0x0206;
  //static const GLuint ALWAYS                         = 0x0207;

  // EnableCap
  static const GLuint TEXTURE_2D                     = 0x0DE1;
  static const GLuint CULL_FACE                      = 0x0B44;
  static const GLuint BLEND                          = 0x0BE2;
  static const GLuint DITHER                         = 0x0BD0;
  static const GLuint STENCIL_TEST                   = 0x0B90;
  static const GLuint DEPTH_TEST                     = 0x0B71;
  static const GLuint SCISSOR_TEST                   = 0x0C11;
  static const GLuint POLYGON_OFFSET_FILL            = 0x8037;
  static const GLuint SAMPLE_ALPHA_TO_COVERAGE       = 0x809E;
  static const GLuint SAMPLE_COVERAGE                = 0x80A0;

  // ErrorCode
#undef NO_ERROR
  static const GLuint NO_ERROR                       = 0;
  static const GLuint INVALID_ENUM                   = 0x0500;
  static const GLuint INVALID_VALUE                  = 0x0501;
  static const GLuint INVALID_OPERATION              = 0x0502;
  static const GLuint OUT_OF_MEMORY                  = 0x0505;

  // FrontFaceDirection
  static const GLuint CW                             = 0x0900;
  static const GLuint CCW                            = 0x0901;

  // GetPName
  static const GLuint LINE_WIDTH                     = 0x0B21;
  static const GLuint ALIASED_POINT_SIZE_RANGE       = 0x846D;
  static const GLuint ALIASED_LINE_WIDTH_RANGE       = 0x846E;
  static const GLuint CULL_FACE_MODE                 = 0x0B45;
  static const GLuint FRONT_FACE                     = 0x0B46;
  static const GLuint DEPTH_RANGE                    = 0x0B70;
  static const GLuint DEPTH_WRITEMASK                = 0x0B72;
  static const GLuint DEPTH_CLEAR_VALUE              = 0x0B73;
  static const GLuint DEPTH_FUNC                     = 0x0B74;
  static const GLuint STENCIL_CLEAR_VALUE            = 0x0B91;
  static const GLuint STENCIL_FUNC                   = 0x0B92;
  static const GLuint STENCIL_FAIL                   = 0x0B94;
  static const GLuint STENCIL_PASS_DEPTH_FAIL        = 0x0B95;
  static const GLuint STENCIL_PASS_DEPTH_PASS        = 0x0B96;
  static const GLuint STENCIL_REF                    = 0x0B97;
  static const GLuint STENCIL_VALUE_MASK             = 0x0B93;
  static const GLuint STENCIL_WRITEMASK              = 0x0B98;
  static const GLuint STENCIL_BACK_FUNC              = 0x8800;
  static const GLuint STENCIL_BACK_FAIL              = 0x8801;
  static const GLuint STENCIL_BACK_PASS_DEPTH_FAIL   = 0x8802;
  static const GLuint STENCIL_BACK_PASS_DEPTH_PASS   = 0x8803;
  static const GLuint STENCIL_BACK_REF               = 0x8CA3;
  static const GLuint STENCIL_BACK_VALUE_MASK        = 0x8CA4;
  static const GLuint STENCIL_BACK_WRITEMASK         = 0x8CA5;
  static const GLuint VIEWPORT                       = 0x0BA2;
  static const GLuint SCISSOR_BOX                    = 0x0C10;
  //static const GLuint SCISSOR_TEST                   = 0x0C11;
  static const GLuint COLOR_CLEAR_VALUE              = 0x0C22;
  static const GLuint COLOR_WRITEMASK                = 0x0C23;
  static const GLuint UNPACK_ALIGNMENT               = 0x0CF5;
  static const GLuint PACK_ALIGNMENT                 = 0x0D05;
  static const GLuint MAX_TEXTURE_SIZE               = 0x0D33;
  static const GLuint MAX_VIEWPORT_DIMS              = 0x0D3A;
  static const GLuint SUBPIXEL_BITS                  = 0x0D50;
  static const GLuint RED_BITS                       = 0x0D52;
  static const GLuint GREEN_BITS                     = 0x0D53;
  static const GLuint BLUE_BITS                      = 0x0D54;
  static const GLuint ALPHA_BITS                     = 0x0D55;
  static const GLuint DEPTH_BITS                     = 0x0D56;
  static const GLuint STENCIL_BITS                   = 0x0D57;
  static const GLuint POLYGON_OFFSET_UNITS           = 0x2A00;
  //static const GLuint POLYGON_OFFSET_FILL            = 0x8037;
  static const GLuint POLYGON_OFFSET_FACTOR          = 0x8038;
  static const GLuint TEXTURE_BINDING_2D             = 0x8069;
  static const GLuint SAMPLE_BUFFERS                 = 0x80A8;
  static const GLuint SAMPLES                        = 0x80A9;
  static const GLuint SAMPLE_COVERAGE_VALUE          = 0x80AA;
  static const GLuint SAMPLE_COVERAGE_INVERT         = 0x80AB;

  // GetTextureParameter
  static const GLuint TEXTURE_MAG_FILTER             = 0x2800;
  static const GLuint TEXTURE_MIN_FILTER             = 0x2801;
  static const GLuint TEXTURE_WRAP_S                 = 0x2802;
  static const GLuint TEXTURE_WRAP_T                 = 0x2803;

  static const GLuint NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
  static const GLuint COMPRESSED_TEXTURE_FORMATS     = 0x86A3;

  // HintMode
  static const GLuint DONT_CARE                      = 0x1100;
  static const GLuint FASTEST                        = 0x1101;
  static const GLuint NICEST                         = 0x1102;

  // HintTarget
  static const GLuint GENERATE_MIPMAP_HINT            = 0x8192;
  static const GLuint FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;

  // DataType
  static const GLuint BYTE                           = 0x1400;
  static const GLuint UNSIGNED_BYTE                  = 0x1401;
  static const GLuint SHORT                          = 0x1402;
  static const GLuint UNSIGNED_SHORT                 = 0x1403;
  static const GLuint INT                            = 0x1404;
  static const GLuint UNSIGNED_INT                   = 0x1405;
  static const GLuint FLOAT                          = 0x1406;
  static const GLuint FIXED                          = 0x140C;

  // PixelFormat
  static const GLuint DEPTH_COMPONENT                = 0x1902;
  static const GLuint ALPHA                          = 0x1906;
#undef RGB
  static const GLuint RGB                            = 0x1907;
  static const GLuint RGBA                           = 0x1908;
  static const GLuint LUMINANCE                      = 0x1909;
  static const GLuint LUMINANCE_ALPHA                = 0x190A;

  // PixelType
  //static const GLuint UNSIGNED_BYTE                  = 0x1401;
  static const GLuint UNSIGNED_SHORT_4_4_4_4         = 0x8033;
  static const GLuint UNSIGNED_SHORT_5_5_5_1         = 0x8034;
  static const GLuint UNSIGNED_SHORT_5_6_5           = 0x8363;
  static const GLuint BGR                            = 0x80E0;
  static const GLuint BGRA                           = 0x80E1;

  // Shaders
  static const GLuint FRAGMENT_SHADER                  = 0x8B30;
  static const GLuint VERTEX_SHADER                    = 0x8B31;
  static const GLuint MAX_VERTEX_ATTRIBS               = 0x8869;
  static const GLuint MAX_VERTEX_UNIFORM_VECTORS       = 0x8DFB;
  static const GLuint MAX_VARYING_VECTORS              = 0x8DFC;
  static const GLuint MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
  static const GLuint MAX_VERTEX_TEXTURE_IMAGE_UNITS   = 0x8B4C;
  static const GLuint MAX_TEXTURE_IMAGE_UNITS          = 0x8872;
  static const GLuint MAX_FRAGMENT_UNIFORM_VECTORS     = 0x8DFD;
  static const GLuint SHADER_TYPE                      = 0x8B4F;
  static const GLuint DELETE_STATUS                    = 0x8B80;
  static const GLuint LINK_STATUS                      = 0x8B82;
  static const GLuint VALIDATE_STATUS                  = 0x8B83;
  static const GLuint ATTACHED_SHADERS                 = 0x8B85;
  static const GLuint ACTIVE_UNIFORMS                  = 0x8B86;
  static const GLuint ACTIVE_UNIFORM_MAX_LENGTH        = 0x8B87;
  static const GLuint ACTIVE_ATTRIBUTES                = 0x8B89;
  static const GLuint ACTIVE_ATTRIBUTE_MAX_LENGTH      = 0x8B8A;
  static const GLuint SHADING_LANGUAGE_VERSION         = 0x8B8C;
  static const GLuint CURRENT_PROGRAM                  = 0x8B8D;

  // StencilFunction
  //static const GLuint NEVER                          = 0x0200;
  //static const GLuint LESS                           = 0x0201;
  //static const GLuint EQUAL                          = 0x0202;
  //static const GLuint LEQUAL                         = 0x0203;
  //static const GLuint GREATER                        = 0x0204;
  //static const GLuint NOTEQUAL                       = 0x0205;
  //static const GLuint GEQUAL                         = 0x0206;
  //static const GLuint ALWAYS                         = 0x0207;

  // StencilOp
  static const GLuint KEEP                           = 0x1E00;
  static const GLuint REPLACE                        = 0x1E01;
  static const GLuint INCR                           = 0x1E02;
  static const GLuint DECR                           = 0x1E03;
  static const GLuint INVERT                         = 0x150A;
  static const GLuint INCR_WRAP                      = 0x8507;
  static const GLuint DECR_WRAP                      = 0x8508;

  // StringName
  static const GLuint VENDOR                         = 0x1F00;
  static const GLuint RENDERER                       = 0x1F01;
  static const GLuint VERSION                        = 0x1F02;
  static const GLuint EXTENSIONS                     = 0x1F03;

  // TextureMagFilter
  static const GLuint NEAREST                        = 0x2600;
  static const GLuint LINEAR                         = 0x2601;

  // TextureMinFilter
  //static const GLuint NEAREST                        = 0x2600;
  //static const GLuint LINEAR                         = 0x2601;
  static const GLuint NEAREST_MIPMAP_NEAREST         = 0x2700;
  static const GLuint LINEAR_MIPMAP_NEAREST          = 0x2701;
  static const GLuint NEAREST_MIPMAP_LINEAR          = 0x2702;
  static const GLuint LINEAR_MIPMAP_LINEAR           = 0x2703;

  // TextureParameterName
  //static const GLuint TEXTURE_MAG_FILTER             = 0x2800;
  //static const GLuint TEXTURE_MIN_FILTER             = 0x2801;
  //static const GLuint TEXTURE_WRAP_S                 = 0x2802;
  //static const GLuint TEXTURE_WRAP_T                 = 0x2803;

  // TextureTarget
  //static const GLuint TEXTURE_2D                     = 0x0DE1;
  static const GLuint TEXTURE                        = 0x1702;

  static const GLuint TEXTURE_CUBE_MAP               = 0x8513;
  static const GLuint TEXTURE_BINDING_CUBE_MAP       = 0x8514;
  static const GLuint TEXTURE_CUBE_MAP_POSITIVE_X    = 0x8515;
  static const GLuint TEXTURE_CUBE_MAP_NEGATIVE_X    = 0x8516;
  static const GLuint TEXTURE_CUBE_MAP_POSITIVE_Y    = 0x8517;
  static const GLuint TEXTURE_CUBE_MAP_NEGATIVE_Y    = 0x8518;
  static const GLuint TEXTURE_CUBE_MAP_POSITIVE_Z    = 0x8519;
  static const GLuint TEXTURE_CUBE_MAP_NEGATIVE_Z    = 0x851A;
  static const GLuint MAX_CUBE_MAP_TEXTURE_SIZE      = 0x851C;

  // TextureUnit
  static const GLuint TEXTURE0                       = 0x84C0;
  static const GLuint TEXTURE1                       = 0x84C1;
  static const GLuint TEXTURE2                       = 0x84C2;
  static const GLuint TEXTURE3                       = 0x84C3;
  static const GLuint TEXTURE4                       = 0x84C4;
  static const GLuint TEXTURE5                       = 0x84C5;
  static const GLuint TEXTURE6                       = 0x84C6;
  static const GLuint TEXTURE7                       = 0x84C7;
  static const GLuint TEXTURE8                       = 0x84C8;
  static const GLuint TEXTURE9                       = 0x84C9;
  static const GLuint TEXTURE10                      = 0x84CA;
  static const GLuint TEXTURE11                      = 0x84CB;
  static const GLuint TEXTURE12                      = 0x84CC;
  static const GLuint TEXTURE13                      = 0x84CD;
  static const GLuint TEXTURE14                      = 0x84CE;
  static const GLuint TEXTURE15                      = 0x84CF;
  static const GLuint TEXTURE16                      = 0x84D0;
  static const GLuint TEXTURE17                      = 0x84D1;
  static const GLuint TEXTURE18                      = 0x84D2;
  static const GLuint TEXTURE19                      = 0x84D3;
  static const GLuint TEXTURE20                      = 0x84D4;
  static const GLuint TEXTURE21                      = 0x84D5;
  static const GLuint TEXTURE22                      = 0x84D6;
  static const GLuint TEXTURE23                      = 0x84D7;
  static const GLuint TEXTURE24                      = 0x84D8;
  static const GLuint TEXTURE25                      = 0x84D9;
  static const GLuint TEXTURE26                      = 0x84DA;
  static const GLuint TEXTURE27                      = 0x84DB;
  static const GLuint TEXTURE28                      = 0x84DC;
  static const GLuint TEXTURE29                      = 0x84DD;
  static const GLuint TEXTURE30                      = 0x84DE;
  static const GLuint TEXTURE31                      = 0x84DF;
  static const GLuint ACTIVE_TEXTURE                 = 0x84E0;

  // TextureWrapMode
  static const GLuint REPEAT                         = 0x2901;
  static const GLuint CLAMP_TO_EDGE                  = 0x812F;
  static const GLuint MIRRORED_REPEAT                = 0x8370;

  // Uniform Types
  static const GLuint FLOAT_VEC2                     = 0x8B50;
  static const GLuint FLOAT_VEC3                     = 0x8B51;
  static const GLuint FLOAT_VEC4                     = 0x8B52;
  static const GLuint INT_VEC2                       = 0x8B53;
  static const GLuint INT_VEC3                       = 0x8B54;
  static const GLuint INT_VEC4                       = 0x8B55;
#undef BOOL
  static const GLuint BOOL                           = 0x8B56;
  static const GLuint BOOL_VEC2                      = 0x8B57;
  static const GLuint BOOL_VEC3                      = 0x8B58;
  static const GLuint BOOL_VEC4                      = 0x8B59;
  static const GLuint FLOAT_MAT2                     = 0x8B5A;
  static const GLuint FLOAT_MAT3                     = 0x8B5B;
  static const GLuint FLOAT_MAT4                     = 0x8B5C;
  static const GLuint SAMPLER_2D                     = 0x8B5E;
  static const GLuint SAMPLER_CUBE                   = 0x8B60;

  // Vertex Arrays
  static const GLuint VERTEX_ATTRIB_ARRAY_ENABLED        = 0x8622;
  static const GLuint VERTEX_ATTRIB_ARRAY_SIZE           = 0x8623;
  static const GLuint VERTEX_ATTRIB_ARRAY_STRIDE         = 0x8624;
  static const GLuint VERTEX_ATTRIB_ARRAY_TYPE           = 0x8625;
  static const GLuint VERTEX_ATTRIB_ARRAY_NORMALIZED     = 0x886A;
  static const GLuint VERTEX_ATTRIB_ARRAY_POINTER        = 0x8645;
  static const GLuint VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;

  // Read Format
  static const GLuint IMPLEMENTATION_COLOR_READ_TYPE   = 0x8B9A;
  static const GLuint IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;

  // Shader Source
  static const GLuint COMPILE_STATUS                 = 0x8B81;
  static const GLuint INFO_LOG_LENGTH                = 0x8B84;
  static const GLuint SHADER_SOURCE_LENGTH           = 0x8B88;
  static const GLuint SHADER_COMPILER                = 0x8DFA;

  // Shader Binary
  static const GLuint PLATFORM_BINARY                = 0x8D63;
  static const GLuint SHADER_BINARY_FORMATS          = 0x8DF8;
  static const GLuint NUM_SHADER_BINARY_FORMATS      = 0x8DF9;

  // Shader Precision-Specified Types
  static const GLuint LOW_FLOAT                      = 0x8DF0;
  static const GLuint MEDIUM_FLOAT                   = 0x8DF1;
  static const GLuint HIGH_FLOAT                     = 0x8DF2;
  static const GLuint LOW_INT                        = 0x8DF3;
  static const GLuint MEDIUM_INT                     = 0x8DF4;
  static const GLuint HIGH_INT                       = 0x8DF5;

  // Framebuffer Object.
  static const GLuint FRAMEBUFFER                    = 0x8D40;
  static const GLuint RENDERBUFFER                   = 0x8D41;

  static const GLuint RGBA4                          = 0x8056;
  static const GLuint RGB5_A1                        = 0x8057;
  static const GLuint RGB565                         = 0x8D62;
  static const GLuint DEPTH_COMPONENT16              = 0x81A5;
  static const GLuint DEPTH_COMPONENT24              = 0x81A6;
  static const GLuint DEPTH_COMPONENT32              = 0x81A7;
  static const GLuint STENCIL_INDEX                  = 0x1901;
  static const GLuint STENCIL_INDEX8                 = 0x8D48;

  static const GLuint RENDERBUFFER_WIDTH             = 0x8D42;
  static const GLuint RENDERBUFFER_HEIGHT            = 0x8D43;
  static const GLuint RENDERBUFFER_INTERNAL_FORMAT   = 0x8D44;
  static const GLuint RENDERBUFFER_RED_SIZE          = 0x8D50;
  static const GLuint RENDERBUFFER_GREEN_SIZE        = 0x8D51;
  static const GLuint RENDERBUFFER_BLUE_SIZE         = 0x8D52;
  static const GLuint RENDERBUFFER_ALPHA_SIZE        = 0x8D53;
  static const GLuint RENDERBUFFER_DEPTH_SIZE        = 0x8D54;
  static const GLuint RENDERBUFFER_STENCIL_SIZE      = 0x8D55;

  static const GLuint FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE           = 0x8CD0;
  static const GLuint FRAMEBUFFER_ATTACHMENT_OBJECT_NAME           = 0x8CD1;
  static const GLuint FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL         = 0x8CD2;
  static const GLuint FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;

  static const GLuint COLOR_ATTACHMENT0              = 0x8CE0;
  static const GLuint DEPTH_ATTACHMENT               = 0x8D00;
  static const GLuint STENCIL_ATTACHMENT             = 0x8D20;

  static const GLuint FRAMEBUFFER_COMPLETE                      = 0x8CD5;
  static const GLuint FRAMEBUFFER_INCOMPLETE_ATTACHMENT         = 0x8CD6;
  static const GLuint FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
  static const GLuint FRAMEBUFFER_INCOMPLETE_DIMENSIONS         = 0x8CD9;
  static const GLuint FRAMEBUFFER_INCOMPLETE_FORMATS            = 0x8CDA;
  static const GLuint FRAMEBUFFER_UNSUPPORTED                   = 0x8CDD;

  static const GLuint FRAMEBUFFER_BINDING            = 0x8CA6;
  static const GLuint RENDERBUFFER_BINDING           = 0x8CA7;
  static const GLuint MAX_RENDERBUFFER_SIZE          = 0x84E8;

  static const GLuint TEXTURE_MAX_ANISOTROPY      = 0x84FE;
  static const GLuint MAX_TEXTURE_MAX_ANISOTROPY  = 0x84FF;

  static const GLuint INVALID_FRAMEBUFFER_OPERATION  = 0x0506;
}
//-----------------------------------------------------------------------------
namespace NOpenGLProc
{
#ifndef QT_OPENGL_ES_2
  typedef int32 (APIENTRY *TExtensionProc)();

  typedef void (APIENTRY *TActiveTexture)(GLenum texture);
  typedef void (APIENTRY *TAttachShader)(GLuint program, GLuint shader);
  typedef void (APIENTRY *TBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
  typedef void (APIENTRY *TBindBuffer)(GLenum target, GLuint buffer);
  typedef void (APIENTRY *TBindFramebuffer)(GLenum target, GLuint framebuffer);
  typedef void (APIENTRY *TBindRenderbuffer)(GLenum target, GLuint renderbuffer);
  //typedef void (APIENTRY *TBindTexture)(GLenum target, GLuint texture);
  typedef void (APIENTRY *TBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
  typedef void (APIENTRY *TBlendEquation)(GLenum mode);
  typedef void (APIENTRY *TBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
  //typedef void (APIENTRY *TBlendFunc)(GLenum sfactor, GLenum dfactor);
  typedef void (APIENTRY *TBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
  typedef void (APIENTRY *TBufferData)(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
  typedef void (APIENTRY *TBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
  typedef GLenum (APIENTRY *TCheckFramebufferStatus)(GLenum target);
  //typedef void (APIENTRY *TClear)(GLbitfield mask);
  //typedef void (APIENTRY *TClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
  //typedef void (APIENTRY *TClearDepth)(GLfloat d);
  //typedef void (APIENTRY *TClearStencil)(GLint s);
  //typedef void (APIENTRY *TColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
  typedef void (APIENTRY *TCompileShader)(GLuint shader);
  typedef void (APIENTRY *TCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
  typedef void (APIENTRY *TCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
  //typedef void (APIENTRY *TCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
  //typedef void (APIENTRY *TCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
  typedef GLuint (APIENTRY *TCreateProgram)(void);
  typedef GLuint (APIENTRY *TCreateShader)(GLenum type);
  //typedef GLuint (APIENTRY *TCullFace)(GLenum mode);
  typedef void (APIENTRY *TDeleteBuffers)(GLsizei n, const GLuint *buffers);
  typedef void (APIENTRY *TDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
  //typedef void (APIENTRY *TDeleteTextures)(GLsizei n, const GLuint *textures);
  typedef void (APIENTRY *TDeleteProgram)(GLuint program);
  typedef void (APIENTRY *TDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
  typedef void (APIENTRY *TDeleteShader)(GLuint shader);
  typedef void (APIENTRY *TDetachShader)(GLuint program, GLuint shader);
  //typedef void (APIENTRY *TDepthFunc)(GLenum func);
  //typedef void (APIENTRY *TDepthMask)(GLboolean flag);
  //typedef void (APIENTRY *TDepthRange)(GLfloat n, GLfloat f);
  //typedef void (APIENTRY *TDisable)(GLenum cap);
  typedef void (APIENTRY *TDisableVertexAttribArray)(GLuint index);
  //typedef void (APIENTRY *TDrawArrays)(GLenum mode, GLint first, GLsizei count);
  //typedef void (APIENTRY *TDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
  //typedef void (APIENTRY *TEnable)(GLenum cap);
  typedef void (APIENTRY *TEnableVertexAttribArray)(GLuint index);
  //typedef void (APIENTRY *TFinish)(void);
  //typedef void (APIENTRY *TFlush)(void);
  typedef void (APIENTRY *TFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
  typedef void (APIENTRY *TFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
  //typedef void (APIENTRY *TFrontFace)(GLenum mode);
  typedef void (APIENTRY *TGenBuffers)(GLsizei n, GLuint *buffers);
  typedef void (APIENTRY *TGenerateMipmap)(GLenum target);
  typedef void (APIENTRY *TGenFramebuffers)(GLsizei n, GLuint *framebuffers);
  typedef void (APIENTRY *TGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
  //typedef void (APIENTRY *TGenTextures)(GLsizei n, GLuint *textures);
  typedef void (APIENTRY *TGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
  typedef void (APIENTRY *TGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
  typedef void (APIENTRY *TGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
  typedef GLint (APIENTRY *TGetAttribLocation)(GLuint program, const GLchar *name);
  //typedef void (APIENTRY *TGetBooleanv)(GLenum pname, GLboolean *params);
  typedef void (APIENTRY *TGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
  //typedef GLenum (APIENTRY *TGetError)(void);
  //typedef void (APIENTRY *TGetFloatv)(GLenum pname, GLfloat *params);
  typedef void (APIENTRY *TGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
  //typedef void (APIENTRY *TGetIntegerv)(GLenum pname, GLint *params);
  typedef void (APIENTRY *TGetProgramiv)(GLuint program, GLenum pname, GLint *params);
  typedef void (APIENTRY *TGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
  typedef void (APIENTRY *TGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
  typedef void (APIENTRY *TGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
  typedef void (APIENTRY *TGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
  typedef void (APIENTRY *TGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
  typedef void (APIENTRY *TGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
  //typedef const GLubyte *(APIENTRY *TGetString)(GLenum name);
  //typedef void (APIENTRY *TGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
  //typedef void (APIENTRY *TGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
  typedef void (APIENTRY *TGetUniformfv)(GLuint program, GLint location, GLfloat *params);
  typedef void (APIENTRY *TGetUniformiv)(GLuint program, GLint location, GLint *params);
  typedef GLint (APIENTRY *TGetUniformLocation)(GLuint program, const GLchar *name);
  typedef void (APIENTRY *TGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
  typedef void (APIENTRY *TGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
  typedef void (APIENTRY *TGetVertexAttribPointerv)(GLuint index, GLenum pname, GLvoid **pointer);
  //typedef void (APIENTRY *THint)(GLenum target, GLenum mode);
  typedef GLboolean (APIENTRY *TIsBuffer)(GLuint buffer);
  //typedef GLboolean (APIENTRY *TIsEnabled)(GLenum cap);
  typedef GLboolean (APIENTRY *TIsFramebuffer)(GLuint framebuffer);
  typedef GLboolean (APIENTRY *TIsProgram)(GLuint program);
  typedef GLboolean (APIENTRY *TIsRenderbuffer)(GLuint renderbuffer);
  typedef GLboolean (APIENTRY *TIsShader)(GLuint shader);
  //typedef GLboolean (APIENTRY *TIsTexture)(GLuint texture);
  //typedef GLboolean (APIENTRY *TLineWidth)(GLfloat width);
  typedef void (APIENTRY *TLinkProgram)(GLuint program);
  //typedef void (APIENTRY *TPixelStorei)(GLenum pname, GLint param);
  //typedef void (APIENTRY *TPolygonOffset)(GLfloat factor, GLfloat units);
  //typedef void (APIENTRY *TReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
  typedef void (APIENTRY *TReleaseShaderCompiler)(void);
  typedef void (APIENTRY *TRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
  typedef void (APIENTRY *TSampleCoverage)(GLfloat value, GLboolean invert);
  //typedef void (APIENTRY *TScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
  typedef void (APIENTRY *TShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLsizei length);
  typedef void (APIENTRY *TShaderSource)(GLuint shader, GLsizei count, const GLchar **string, const GLint *length);
  //typedef void (APIENTRY *TStencilFunc)(GLenum func, GLint ref, GLuint mask);
  typedef void (APIENTRY *TStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
  //typedef void (APIENTRY *TStencilMask)(GLuint mask);
  typedef void (APIENTRY *TStencilMaskSeparate)(GLenum face, GLuint mask);
  //typedef void (APIENTRY *TStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
  typedef void (APIENTRY *TStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
  //typedef void (APIENTRY *TTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
  //typedef void (APIENTRY *TTexParameterf)(GLenum target, GLenum pname, GLfloat param);
  //typedef void (APIENTRY *TTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
  //typedef void (APIENTRY *TTexParameteri)(GLenum target, GLenum pname, GLint param);
  //typedef void (APIENTRY *TTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
  //typedef void (APIENTRY *TTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
  typedef void (APIENTRY *TUniform1f)(GLint location, GLfloat v0);
  typedef void (APIENTRY *TUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
  typedef void (APIENTRY *TUniform1i)(GLint location, GLint v0);
  typedef void (APIENTRY *TUniform1iv)(GLint location, GLsizei count, const GLint *value);
  typedef void (APIENTRY *TUniform2f)(GLint location, GLfloat v0, GLfloat v1);
  typedef void (APIENTRY *TUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
  typedef void (APIENTRY *TUniform2i)(GLint location, GLint v0, GLint v1);
  typedef void (APIENTRY *TUniform2iv)(GLint location, GLsizei count, const GLint *value);
  typedef void (APIENTRY *TUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
  typedef void (APIENTRY *TUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
  typedef void (APIENTRY *TUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
  typedef void (APIENTRY *TUniform3iv)(GLint location, GLsizei count, const GLint *value);
  typedef void (APIENTRY *TUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
  typedef void (APIENTRY *TUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
  typedef void (APIENTRY *TUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
  typedef void (APIENTRY *TUniform4iv)(GLint location, GLsizei count, const GLint *value);
  typedef void (APIENTRY *TUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (APIENTRY *TUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (APIENTRY *TUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (APIENTRY *TUseProgram)(GLuint program);
  typedef void (APIENTRY *TValidateProgram)(GLuint program);
  typedef void (APIENTRY *TVertexAttrib1f)(GLuint index, GLfloat x);
  typedef void (APIENTRY *TVertexAttrib1fv)(GLuint index, const GLfloat *v);
  typedef void (APIENTRY *TVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
  typedef void (APIENTRY *TVertexAttrib2fv)(GLuint index, const GLfloat *v);
  typedef void (APIENTRY *TVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
  typedef void (APIENTRY *TVertexAttrib3fv)(GLuint index, const GLfloat *v);
  typedef void (APIENTRY *TVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  typedef void (APIENTRY *TVertexAttrib4fv)(GLuint index, const GLfloat *v);
  typedef void (APIENTRY *TVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
  //typedef void (APIENTRY *TViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
#endif
}
//-----------------------------------------------------------------------------
#endif // OPENGLTYPES_H

//------------------------------------------------------------------------------
#ifndef SHADERSTYPES_H
#define SHADERSTYPES_H

#include "modelsTypes.h"

//------------------------------------------------------------------------------
namespace NShader
{
  static const uint32 SHADERS_COUNT = 5;

  static const uint8 SHADER_MAX_LIGHTS = 1;

  static const char STR_SHADER_UNIFORM_VERTEX_POSITION[] = "vertexPosition";
  static const char STR_SHADER_UNIFORM_VERTEX_NORMAL[] = "vertexNormal";
  static const char STR_SHADER_UNIFORM_VERTEX_NORMAL_TANGENT[] = "vertexNormalTangent";
  static const char STR_SHADER_UNIFORM_VERTEX_NORMAL_BITANGENT[] = "vertexNormalBitangent";
  static const char STR_SHADER_UNIFORM_VERTEX_TEX_COORD[] = "vertexTexCoord";
  static const char STR_SHADER_UNIFORM_VERTEX_COLOR[] = "vertexColor";
  static const char STR_SHADER_UNIFORM_VERTEX_COLOR2[] = "vertexColor2";
  static const char STR_SHADER_UNIFORM_MW[] = "mw"; // model world (4x4)
  static const char STR_SHADER_UNIFORM_MWNIT[] = "mwnit"; // model world normal inversed transposed (3x3)
  static const char STR_SHADER_UNIFORM_MVP[] = "mvp"; // projection * view * model world (4x4)
  static const char STR_SHADER_UNIFORM_CAM[] = "cam"; // camera world
  static const char STR_SHADER_UNIFORM_FB_SIZE[] = "fbSize"; // framebuffer size
  static const char STR_SHADER_UNIFORM_DIF_TEX[] = "difTex";
  static const char STR_SHADER_UNIFORM_ALP_TEX[] = "alpTex";
  static const char STR_SHADER_UNIFORM_SPE_TEX[] = "speTex";
  static const char STR_SHADER_UNIFORM_NOR_TEX[] = "norTex";
  static const char STR_SHADER_UNIFORM_ENV_TEX[] = "envTex";
  static const char STR_SHADER_UNIFORM_DIF_TEX1[] = "difTex1";
  static const char STR_SHADER_UNIFORM_DIF_TEX2[] = "difTex2";
  static const char STR_SHADER_UNIFORM_SPE_TEX1[] = "speTex1";
  static const char STR_SHADER_UNIFORM_SPE_TEX2[] = "speTex2";
  static const char STR_SHADER_UNIFORM_NOR_TEX1[] = "norTex1";
  static const char STR_SHADER_UNIFORM_NOR_TEX2[] = "norTex2";
  static const char STR_SHADER_UNIFORM_LIGHT_AMB[] = "lightAmb";
  static const char STR_SHADER_UNIFORM_LIGHT_POS[] = "lightPos";
  static const char STR_SHADER_UNIFORM_LIGHT_COLOR[] = "lightColor";
  static const char STR_SHADER_UNIFORM_LIGHT_SPEC_COLOR[] = "lightSpeColor";
  static const char STR_SHADER_UNIFORM_FOG_DIST[] = "fogDist";
  static const char STR_SHADER_UNIFORM_FOG_COLOR[] = "fogColor";
  static const char STR_SHADER_UNIFORM_FOG_WATER_DIST[] = "fogWaterDist";
  static const char STR_SHADER_UNIFORM_FOG_WATER_COLOR[] = "fogWaterColor";
  static const char STR_SHADER_UNIFORM_FOG_START[] = "fogStart";
  static const char STR_SHADER_UNIFORM_CLIP_REFL[] = "clipRefl";

  static const char STR_SHADER_VERTER_BASIC[] = ":/shaders/src/shaders/basic.vs";
  static const char STR_SHADER_VERTER_TERRAIN[] = ":/shaders/src/shaders/terrain.vs";
  static const char STR_SHADER_VERTER_WATER[] = ":/shaders/src/shaders/water.vs";
  static const char STR_SHADER_VERTER_UNDER_WATER[] = ":/shaders/src/shaders/underWater.vs";

  static const char STR_SHADER_FRAGMENT_BASIC[] = ":/shaders/src/shaders/basic.fs";
  static const char STR_SHADER_FRAGMENT_BASIC_ALPHA[] = ":/shaders/src/shaders/basicAlpha.fs";
  static const char STR_SHADER_FRAGMENT_TERRAIN[] = ":/shaders/src/shaders/terrain.fs";
  static const char STR_SHADER_FRAGMENT_WATER[] = ":/shaders/src/shaders/water.fs";
  static const char STR_SHADER_FRAGMENT_UNDER_WATER[] = ":/shaders/src/shaders/underWater.fs";

  enum EType
  {
    TYPE_UNDEFINED = 0,
    TYPE_VERTEX,
    TYPE_FRAGMENT
  };

  enum EProgram
  {
    PROGRAM_BASIC = 0,
    PROGRAM_BASIC_ALPHA,
    PROGRAM_TERRAIN,
    PROGRAM_WATER,
    PROGRAM_UNDER_WATER
  };

  static const uint8 SAMPLER_BASIC_DIF = 0;
  static const uint8 SAMPLER_BASIC_APLHA_DIF = 0;
  static const uint8 SAMPLER_BASIC_APLHA_ALP = 1;
  static const uint8 SAMPLER_TERRAIN_NOR = 0;
  static const uint8 SAMPLER_TERRAIN_NOR1 = 1;
  static const uint8 SAMPLER_TERRAIN_NOR2 = 2;
  static const uint8 SAMPLER_WATER_ALP = 0;
  static const uint8 SAMPLER_WATER_NOR = 1;
  static const uint8 SAMPLER_WATER_ENV = 2;
  static const uint8 SAMPLER_UNDER_WATER_ALP = 0;
  static const uint8 SAMPLER_UNDER_WATER_NOR = 1;
  static const uint8 SAMPLER_UNDER_WATER_ENV = 2;
}
//------------------------------------------------------------------------------
struct SShaderUniforms
{
  GLuint vertexPosition;
  GLuint vertexNormal;
  GLuint vertexNormalTangent;
  GLuint vertexNormalBitangent;
  GLuint vertexTexCoord;
  GLuint vertexColor;
  GLuint vertexColor2;

  GLuint mw;
  GLuint mwnit;
  GLuint mvp;
  GLuint cam;
  GLuint fbSize;

  GLuint difTex;
  GLuint alpTex;
  GLuint speTex;
  GLuint norTex;
  GLuint envTex;

  GLuint difTex1;
  GLuint difTex2;
  GLuint speTex1;
  GLuint speTex2;
  GLuint norTex1;
  GLuint norTex2;

  GLuint lightAmb;
  GLuint lightPos;
  GLuint lightColor;
  GLuint lightSpeColor;

  GLuint fogDist;
  GLuint fogColor;
  GLuint fogWaterDist;
  GLuint fogWaterColor;
  GLuint fogStart;

  GLuint clipRefl;

  inline SShaderUniforms() : vertexPosition(0), vertexNormal(0), vertexNormalTangent(0), vertexNormalBitangent(0), vertexTexCoord(0), vertexColor(0), vertexColor2(0),
                             mw(0), mwnit(0), mvp(0), cam(0), fbSize(0),
                             difTex(0), alpTex(0), speTex(0), norTex(0), envTex(0),
                             difTex1(0), difTex2(2),
                             speTex1(0), speTex2(2),
                             norTex1(0), norTex2(2),
                             lightAmb(0), lightPos(0), lightColor(0), lightSpeColor(0),
                             fogDist(0), fogColor(0), fogWaterDist(0), fogWaterColor(0), fogStart(0),
                             clipRefl(0) {}
};
//------------------------------------------------------------------------------
struct SShaderTechnique
{
  QMatrix4x4 mw;
  QMatrix3x3 mwnit;
  mutable QMatrix4x4 mvp;
  mutable QVector3D cam;
  mutable QVector4D fbSize;

  mutable const SMaterial *material;

  QVector3D lightAmb;
  QVector3D lightPos;
  QVector3D lightColor;
  QVector4D lightSpeColor;

  QVector2D fogDist;
  QVector3D fogColor;
  QVector2D fogWaterDist;
  QVector3D fogWaterColor;
  QVector2D fogStart;

  inline SShaderTechnique() : material(NULL) {}
};
//------------------------------------------------------------------------------
struct SShader
{
  NShader::EType type;
  QString file;
  GLuint shader;

  inline SShader() : type(NShader::TYPE_UNDEFINED), shader(0) {}
  inline SShader(NShader::EType type, QString file, GLuint shader = 0) : type(type), file(file), shader(shader) {}
};

class CShader;
//------------------------------------------------------------------------------
struct SShaderProgram
{
  NShader::EProgram name;
  CShader *vertexShader;
  CShader *fragmentShader;
  GLuint program;
  SShaderUniforms uniforms;

  inline SShaderProgram() : name(NShader::PROGRAM_BASIC), vertexShader(NULL), fragmentShader(NULL), program(0) {}
  inline SShaderProgram(NShader::EProgram name, CShader *vertexShader, CShader *fragmentShader, GLuint program = 0, SShaderUniforms uniforms = SShaderUniforms()) : name(name), vertexShader(vertexShader), fragmentShader(fragmentShader), program(program), uniforms(uniforms) {}
};
//------------------------------------------------------------------------------
#endif // SHADERSTYPES_H

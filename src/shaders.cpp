//------------------------------------------------------------------------------
#include "shaders.h"

//------------------------------------------------------------------------------
CShader::CShader() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CShader::CShader(CContext *context, const SShader &shader) : CEngineBase(context), shader(shader)
{
  compile();
}
//------------------------------------------------------------------------------
CShader::~CShader()
{
}
//------------------------------------------------------------------------------
void CShader::compile()
{
  COpenGL *gl = context->getOpenGL();
  GLenum shaderType = (shader.type == NShader::TYPE_VERTEX) ? NOpenGL::VERTEX_SHADER : NOpenGL::FRAGMENT_SHADER;
  GLint status = 0;
  GLint infoLength = 0;
  QVector<char> log;
  QFile f(shader.file);

  if(!f.open(QIODevice::ReadOnly))
    return;

  QString data = f.readAll().constData();
#ifdef QT_OPENGL_ES_2
  data = setES2compatible(data);
#endif
  const char *d = data.toStdString().c_str();
  //qDebug(d);
  shader.shader = gl->createShader(shaderType);
  gl->shaderSource(shader.shader, 1, &d, NULL);
  gl->compileShader(shader.shader);
  gl->getShaderiv(shader.shader, NOpenGL::COMPILE_STATUS, &status);
  gl->getShaderiv(shader.shader, NOpenGL::INFO_LOG_LENGTH, &infoLength);
  log.resize(infoLength);
  if(infoLength)
    gl->getShaderInfoLog(shader.shader, infoLength, &infoLength, &log[0]);
  qDebug(&log[0]);
  if(status == NOpenGL::FALSE)
  {
    QMessageBox *msg = new QMessageBox();
    msg->setWindowTitle("Shader Compilation Error");
    msg->setText(&log[0]);
    msg->setStandardButtons(QMessageBox::Ok);
    msg->setDefaultButton(QMessageBox::Ok);
    msg->setModal(false);
    msg->show();
  }

  /*QMessageBox *msg = new QMessageBox();
  msg->setWindowTitle("Shader");
  msg->setText(data);
  msg->setStandardButtons(QMessageBox::Ok);
  msg->setDefaultButton(QMessageBox::Ok);
  msg->setModal(false);
  msg->show();*/

  f.close();
}
//------------------------------------------------------------------------------
QString CShader::setES2compatible(const QString &data)
{
  QString d = data;

  d.remove(0, d.indexOf("in "));

  if(shader.type == NShader::TYPE_VERTEX)
  {
    d.replace("in ", "attribute ");
    d.replace("out ", "varying ");
  }
  else if(shader.type == NShader::TYPE_FRAGMENT)
  {
    d.replace("in ", "varying ");
    d.replace("out vec4 glFragColor;", "");
    d.replace("glFragColor", "gl_FragColor");
    d.replace("texture(", "texture2D(");
  }

  d.replace("float ", "lowp float ");
  d.replace("vec2 ", "lowp vec2 ");
  d.replace("vec3 ", "lowp vec3 ");
  d.replace("vec4 ", "lowp vec4 ");
  d.replace("mat2 ", "lowp mat2 ");
  d.replace("mat3 ", "lowp mat3 ");
  d.replace("mat4 ", "lowp mat4 ");
  d.replace("sampler2D ", "lowp sampler2D ");

  return d;
}
//------------------------------------------------------------------------------
CShaderProgram::CShaderProgram() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CShaderProgram::CShaderProgram(CContext *context, const SShaderProgram &shaderProgram) : CEngineBase(context), program(shaderProgram)
{
  link();
  initUniforms();
}
//------------------------------------------------------------------------------
CShaderProgram::~CShaderProgram()
{
}
//------------------------------------------------------------------------------
void CShaderProgram::link()
{
  COpenGL *gl = context->getOpenGL();
  GLint status = 0;
  GLint infoLength = 0;
  QVector<char> log;

  program.program = gl->createProgram();
  gl->attachShader(program.program, program.vertexShader->getShader()->shader);
  gl->attachShader(program.program, program.fragmentShader->getShader()->shader);
  gl->linkProgram(program.program);

  gl->getProgramiv(program.program, NOpenGL::LINK_STATUS, &status);
  gl->getProgramiv(program.program, NOpenGL::INFO_LOG_LENGTH, &infoLength);
  log.resize(infoLength);
  if(infoLength)
    gl->getProgramInfoLog(program.program, infoLength, &infoLength, &log[0]);
#ifndef QT_OPENGL_ES_2
  qDebug(&log[0]);
#endif
  if(status == NOpenGL::FALSE)
  {
    QMessageBox *msg = new QMessageBox();
    msg->setWindowTitle("Shader Program Link Error");
    msg->setText(&log[0]);
    msg->setModal(false);
    msg->show();
  }
}
//------------------------------------------------------------------------------
void CShaderProgram::initUniforms()
{
  COpenGL *gl = context->getOpenGL();

  program.uniforms.vertexPosition = gl->getAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_POSITION);
  program.uniforms.vertexNormal = gl->getAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL);
  program.uniforms.vertexNormalTangent = gl->getAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL_TANGENT);
  program.uniforms.vertexNormalBitangent = gl->getAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL_BITANGENT);
  program.uniforms.vertexTexCoord = gl->getAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_TEX_COORD);
  program.uniforms.vertexColor = gl->getAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_COLOR);
  program.uniforms.vertexColor2 = gl->getAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_COLOR2);
  program.uniforms.mw = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MW);
  program.uniforms.mwnit = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MWNIT);
  program.uniforms.mvp = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MVP);
  program.uniforms.cam = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_CAM);
  program.uniforms.fbSize = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FB_SIZE);
  program.uniforms.difTex = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_DIF_TEX);
  program.uniforms.alpTex = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_ALP_TEX);
  program.uniforms.speTex = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_SPE_TEX);
  program.uniforms.norTex = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_NOR_TEX);
  program.uniforms.envTex = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_ENV_TEX);
  program.uniforms.difTex1 = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_DIF_TEX1);
  program.uniforms.difTex2 = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_DIF_TEX2);
  program.uniforms.speTex1 = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_SPE_TEX1);
  program.uniforms.speTex2 = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_SPE_TEX2);
  program.uniforms.norTex1 = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_NOR_TEX1);
  program.uniforms.norTex2 = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_NOR_TEX2);
  program.uniforms.lightAmb = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_AMB);
  program.uniforms.lightPos = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_POS);
  program.uniforms.lightColor = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_COLOR);
  program.uniforms.lightSpeColor = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_SPEC_COLOR);
  program.uniforms.fogDist = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_DIST);
  program.uniforms.fogColor = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_COLOR);
  program.uniforms.fogWaterDist = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_WATER_DIST);
  program.uniforms.fogWaterColor = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_WATER_COLOR);
  program.uniforms.fogStart = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_START);
  program.uniforms.clipRefl = gl->getUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_CLIP_REFL);
}
//------------------------------------------------------------------------------
void CShaderProgram::bind() const
{
  context->getOpenGL()->useProgram(program.program);
}
//------------------------------------------------------------------------------
void CShaderProgram::begin(const SShaderTechnique *technique) const
{
  COpenGL *gl = context->getOpenGL();

  gl->enableVertexAttribArray(program.uniforms.vertexPosition);
  gl->enableVertexAttribArray(program.uniforms.vertexNormal);
  gl->enableVertexAttribArray(program.uniforms.vertexNormalTangent);
  gl->enableVertexAttribArray(program.uniforms.vertexNormalBitangent);
  gl->enableVertexAttribArray(program.uniforms.vertexTexCoord);
  gl->enableVertexAttribArray(program.uniforms.vertexColor);
  gl->enableVertexAttribArray(program.uniforms.vertexColor2);
  gl->vertexAttribPointer(program.uniforms.vertexPosition, 3, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_PNTBTCC_SIZE, (float *)(sizeof(float) * NModel::VBO_OFFSET_POSITION));
  gl->vertexAttribPointer(program.uniforms.vertexNormal, 3, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_PNTBTCC_SIZE, (float *)(sizeof(float) * NModel::VBO_OFFSET_NORMAL));
  gl->vertexAttribPointer(program.uniforms.vertexNormalTangent, 3, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_PNTBTCC_SIZE, (float *)(sizeof(float) * NModel::VBO_OFFSET_NORMAL_TANGENT));
  gl->vertexAttribPointer(program.uniforms.vertexNormalBitangent, 3, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_PNTBTCC_SIZE, (float *)(sizeof(float) * NModel::VBO_OFFSET_NORMAL_BITANGENT));
  gl->vertexAttribPointer(program.uniforms.vertexTexCoord, 2, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_PNTBTCC_SIZE, (float *)(sizeof(float) * NModel::VBO_OFFSET_TEX_COORD));
  gl->vertexAttribPointer(program.uniforms.vertexColor, 3, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_PNTBTCC_SIZE, (float *)(sizeof(float) * NModel::VBO_OFFSET_COLOR));
  gl->vertexAttribPointer(program.uniforms.vertexColor2, 3, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_PNTBTCC_SIZE, (float *)(sizeof(float) * NModel::VBO_OFFSET_COLOR2));

  if(!technique)
    return;

  gl->uniformMatrix4fv(program.uniforms.mw, 1, NOpenGL::FALSE, &SMatrix::toFloat(technique->mw)[0]);
  gl->uniformMatrix3fv(program.uniforms.mwnit, 1, NOpenGL::FALSE, &SMatrix::toFloat(technique->mwnit)[0]);
  gl->uniformMatrix4fv(program.uniforms.mvp, 1, NOpenGL::FALSE, &SMatrix::toFloat(technique->mvp)[0]);
  gl->uniform3f(program.uniforms.cam, technique->cam.x(), technique->cam.y(), technique->cam.z());
  gl->uniform4f(program.uniforms.fbSize, technique->fbSize.x(), technique->fbSize.y(), technique->fbSize.z(), technique->fbSize.w());

  if(technique->material)
  {
    if(!technique->material->depth)
      gl->disable(NOpenGL::DEPTH_TEST);

    if(technique->material->blend)
      gl->enable(NOpenGL::BLEND);

    if(program.name == NShader::PROGRAM_BASIC)
    {
      setSampler(technique->material->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_BASIC_DIF);
    }
    else if(program.name == NShader::PROGRAM_BASIC_ALPHA)
    {
      setSampler(technique->material->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_BASIC_APLHA_DIF);
      setSampler(technique->material->alphaTexture, program.uniforms.alpTex, NShader::SAMPLER_BASIC_APLHA_ALP);
    }
    else if(program.name == NShader::PROGRAM_TERRAIN)
    {
      setSampler(technique->material->normalTexture, program.uniforms.norTex, NShader::SAMPLER_TERRAIN_NOR);
      setSampler(technique->material->normalTexture1, program.uniforms.norTex1, NShader::SAMPLER_TERRAIN_NOR1);
      setSampler(technique->material->normalTexture2, program.uniforms.norTex2, NShader::SAMPLER_TERRAIN_NOR2);
    }
    else if(program.name == NShader::PROGRAM_WATER)
    {
      setSampler(technique->material->alphaTexture, program.uniforms.alpTex, NShader::SAMPLER_WATER_ALP);
      setSampler(technique->material->normalTexture, program.uniforms.norTex, NShader::SAMPLER_WATER_NOR, false, false);
      setSampler(technique->material->environmentTexture, program.uniforms.envTex, NShader::SAMPLER_WATER_ENV, false, true);
    }
    else if(program.name == NShader::PROGRAM_UNDER_WATER)
    {
      setSampler(technique->material->alphaTexture, program.uniforms.alpTex, NShader::SAMPLER_UNDER_WATER_ALP);
      setSampler(technique->material->normalTexture, program.uniforms.norTex, NShader::SAMPLER_UNDER_WATER_NOR);
      setSampler(technique->material->environmentTexture, program.uniforms.envTex, NShader::SAMPLER_WATER_ENV, false, true);
    }
    context->getMaps()->finishBind();
  }

  gl->uniform3f(program.uniforms.lightAmb, technique->lightAmb.x(), technique->lightAmb.y(), technique->lightAmb.z());
  gl->uniform3f(program.uniforms.lightPos, technique->lightPos.x(), technique->lightPos.y(), technique->lightPos.z());
  gl->uniform3f(program.uniforms.lightColor, technique->lightColor.x(), technique->lightColor.y(), technique->lightColor.z());
  gl->uniform4f(program.uniforms.lightSpeColor, technique->lightSpeColor.x(), technique->lightSpeColor.y(), technique->lightSpeColor.z(), technique->lightSpeColor.w());
  gl->uniform2f(program.uniforms.fogDist, technique->fogDist.x(), technique->fogDist.y());
  gl->uniform3f(program.uniforms.fogColor, technique->fogColor.x(), technique->fogColor.y(), technique->fogColor.z());
  gl->uniform2f(program.uniforms.fogWaterDist, technique->fogWaterDist.x(), technique->fogWaterDist.y());
  gl->uniform3f(program.uniforms.fogWaterColor, technique->fogWaterColor.x(), technique->fogWaterColor.y(), technique->fogWaterColor.z());
  gl->uniform2f(program.uniforms.fogStart, technique->fogStart.x(), technique->fogStart.y());

  const float reflHeight = 0.0f;
  gl->uniform2f(program.uniforms.clipRefl, reflHeight, (context->getCamera()->getCamera()->renderMode == NCamera::RENDER_MODE_NORMAL) ? 0.0f : ((context->getCamera()->getCamera()->position.y() > reflHeight) ? 1.0f : 2.0f));
}
//------------------------------------------------------------------------------
void CShaderProgram::end(const SShaderTechnique *technique) const
{
  COpenGL *gl = context->getOpenGL();

  if((technique) && (technique->material))
  {
    if(!technique->material->depth)
      gl->enable(NOpenGL::DEPTH_TEST);

    if(technique->material->blend)
      gl->disable(NOpenGL::BLEND);
  }

  gl->disableVertexAttribArray(program.uniforms.vertexPosition);
  gl->disableVertexAttribArray(program.uniforms.vertexNormal);
  gl->disableVertexAttribArray(program.uniforms.vertexNormalTangent);
  gl->disableVertexAttribArray(program.uniforms.vertexNormalBitangent);
  gl->disableVertexAttribArray(program.uniforms.vertexTexCoord);
  gl->disableVertexAttribArray(program.uniforms.vertexColor);
  gl->disableVertexAttribArray(program.uniforms.vertexColor2);
}
//------------------------------------------------------------------------------
void CShaderProgram::unbind() const
{
  context->getOpenGL()->useProgram(0);
}
//------------------------------------------------------------------------------
CShaders::CShaders() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CShaders::CShaders(CContext *context) : CEngineBase(context)
{
}
//------------------------------------------------------------------------------
CShaders::~CShaders()
{
}
//------------------------------------------------------------------------------

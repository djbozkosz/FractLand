#version 130
precision lowp float;

in vec3 vertexPosition;
in vec3 vertexNormal;
in vec3 vertexNormalTangent;
in vec3 vertexNormalBitangent;
in vec2 vertexTexCoord;
in vec3 vertexColor;

uniform mat4 mw;
uniform mat3 mwnit;
uniform mat4 mvp;

out vec3 positionWorld;
out vec2 texCoord;
out vec3 color;
out mat3 mtbnt;

mat3 transpose(mat3 m)
{
  return mat3(
    m[0][0], m[1][0], m[2][0],
    m[0][1], m[1][1], m[2][1],
    m[0][2], m[1][2], m[2][2]);
}

void main()
{
  positionWorld = vec4(mw * vec4(vertexPosition, 1.0)).xyz;
  texCoord = vertexTexCoord;
  color = vertexColor;
  mtbnt = transpose(mat3(normalize(mwnit * vertexNormalTangent), normalize(mwnit * vertexNormalBitangent), normalize(mwnit * vertexNormal)));
  gl_Position = mvp * vec4(vertexPosition, 1.0);
}

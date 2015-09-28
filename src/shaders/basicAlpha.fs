#version 130
precision lowp float;

in vec2 texCoord;
in vec3 color;

uniform sampler2D difTex;
uniform sampler2D alpTex;

out vec4 glFragColor;

void main()
{
  vec3 a = texture(alpTex, texCoord).rgb;
  glFragColor = vec4(texture(difTex, texCoord).rgb * color, (a.r + a.g + a.b) * 0.333334);
}

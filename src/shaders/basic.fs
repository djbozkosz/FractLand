#version 130
precision lowp float;

in vec2 texCoord;
in vec3 color;

uniform sampler2D difTex;

out vec4 glFragColor;

void main()
{
  glFragColor = vec4(texture(difTex, texCoord).rgb * color, 1.0);
}

#version 130
precision lowp float;

in vec3 positionWorld;
in vec2 texCoord;
in vec3 color;
in mat3 mtbnt;

uniform vec3 cam;
uniform vec4 fbSize;
uniform sampler2D alpTex;
uniform sampler2D norTex;
uniform sampler2D envTex;

/*uniform vec2 fogDist;
uniform vec3 fogColor;
uniform vec2 fogWaterDist;
uniform vec3 fogWaterColor;
uniform vec2 fogStart;*/

out vec4 glFragColor;

const float frePow = 8.0;
const float freRatio = 2.0;

void main()
{
  vec3 wave = texture(alpTex, texCoord * 0.2).rgb;
  float wav = (wave.r + wave.g + wave.b) * 0.333334;

  vec3 normalMix = texture(norTex, texCoord).rgb;
  vec3 viewDir = normalize(mtbnt * normalize(cam - positionWorld));
  vec3 normalDir = normalize((normalMix * 2.0 - 1.0) * vec3(wav, wav, 1.0)) * vec3(-1.0, 1.0, 1.0);

  vec3 c = color;
  vec3 tex = texture(envTex, vec2(gl_FragCoord.x * fbSize.z + normalDir.x * 0.02, 1.0 - gl_FragCoord.y * fbSize.w + normalDir.y * 1.0)).xyz;
  float fre = clamp(pow((1.0 - dot(viewDir, -normalDir)) * freRatio, frePow), 0.0, 1.0);

  /*float dist = distance(cam, positionWorld);
  float fDist = min(dist / fogDist.x, 1.0);
  float fWaterDist = min((1.0 - dot(normalize(positionWorld - cam), vec3(0.0, 1.0, 0.0))) * 2.0, 1.0) * min(dist / fogWaterDist.x, 1.0);
  float fHeight = clamp((fogDist.y - positionWorld.y + fogStart.x) / fogDist.y, 0.0, 1.0);*/

  /*glFragColor = vec4(
    mix(
      fogWaterColor,
      fogColor,
      fDist * fHeight),
    fre + fWaterDist);*/
  glFragColor = vec4(
    tex,
    fre);
}

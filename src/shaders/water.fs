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

//uniform vec3 lightAmb;
uniform vec3 lightPos;
//uniform vec3 lightColor;
uniform vec4 lightSpeColor;
/*uniform vec2 fogDist;
uniform vec3 fogColor;
uniform vec3 fogWaterColor;
uniform vec2 fogStart;*/

out vec4 glFragColor;

const float frePow = 2.0/*fix*/;
const float freRatio = 1.0/*fix*/;

void main()
{
  // phong
  //vec3 viewDir = normalize(cam - positionWorld);
  //vec3 normalDir = normalize(mwnit * normal);
  //vec3 lightDir = normalize(lightPos - positionWorld);

  // nomal
  vec3 wave = texture(alpTex, texCoord * 0.2).rgb;
  float wav = (wave.r + wave.g + wave.b) * 0.333334;

  vec3 normalMix = texture(norTex, texCoord).rgb;
  vec3 viewDir = normalize(mtbnt * normalize(cam - positionWorld));
  vec3 normalDir = normalize((normalMix * 2.0 - 1.0) * vec3(wav, wav, 1.0)) * vec3(-1.0, 1.0, 1.0);
  vec3 lightDir = normalize(mtbnt * normalize(lightPos - positionWorld));
  float lightDot = max(0.0, dot(normalDir, lightDir));

  vec3 c = color;
  vec3 tex = texture(envTex, vec2(gl_FragCoord.x * fbSize.z + normalDir.x * 0.02, 1.0 - gl_FragCoord.y * fbSize.w + normalDir.y * 1.0)).xyz;
  //vec3 dif = lightColor * lightDot + lightAmb;
  vec3 spe = lightSpeColor.rgb * 100.0 * pow(max(0.0, dot(viewDir, reflect(-lightDir, normalDir))), 512.0) * lightDot;
  float fre = clamp(pow(1.0 - dot(viewDir, normalDir) * 0.5, frePow), 0.0, 1.0) * freRatio/* * min(wav + 0.7, 1.0)*/;
  //vec3 fres = fre * fogColor;

  //float dist = distance(cam, positionWorld);
  //float fDist = min(dist / fogDist.x, 1.0);
  //float fHeight = clamp((fogDist.y - positionWorld.y + fogStart.x) / fogDist.y, 0.0, 1.0);

  /*glFragColor = vec4(
    mix(
      clamp(tex * dif + spe + fres, 0.0, 1.0),
      fogColor,
      fDist * fHeight),
    fre + (spe.r + spe.g + spe.b) * 0.333334);*/

  glFragColor = vec4(
    tex + spe,
    fre + (spe.r + spe.g + spe.b) * 0.333334);
}

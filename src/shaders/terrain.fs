#version 130
precision lowp float;

in vec3 positionWorld;
in vec2 texCoord;
in vec3 color;
in vec3 color2;
in mat3 mtbnt;

uniform vec3 cam;
uniform sampler2D norTex;
uniform sampler2D norTex1;
uniform sampler2D norTex2;

uniform vec3 lightAmb;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec4 lightSpeColor;
uniform vec2 fogDist;
uniform vec3 fogColor;
uniform vec2 fogWaterDist;
uniform vec3 fogWaterColor;
uniform vec2 fogStart;

uniform vec2 clipRefl;

out vec4 glFragColor;

const float frePow = 4.0;
const float freRatio = 0.1;

void main()
{
  float dist = distance(cam, positionWorld);
  float clipDist = dist * 0.01;
  float clip = clipRefl.x + ((cam.y > clipRefl.x) ? clipDist : -clipDist);

  if((clipRefl.y == 1.0) && (positionWorld.y > clip))
    discard;
  else if((clipRefl.y == 2.0) && (positionWorld.y < clip))
    discard;

  // phong
  //vec3 viewDir = normalize(cam - positionWorld);
  //vec3 normalDir = normalize(mwnit * normal);
  //vec3 lightDir = normalize(lightPos - positionWorld);

  // nomal
  vec3 normalMix = texture(norTex, texCoord).rgb * color2.r + texture(norTex1, texCoord).rgb * color2.g + texture(norTex2, texCoord).rgb * color2.b;
  vec3 viewDir = normalize(mtbnt * normalize(cam - positionWorld));
  vec3 normalDir = normalize(normalMix * 2.0 - 1.0) * vec3(-1.0, 1.0, 1.0);
  vec3 lightDir = normalize(mtbnt * normalize(lightPos - positionWorld));
  float lightDot = max(0.0, dot(normalDir, lightDir));

  vec3 tex = color;
  vec3 dif = lightColor * lightDot + lightAmb;
  vec3 spe = lightSpeColor.rgb * pow(max(0.0, dot(viewDir, reflect(-lightDir, normalDir))), lightSpeColor.a) * lightDot;
  float fre = clamp(pow(1.0 - dot(viewDir, normalDir) * 0.5, frePow), 0.0, 1.0) * freRatio;
  vec3 fres = fre * fogColor;

  //float dist = distance(cam, positionWorld);
  float fDist = min(dist / fogDist.x, 1.0);
  //float fWaterDist = min(dist / fogWaterDist.x, 1.0);
  float fWaterDist = min((1.0 - dot(normalize(positionWorld - cam), vec3(0.0, -1.0, 0.0))) * 1.5, 1.0) * min(dist / fogWaterDist.x, 1.0);
  float fHeight = clamp((fogDist.y - positionWorld.y + fogStart.x) / fogDist.y, 0.0, 1.0);
  float fwaterHeight = clamp((-fogWaterDist.y - positionWorld.y + fogStart.y) / fogWaterDist.y + 1.0, 0.0, 1.0);

  glFragColor = vec4(
    mix(
      mix(
        clamp(tex * dif + spe + fres, 0.0, 1.0),
        fogWaterColor,
        fWaterDist * fwaterHeight),
      fogColor,
      fDist * fHeight),
    1.0);
}

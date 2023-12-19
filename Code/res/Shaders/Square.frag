#version 410 compatibility

in flat int in_flag;

out vec4 out_fragColor;

uniform sampler2D u_textureAtlas;
uniform ivec2 u_textureAtlasDimensions;

void main()
{
  out_fragColor = texture(vec2(1 / u_textureAtlasDimensions.x * gl_PointCoord.x,
                               1 / u_textureAtlasDimensions.y * gl_PointCoord.y));
} 
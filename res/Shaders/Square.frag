#version 410 compatibility

flat in int geo_flag;
flat in vec3 geo_leftBottom;
flat in vec3 geo_rightTop;

out vec4 out_fragColor;

uniform sampler2DArray u_texture0;

void main()
{
  // Layer clamps automatically
  out_fragColor = texture(u_texture0, vec3(0, 0, 0));
  //out_fragColor = texture(u_texture0, geo_barycentric);
} 
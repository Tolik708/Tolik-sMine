#version 410 compatibility

flat in int flag;
in vec2 barycentric;

out vec4 out_fragColor;

uniform sampler2D u_texture0;

void main()
{
  // Layer clamps automatically
  out_fragColor = texture(u_texture0, vec3(barycentric, flag & 0x0FFFFFFF));
} 
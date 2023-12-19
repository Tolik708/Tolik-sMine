#version 410 compatibility

layout (location = 0) in vec3 in_position;
layout (location = 1) in int in_flag;

out flat int out_flag;

uniform mat4 u_view;

void main()
{
  gl_Position = u_view * vec4(in_position, 1);
  out_flag = in_flag;
}
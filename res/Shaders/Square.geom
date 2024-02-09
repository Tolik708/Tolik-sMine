#version 410 compatibility

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

flat in int flag[];

flat out int geo_flag;
flat out vec3 geo_leftBottom;
flat out vec3 geo_rightTop;

void main()
{
  geo_leftBottom = gl_in[2].gl_Position; // Vertices arranged so that lowest bottom vertex is last
  geo_rightTop = gl_in[0].gl_Position; // Same for top right. It's located at the start of the primitive.
  geo_flag = flag[2]; // We use last vertex convention

  gl_Position = gl_in[0].gl_Position;
  EmitVertex();
  gl_Position = gl_in[1].gl_Position;
  EmitVertex();
  gl_Position = gl_in[2].gl_Position;
  EmitVertex();
  EndPrimitive();
}
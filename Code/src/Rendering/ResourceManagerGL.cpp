#include "Rendering/OpenGL/ResourceManagerGL.hpp"

#include <vector>
#include <unordered_map>
#include <array>
#include <stdint.h>

#include "Rendering/OpenGL/ShaderGL.hpp"
#include "Rendering/OpenGL/BuffersGL.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/MeshSpecification.hpp"

namespace Tolik
{
ResourceManagerGL::ResourceManagerGL()
  : m_indexes
  {
    //                     Shader Layout DrawMode Texture
    { MeshType::Default, { 0,     0,     0,       0 } },
    { MeshType::Square,  { 1,     1,     0,       1 } }
  },
  m_shaders
  {
    ShaderGL("res/Shaders/Default.vert", "res/Shaders/Default.frag"),
    ShaderGL("res/Shaders/Square.vert", "res/Shaders/Square.frag")
  },
  m_layouts
  {
    BufferLayoutGL(GL_FLOAT, 3, GL_FALSE),
    BufferLayoutGL(GL_FLOAT, 3, GL_FALSE,
                   GL_INT,   1, GL_FALSE)
  },
  m_drawModes
  {
    GL_TRIANGLES
  },
  m_textures
  {
    
  }
{}

ResourceManagerGL::~ResourceManagerGL()
{
  for(auto &shader : m_shaders)
    shader.Delete();

  for(auto &texture : m_textures)
    texture.Delete();
}
}
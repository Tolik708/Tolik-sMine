#include "Tolik/Rendering/OpenGL/ResourceManagerGL.hpp"

#include <vector>
#include <unordered_map>
#include <array>
#include <stdint.h>

#include "Tolik/Rendering/OpenGL/ShaderGL.hpp"
#include "Tolik/Rendering/OpenGL/BuffersGL.hpp"
#include "Tolik/Rendering/Renderer.hpp"
#include "Tolik/Math/Vector.hpp"
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
    {
      TextureGL(GL_TEXTURE_2D, TextureFlags::NONE, "C:/proggraming/c++/Tolik\'sMine/Code/res/Textures/No Texture.png",
        std::make_tuple(
          std::pair(GL_TEXTURE_WRAP_S, GL_REPEAT),
          std::pair(GL_TEXTURE_WRAP_T, GL_REPEAT),
          std::pair(GL_TEXTURE_MIN_FILTER, GL_LINEAR),
          std::pair(GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        ))
    },

    {
      TextureGL(GL_TEXTURE_2D, TextureFlags::NONE, "C:/proggraming/c++/Tolik\'sMine/Code/res/Textures/Test.png",
        std::make_tuple(
          std::pair(GL_TEXTURE_WRAP_S, GL_REPEAT),
          std::pair(GL_TEXTURE_WRAP_T, GL_REPEAT),
          std::pair(GL_TEXTURE_MIN_FILTER, GL_NEAREST),
          std::pair(GL_TEXTURE_MAG_FILTER, GL_NEAREST)
        ))
    },
  }
{}

ResourceManagerGL::~ResourceManagerGL()
{
  for(auto &shader : m_shaders)
    shader.Delete();

  for(auto &textures : m_textures)
  {
    for(auto &texture : textures)
      texture.Delete();
  }
}
}
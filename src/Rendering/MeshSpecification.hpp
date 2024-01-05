#ifndef MESH_SPECIFICATION_HPP
#define MESH_SPECIFICATION_HPP

#include "Setup.hpp"

#include "Tolik/Rendering/Renderer.hpp"
#include "Tolik/Math/Constants.hpp"

namespace Tolik
{
struct SquareVertex : public Vertex
{
  SquareVertex(DefFloatType newX, DefFloatType newY, DefFloatType newZ) : Vertex(newX, newY, newZ) {}
  SquareVertex(DefFloatType newX, DefFloatType newY, DefFloatType newZ, int newTexture) : Vertex(newX, newY, newZ), flag(newTexture) {}
  // 00       00   0000000000000000000000000000
  // Rotation Flip Texture id                   
  int flag = 0;
};

enum class MeshType : uint32_t
{
  NONE = 0,

  // 3D
  Default,
  Square,

  // 2D
};
}

#endif
#ifndef MESH_SPECIFICATION_HPP
#define MESH_SPECIFICATION_HPP

#include "Rendering/Renderer.hpp"
#include "Math/Constants.hpp"

#define BIT(x) (1 << x)

namespace Tolik
{
struct SquareVertex : public Vertex
{
  SquareVertex(DefFloatType newX, DefFloatType newY, DefFloatType newZ) : Vertex(newX, newY, newZ) {}
  SquareVertex(DefFloatType newX, DefFloatType newY, DefFloatType newZ, int newTexture) : Vertex(newX, newY, newZ), flag(newTexture) {}
  // 00000000000000000000000000000 00       00
  // Texture id                    Rotation Flip
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
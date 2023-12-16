#ifndef MESH_SPECIFICATION_HPP
#define MESH_SPECIFICATION_HPP

#include "Rendering/Renderer.hpp"
#include "Math/Constants.hpp"

namespace Tolik
{
struct BlockVertex : public Vertex
{
  BlockVertex(DefaultPrecisionType newX, DefaultPrecisionType newY, DefaultPrecisionType newZ) : Vertex(newX, newY, newZ) {}
  BlockVertex(DefaultPrecisionType newX, DefaultPrecisionType newY, DefaultPrecisionType newZ, int newTexture) : Vertex(newX, newY, newZ), texture(newTexture) {}
  // First 29 bits are index of texture in atlas. Last 2 are rotation
  int texture = 0;
};

enum class MeshType : uint32_t
{
  Default = 0,
  Chunk
};
}

#endif
#ifndef WORLD_CONSTANTS_HPP
#define WORLD_CONSTANTS_HPP

#include "Setup.hpp"

#include "Tolik/Math/Vector.hpp"

namespace Tolik
{
namespace Constants
{
  constexpr Vec3 worldUp = Vec3(0, 1, 0);
  constexpr Vec3 chunkSize = Vec3(32, 32, 32);
  constexpr std::size_t blocksInChunk = chunkSize.x() * chunkSize.y() * chunkSize.z();
}
}

#endif
#ifndef WORLD_HPP
#define WORLD_HPP

#include "Setup.hpp"

#include "Tolik/Rendering/Renderer.hpp"

namespace Tolik
{
class World
{
public:
  World();
  void Render(const Renderer &renderer);

private:
  //std::vector<Chunk*> m_chunks;
};
}

#endif
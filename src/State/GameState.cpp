#include "GameState.hpp"

#include <vector>

#include "Setup.hpp"

#include "Tolik/Debug/Debug.hpp"
#include "Tolik/Rendering/Renderer.hpp"
#include "Tolik/Input/UserInput.hpp"
#include "Tolik/Rendering/Window.hpp"
#include "Rendering/MeshSpecification.hpp"
#include "Player/Player.hpp"


namespace Tolik
{
GameState::GameState(StateDeps *newDeps)
{
  deps = newDeps;
}

void GameState::Init()
{
  player = new Player(deps->userInput);

  std::vector<uint32_t> inds =
  {
    0, 2, 6,  0, 4, 6,
    7, 3, 2,  7, 6, 2,
    7, 5, 1,  7, 3, 1,
    0, 1, 5,  0, 4, 5,
    7, 6, 4,  7, 5, 4,
    3, 2, 0,  3, 1, 0
  };


  std::vector<SquareVertex> verts =
  {
      { -1, -1, -1, 5 },
      {  1, -1, -1, 2 },
      { -1,  1, -1, 1 },
      {  1,  1, -1, 999 },
      { -1, -1,  1, 4 },
      {  1, -1,  1, 3 },
      { -1,  1,  1, 0 },
      {  1,  1,  1, 999 }
  };

  m_mesh = deps->renderer.CreateMesh(MeshType::Square, verts.data(), verts.size(), inds.data(), inds.size());
}

void GameState::Update()
{
  deps->renderer.StartFrame();

  player->Update();
  deps->renderer.RenderMesh(m_mesh);

  deps->renderer.Render(player->GetCamera());
  
  deps->renderer.EndFrame();
}
}
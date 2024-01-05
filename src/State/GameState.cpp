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
    4, 0, 1,  4, 5, 1,
    5, 1, 2,  5, 6, 2,
    2, 3, 7,  2, 6, 7,
    7, 3, 0,  7, 4, 0,
    1, 0, 3,  1, 2, 3,
    4, 5, 6,  4, 7, 6
  };


  std::vector<SquareVertex> verts =
  {
      { -1, -1,  1, 3 },
      { -1,  1,  1, 0 },
      {  1,  1,  1, 1 },
      {  1, -1,  1, 4 },
      { -1, -1, -1, 999 },
      { -1,  1, -1, 999 },
      {  1,  1, -1, 5 },
      {  1, -1, -1, 2 }
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
#include "GameState.hpp"

#include <vector>

#include "Debug/Debug.hpp"
#include "Rendering/Renderer.hpp"
#include "Player/Player.hpp"
#include "Rendering/MeshSpecification.hpp"
#include "Input/UserInput.hpp"
#include "Input/KeyID.hpp"


namespace Tolik
{
GameState::GameState(StateDeps *newDeps)
{
  deps = newDeps;
}

void GameState::Init()
{
  player = new Player(deps->userInput);

  std::vector<GLuint> inds =
  {
    2, 6, 7, 2, 3, 7,
    0, 4, 5, 0, 1, 5,
    0, 2, 6, 0, 4, 6,
    1, 3, 7, 1, 5, 7,
    0, 2, 3, 0, 1, 3,
    4, 6, 7, 4, 5, 7
  };


  std::vector<Vertex> verts =
  {
      { -1, -1,  1 },
      {  1, -1,  1 },
      { -1,  1,  1 },
      {  1,  1,  1 },
      { -1, -1, -1 },
      {  1, -1, -1 },
      { -1,  1, -1 },
      {  1,  1, -1 } 
  };

  m_mesh = deps->renderer.CreateMesh(MeshType::Default, verts.data(), verts.size(), inds.data(), inds.size());
}

void GameState::Update()
{
  deps->renderer.StartFrame(player->GetCamera());

  player->Update();
  deps->renderer.RenderMesh(m_mesh);
  
  deps->renderer.EndFrame();
}
}
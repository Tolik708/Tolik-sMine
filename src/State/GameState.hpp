#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "Setup.hpp"

#include "State/State.hpp"

namespace Tolik
{
class Debug;
class Player;
class Mesh;

class GameState : public State
{
public:
  GameState(StateDeps *newDeps);

  virtual void Init() override;
  virtual void Update() override;

private:
  StateDeps *deps;
  Mesh *m_mesh;
  Player *player;

  // Temp
  bool visibleCursor = true;
};
}

#endif
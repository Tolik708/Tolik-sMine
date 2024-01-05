#ifndef GAME_HPP
#define GAME_HPP

#include "Setup.hpp"

#include "State/State.hpp"
#include "State/GameState.hpp"

namespace Tolik
{
class Game
{
public:
  Game(StateDeps *deps);
  ~Game() { delete m_state; delete pendingState; }

  template<typename T> inline void ChangeState(T *newState) { delete pendingState; pendingState = newState; }
  void Update();

private:

  State *m_state = nullptr;
  State *pendingState = nullptr;
};
}

#endif
#ifndef STATE_HPP
#define STATE_HPP

#include "Setup.hpp"

namespace Tolik
{
class UserInput;
class Window;
class Renderer;
class Game;

struct StateDeps
{
  StateDeps(Game &newGame, Window &newWindow, Renderer &newRenderer, UserInput &newUserInput)
   : game(newGame)
   , window(newWindow)
   , renderer(newRenderer)
   , userInput(newUserInput) {}
  
  Game &game;
  Window &window;
  Renderer &renderer;
  UserInput &userInput;
};

class State
{
public:
  virtual ~State() = default;

  virtual void Init() = 0;
  virtual void Update() = 0;
};
}

#endif
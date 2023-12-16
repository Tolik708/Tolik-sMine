#ifndef STATE_HPP
#define STATE_HPP

namespace Tolik
{
class UserInput;
class Window;
class Renderer;
class Game;

struct StateDeps
{
  StateDeps(const Game &newGame, const Window &newWindow, const Renderer &newRenderer, const UserInput &newUserInput)
   : game(newGame)
   , window(newWindow)
   , renderer(newRenderer)
   , userInput(newUserInput) {}
  
  const Game &game;
  const Window &window;
  const Renderer &renderer;
  const UserInput &userInput;
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
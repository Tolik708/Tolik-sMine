#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Rendering/Window.hpp"
#include "State/Game.hpp"
#include "Input/UserInput.hpp"


namespace Tolik
{
class Application
{
public:
  Application();
  void Run();

private:
  bool m_running = false;
  UserInput m_userInput;
  Window m_window;
  Game m_game;
};
}

#endif
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Setup.hpp"

#include "Tolik/Rendering/Window.hpp"
#include "Tolik/Input/UserInput.hpp"
#include "State/Game.hpp"


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
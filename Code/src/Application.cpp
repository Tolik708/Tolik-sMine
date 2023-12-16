#include "Application.hpp"

#include "State/State.hpp"
#include "Rendering/Window.hpp"
#include "Rendering/Renderer.hpp"
#include "State/Game.hpp"

namespace Tolik
{
class RendererGL;

Application::Application()
  : m_window(&m_running, &m_userInput)
  , m_game(new StateDeps(m_game, m_window, m_window.GetRenderer(), m_userInput))
{}

void Application::Run()
{
  m_running = true;
  while(m_running)
  {
    m_window.ListenToEvents();
    m_game.Update();
  }
}
}

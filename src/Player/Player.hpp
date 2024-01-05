#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Setup.hpp"

#include "Tolik/Rendering/Camera.hpp"

namespace Tolik
{
class UserInput;

class Player
{
public:
  Player(const UserInput &userInput);

  void Update();
  inline const Camera &GetCamera() const { return m_camera; }
  inline Camera &GetCamera() { return m_camera; }

private:
  const UserInput &m_userInput;
  Camera m_camera;
  Transform m_transform;

  static constexpr float s_sensativity = 0.25;
};
}


#endif
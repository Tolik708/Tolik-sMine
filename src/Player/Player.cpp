#include "Player.hpp"

#include "Setup.hpp"

#include "Tolik/Input/KeyID.hpp"
#include "Tolik/Input/UserInput.hpp"
#include "Tolik/Math/Vector.hpp"
#include "Tolik/Math/MathFunctions.hpp"
#include "Tolik/Debug/Debug.hpp"

namespace Tolik
{
Player::Player(const UserInput &userInput)
  : m_userInput(userInput)
  , m_camera(Transform(&m_transform))
{}

void Player::Update()
{
  if(m_userInput.GetKey(KeyID::W))
    m_transform.SetPosition(m_transform.GetPosition() + (m_camera.transform.Forward() * 0.001));
  if(m_userInput.GetKey(KeyID::A))
    m_transform.SetPosition(m_transform.GetPosition() + (m_camera.transform.Left() * 0.001));
  if(m_userInput.GetKey(KeyID::S))
    m_transform.SetPosition(m_transform.GetPosition() + (m_camera.transform.Backward() * 0.001));
  if(m_userInput.GetKey(KeyID::D))
    m_transform.SetPosition(m_transform.GetPosition() + (m_camera.transform.Right() * 0.001));
  if(m_userInput.GetKey(KeyID::Space))
    m_transform.SetPosition(m_transform.GetPosition() + (Vec3::up() * 0.001));
  if(m_userInput.GetKey(KeyID::Lshift))
    m_transform.SetPosition(m_transform.GetPosition() + (Vec3::down() * 0.001));

  static float xRotation;
  static float yRotation;

  xRotation += m_userInput.GetAxis(InputAxis::MouseDelta).y() * s_sensativity;
  yRotation += m_userInput.GetAxis(InputAxis::MouseDelta).x() * s_sensativity;
  //xRotation = std::clamp(xRotation, -89.0f, 89.0f);

  // Oder matters!!!
  m_camera.transform.SetLocalRotation(Qua::FromAxis(Vec3::up(), DegreesToRadians(yRotation)) * Qua::FromAxis(Vec3::right(), DegreesToRadians(xRotation)));
}
}
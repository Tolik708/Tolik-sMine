#include "Rendering/Renderer.hpp"

#include "glad/glad.h"
#include "SDL2/SDL.h"

#include "Math/Transform.hpp"
#include "Rendering/Window.hpp"
#include "Math/MathFunctions.hpp"
#include "Rendering/Camera.hpp"
#include "Debug/Debug.hpp"
#include "Rendering/OpenGL/ShaderGL.hpp"
#include "Rendering/OpenGL/ResourceManagerGL.hpp"
#include "Rendering/MeshSpecification.hpp"

namespace Tolik
{
void Renderer::InitGL()
{
  SDL_CALL(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4));
  SDL_CALL(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1));
  SDL_CALL(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY));
  SDL_CALL(SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1));
  SDL_CALL(SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24));
}

void Renderer::SetWindowGL(Window *window)
{
  m_window = window;
  SDL_CALL(m_context = SDL_GL_CreateContext(m_window->GetSDLWindow()));
  GL_CALL(gladLoadGLLoader(SDL_GL_GetProcAddress));

  UpdateDrawbleSizeGL();

  m_resources = new ResourceManagerGL();

  GL_CALL(glClearColor(0.2, 0.2, 0.2, 1));
  GL_CALL(glEnable(GL_DEPTH_TEST));
  GL_CALL(glProvokingVertex(GL_LAST_VERTEX_CONVENTION));
  GL_CALL(glViewport(0, 0, m_width, m_height));
}

void Renderer::QuitGL()
{
  SDL_GL_DeleteContext(static_cast<SDL_GLContext>(m_context));
}

void Renderer::StartFrameGL() const
{
  GL_CALL(glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));
}

void Renderer::RenderGL(const Camera &camera)
{
  for(const auto &mesh : meshes)
  {
    ResourceManagerGL *resources = static_cast<ResourceManagerGL*>(m_resources);
    const ShaderGL &shader = resources->GetShader(mesh->GetMeshType());
    shader.SetUniform<4, 4>("u_view", 1, GL_FALSE, &(glm::perspective(DegreesToRadians(camera.FOV), static_cast<float>(m_width) / static_cast<float>(m_height), 0.1f, 1000.0f) * camera.GetViewMatrix())[0][0]);
    std::array<int, 2> dimensions = { 3, 3 };
    shader.SetUniform<2>("u_textureAtlasDimensions", 2, dimensions.data());
    static_cast<MeshGL*>(mesh)->Draw();
  }

  meshes.clear();
}

void Renderer::EndFrameGL() const
{
  SDL_GL_SwapWindow(m_window->GetSDLWindow());
}

void Renderer::DebugGL(void *data) const
{

}

void Renderer::UpdateDrawbleSizeGL()
{
  SDL_GL_GetDrawableSize(m_window->GetSDLWindow(), &m_width, &m_height);
}

uint32_t Renderer::GetSDLWindowFlagsGL() const
{
  return SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
}
}
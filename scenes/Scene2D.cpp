#include "Scene2D.hpp"

namespace Graphics
{
    Scene2D::Scene2D() : Scene(new Camera(Maths::mat4::Identity())), m_Renderer(nullptr)
    {
        m_Renderer = new Renderer2D(m_Camera);
    }

    Scene2D::Scene2D(const Maths::mat4& projMatrix) : Scene(new Camera(projMatrix))
    {
        m_Renderer = new Renderer2D(m_Camera);
    }

    Scene2D::Scene2D(Camera* camera): Scene(camera)
    {
        m_Renderer = new Renderer2D(m_Camera);
    }

    Scene2D::~Scene2D()
    {

    }

    void Scene2D::Add(Layer* layer)
    {
        m_Layers.push_back(layer);
    }

    void Scene2D::SetCamera(Camera* camera)
    {
        m_Camera = camera;
    }

    void Scene2D::OnTick()
    {

    }

    void Scene2D::OnUpdate()
    {
        for (Layer* layer : m_Layers)
            layer->OnUpdate();
    }

    void Scene2D::OnRender()
    {
        
        for (Layer* layer : m_Layers)
            layer->OnRender(m_Renderer);

    }

    Camera* Scene2D::GetCamera() const
    {
        return m_Camera;
    }

    const std::vector<Layer*>& Scene2D::GetLayers() const
    {
        return m_Layers;
    }
};
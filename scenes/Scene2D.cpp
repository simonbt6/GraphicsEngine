#include "Scene2D.hpp"

namespace Graphics
{
    Scene2D::Scene2D()
    {

    }

    Scene2D::Scene2D(Camera* camera): m_Camera(camera)
    {

    }

    void Scene2D::Add(Layer2D* layer)
    {
        m_Layers.push_back(layer);
    }

    void Scene2D::SetCamera(Camera* camera)
    {
        m_Camera = camera;
    }

    void Scene2D::Update()
    {

    }

    void Scene2D::Render(Renderer2D& renderer)
    {

    }

    Camera* Scene2D::GetCamera() const
    {
        return m_Camera;
    }

    const std::vector<Layer2D*>& Scene2D::GetLayers() const
    {
        return m_Layers;
    }
};
#include "Scene3D.hpp"

namespace Graphics
{
    Scene3D::Scene3D() : Scene(nullptr)
    {

    }

    Scene3D::Scene3D(Camera* camera): Scene(camera)
    {

    }

    void Scene3D::Add(Layer* layer)
    {
        m_Layers.push_back(layer);
    }

    void Scene3D::SetCamera(Camera* camera)
    {
        m_Camera = camera;
    }

    void Scene3D::Update()
    {

    }

    void Scene3D::Render()
    {

    }

    Camera* Scene3D::GetCamera() const
    {
        return m_Camera;
    }

    const std::vector<Layer*>& Scene3D::GetLayers() const
    {
        return m_Layers;
    }
};
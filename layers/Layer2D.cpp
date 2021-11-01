#include "Layer2D.hpp"

namespace Graphics
{
    Layer2D::Layer2D()
    {

    }

    void Layer2D::Init()
    {

    }

    void Layer2D::Submit(IRenderable2D* renderable)
    {
        this->m_SubmittedRenderables.push_back(renderable);
    }

    void Layer2D::OnRender(Renderer2D* renderer)
    {
        for (const IRenderable2D* renderable : m_SubmittedRenderables)
            renderable->Submit(renderer);

        m_SubmittedRenderables.clear();
    }

    void Layer2D::OnUpdateInternal()
    {

    }
}
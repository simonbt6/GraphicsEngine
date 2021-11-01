#pragma once

/**
 * @author Simon Brisebois-Therrien
 * @date 2021-10-24 
 * 
 * 
 */ 
#include <graphics/layers/ILayer.hpp>
#include <graphics/renderer/Renderer2D.hpp>
#include <graphics/renderer/renderables/IRenderable2D.hpp>
// #include <graphics/renderer/text/TextRenderer.hpp>

#include <maths/maths.hpp>


#include <inttypes.h>
#include <vector>

namespace Graphics
{
    class Layer2D : public Layer
    {
        protected:
            std::vector<IRenderable2D*> m_SubmittedRenderables;

        public:
            Layer2D();

            virtual ~Layer2D(){};

            virtual void Init();

            virtual void Submit(IRenderable2D* renderable);

            void OnUpdateInternal() override;
            virtual void OnRender(Renderer2D* renderer);

    };
}
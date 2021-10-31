#pragma once

/**
 * @author Simon Brisebois-Therrien
 * @date 2021-10-31 
 * 
 * 
 */

#include <graphics/camera/Camera.hpp>
#include <graphics/layers/ILayer.hpp>
#include <graphics/layers/Layer2D.hpp>
#include <graphics/renderer/Renderables/IRenderable2D.hpp>
#include <graphics/renderer/Renderer2D.hpp>

namespace Graphics
{
    class Scene
    {
        protected:
            Camera* camera;

            std::vector<Layer*> m_Layers;

        public:

            Scene();
            Scene(Camera* camera);

            virtual ~Scene();

            virtual void Render();


        protected:

    };
}
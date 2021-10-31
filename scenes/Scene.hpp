#pragma once

/**
 * @author Simon Brisebois-Therrien
 * @date 2021-10-31 
 * 
 * 
 */

#include "Camera.hpp"
#include "ILayer.hpp"
#include "Layer2D.hpp"
#include "IRenderable2D.hpp"
#include "Renderer2D.hpp"


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
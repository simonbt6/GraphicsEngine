#pragma once

/**
 * @author Simon Brisebois-Therrien
 * @date 2021-10-31 
 * 
 * 
 */

#include <graphics/camera/Camera.hpp>
#include <graphics/layers/ILayer.hpp>

namespace Graphics
{
    class Scene
    {
        protected:
            Camera* m_Camera;

            std::vector<Layer*> m_Layers;

        public:
            Scene(Camera* camera): m_Camera(camera){}

            virtual ~Scene(){}

            virtual void OnUpdate(){}
            virtual void OnTick(){}
            virtual void OnRender(){}

    };
}
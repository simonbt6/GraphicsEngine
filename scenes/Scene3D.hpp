#pragma once

#include <vector>

#include "Camera.hpp"
#include "Layer2D.hpp"
#include "Renderer2D.hpp"

namespace Graphics
{
    class Scene3D
    {
        private:
            std::vector<Layer2D*> m_Layers2D;
            Camera* m_Camera;

        public:
            Scene3D();
            Scene3D(Camera* camera);

            ~Scene3D();

            void Add(Layer2D* layer);

            void Update();
            void Render();

            void SetCamera(Camera* camera);
            
            Camera* GetCamera() const;
            const std::vector<Layer2D*>& GetLayers() const;
            

    };
};
#pragma once

#include <vector>

#include <graphics/scenes/Scene.hpp>
#include <graphics/camera/Camera.hpp>
#include <graphics/layers/ILayer.hpp>
#include <graphics/renderer/Renderer2D.hpp>

namespace Graphics
{
    class Scene3D : public Scene
    {
        private:
            Camera* m_Camera;

        public:
            Scene3D();
            Scene3D(Camera* camera);

            ~Scene3D();

            void Add(Layer* layer);

            void Update();
            void Render();

            void SetCamera(Camera* camera);
            
            Camera* GetCamera() const;
            const std::vector<Layer*>& GetLayers() const;
            

    };
};
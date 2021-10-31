#pragma once

#include "Scene.hpp"
#include "Camera.hpp"
#include "Layer2D.hpp"
#include "IRenderable2D.hpp"
#include "Renderer2D.hpp"

#include <vector>

namespace Graphics
{
    class Scene2D : public Scene
    {
        private:
            std::vector<Layer2D*> m_Layers;
            Camera* m_Camera;

        public:
            Scene2D();
            Scene2D(Camera* camera);

            ~Scene2D();

            void Add(Layer2D* layer);

            void SetCamera(Camera* camera);

            void Update();
            void Render(Renderer2D& renderer);

            Camera* GetCamera() const;
            const std::vector<Layer2D*>& GetLayers() const;
            const std::vector<IRenderable2D*> GetRenderables() const;

    };
};
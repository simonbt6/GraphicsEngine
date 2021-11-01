#pragma once

#include <graphics/scenes/Scene.hpp>

#include <graphics/camera/Camera.hpp>

#include <graphics/layers/ILayer.hpp>

#include <graphics/renderer/Renderer2D.hpp>
#include <graphics/renderer/Renderables/IRenderable2D.hpp>

#include <maths/mat4.hpp>

#include <vector>

namespace Graphics
{
    class Scene2D : public Scene
    {
        private:
            std::vector<Layer*> m_Layers;
            Renderer2D* m_Renderer;

        public:
            Scene2D();
            Scene2D(const Maths::mat4& projMatrix);
            Scene2D(Camera* camera);

            ~Scene2D();

            void Add(Layer* layer);

            void SetCamera(Camera* camera);

            void OnTick();
            void OnUpdate();
            void OnRender() override;

            Camera* GetCamera() const;
            const std::vector<Layer*>& GetLayers() const;
            const std::vector<IRenderable2D*> GetRenderables() const;

    };
};
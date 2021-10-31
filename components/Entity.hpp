#pragma once

#include <graphics/components/Component.hpp>
#include <graphics/renderer/renderables/Sprite.hpp>

#include <unordered_map>
#include <maths/maths.hpp>


namespace Graphics
{
    class Entity
    {
        protected:
            std::unordered_map<ComponentType*, Component*> m_Components;

        public:
            Entity();
            Entity(Primitives::Sprite* sprite, const Maths::mat4& transform = Maths::mat4::Identity());

            void AddComponent(Component* component);

            template<typename T>
            const T* GetComponent() const;

            template<typename T>
            T* GetComponent();

        private:
            template<typename T>
            const T* GetComponentInternal() const;
    };
}
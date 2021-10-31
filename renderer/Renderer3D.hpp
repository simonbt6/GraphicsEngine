#pragma once

#include "Shader.hpp"

namespace Graphics
{
    class Renderer3D
    {
        protected:
            uint32_t m_ScreenBufferWidth, m_ScreenBufferHeight;
        public:
            virtual ~Renderer3D() {}
            virtual void Init();
    };
};
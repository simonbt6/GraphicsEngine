#pragma once

/**
 * @author Simon Brisebois-Therrien
 * @date 2021-10-14 
 * 
 * A simple renderer 2D to draw sprites & basic geometry.
 */

#include <glad/gl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <graphics/camera/Camera.hpp>

#include <graphics/renderer/Shader.hpp>
#include <graphics/renderer/Texture.hpp>

#include <graphics/buffers/VertexArray.hpp>
#include <graphics/buffers/VertexBuffer.hpp>
#include <graphics/buffers/VertexBufferLayout.hpp>
#include <graphics/buffers/IndexBuffer.hpp>

#include <graphics/utils/color.hpp>

#include <graphics/renderer/renderables/IRenderable2D.hpp>

#include <graphics/renderer/text/TextRenderer.hpp>

#include <maths/maths.hpp>

#include <utils/FileManager.hpp>
#include <utils/FormatedPrint.hpp>

#include <map>
#include <string>

namespace Graphics
{

    
    class IRenderable2D;

    class Renderer2D
    {
        private:
            static inline const std::string s_FolderPath = "D:/dev-repo/VideoStreaming/RTMP/src/graphics/shaders/";

        private:
            TextRenderer* m_TextRenderer;
            
            Camera* m_Camera;

            VertexArray m_VAO;

            std::map<std::string, Shader*> m_Shaders;

        public:
            Renderer2D(Camera* camera);
           ~Renderer2D();

            void Clear();

            void Draw(const IndexBuffer& ibo, const Shader& shader);
            void Draw(const IRenderable2D& renderable);
            
            void DrawRect(const Maths::Rectangle& rectangle, const Color& color);
            void DrawRect(float width, float height, const Color& color);

            void DrawLine(const Maths::vec2& v1, const Maths::vec2& v2, float thickness, const Color& color);

            void DrawQuad(Maths::vec4 positions, Color color);
            
            void DrawSprite(const Texture& texture, Maths::Rectangle bounds, const Maths::mat4& modelMatrix);
            void DrawSprite(const Texture& texture, Maths::vec2 position, Maths::vec2 size, const Maths::mat4& modelMatrix);
            void DrawSprite(const Texture& texture, float x, float y, float width, float height, const Maths::mat4& modelMatrix);

            void DrawText(const std::string& text, const std::string& font_name, float size,  const Color& color, Maths::vec2 position);

            inline void SetCamera(Camera* camera) { m_Camera = camera; }
            inline Camera* GetCamera() const { return m_Camera; }
            
        private:
            Shader* GetShader(const std::string& name);

            void LoadShaders();

            void LoadCharacters();

    };
};
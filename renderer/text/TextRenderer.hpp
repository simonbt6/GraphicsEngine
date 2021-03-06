#pragma once

/**
 * @author Simon Brisebois-Therrien
 * @date 2021-10-26 
 * 
 * 
 */

#include <ft2build.h>
#include FT_FREETYPE_H

#include <graphics/renderer/text/Font.hpp>
#include <graphics/utils/color.hpp>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>


namespace Graphics
{


    class TextRenderer
    {
        private:
            FT_Library* m_FreeType;

            std::map<std::string, std::map<uint32_t, Font*>> m_Fonts;

        public:
            TextRenderer();
            ~TextRenderer();

            void DrawString(const std::string& text, const std::string& font_name, const Color& color, uint32_t size, Maths::vec2 position);

        private:
            void LoadCharacters();

            Font* LoadFont(const std::string& name, const std::string& filename, uint32_t size);
            Font* GetFont(const std::string& name,  const std::string& filename, uint32_t size);
    };
};
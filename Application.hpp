#pragma once

/**
 * @author Simon Brisebois-Therrien
 * @date 2021-10-24
 * 
 * 
 **/

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <graphics/window/Window.hpp>

#include <graphics/layers/Layer2D.hpp>

#include <graphics/scenes/Scene.hpp>
#include <graphics/scenes/Scene2D.hpp>

#include <graphics/renderer/text/Font.hpp>
#include <graphics/renderer/renderables/Sprite.hpp>
#include <graphics/renderer/renderables/Rectangle.hpp>
#include <graphics/renderer/renderables/Label.hpp>

#include <graphics/utils/color.hpp>

#include <graphics/sound/SoundEngine.hpp>

#include <maths/maths.hpp>

#include <utils/FileManager.hpp>

#include <iostream>


#define DEFAULT_WINDOW_WIDTH  300
#define DEFAULT_WINDOW_HEIGHT 300
#define DEFAULT_WINDOW_POSITION_X 0
#define DEFAULT_WINDOW_POSITION_Y 0
#define DEFAULT_WINDOW_NAME "Template application"

namespace Graphics
{
    // class Window;
    class Application
    {

        private:
            Window* m_Window;

            SoundEngine* m_SoundEngine;


            bool m_Running, m_Suspended;
            uint32_t m_UPS, m_FPS;
            float m_Frametime;

            std::string m_Name;

            Scene* m_Scene;

        public:
            Application();
            Application(const std::string& name);
            Application(const std::string& name, float width, float height);
            Application(const std::string& name, float x, float y, float width, float height);
            Application(const std::string& name, const Maths::Rectangle& bounds);

            virtual ~Application();

            inline void SetScene(Scene* scene) { m_Scene = scene; }
            inline Scene* GetScene() { return m_Scene; }

            void SetWindowHandler(void(* handler)()) { m_Window->SetHandler(handler); };

            void OpenWindow(){ m_Window->Init(); }

            void Start();
            void Suspend();
            void Resume();
            void Stop();

            inline uint32_t GetFPS() const { return m_FPS; }
            inline uint32_t GetUPS() const { return m_UPS; }
            inline float GetFrametime() const { return m_Frametime; }

            inline Window* GetWindow() const { return m_Window; }
            
            void OnRender();

            inline SoundEngine& GetSoundEngine() const{ return *m_SoundEngine; }

            inline Scene* GetCurrentScene() const { return m_Scene; }
        private:

            void Run(){}

            void OnTick();
            void OnUpdate();
    };
};
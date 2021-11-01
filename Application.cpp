#include "Application.hpp"

namespace Graphics
{
    Application::Application()
        : Application(
            DEFAULT_WINDOW_NAME,
            Maths::Rectangle(
                DEFAULT_WINDOW_POSITION_X,
                DEFAULT_WINDOW_POSITION_Y, 
                DEFAULT_WINDOW_WIDTH, 
                DEFAULT_WINDOW_HEIGHT
            )
        )
    {
        
    }

    Application::Application(const std::string& name)
        : Application(
            name, 
            Maths::Rectangle(
                DEFAULT_WINDOW_POSITION_X, 
                DEFAULT_WINDOW_POSITION_Y, 
                DEFAULT_WINDOW_WIDTH, 
                DEFAULT_WINDOW_HEIGHT
            )
        )
    {

    }

    Application::Application(const std::string& name, float width, float height)
        :Application(
            name,
            Maths::Rectangle(
                DEFAULT_WINDOW_POSITION_X,
                DEFAULT_WINDOW_POSITION_Y,
                width,
                height
            )
        )    
    {

    }
    Application::Application(const std::string& name, float x, float y, float width, float height)
        :Application(
            name,
            Maths::Rectangle(
                x,
                y,
                width,
                height
            )
        )    
    {

    }

    Application::Application(const std::string& name, const Maths::Rectangle& bounds)
    {
        m_Window = new Window(name, bounds);
        m_SoundEngine = new SoundEngine();
    }

    Application::~Application()
    {

    }

    void Application::Start()
    {
        Run();
        m_Window->Start();
    }

    void Application::Stop()
    {

    }

    void Application::OnTick()
    {
        m_Scene->OnTick();
    }

    void Application::OnUpdate()
    {
        m_Scene->OnUpdate();
    }

    void Application::OnRender()
    {
        m_Scene->OnRender();
    }
}

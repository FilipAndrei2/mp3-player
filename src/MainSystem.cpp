#include "class/MainSystem.hpp"
#include "class/SDL_Handler.hpp"

#include "proj/global.hpp"
#include "proj/compile_settings.hpp"

mp3::MainSystem::MainSystem()
    : m_imgui_handler(m_sdl_handler.getWindow(), m_sdl_handler.getRenderer()), m_isRunning(true)
{

}

mp3::MainSystem::~MainSystem()
{

}

void mp3::MainSystem::run()
{
        while (m_isRunning)
        {
            int start = SDL_GetTicks();
            m_imgui_handler.newFrame(m_sdl_handler.getWindow());
            m_imgui_handler.testWindow();
            ImGui::ShowDemoWindow();

            m_isRunning = m_sdl_handler.takeInput();
            //gameLogic();
            m_sdl_handler.renderFrame();
            m_imgui_handler.render();
            SDL_RenderPresent(m_sdl_handler.getRenderer());
            int deltaTime = start - SDL_GetTicks();
            if(deltaTime < FRAME_TIME_MS)
            {
                SDL_Delay(FRAME_TIME_MS - deltaTime);
            } else {
                SDL_Delay(1);
            }
        }
}
#pragma once

#include "class/SDL_Handler.hpp"
#include "class/ImGui_Handler.hpp"

namespace mp3{
    class MainSystem
    {
    public:
        MainSystem();
        ~MainSystem();
        void run();
    private:
        SDL_Handler m_sdl_handler;
        ImGui_Handler m_imgui_handler;
        bool m_isRunning;
    };
}
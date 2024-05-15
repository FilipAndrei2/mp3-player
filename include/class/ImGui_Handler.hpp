#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

#include <SDL2/SDL.h>

namespace mp3
{
    class ImGui_Handler
    {
        public:
            ImGui_Handler(SDL_Window * p_window, SDL_Renderer * p_renderer);
            ~ImGui_Handler();
            void newFrame(SDL_Window * p_window);
            void testWindow(void);
            void render(void);
        private:
    };
}
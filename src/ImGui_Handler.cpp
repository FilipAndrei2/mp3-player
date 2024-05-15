#include "class/ImGui_Handler.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

#include <SDL2/SDL.h>

namespace mp3
{
    ImGui_Handler::ImGui_Handler(SDL_Window * p_window, SDL_Renderer * p_renderer)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;

        ImGui_ImplSDL2_InitForSDLRenderer(p_window, p_renderer);
        ImGui_ImplSDLRenderer2_Init(p_renderer);
    }

    ImGui_Handler::~ImGui_Handler()
    {
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGui_Handler::newFrame(SDL_Window * p_window)
    {
        (void)p_window;
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void ImGui_Handler::testWindow(void)
    {
        ImGui::Begin("test :)");
        ImGui::Text("Hello, world from imgui window!\n");
        ImGui::End();
    }

    void ImGui_Handler::render(void)
    {
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    }

}
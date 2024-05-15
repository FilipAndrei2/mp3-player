#include "class/SDL_Handler.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>

#include <fstream>
#include <cstdio>

#include "proj/global.hpp"
#include "proj/compile_settings.hpp"

namespace mp3
{
    SDL_Handler::SDL_Handler(void)
        : m_window(nullptr), m_renderer(nullptr), m_isRunning(true)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            sdlerr << "Eroare la initializarea SDL! Error: " << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        if (IMG_INIT_FLAGS != IMG_Init(IMG_INIT_FLAGS))
        {
            sdlerr << "Eroare la initializarea SDL_image! Error: " << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        if (MIX_INIT_FLAGS != Mix_Init(MIX_INIT_FLAGS))
        {
            sdlerr << "Eroare la initializarea SDL_mixer! Error: " << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        if (TTF_Init() != 0)
        {
            sdlerr << "Eroare la initializarea SDL_ttf! Error: " << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        m_window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
        if (!m_window)
        {
            sdlerr << "Eroare la initializarea ferestrei! Error: " << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, RENDERER_FLAGS);
        if (!m_renderer)
        {
            sdlerr << "Eroare la initializarea renderului! Error: " << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    SDL_Handler::~SDL_Handler(void)
    {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;

        SDL_DestroyWindow(m_window);
        m_window = nullptr;

        TTF_Quit();
        Mix_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    inline void SDL_Handler::stop(void)
    {
        m_isRunning = false;
    }

    bool SDL_Handler::takeInput(void)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return false;
            }

            switch (event.key.keysym.sym) //verifica apasarea tastelor
            {

            }
            ImGui_ImplSDL2_ProcessEvent(&event);
        }
        return true;
    }

    void SDL_Handler::renderFrame(void)
    {
        SDL_SetRenderDrawColor(m_renderer, 255, 254, 253, 255);
        SDL_RenderClear(m_renderer);

    }

    void SDL_Handler::mainLoop(void)
    {
        while (m_isRunning)
        {
            takeInput();
            //gameLogic();
            renderFrame();
        }
    }

    SDL_Window * SDL_Handler::getWindow(void)
    {
        return m_window;
    }

    SDL_Renderer * SDL_Handler::getRenderer(void)
    {
        return m_renderer;
    }
    
}
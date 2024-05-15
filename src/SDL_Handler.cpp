#include "class/SDL_Handler.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <fstream>
#include <cstdio>

#include "proj/global.hpp"
#include "proj/compile_settings.hpp"

namespace mp3
{
    SDL_Handler::SDL_Handler()
        : m_window(nullptr), m_renderer(nullptr)
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

    SDL_Handler::~SDL_Handler()
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
}
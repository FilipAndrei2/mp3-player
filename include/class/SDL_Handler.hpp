#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

namespace mp3
{
    class SDL_Handler
    {
    public:
        SDL_Handler();
        ~SDL_Handler();
    private:
        SDL_Window * m_window;
        SDL_Renderer * m_renderer;
    };
} 
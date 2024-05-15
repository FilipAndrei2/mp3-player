#include "class/MainSystem.hpp"
#include "class/SDL_Handler.hpp"

#include "proj/global.hpp"

void mp3::MainSystem::run()
{
    SDL_Handler handler;
    handler.mainLoop();
}
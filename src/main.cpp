#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

#include "class/MainSystem.hpp"

std::ofstream sdlerr("SDL.err");

int main(int argc, char ** argv)
{
    mp3::MainSystem app;
    app.run();
}
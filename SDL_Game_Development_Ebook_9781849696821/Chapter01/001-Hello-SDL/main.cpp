/*
  SDL Game Development Ebook
  Discover how to leverage the power of SDL 2.0 to create awesome games in C
  by Shaun Ross Mitchell
  IBSN 9781849696821
  Copyright © 2013 Packt Publishing

  Chapter 1: Getting Started with SDL
  Lesson: Hello SDL

  Date 2021-08-03
  Begin Program 001-Hello-SDL
*/

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "../../defines.hpp"

const int g_iWidth = WINDOW_WIDTH;
const int g_iHeight = WINDOW_HEIGHT;
std::string g_cSubTitle = "Chapter 1: Setting up SDL";
std::string g_cTitle = g_cSubTitle + WINDOW_TITLE;

SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

int main(int argc, char* args[])
{
    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        /* SDL initalized */
        g_pWindow = SDL_CreateWindow(g_cTitle.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            g_iWidth, g_iHeight, SDL_WINDOW_SHOWN);

        /* if the window creation succeeded create the renderer */
        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
        else
        {
            /* Window initialization failed */
            std::cout << "SDL Window Initialization Failed" << std::endl;
            return 1;
        }
    }
    else
    {
        /* SDL could not initialize */
        std::cout << "SDL Initialization Failed" << std::endl;
        return 1;
    }

    /* Looks like everything initialized - let us draw the window */

    /* set Render Draw Color to black */
    /* The function expects Red, Green, Blue and Alpha as color values */
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    /* Let us clear the window to black */
    SDL_RenderClear(g_pRenderer);

    /* Now show the window */
    SDL_RenderPresent(g_pRenderer);

    /* Set a delay before quiting in milliseconds - 1000 = 1 second */
    SDL_Delay(5000);

    /* Clean up SDL before we quit */
    SDL_Quit();

    return 0;
}
/* End of 001-Hello-SDL */
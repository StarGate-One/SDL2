/*
  SDL Game Development Ebook
  Discover how to leverage the power of SDL 2.0 to create awesome games in C
  by Shaun Ross Mitchell
  IBSN 9781849696821
  Copyright © 2013 Packt Publishing

  Chapter 1: Getting Started with SDL
  Lesson: Breaking Up The Code

  Date 2021-08-03
  Begin Program 002-Breaking-Up-Code
*/

#include <iostream>
#include <SDL2/SDL.h>

/* Screen Width and Height */
const int g_iWidth = 1920;
const int g_iHeight = 1080;
const char* g_cTitle = "Chapter 1: Breaking Up the Code";

/* Used to continue or end our loop */
bool g_bRunning = false;
int g_iCounter = 0;

SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

/* Create our Initialize Function */
bool init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        /* SDL initalized */
        g_pWindow = SDL_CreateWindow(title, xpos, ypos,
            width, height, flags);

        /* if the window creation succeeded create the renderer */
        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
        else
        {
            /* Window initialization failed */
            std::cout << "SDL Window Initialization Failed" << std::endl;
            return false;
        }
    }
    else
    {
        /* SDL could not initialize */
        std::cout << "SDL Initialization Failed" << std::endl;
        return false;
    }
    return true;
}

/* Create our Renderer Function */
void render()
{
    /* set Render Draw Color to black */
    /* The function expects Red, Green, Blue and Alpha as color values */
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    /* Let us clear the window to black */
    SDL_RenderClear(g_pRenderer);

    /* Now show the window */
    SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[])
{
    if (init(g_cTitle,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        g_iWidth, g_iHeight, SDL_WINDOW_SHOWN))
    {
        /* Looks like everything initialized - let us draw the window */
        g_bRunning = true;
    }
    else
    {
        /* SDL did not initialize properly */
        std::cout << "SDL did not initialize properly - something is wrong" << std::endl;
        return 1;
    }

    while (g_bRunning)
    {
        g_iCounter++;

        if (g_iCounter <= 9)
        {
            render();
            /* Set a delay before next loop in milliseconds - 1000 = 1 second */
            SDL_Delay(5000); // 5 seconds
        }
        else
        {
            g_bRunning = false;
        }
    }

    /* Clean up SDL before we quit */
    SDL_Quit();

    return 0;
}
/* End of 002-Breaking-Up-Code */
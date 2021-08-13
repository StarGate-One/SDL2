/*
  SDL Game Development Ebook
  Discover how to leverage the power of SDL 2.0 to create awesome games in C
  by Shaun Ross Mitchell
  IBSN 9781849696821
  Copyright © 2013 Packt Publishing

  Chapter 2: Drawing in SDL
  Lesson: Creating an SDL Texture

  Date 2021-08-12
  Begin Program 001-Creating-SDL-Texture
  File Game.cpp
*/
#include <iostream>
#include "Game.h"

/* Create our Initialize Function */
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        int flags = 0;
        if (fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        /* SDL initalized */
        std::cout << "SDL init success\n" << std::endl;

        /* Initialize the window */
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
            width, height, flags);

        /* if the window creation succeeded create the renderer */
        if (m_pWindow != 0)
        {
            /* Window initialization successful */
            std::cout << "Window init success\n" << std::endl;

            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0)
            {
                /* Renderer Creation was successful */
                std::cout << "Renderer creation success\n" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 15, 30, 45, 255);
            }
            else
            {
                /* Renderer Creation failed */
                std::cout << "Renderer creation failed\n" << std::endl;
                return false;
            }
        }
        else
        {
            /* Window initialization failed */
            std::cout << "SDL Window Initialization Failed\n" << std::endl;
            return false;
        }
    }
    else
    {
        /* SDL could not initialize */
        std::cout << "SDL Initialization Failed\n" << std::endl;
        return false;
    }

    /* Everying clean and green, startup the main loop */
    std::cout << "Initialization Successful\n" << std::endl;
    m_bRunning = true;

    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

    // m_destinationRectangle.x = m_sourceRectangle.x = 0;
    // m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.x = 100;
    m_destinationRectangle.y = 100;

    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;

    return true;
}

void Game::render()
{
    /* Clear the renderer to our preferred draw color */
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    // SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, NULL);

    /* Draw the screen */
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout << "Cleaning up Game\n" << std::endl;
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        m_bRunning = false;
                        break;

                    default:
                        break;
                }
                break;

            case SDL_QUIT:
                m_bRunning = false;
                break;

            default:
                break;
        }
    }
}
/* End of 001-Creating-SDL-Texture */
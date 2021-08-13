/*
  SDL Game Development Ebook
  Discover how to leverage the power of SDL 2.0 to create awesome games in C
  by Shaun Ross Mitchell
  IBSN 9781849696821
  Copyright © 2013 Packt Publishing

  Chapter 2: Drawing in SDL
  Lesson: Animating a Sprite Sheet

  Date 2021-08-12
  Begin Program 002-Animating-Sprite-Sheet
  File Game.h
*/
#ifndef __Game_H__
#define __Game_H__

#include <SDL2/SDL.h>

class Game
{
public:

    Game() {}
    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();

    /* Function to access the private running variable */
    bool running()
    {
        return m_bRunning;
    }

private:

    SDL_Window* m_pWindow = NULL;
    SDL_Renderer* m_pRenderer = NULL;
    SDL_Texture* m_pTexture = NULL;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;

    bool m_bRunning = false;
};

#endif /* defined(__Game_H__) */
/* End of 002-Animating-Sprite-Sheet */
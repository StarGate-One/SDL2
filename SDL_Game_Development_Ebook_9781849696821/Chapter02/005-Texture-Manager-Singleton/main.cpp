/*
  SDL Game Development Ebook
  Discover how to leverage the power of SDL 2.0 to create awesome games in C
  by Shaun Ross Mitchell
  IBSN 9781849696821
  Copyright © 2013 Packt Publishing

  Chapter 2: Drawing in SDL
  Lesson: Using The Texture Manager As A Singleton

  Date 2021-08-25
  Begin Program 005-Using-The-Texture-Manager-As-A-Singleton
  File main.cpp
*/

#include "Game.h"

/* Screen Width and Height */
const int m_pWidth = 1920;
const int m_pHeight = 1080;
const char* m_cTitle = "Chapter 2: Using The Texture Manager As A Singleton";

/* The Game Object */
Game* g_game = 0;

int main(int argc, char* args[])
{
    g_game = new Game();

    g_game->init(m_cTitle, 100, 100, m_pWidth, m_pHeight, false);

    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }

    g_game->clean();

    return 0;
}
/* End of 005-Using-The-Texture-Manager-As-A-Singleton */
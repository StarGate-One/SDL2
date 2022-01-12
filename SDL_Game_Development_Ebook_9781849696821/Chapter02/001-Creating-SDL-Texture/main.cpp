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
  File main.cpp
*/
#include <string>
#include "Game.h"
#include "../../defines.hpp"

/* Screen Width and Height */
const int m_pWidth = WINDOW_WIDTH;
const int m_pHeight = WINDOW_HEIGHT;
std::string m_cSubTitle = "Chapter 2: Creating an SDL Texture";
std::string m_cTitle = m_cSubTitle + WINDOW_TITLE;

/* The Game Object */
Game* g_game = 0;

int main(int argc, char* args[])
{
    g_game = new Game();

    g_game->init(m_cTitle.c_str(), 100, 100, m_pWidth, m_pHeight, false);

    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }

    g_game->clean();

    return 0;
}
/* End of 001-Creating-SDL-Texture */
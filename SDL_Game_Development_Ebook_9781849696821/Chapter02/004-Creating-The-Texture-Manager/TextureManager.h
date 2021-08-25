/*
  SDL Game Development Ebook
  Discover how to leverage the power of SDL 2.0 to create awesome games in C
  by Shaun Ross Mitchell
  IBSN 9781849696821
  Copyright © 2013 Packt Publishing

  Chapter 2: Drawing in SDL
  Lesson: Creating The Texture Manager

  Date 2021-08-25
  Begin Program 004-Creating-The-Texture-Manager
  File TextureManager.h
*/
#ifndef __TextureManager_H__
#define __TextureManager_H__

#include <string>
#include <map>
#include <SDL2/SDL.h>

class TextureManager
{
public:

    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer*
        pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame, SDL_Renderer* pRenderer,
        SDL_RendererFlip flip = SDL_FLIP_NONE);

private:

    std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif /* defined(__TextureManager_H__) */
/* End of 004-Creating-The-Texture-Manager */
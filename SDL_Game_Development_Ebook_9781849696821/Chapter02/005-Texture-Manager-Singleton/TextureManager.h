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

    static TextureManager* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }

private:

    TextureManager() {}

    std::map<std::string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
};

typedef TextureManager TheTextureManager;

#endif /* defined(__TextureManager_H__) */
/* End of 005-Using-The-Texture-Manager-As-A-Singleton */
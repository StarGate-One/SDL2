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
  File TextureManager.cpp
*/

#include "TextureManager.h"
#include <SDL2/SDL_image.h>

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if (pTempSurface == 0)
    {
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    if (pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }

    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
    SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

/* End of 005-Using-The-Texture-Manager-As-A-Singleton */
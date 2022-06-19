
#include "TextureManager.hpp"
#include "Engine.hpp"

TextureManager* TextureManager::Instance = nullptr;

bool    TextureManager::Load(std::string id,std::string filePath)
{
    SDL_Surface* Surface;
    SDL_Texture* texture;
    
    Surface = NULL;
    texture = NULL;
    Surface = IMG_Load(filePath.c_str());
    if(Surface == NULL)
    {
        SDL_Log("!! failed to load Texture \"%s\" . Error: %s !!", filePath.c_str(),  SDL_GetError());
        return (false); 
    }
    texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), Surface);
    if(texture == NULL)
    {
        SDL_Log("!! Erorr create texture from Surface. Error: %s !!",SDL_GetError());
        return (false); 
    }
    TextureMap[id] = texture;
    return (true);
}

void    TextureManager::Draw(std::string id,int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect src = {0, 0, width, height};
    SDL_Rect dest = {x, y, width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), TextureMap[id], &src, &dest, 0, nullptr, flip);
}

void    TextureManager::Drop(std::string id)
{
    SDL_DestroyTexture(TextureMap[id]);
    TextureMap.erase(id);
    SDL_Log("texture Destroy \"%s\"  !!",id.c_str());
}

void    TextureManager::clean()
{
    std::map<std::string, SDL_Texture*>::iterator it;

    it = TextureMap.begin();
    while (it != TextureMap.end())
    {
        SDL_DestroyTexture(it->second);
        it++;
    }
    TextureMap.clear();
    SDL_Log("texture map cleaned !!"); 
}
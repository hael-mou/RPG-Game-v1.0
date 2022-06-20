#include "Engine.hpp"
#include "TextureManager.hpp"
#include "Transform.hpp"

Engine* Engine::Instance = nullptr;

bool            Engine::Init(const char* title, int width,int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("!! ERROR.. SDL_Init Has Failed: %s !!",SDL_GetError());
        return (false);
    }
    window = SDL_CreateWindow(title,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                width, height,
                                SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        SDL_Log("!! Window failed to init. Error: %s !!",SDL_GetError());
        return (false); 
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        SDL_Log("!! Renderer Creation is failed. Error: %s !!",SDL_GetError());
        return (false);
    }

    TextureManager::GetInstance()->Load("Bush1","res/gfx/Objects/Bush1.png");
    //------------------------------------------------------------------------
        Transform tr;
        tr.Log();
    //------------------------------------------------------------------------
    return (EisRunning = true);
}

void            Engine::update()
{

}

void            Engine::Render()
{
    SDL_RenderClear(renderer);
    TextureManager::GetInstance()->Draw("Bush1", 100, 100,145, 88);
    SDL_RenderPresent(renderer);
}

void            Engine::Events()
{
    SDL_Event       event;

    SDL_PollEvent(&event);
    switch (event.type)
     {
        case SDL_QUIT:
             Quit();
             break;
    }
}

void            Engine::Clean()
{
    TextureManager::GetInstance()->clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void            Engine::Quit()
{
    EisRunning = false;
}
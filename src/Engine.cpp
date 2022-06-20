#include "Engine.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"

Engine* Engine::Instance = nullptr;
Player *player = nullptr;

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
     //------------------------------------------------------------------------
    TextureManager::GetInstance()->Load("player1","res/dev/player/idle.png");
    player = new Player(new Properties("player1", 100, 200, 128, 194));
    //------------------------------------------------------------------------
    return (EisRunning = true);
}

void            Engine::update()
{
    player->Updade(0);
}

void            Engine::Render()
{
    SDL_RenderClear(renderer);
    player->Draw();
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
    player->Clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void            Engine::Quit()
{
    EisRunning = false;
}
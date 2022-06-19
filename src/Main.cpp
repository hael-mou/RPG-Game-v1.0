#include "Engine.hpp"

int     main()
{
    Engine::GetInstance()->Init("RPG GAME v1.0", 1280, 680);
    while (Engine::GetInstance()->IsRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->update();
        Engine::GetInstance()->Render();
    }
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();
    return (0);
}



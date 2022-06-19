#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

class Engine
{
    private:
        Engine():window(NULL), renderer(NULL){}
        static Engine*  Instance;
        bool            EisRunning;
        SDL_Window*     window;
        SDL_Renderer*   renderer;

    public:
        bool                    Init(const char* title, int width,int height);
        void                    update();
        void                    Render();
        void                    Events();
        void                    Clean();
        void                    Quit();
        inline  bool            IsRunning(){return(EisRunning);}
        inline SDL_Renderer*    GetRenderer(){return(renderer);}
        static Engine*          GetInstance(){ return (Instance = (Instance != nullptr) ? Instance : new Engine()); }
         
};

#endif
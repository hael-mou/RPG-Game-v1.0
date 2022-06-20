#ifndef TEXTUREMANAGER_HPP
# define TEXTUREMANAGER_HPP

# include <string>
# include <map>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

class TextureManager
{
private:
        TextureManager(){}
        static TextureManager*  Instance;
        std::map<std::string,SDL_Texture*> TextureMap;

public:
        bool                            Load(std::string id,std::string filePath);
        void                            Drop(std::string id);
        void                            clean();
        void                            Draw(std::string id,int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void                            DrawFrame(std::string id,int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);
        static TextureManager*          GetInstance(){ return (Instance = (Instance != nullptr) ? Instance : new TextureManager()); }

};

#endif
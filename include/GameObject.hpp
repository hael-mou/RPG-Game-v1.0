#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

# include "IObject.hpp"
# include "Transform.hpp"
# include <SDL2/SDL.h>

struct Properties
{
    public:
        Properties(std::string TextureID,int X, int Y, int Width, int Height, SDL_RendererFlip Flip)
        {
            textureID = TextureID;
            x         = X;
            y         = Y;
            width     = Width;
            height    = Height;
            Flip      = flip;
        }
    public:
        int                 x;
        int                 y;
        int                 width;
        int                 height;
        std::string         textureID;
        SDL_RendererFlip    flip;
};


class GameObject : public IObject
{
public:
    GameObject(Properties *props)
    :textureID(props->textureID), width(props->width),height(props->height), flip(props->flip)
    {
        transform = new Transform(props->x, props->y);
    }
    virtual void    Draw()=0;
    virtual void    Updade(float dt)=0;
    virtual void    Clean()=0;

protected:
    int              width;
    int              height;
    std::string      textureID;
    Transform*       transform;
    SDL_RendererFlip flip;
};

#endif
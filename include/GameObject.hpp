#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

# include "IObject.hpp"
# include "Transform.hpp"
# include <SDL2/SDL.h>

struct Properties
{
    public:
        Properties(std::string TextureID,int X, int Y, int Width, int Height, SDL_RendererFlip Flip = SDL_FLIP_NONE)
        {
            textureID = TextureID;
            x         = X;
            y         = Y;
            width     = Width;
            height    = Height;
            flip      = Flip;
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
    {
        ObjtextureID = props->textureID;
        Objwidth = props->width;
        Objheight = props->height;
        Objflip = props->flip;
        Objtransform = new Transform(props->x, props->y);
    }
    virtual void    Draw()=0;
    virtual void    Updade(float dt)=0;
    virtual void    Clean()=0;

protected:
    int              Objwidth;
    int              Objheight;
    std::string      ObjtextureID;
    Transform*       Objtransform;
    SDL_RendererFlip Objflip;
};

#endif
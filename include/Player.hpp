#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Character.hpp"

class Player : public Character
{
private:
    int nRow;
    int nFrame;
    int frame;
    int animationSpeed;

public:
    Player(Properties* props);
    virtual void    Draw();
    virtual void    Updade(float dt);
    virtual void    Clean();
};

#endif
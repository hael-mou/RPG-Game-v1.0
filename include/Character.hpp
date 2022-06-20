#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "GameObject.hpp"

class Character : public GameObject
{
protected:
    std::string nameID;

public:
    Character(Properties *props):GameObject(props){}
    virtual void    Draw()=0;
    virtual void    Updade(float dt)=0;
    virtual void    Clean()=0;
};



#endif
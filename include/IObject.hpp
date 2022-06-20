#ifndef IOBJECT_HPP
# define IOBJECT_HPP

class IObject
{ 
public:
    virtual void    Draw()=0;
    virtual void    Updade(float dt)=0;
    virtual void    Clean()=0;
 
};

#endif
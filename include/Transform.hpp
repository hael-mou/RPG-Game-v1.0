#ifndef TRANSFORM_HPP
# define TRANSFORM_HPP

#include "Vector2D.hpp"

class Transform
{
private:
    float X;
    float Y;
    
public:
    Transform(float x = 0, float y = 0):X(x),Y(y){}
    float           GetX(){return (X);}
    float           GetY(){return (Y);}
    inline void     TranslateX(float x){X += x;}
    inline void     TranslateY(float y){Y += y;}
    inline void     Translate(Vector2D V){X += V.GetX(); Y += V.GetY();}
    void    Log(std::string message = "")
    {
        std::cout << message << ": (x,y) = (" << X << "," << Y << ");" << std::endl;
    }
};

#endif
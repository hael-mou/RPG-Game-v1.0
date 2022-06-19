#ifndef VECTOR2D_CPP
# define VECTOR2D_CPP

# include <iostream>

class Vector2D
{
private:
    float X;
    float Y;

public:
    Vector2D(float x = 0, float y = 0):X(x),Y(y){}
    float   GetX(){return (X);}
    float   GetY(){return (Y);}
    inline Vector2D     operator+(Vector2D& v2)const
    {
        return (Vector2D(X + v2.GetX(), Y + v2.GetY()));
    }
    inline Vector2D     operator-(Vector2D& v2)const
    {
        return (Vector2D(X - v2.GetX(), Y - v2.GetY()));
    }
    inline Vector2D     operator*(const float sc)const
    {
        return (Vector2D((sc * X),(sc * Y)));
    }
    inline Vector2D     operator/(const float sc)const
    {
        return (Vector2D((sc / X),(sc / Y)));
    }
    void    Log(std::string message = "")
    {
        std::cout << message << ": (x,y) = (" << X << "," << Y << ");" << std::endl;
    }
};

#endif
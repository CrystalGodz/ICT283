#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "Shape.h"

class Square: public Shape{
public:
    Square();
    ~Square() {};

    int area() const;

private:

};



#endif // SQUARE_H_INCLUDED

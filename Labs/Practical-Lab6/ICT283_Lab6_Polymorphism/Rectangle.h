#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle: public Shape{
public:
    Rectangle();
    ~Rectangle() {};

    int GetLength() const;
    void SetLength(int length);

    int area() const;

private:
    int m_length;
};



#endif // RECTANGLE_H_INCLUDED

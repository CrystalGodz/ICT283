#include "Square.h"

Square::Square(){
    m_description = "Square";
    m_height = 5;
}

int Square::area() const{
    return m_height * m_height;
}

int Square::area()

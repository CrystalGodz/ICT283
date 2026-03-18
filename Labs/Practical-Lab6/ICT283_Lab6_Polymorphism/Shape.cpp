#include "Shape.h"

Shape::Shape(){
    m_height = 0;
    m_description = "Shape";
}

int Shape::GetHeight() const{
    return m_height;
}

void GetDescription(string& description) const{
    description = m_description;
}

void SetHeight(int height){
    m_height = height;
}

void SetDescription(const string& description){
    m_description = description;
}

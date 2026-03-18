#include "Light.h"

Light::Light(){
    m_colour = "white";
    m_radius = 0;
    m_on = false;
}


string Light::GetColour() const{
    return m_colour;    //do not do this for objects or large strings
}

float Light::GetRadius() const{
    return m_radius;
}

bool Light::IsOn() const{
    return m_on;
}

void Light::SetColour(const string& colour){
    m_colour = colour;
}

void Light::SetRadius(const float& radius){
    m_radius = radius;
}

//function
ostream& operator << (ostream& ostr, const Light& light){
    //15 cm red light is off
    string state = (light.m_on ? "on" : "off"); //conditional operator(simplified if else)
    ostr << light.m_radius << " cm " << light.m_colour << " light is " << state;
    return ostr;
}



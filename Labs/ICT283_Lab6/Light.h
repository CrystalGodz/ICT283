#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Light{
public:
    Light();
    virtual ~Light() {}     //destructor has no implementation now

    //void GetColour(string& colour) const;   correct way for objects
    string GetColour() const;               //allowable if string is small
    float GetRadius() const;
    bool IsOn() const;

    void SetColour(const string& colour);
    void SetRadius(const float& radius);

    friend ostream& operator << (ostream& ostr, const Light& light);

protected:
    string m_colour;
    float m_radius;
    bool m_on;
};


#endif // LIGHT_H_INCLUDED

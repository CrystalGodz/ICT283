#include "Result.h"

Result::Result(){
    m_mark = 0;
}

Result::Result(const Unit & unit, float mark){
    m_unit = unit;
    m_mark = mark;
}

//Get and Set Methods
float Result::GetMark() const{
    return m_mark;
}

void Result::GetUnit(Unit & unit) const{
    unit = m_unit;  //return by reference
}

void Result::SetMark(float mark){
    m_mark = mark;
}

void Result::SetUnit(Unit & unit){
    m_unit = unit;
}


//functions
ostream & operator <<( ostream & ostr, const Result & result ){
    ostr << result.m_unit << "  Marks  : " << result.m_mark;

    return ostr;
}

istream & operator >>( istream & input, Result & result ){
    input >> result.m_unit >> result.m_mark;

    return input;
}

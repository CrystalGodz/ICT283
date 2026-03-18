#include "Result.h"

Result::Result(){
    m_mark = 0;
}

Result::Result(const Unit& unit, const Date& date, float mark){
    m_unit = unit;
    m_date = date;
    m_mark = mark;
}

//Get and Set Methods
float Result::GetMark() const{
    return m_mark;
}

void Result::GetUnit(Unit& unit) const{
    unit = m_unit;  //return by reference
}

void Result::GetDate(Date& date) const{
    date = m_date;
}



void Result::SetMark(float mark){
    m_mark = mark;
}

void Result::SetUnit(const Unit& unit){
    m_unit = unit;
}

void Result::SetDate(const Date& date){
    m_date = date;
}



//functions
istream& operator >>(istream& input, Result& result){
    Unit tempUnit;
    Date tempDate;
    input >> tempUnit >> tempDate;
    result.SetUnit(tempUnit);
    result.SetDate(tempDate);

    string data;
    getline(input, data);
    result.SetMark(stoi(data));
    cout << result.GetMark() << "Mark" << endl;

    return input;
}

ostream& operator <<(ostream& ostr, const Result& result){
    Unit tempUnit;
    result.GetUnit(tempUnit);
    Date tempDate;
    result.GetDate(tempDate);

    ostr << tempUnit << "  Marks  : " << result.GetMark() << '\n' << tempDate;
    return ostr;
}

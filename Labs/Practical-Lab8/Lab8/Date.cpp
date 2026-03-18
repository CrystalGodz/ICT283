#include "Date.h"

Date::Date(){
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(unsigned day, unsigned month, unsigned year){
    m_day = day;
    m_month = month;
    m_year = year;
}

//Get methods
unsigned Date::GetDay() const{
    return m_day;
}
unsigned Date::GetMonth() const{
    return m_month;
}
unsigned Date::GetYear() const{
    return m_year;
}

//Set methods
void Date::SetDay(unsigned day){
    m_day = day;
}
void Date::SetMonth(unsigned month){
    if(month <= 12){
        m_month = month;
    }
}
void Date::SetYear(unsigned year){
    m_year = year;
}


istream& operator >>(istream& input, Date& date){
    char delimiter = '/';
    string data;
    getline(input, data, delimiter);
    date.SetDay(stoi(data));
    //cout << date.GetDay() << "Day" << endl; //check if day is properly converted

    getline(input, data, delimiter);
    date.SetMonth(stoi(data));
    //cout << date.GetMonth() << "Month" << endl; //check if month is properly converted

    getline(input, data);
    date.SetYear(stoi(data));
    //cout << date.GetYear() << "Year" << endl; //check if year is properly converted

    return input;
}

ostream& operator <<(ostream& os, const Date& date){
    os << "Date           : "
    << setw(2) << setfill('0') << date.GetDay() << "/"
    << setw(2) << setfill('0') << date.GetMonth() << "/"
    << date.GetYear() << '\n';

    return os;
}

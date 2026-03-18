#include "Time.h"

Time::Time(){
    m_hour = 0;
    m_minute = 0;
    m_second = 0;
}

Time::Time(unsigned hour, unsigned minute, unsigned second){
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}

//Get methods
unsigned Time::GetHour() const{
    return m_hour;
}

unsigned Time::GetMinute() const{
    return m_minute;
}

unsigned Time::GetSecond() const{
    return m_second;
}

//Set methods
void Time::SetHour(unsigned hour){
    if(hour < 24){
        m_hour = hour;
    }
}

void Time::SetMinute(unsigned minute){
    if(minute < 60){
        m_minute = minute;
    }
}

void Time::SetSecond(unsigned second){
    if(second < 60){
        m_second = second;
    }
}


istream& operator >>(istream& input, Time& time){
    char delimiter = ':';
    string data;
    getline(input, data, delimiter);
    time.SetHour(stoi(data));
    //cout << time.GetHour() << "Hour" << endl; //check if hour is properly converted

    getline(input, data, delimiter);
    time.SetMinute(stoi(data));
    //cout << time.GetMinute() << "Minute" << endl; //check if minute is properly converted

    getline(input, data);
    time.SetSecond(stoi(data));
    //cout << time.GetSecond() << "Second" << endl; //check if second is properly converted

    return input;
}

ostream& operator <<(ostream& os, const Time& time){
    os << "Time           : "
    << setw(2) << setfill('0') << time.GetHour() << ":"
    << setw(2) << setfill('0') << time.GetMinute() << ":"
    << setw(2) << setfill('0') << time.GetSecond() << '\n';

    return os;
}

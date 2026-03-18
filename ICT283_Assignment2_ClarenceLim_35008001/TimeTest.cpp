#include <iostream>

#include "Time.h"

using namespace std;

int main(){
    Time time1(10, 30, 24);
    cout << time1 << endl;

    cout << "Check if the get methods are correct.\n"
    << "Hour  : " << time1.GetHour() << '\n'
    << "Minute: " << time1.GetMinute() << '\n'
    << "Second: " << time1.GetSecond() << endl;

    Time time2;
    time2.SetHour(12);
    time2.SetMinute(55);
    time2.SetSecond(53);

    cout << "\nCheck if the set methods are correct.\n"
    << "Hour  : " << time2.GetHour() << '\n'
    << "Minute: " << time2.GetMinute() << '\n'
    << "Second: " << time2.GetSecond() << endl;
    cout << time2 << endl;

    return 0;
}

#include <iostream>

#include "Date.h"

using namespace std;

int main(){
    Date date1(10, 14, 2020);
    cout << date1 << endl;

    cout << "Check if the get methods are correct.\n"
    << "Day  : " << date1.GetDay() << '\n'
    << "Month: " << date1.GetMonth() << '\n'
    << "Year : " << date1.GetYear() << endl;

    Date date2;
    date2.SetDay(15);
    date2.SetMonth(10);
    date2.SetYear(2022);

    cout << "\nCheck if the set methods are correct.\n"
    << "Day  : " << date2.GetDay() << '\n'
    << "Month: " << date2.GetMonth() << '\n'
    << "Year : " << date2.GetYear() << endl;
    cout << date2 << endl;

    return 0;
}

#include <iostream>

using namespace std;

void Func1(int number); //pass by value
void Func2(int &number); //pass by reference
void Func3(const int &number); //pass by constant reference
void Func4(int *ptr); //pass by pointer

int main(){
    int num = 8;
    cout << " Initial num = " << num << endl;
    Func1(num);
    cout << "After Func1(), num = " << num << endl;
    Func2(num);
    cout << "After Func2(), num = " << num << endl;
    Func3(num);
    cout << "After Func3(), num = " << num << endl;
    Func4(&num); //&num is the address of num
    cout << "After Func4(), num = " << num << endl;

    return 0;
}

void Func1(int number){
    number = 10;
    cout << "   -- Func1(), number = " << number << endl;
}

void Func2(int &number){
    number = 11;
    cout << "   -- Func2(), number = " << number << endl;
}

void Func3(const int &number){
    //number = 12; // cannot modify a constant variable
    cout << "   -- Func3(), number = " << number << endl;
}

void Func4(int *ptr){
    *ptr = 13;
    cout << "   -- Func4(), *ptr = " << *ptr << endl;
}


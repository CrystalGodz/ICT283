#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int SIZE = 8;

typedef vector<int> IntVector;
typedef vector<IntVector> IntTable;         //a vector of vectors of integers

void Display(const IntVector& numbers);
void Display2(const IntVector& numbers);
void Display3(const IntVector& numbers);
void DisplayTable(const IntTable& table);

int main(){
    //0.data stored + init
    srand(time(NULL));                      //randomize with a changing "seed" with 'time'
    IntVector numbers;
    IntTable table;

    //1.Input
    for(int i=0; i < SIZE; i++){
        numbers.push_back(rand() % 100);    //0 to 99
    }

    for(int i=0; i < SIZE; i++){
        table.push_back(numbers);         //create a "SIZE x SIZE" 2D array, using the same array
    }   //makes a copy of numbers each time, using the copy constructor

    //to demonstrate each row is different
    table[0][0] *= -1;
    table[SIZE-1][SIZE-1] *= -1;


    //3.Output
    Display(numbers);
    cout << '\n' << endl;
    Display2(numbers);
    cout << '\n' << endl;
    Display3(numbers);

    cout << endl << endl;
    DisplayTable(table);

    return 0;
}


// type of for loops
void Display(const IntVector& numbers){
    cout << "[ ";
    for(unsigned i=0; i < SIZE; i++){
        cout << numbers[i] << " ";
    }
    cout << " ]";
}

void Display2(const IntVector& numbers){
    for(IntVector::const_iterator citer = numbers.begin(); citer != numbers.end(); citer++){
        cout << *citer << " - ";
    }
    cout << endl;
}

void Display3(const IntVector& numbers){
    for(int number: numbers){
        cout << number << ", ";
    }
    cout << endl;
}


void DisplayTable(const IntTable& table){
    for(unsigned row = 0; row < table.size(); row++){
        for(unsigned col = 0; col < table.size(); col++){
            cout << table[row][col] << " ";
        }
    }
    cout << endl;
}

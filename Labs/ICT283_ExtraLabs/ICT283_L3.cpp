#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 10;        //size of array
const int maxLength = 9;    //max length of number
const int END = -1;         //exit flag

typedef int IntArray[SIZE]; //a new type -> ab array of 10 integers

int Input(IntArray& numbers);
//return count and an array of numbers(by reference) from the user input

void Output(int size, const IntArray& numbers);
//numbers is read only

int main(){
    //0. Create the data store
    IntArray numbers;

    //1. Input
    int numberCount = Input(numbers);
    cout << "Number of items: " << numberCount <<endl;

    //2. Process - no further processes

    //3. Output
    Output(numberCount, numbers);

    return 0;
}

int Input(IntArray& numbers){
    cout << "Enter up to " << SIZE << " integers(9 digits in length), " << END << " to exit." << endl;

    int index = 0;
    int num;

    cout << "Number?\n";
    if((log10(num)+1) <= maxLength){
        cin >> num;
    }
    else{
        num = END;
        cin >> num;
    }

    while(num != END && index < SIZE){
        numbers[index] = num;
        index++;
        if(index < SIZE){
            cout << "Number?\n";
            if((log10(num)+1) <= maxLength){
                cin >> num;
            }
            else{
                num = END;
                cin >> num;
            }
        }
    }

    return index; //return the number of items entered
}

void Output(int size, const IntArray& numbers){
    cout << "Address of numbers: " << &numbers << endl;
    cout << "Contents of numbers: " << numbers << endl;

    for(int i = 0; i < size; i++){
        cout << "Address and contents of elements:\n " << i << " => " << &numbers[i] << " : " << numbers[i] <<endl;
    }
}

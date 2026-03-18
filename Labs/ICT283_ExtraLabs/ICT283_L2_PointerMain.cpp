#include <iostream>

using namespace std;

int main(){
    cout << " --Playing with pointers --" << endl;
    int *ptr = nullptr; //declare a pointer to an int
    //int *ptr;
    //ptr = nullptr;
    cout << "Addr of ptr: " << &ptr << endl;
    cout << "Contents of ptr: " << ptr << endl;

    ptr = new int; //attempt to allocate heap memory
    //every new must have a matching delete

    if(ptr != nullptr){ //if memory is sufficient
        *ptr = 1000; //store 1000 at location ptr is pointing to
        cout << "Value of *ptr: " << *ptr << endl;
        cout << "Contents of ptr after declaration of new: " << ptr << endl;
    }
    else{
        cout << "Unable to allocate, insufficient memory" << endl;
    }

    delete ptr; //return space to OS
    //matching delete for new
    ptr = nullptr; //prevent dangling pointers

    return 0;
}

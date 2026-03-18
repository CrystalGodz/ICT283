#include <iostream>

#include "Vector.h"

using namespace std;

int main(){
    Vector<int> Vector1;
    Vector1.Add(10);
    Vector1.Add(15);
    Vector1.Add(32);
    cout << "Size             : " << Vector1.GetSize() << endl;
    cout << "Capacity         : " << Vector1.GetCapacity() << endl;
    for(unsigned i=0; i < Vector1.GetSize(); i++){
        cout << Vector1[i] << endl;
    }

    Vector1.Insert(90, 2);
    cout << "Size aft insert1 : " << Vector1.GetSize() << endl;
    cout << "Capacity         : " << Vector1.GetCapacity() << endl;
    for(unsigned i=0; i < Vector1.GetSize(); i++){
        cout << Vector1[i] << endl;
    }

    Vector1.Delete(1);
    cout << "Size aft delete  : " << Vector1.GetSize() << endl;
    cout << "Capacity         : " << Vector1.GetCapacity() << endl;
    for(unsigned i=0; i < Vector1.GetSize(); i++){
        cout << Vector1[i] << endl;
    }

    Vector1.Insert(72, 3);
    cout << "Size aft insert2 : " << Vector1.GetSize() << endl;
    cout << "Capacity         : " << Vector1.GetCapacity() << endl;
    for(unsigned i=0; i < Vector1.GetSize(); i++){
        cout << Vector1[i] << endl;
    }

    Vector1.Modify(30, 3);
    cout << "Size aft modify  : " << Vector1.GetSize() << endl;
    cout << "Capacity         : " << Vector1.GetCapacity() << endl;
    for(unsigned i=0; i < Vector1.GetSize(); i++){
        cout << Vector1[i] << endl;
    }

    Vector1.Remove();
    cout << "Size aft remove  : " << Vector1.GetSize() << endl;
    cout << "Capacity         : " << Vector1.GetCapacity() << endl;
    for(unsigned i=0; i < Vector1.GetSize(); i++){
        cout << Vector1[i] << endl;
    }

    Vector1.Add(93);
    Vector1.Add(29);
    cout << "Size             : " << Vector1.GetSize() << endl;
    cout << "Capacity         : " << Vector1.GetCapacity() << endl;
    for(unsigned i=0; i < Vector1.GetSize(); i++){
        cout << Vector1[i] << endl;
    }

    cout << "Value of Array[4]: " << Vector1.At(4) << endl;

    Vector<int> Vector2;
    Vector2 = Vector1;
    for(unsigned i=0; i < Vector2.GetSize(); i++){
        cout << Vector2[i] << endl;
    }
    return 0;
}

#include <iostream>

#include "Light.h"

//Need to pass in "Light &light":
//As plainly Test1()... would not contain the previous local variable
//Such as light.SetColor("red")
void Test1(Light &light);
void Test2(Light &light);
void Test3(Light &light);
void Test4(Light &light);

int main(){
    cout << "Light Test" << endl;
    Light light;
    Test1(light);
    Test1(light);
    Test1(light);
    Test1(light);

    return 0;
}


void Test1(Light &light){
    cout << "== Test 1 (Construction) ==" << endl;
    cout << light << endl;
    cout << endl;
}

void Test2(Light &light){
    cout << "== Test 2 (SetColor as red) ==" << endl;
    light.SetColour("red");
    cout << light << endl;
    cout << endl;
}

void Test3(Light &light){
    cout << "== Test 3 (SetRadius to -9.3) ==" << endl;
    if(!light.SetRadius(-9.3)){
        cout << "Radius must be > 0" << endl;
    }
    cout << light << endl;
    cout << endl;
}

void Test4(Light &light){
    cout << "== Test 4 (SetRadius to +9.3) ==" << endl;
    if(!light.SetRadius(9.3)){
        cout << "Radius must be > 0" << endl;
    }
    cout << light << endl;
    cout << endl;
}

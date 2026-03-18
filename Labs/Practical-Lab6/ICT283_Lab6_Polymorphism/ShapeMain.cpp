#include <iostream>
#include <string>

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"

using std::cout;
using std::endl;
using std::string;

int main(){
    /*
    ::Fails to compile as it is abstract::
    Shape myShape;
    string description
    myShape. GetDescription(description);
    */

    Square mySquare;
    cout << mySquare.area() << endl;

    Rectangle myRectangle;
    cout << myRectangle.area() << endl;

    return 0;
}

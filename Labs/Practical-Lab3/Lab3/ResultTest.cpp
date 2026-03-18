#include <iostream>
#include "Result.h"
#include "Unit.h"

using namespace std;

int main(){
    Unit myUnit("Data Structures", "ICT283", 3);

    cout << "--- 1. Construct Result Object ---" << endl;
    Result myResult(myUnit, 88.8);
    cout << myResult << endl;

    cout << "--- 2. Retrieve unit from Result Object ---" << endl;
    Unit tempUnit;
    myResult.GetUnit(tempUnit);
    cout << tempUnit << endl;

    return 0;
}

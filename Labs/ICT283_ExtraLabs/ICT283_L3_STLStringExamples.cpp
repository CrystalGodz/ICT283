#include <iostream>
#include <string> //STL string

using namespace std;

int main(){
    string name = "King Kong";
    name = "Bundy";

    cout << name << endl;

    string name2 = "Bundy";

    if(name == name2){
        cout << "Both names are the same" << endl;
    }

    string name3 = "Donkey Kong";
    cout << name3[5] << endl; //y
    cout << name3[12] << endl; //no bounds checking(maximum index is 10)

    return 0;
}

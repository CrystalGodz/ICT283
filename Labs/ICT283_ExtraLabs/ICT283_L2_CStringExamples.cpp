#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 10;
typedef char StringType[SIZE + 1];

int main(){
    StringType str1 = "Mountain";
    cout << str1 << endl;
    cout << strlen(str1) << endl;

    //manipulates a single character of a string
    str1[4] = toupper(str1[4]);
    cout << str1 << endl;

    //appends characters after str1[1] into null characters
    str1[1] = '\0';
    cout << str1 << endl;
    /**
    Output:
    M
    */

    //Change the string output for 'C-String' type string
    strcpy(str1, "Bukit");
    cout << str1 << endl;

    //example to show that it does not append a null character after 3 letters.
    strncpy(str1, "Mummy", 3);
    cout << str1 << endl;
    /**
    Output:
    Mumit
    */

    return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 10;
typedef char StringType[SIZE + 1];

int main(){
    StringType str1 = "This is history";
    StringType str2 = "is";

    int numOfOccurences = Count(srr1, str2);
    cout << "There are " << numOfOccurences << " " << str2 << ",";

    return 0;
}

int Count(const StringType &str1, const Stringtype &str2){
    int counter = 0;

    //Prime the while loop by looking for a first occurrence
    char *ptr = strstr(str1, str2);

    //While we find an occurrence of str2 in str1
    while(ptr != NULL){
        counter++
        cout << "ptr is now pointing to the start of: " << ptr << endl;
        ptr++; //go to the next char in str1
        /*
        without 'ptr++' it will go into an infinite loop
        **/
        cout << "--> after ptr++, ptr is now pointing to the start of: " << ptr << endl;
        ptr = strstr(ptr,str2);
    }
}

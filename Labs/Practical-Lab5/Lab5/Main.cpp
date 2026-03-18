#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <sstream>

#include "Date.h"
#include "Time.h"
#include "Vector.h"

using namespace std;
using std::string;

typedef struct{
    Date d;
    Time t;
    float speed;
} WindRecType;

typedef Vector<WindRecType> WindlogType;

int main(){
    ifstream infile("data/MetData-31-3.csv");
    if(!infile){
        return -1;
    }

    Vector<string> FieldArray;
    char delimiter = ',';
    string data;
    getline(infile, data);
    istringstream FieldStream(data);
    for(string curr; getline(FieldStream, curr, delimiter); FieldArray.Add(curr));

    unsigned WASTIndex;
    unsigned SIndex;
    for(unsigned i = 0; i<FieldArray.GetSize(); i++){
        if(FieldArray[i] == "WAST"){
            WASTIndex = i;
        }
        else if(FieldArray[i] == "S"){
            SIndex = i;
        }
    }

    WindlogType WindData;
    string currLine;
    while(getline(infile,currLine)){
        Vector<string> DataArray;
        istringstream DataStream(currLine);
        for(string curr; getline(DataStream, curr, delimiter); DataArray.Add(curr));

        WindRecType ThisWindRecord;

        string WAST = DataArray[WASTIndex];
        //cout << WAST << endl;
        istringstream WASTStream(WAST);
        string Date;
        string Time;
        getline(WASTStream, Date, ' ');
        getline(WASTStream, Time);
        cout << Date << endl;
        cout << Time << endl;
        istringstream DateStream(Date);
        istringstream TimeStream(Time);
        DateStream >> ThisWindRecord.d;
        TimeStream >> ThisWindRecord.t;
        ThisWindRecord.speed = stof(DataArray[SIndex]);
        WindData.Add(ThisWindRecord);

        cout << ThisWindRecord.d << ThisWindRecord.t << "Speed: " << ThisWindRecord.speed << endl;
    }

    ofstream ofile("data/OutputTest.csv");

    return 0;
}

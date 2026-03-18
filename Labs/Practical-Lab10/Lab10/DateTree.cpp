#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>

#include "Bst.h"
#include "Date.h"

using namespace std;
using std::string;

typedef struct{
    Date d;
} WindRecType;

typedef Bst<int> DateTree;
typedef multimap<int, WindRecType> DateMap;
typedef vector<WindRecType> DateLog;

int main(){
    DateTree date_tree;
    DateMap date_map;
    ifstream sourceFile("data/MetData_Jan01-2010-Jan01-2011-ALL.csv");
    if(!sourceFile){
        cout << "Source file not found." << endl;
        return -1;
    }

    string data;
    getline(sourceFile, data);
    vector<string> FieldArray;
    char delimiter = ',';
    istringstream FieldStream(data);
    for(string curr; getline(FieldStream, curr, delimiter); FieldArray.push_back(curr));

    //Define Indexes
    unsigned WASTIndex;
    for(unsigned i = 0; i<FieldArray.size(); i++){
        if(FieldArray[i] == "WAST"){
            WASTIndex = i;
        }
    }

    string currLine;
    while(getline(sourceFile,currLine)){
        vector<string> DataArray;
        istringstream DataStream(currLine);
        for(string curr; getline(DataStream, curr, delimiter); DataArray.push_back(curr));

        WindRecType ThisWindRecord;
        string WAST = DataArray[WASTIndex];
        istringstream WASTStream(WAST);
        string Date;
        getline(WASTStream, Date, ' ');
        istringstream DateStream(Date);
        try{
            DateStream >> ThisWindRecord.d;
            int MapKey = ThisWindRecord.d.GetDay() + ThisWindRecord.d.GetMonth()*100 + ThisWindRecord.d.GetYear()*10000;
            date_tree.Insert(MapKey);
            date_map.insert({MapKey, ThisWindRecord});
        }
        catch(const invalid_argument& err){
            cout << "Invalid record in: " << data << endl;
        }
    }
    sourceFile.close();

    for(auto i = date_map.begin(); i != date_map.end(); i++){
        cout << "Key: " << i->first << '\n' << i->second.d << endl;
    }

    return 0;
}

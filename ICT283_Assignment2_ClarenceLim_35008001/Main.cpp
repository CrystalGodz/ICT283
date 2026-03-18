#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <map>

#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "Bst.h"

using namespace std;
using std::string;

typedef struct{
    Date d;
    Time t;
    float speed = 0.0;
    float airTemp = 0.0;
    float solarRad = 0.0;
} WindRecType;

typedef Vector<WindRecType> WindLogType;
typedef Bst<int64_t> WindTreeType;
typedef map<int64_t, WindRecType> WindMapType;

//Main class method declaration
unsigned UserInput(); //Get user input
bool ValidMonth(unsigned month); //Check if month is valid
string ConvertMonth(unsigned month); //Convert Numerical month to string month
unsigned MatchMonth(int64_t key); //Retrieves matching month from unique key
bool ValidYear(unsigned year); // Check if year is valid
unsigned MatchYear(int64_t key); //Retrieves matching year from unique key

float MsToKmh(float& speed); //Convert M/s to Km/h
float SumOfSpeed(const WindLogType& Log); //Calculate sum of speed
float SpeedSD(const WindLogType& Log, float& mean); //Calculate Standard Deviation of speed
string CalculateAverageSpeed(WindLogType& Log, string& month, unsigned& year); //Calculate average speed
void Option1(const WindMapType& windMap); //Menu option 1

float SumOfTemperature(const WindLogType& Log); //Calculate sum of temperature
float TemperatureSD(const WindLogType& Log, float& mean); //Calculate Standard Deviation of temperature
string CalculateAverageTemp(WindLogType& Log, string& month); //Calculate average temperature
void Option2(const WindMapType& windMap); //Menu option 2

float WhTokWh(float& solarRad); //Convert W/h to kW/h
float SumOfRadiation(const WindLogType& Log); //Calculate sum of solar radiation
string CalculatesPCC(WindLogType& Log, string& month); //Calculate sPCC
void Option3(const WindMapType& windMap); //Menu option 3

string CalculateOutput(WindLogType& Log, string& month); //Calculate output data
void Option4(const WindMapType& windMap, const WindTreeType& windTree); //Menu option 4

int64_t GenerateKey(WindRecType& Record); //Method to generate the unique key for BST to Map
void LoadData(WindMapType& windMap, WindTreeType& windTree); //Method to load data into map and tree array.

//main() Method
int main(){
    WindMapType WindMap;
    WindTreeType WindTree;
    LoadData(WindMap, WindTree);
    //used to exit program if there is a failure to load file into map
    if(WindMap.size() <= 0){
        return -1;
    }

    //Menu interface
    int MenuOp = 0;
    cout << "Please Select From 1 to 5 To Start." << '\n';
    while(MenuOp != 5){
        if(MenuOp == 0){
            cout
            << "<1> Calculate Average Wind Speed for The Selected Month & Year With(Sample SD).\n"
            << "<2> Calculate Average Ambient Air Temperature for Each Month of Selected Year with(Sample SD).\n"
            << "<3> Calculate Sample Pearson Correlation Coefficient for All Years of Selected Month.\n"
            << "<4> Output Average Wind and Temperature Of Specified Month & Year with(SD/MAD) & Total Radiation to 'WindTempSolar.csv'.\n"
            << "<5> Exit The Program.\n" << endl;
        }
        MenuOp = UserInput();
        if(MenuOp == 1){
            Option1(WindMap);
            MenuOp = 0;
        }
        else if(MenuOp == 2){
            Option2(WindMap);
            MenuOp = 0;
        }
        else if(MenuOp == 3){
            Option3(WindMap);
            MenuOp = 0;
        }
        else if(MenuOp == 4){
            Option4(WindMap, WindTree);
            MenuOp = 0;

        }
        else if(MenuOp == 5){
            cout << "\nThank You For Using My Service." << endl;
            break;
        }
        else{
            cout << "\nInvalid Selection, Select a number from 1 to 5." <<endl;
            MenuOp = 0;
        }
    }

    return 0;
}


unsigned UserInput(){
    bool InputOk = false;
    unsigned IntegerInput = 0;
    while(!InputOk){
        cin >> IntegerInput;
        if(cin.fail()){
            InputOk = false;
            cin.clear();
            cin.ignore(999, '\n');
            IntegerInput = 0;
        }
        InputOk = true;
    }
    return IntegerInput;
}


bool ValidMonth(unsigned month){
    if(month > 0 && month < 13){
        return true;
    }
    else{
        return false;
    }
}


string ConvertMonth(unsigned month){
    string ThisMonth;
    if(month == 1){
        ThisMonth = "January  ";
    }
    else if(month == 2){
        ThisMonth = "February ";
    }
    else if(month == 3){
        ThisMonth = "March    ";
    }
    else if(month == 4){
        ThisMonth = "April    ";
    }
    else if(month == 5){
        ThisMonth = "May      ";
    }
    else if(month == 6){
        ThisMonth = "June     ";
    }
    else if(month == 7){
        ThisMonth = "July     ";
    }
    else if(month == 8){
        ThisMonth = "August   ";
    }
    else if(month == 9){
        ThisMonth = "September";
    }
    else if(month == 10){
        ThisMonth = "October  ";
    }
    else if(month == 11){
        ThisMonth = "November ";
    }
    else{
        ThisMonth = "December ";
    }
    return ThisMonth;
}


unsigned MatchMonth(int64_t key){
    unsigned month = 0;
    month = (key%10000)/100;
    return month;
}


bool ValidYear(unsigned year){
    if(year > 1999 && year <= 2099){
        return true;
    }
    else{
        return false;
    }
}


unsigned MatchYear(int64_t key){
    unsigned year = 0;
    year = (key%100) + 2000; //Assumption for this program is that the key is only unique for 100 years
    return year;
}


float MsToKmh(float& speed){
    speed = speed * 3.6;
    return speed;
}


float SumOfSpeed(const WindLogType& Log){
    float sum = 0.0;
    for(WindRecType each : Log){
        sum += each.speed;
    }
    return sum;
}


float SpeedSD(const WindLogType& Log, float& mean){
    float SDBeforeSqrt = 0.0;
    float SD = 0.0;
    for(WindRecType each : Log){
        SDBeforeSqrt += pow((each.speed - mean), 2);
    }
    SD = sqrt(SDBeforeSqrt/Log.GetSize());
    return SD;
}


string CalculateAverageSpeed(WindLogType& Log, string& month, unsigned& year){
    stringstream output;

    //Calculate Average
    float AvgSpeed = SumOfSpeed(Log)/Log.GetSize();
    //Calculate Standard Deviation
    float SD = SpeedSD(Log, AvgSpeed);

    output << '\n' << month << ", " << year << ":\n"
    << "Average speed : " << fixed << setprecision(2) << AvgSpeed << "km/h\n"
    << "Sample SD     : " << fixed << setprecision(2) << SD << "km/h\n"
    << "End\n";

    return output.str();
}


void Option1(const WindMapType& windMap){
    unsigned MonthInput = 0;
    string SelectedMonth = "";
    unsigned YearInput = 0;

    cout << "\nEnter Month(Numerical):" << endl;
    MonthInput = UserInput();
    while(!ValidMonth(MonthInput)){
        cout << "\nThe Month You Entered Is Invalid, Try Again.\n" << endl;
        unsigned TempMonth;
        TempMonth = UserInput();
        ValidMonth(TempMonth);
        if(ValidMonth){
            MonthInput = TempMonth;
        }
    }
    SelectedMonth = ConvertMonth(MonthInput);
    cout << "\nEnter Year:" << endl;
    YearInput = UserInput();
    while(!ValidYear(YearInput)){
        cout << "\nThe Year Can Only Be From 2000 To 2099, Try Again.\n" << endl;
        unsigned TempYear;
        TempYear = UserInput();
        ValidYear(TempYear);
        if(ValidYear){
            YearInput = TempYear;
        }
    }

    WindLogType RequestedSpeedInfo;

    for(auto i = windMap.begin(); i != windMap.end(); i++){
        WindRecType record = i->second;
        if(MatchMonth(i->first) == MonthInput && MatchYear(i->first) == YearInput){
            MsToKmh(record.speed);
            RequestedSpeedInfo.Add(record);
        }
    }

    if(RequestedSpeedInfo.GetSize() == 0){
        cout << '\n' << SelectedMonth << " " << YearInput << ": No Data\n"
        << "End\n" << endl;
    }
    else{
        cout << CalculateAverageSpeed(RequestedSpeedInfo, SelectedMonth, YearInput) << endl;
        RequestedSpeedInfo.Clear();
    }
}


float SumOfTemperature(const WindLogType& Log){
    float sum = 0.0;
    for(WindRecType each : Log){
        sum += each.airTemp;
    }
    return sum;
}


float TemperatureSD(const WindLogType& Log, float& mean){
    float SDBeforeSqrt = 0.0;
    float SD = 0.0;
    for(WindRecType each : Log){
        SDBeforeSqrt += pow((each.airTemp - mean), 2);
    }
    SD = sqrt(SDBeforeSqrt/Log.GetSize());
    return SD;
}


string CalculateAverageTemp(WindLogType& Log, string& month){
    stringstream output;

    //Calculate Average
    float AvgTemperature = SumOfTemperature(Log)/Log.GetSize();
    //Calculate Standard Deviation
    float SD = TemperatureSD(Log, AvgTemperature);

    output << month << ":\n"
    << "  Average temperature : " << fixed << setprecision(2) << AvgTemperature << " degrees\n"
    << "  Sample SD           : " << fixed << setprecision(2) << SD << " degrees\n";

    return output.str();
}


void Option2(const WindMapType& windMap){
    unsigned YearInput = 0;
    unsigned MonthIndex = 0;
    string CurrMonth = "";

    cout << "\nEnter Year:" << endl;
    YearInput = UserInput();
    while(!ValidYear(YearInput)){
        cout << "\nThe Year Can Only Be From 2000 To 2099, Try Again.\n" << endl;
        unsigned TempYear;
        TempYear = UserInput();
        ValidYear(TempYear);
        if(ValidYear){
            YearInput = TempYear;
        }
    }
    WindLogType RequestedTemperatureInfo;
    cout << '\n' << YearInput  << ":" << endl;
    for(MonthIndex = 1; MonthIndex < 13; MonthIndex++){
        for(unsigned i = RequestedTemperatureInfo.GetSize(); i > 0; i--){
            RequestedTemperatureInfo.Remove();
        }
        for(auto i = windMap.begin(); i != windMap.end(); i++){
            WindRecType record = i->second;
            if(MatchYear(i->first) == YearInput){
                RequestedTemperatureInfo.Add(record);
            }
        }
        CurrMonth = ConvertMonth(MonthIndex);
        if(RequestedTemperatureInfo.GetSize() == 0){
            cout << CurrMonth << ": No Data\n" << endl;
        }
        else{
            cout << CalculateAverageTemp(RequestedTemperatureInfo, CurrMonth) << endl;
        }
    }
    RequestedTemperatureInfo.Clear();
    cout << "End\n" << endl;
}


float WhTokWh(float& solarRad){
    solarRad = solarRad/1000;
    return solarRad;
}


float SumOfRadiation(const WindLogType& Log){
    float sum = 0.0;
    for(WindRecType each : Log){
        if(each.solarRad >= 0.1){
            sum += (each.solarRad / 3600);
        }
    }
    return sum;
}


string CalculatesPCC(WindLogType& Log, string& month){
    stringstream output;
    output << fixed << setprecision(2);

    float S_T = 0.0;
    float S_R = 0.0;
    float T_R = 0.0;
    float spdDev2 = 0.0;
    float tempDev2 = 0.0;
    float radDev2 = 0.0;
    float numOfS_T = 0.0;
    float numOfS_R = 0.0;
    float numOfT_R = 0.0;

    //Calculate Average
    float AvgSpd = SumOfSpeed(Log)/Log.GetSize();
    float AvgTemp = SumOfTemperature(Log)/Log.GetSize();
    float AvgRad = SumOfRadiation(Log)/Log.GetSize();

    for(unsigned i = 0; i < Log.GetSize(); i++){
        //Calculate Deviation
        float spdDev = Log.At(i).speed - AvgSpd;
        float tempDev = Log.At(i).airTemp - AvgTemp;
        float radDev = Log.At(i).solarRad - AvgRad;

        S_T += spdDev*tempDev;
        S_R += spdDev*radDev;
        T_R += tempDev*radDev;

        //Calculate sum of deviation^2
        spdDev2 += spdDev*spdDev;
        tempDev2 += tempDev*tempDev;
        radDev2 += radDev*radDev;

        //Calculate numerators
        numOfS_T += spdDev*tempDev;
        numOfS_R += spdDev*radDev;
        numOfT_R += tempDev*radDev;
    }
    //Calculate Denominators
    float denoOfS_T = sqrt(spdDev2)*sqrt(tempDev2);
    float denoOfS_R = sqrt(spdDev2)*sqrt(radDev2);
    float denoOfT_R = sqrt(tempDev2)*sqrt(radDev2);

    //Calculate Sample Pearson Correlation Coefficient
    float sPCCofS_T = numOfS_T/denoOfS_T;
    float sPCCofS_R = numOfS_R/denoOfS_R;
    float sPCCofT_R = numOfT_R/denoOfT_R;


    output << "  Sample Pearson Correlation Coefficient for " << month << ":\n"
    << "   Speed_Temperature:\n    " << sPCCofS_T << '\n'
    << "   Speed_Radiation:\n    " << sPCCofS_R << '\n'
    << "   Radiation_Temperature:\n    " << sPCCofT_R << '\n';

    return output.str();
}


void Option3(const WindMapType& windMap){
    unsigned MonthInput = 0;
    string CurrMonth = "";

    cout << "\nEnter Month(Numerical):" << endl;
    MonthInput = UserInput();
    while(!ValidMonth(MonthInput)){
        cout << "\nThe Month You Entered Is Invalid, Try Again.\n" << endl;
        unsigned TempMonth;
        TempMonth = UserInput();
        ValidMonth(TempMonth);
        if(ValidMonth){
            MonthInput = TempMonth;
        }
    }
    WindLogType RequestedsPCC;
    for(auto i = windMap.begin(); i != windMap.end(); i++){
        WindRecType record = i->second;
        if(MatchMonth(i->first) == MonthInput){
            MsToKmh(record.speed);
            WhTokWh(record.solarRad);
            RequestedsPCC.Add(record);
        }
    }
    CurrMonth = ConvertMonth(MonthInput);
    if(RequestedsPCC.GetSize() == 0){
        cout << CurrMonth << ": No Data\n" << endl;
    }
    else{
        cout << CalculatesPCC(RequestedsPCC, CurrMonth) << endl;
    }
    RequestedsPCC.Clear();
    cout << "End\n" << endl;
}


string CalculateOutput(WindLogType& Log, string& month){
    stringstream output;
    output << month << ',' << fixed << setprecision(2);

    //Calculate Average
    float AvgSpd = SumOfSpeed(Log)/Log.GetSize();
    float AvgTemp = SumOfTemperature(Log)/Log.GetSize();

    //Calculate Standard Deviation
    float SpdSD = SpeedSD(Log, AvgSpd);
    float TempSD = TemperatureSD(Log, AvgTemp);

    //Calculate Total Radiation
    float TotalRad = SumOfRadiation(Log);

    float SpdAbsDev = 0.0;
    float TempAbsDev = 0.0;
    for(unsigned i = 0; i < Log.GetSize(); i++){
        //Calculate Total Absolute Deviation
        SpdAbsDev += abs(Log.At(i).speed - AvgSpd);
        TempAbsDev += abs(Log.At(i).airTemp - AvgTemp);
    }
    //Calculate Mean Absolute Deviation
    float SpdMAD = SpdAbsDev/Log.GetSize();
    float TempMAD = TempAbsDev/Log.GetSize();

    if(AvgSpd > 0){
        output << AvgSpd << '(' << SpdSD << '/' << SpdMAD << "),";
    }
    else{
        output << ',';
    }
    if(AvgTemp > 0){
        output << AvgTemp << '(' << TempSD << '/' << TempMAD << "),";
    }
    else{
        output << ',';
    }
    if(TotalRad > 0){
        output << fixed << setprecision(4) << TotalRad;
    }

    return output.str();
}


void Option4(const WindMapType& windMap, const WindTreeType& windTree){
    unsigned YearInput = 0;
    unsigned MonthIndex = 0;
    string CurrMonth = "";
    ofstream outFile("data/WindTempSolar.csv");

    cout << "\nEnter Year:" << endl;
    YearInput = UserInput();
    while(!ValidYear(YearInput)){
        cout << "\nThe Year Can Only Be From 2000 To 2099, Try Again.\n" << endl;
        unsigned TempYear;
        TempYear = UserInput();
        ValidYear(TempYear);
        if(ValidYear){
            YearInput = TempYear;
        }
    }
    if(outFile.is_open()){
        outFile << YearInput << endl;
        WindLogType OutputRequestData;
        for(MonthIndex = 1; MonthIndex < 13; MonthIndex++){
            for(unsigned i = OutputRequestData.GetSize(); i > 0; i--){
                OutputRequestData.Remove();
            }
            for(auto m = windMap.begin(); m != windMap.end(); m++){
                WindRecType record = m->second;
                if(MatchMonth(m->first) == MonthIndex && MatchYear(m->first) == YearInput){
                    if(windTree.Search(m->first)){
                        MsToKmh(record.speed);
                        WhTokWh(record.solarRad);
                        OutputRequestData.Add(record);
                    }
                }
            }
            CurrMonth = ConvertMonth(MonthIndex);
            if(OutputRequestData.GetSize() > 0){
                outFile << CalculateOutput(OutputRequestData, CurrMonth) << endl;
            }
        }
        cout << "The Data Have Been Saved In: 'WindTempSolar.csv'\n" << endl;
    }
    else{
        cout << "There Was An Error Opening The File, Please Try Again.\n" << endl;
    }

    /**
    //The intended method to retrieve the data if my key generation was sorted by year
    //The plan was to retrieve the data by matching a range of keys
    if(outFile.is_open()){
        outFile << YearInput << endl;
        WindLogType OutputRequestData;
        for(MonthIndex = 1; MonthIndex < 13; MonthIndex++){
            for(unsigned i = OutputRequestData.GetSize(); i > 0; i--){
                OutputRequestData.Remove();
            }
            for(int64_t k = ((YearInput%100)*10000000 + MonthIndex*100000); k < ((YearInput%100)*10000000 + (MonthIndex+1)*100000 - 1) ;k++){
                if(windTree.Search(k)){
                    for(auto m = windMap.begin(); m != windMap.end(); m++){
                        WindRecType record = m->second;
                        if(m->first == k){
                            MsToKmh(record.speed);
                            WhTokWh(record.solarRad);
                            OutputRequestData.Add(record);
                        }
                    }
                }
            }
            CurrMonth = ConvertMonth(MonthIndex);
            if(OutputRequestData.GetSize() > 0){
                outFile << CalculateOutput(OutputRequestData, CurrMonth) << endl;
            }
        }
        cout << "The Data Have Been Saved In: 'WindTempSolar.csv'\n" << endl;
    }
    else{
        cout << "There Was An Error Opening The File, Please Try Again.\n" << endl;
    }
    */
}


int64_t GenerateKey(WindRecType& Record){
    int64_t FormatYear = 0;
    int64_t YearMonthKey = 0;
    int64_t DayTimeKey = 0;
    int64_t Key = 0;

    FormatYear = Record.d.GetYear()%100;

    //Original Key Calculation that causes my program to crash from a possible overflow of data.
    //Key = FormatYear*10000000 + Record.d.GetMonth()*100000 + Record.d.GetDay()*1000 + Record.t.GetHour()*10+ Record.t.GetMinute()/10;
    YearMonthKey = FormatYear + Record.d.GetMonth()*100;
    DayTimeKey = Record.d.GetDay()*100000000 + Record.t.GetHour()*1000000+ Record.t.GetMinute()*10000;
    Key = YearMonthKey + DayTimeKey;

    return Key;
}


void LoadData(WindMapType& windMap, WindTreeType& windTree){
    ifstream sourceFile("data/data_source.txt");
    if(!sourceFile){
        cout << "Source file not found." << endl;
        return;
    }

    string sourceLine;
    int Count = 0;
    while(getline(sourceFile, sourceLine)){
        ifstream dataFile("data/" + sourceLine);
        if(sourceLine == ""){
            continue;
        }
        else if(!dataFile){
            cout << "Data file not found." << endl;
            return;
        }

        cout << "Currently Reading file: " << sourceLine << endl;
        Vector<string> FieldArray;
        char delimiter = ',';
        string data;
        getline(dataFile, data);
        istringstream FieldStream(data);
        for(string curr; getline(FieldStream, curr, delimiter); FieldArray.Add(curr));

        //Define Indexes
        unsigned WASTIndex;
        unsigned SIndex;
        unsigned TIndex;
        unsigned SRIndex;
        for(unsigned i = 0; i<FieldArray.GetSize(); i++){
            if(FieldArray[i] == "WAST"){
                WASTIndex = i;
            }
            else if(FieldArray[i] == "S"){
                SIndex = i;
            }
            else if(FieldArray[i] == "T"){
                TIndex = i;
            }
            else if(FieldArray[i] == "SR"){
                SRIndex = i;
            }
        }

        string currLine;
        while(getline(dataFile,currLine)){
            if(currLine == ""){
                continue;
            }
            Vector<string> DataArray;
            istringstream DataStream(currLine);
            for(string curr; getline(DataStream, curr, delimiter); DataArray.Add(curr));

            int64_t MapKey;
            WindRecType ThisWindRecord;
            string WAST = DataArray[WASTIndex];
            istringstream WASTStream(WAST);
            string Date;
            string Time;
            getline(WASTStream, Date, ' ');
            getline(WASTStream, Time);
            istringstream DateStream(Date);
            istringstream TimeStream(Time);
            try{
                DateStream >> ThisWindRecord.d;
                TimeStream >> ThisWindRecord.t;
            }
            catch(const invalid_argument& err){
                cout << "Invalid record in: " << sourceLine << "\nData: " << DataArray[WASTIndex] << endl;
            }
            try{
                ThisWindRecord.speed = stof(DataArray[SIndex]);
            }
            catch(const invalid_argument& err){
                cout << "Invalid speed record conversion in: " << sourceLine << "\nData: " << endl;
            }

            try{
                ThisWindRecord.airTemp = stof(DataArray[TIndex]);
            }
            catch(const invalid_argument& err){
                cout << "Invalid air temperature record conversion in: " << sourceLine << "\nData: " << DataArray[TIndex] << "\nWAST: " << WAST << endl;
            }

            try{
                ThisWindRecord.solarRad = stof(DataArray[SRIndex]);
            }
            catch(const invalid_argument& err){
                cout << "Invalid solar radiation record conversion in: " << sourceLine << "\nData: " << DataArray[SRIndex] << "\nWAST: " << WAST << endl;
            }
            //Generate a unique key as a link between BST and map using WAST.
            try{
                MapKey = GenerateKey(ThisWindRecord);
            }
            catch(const invalid_argument& err){
                cout << "Key Generation Failed: " << sourceLine << "\nData: " << DataArray[WASTIndex] << endl;
            }
            //For debugging check
            if(windTree.Search(MapKey)){
                Count++;
            }
            windTree.Insert(MapKey);
            windMap.insert({MapKey, ThisWindRecord});
        }
        dataFile.close();
    }
    sourceFile.close();

    //For visual debugging
    cout << "WindMap Size: " << windMap.size() << "\nData Duplicates:" << Count << endl;
}

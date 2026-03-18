#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>

#include "Date.h"
#include "Time.h"
#include "Vector.h"

using namespace std;
using std::string;

typedef struct{
    Date d;
    Time t;
    float speed;
    float airTemp;
    float solarRad;
} WindRecType;
typedef Vector<WindRecType> WindlogType;

//Main class method declaration
unsigned UserInput(); //Get user input
bool ValidMonth(unsigned month); //Check if month is valid
string ConvertMonth(unsigned month); //Convert Numerical month to string month
float MsToKmh(float& speed); //Convert M/s to Km/h
float SumOfSpeed(const WindlogType& log); //Calculate sum of speed
float SpeedSD(const WindlogType& log, float& mean); //Calculate Standard Deviation of speed
void AverageWindSpeed(const WindlogType& log); //Menu option1
float SumOfTemperature(const WindlogType& log); //Calculate sum of temperature
float TemperatureSD(const WindlogType& log, float& mean); //Calculate Standard Deviation of temperature
void AverageAirTemp(const WindlogType& log); //Menu option2
float WhTokWh(float& solarRad); //Convert W/h to kW/h
float SumOfRadiation(const WindlogType& log); //Calculate sum of solar radiation
void TotalSolarRad(const WindlogType& log); //Menu option3
void OutputData(const WindlogType& log); //Menu option4

//main() Method
int main(){
    ifstream sourceFile("data/data_source.txt");
    if(!sourceFile){
        cout << "Source file not found." << endl;
        return -1;
    }
    string sourceLine;
    getline(sourceFile, sourceLine);
    ifstream dataFile("data/" + sourceLine);
    if(!dataFile){
        cout << "Data file not found." << endl;
        return -1;
    }

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

    WindlogType WindData;
    string currLine;
    while(getline(dataFile,currLine)){
        Vector<string> DataArray;
        istringstream DataStream(currLine);
        for(string curr; getline(DataStream, curr, delimiter); DataArray.Add(curr));

        WindRecType ThisWindRecord;

        string WAST = DataArray[WASTIndex];
        //cout << WAST << endl;     //check for proper data retrieval
        istringstream WASTStream(WAST);
        string Date;
        string Time;
        getline(WASTStream, Date, ' ');
        getline(WASTStream, Time);
        //cout << Date << endl;       //check for proper data retrieval
        //cout << Time << endl;       //check for proper data retrieval
        istringstream DateStream(Date);
        istringstream TimeStream(Time);
        DateStream >> ThisWindRecord.d;
        TimeStream >> ThisWindRecord.t;
        ThisWindRecord.speed = stof(DataArray[SIndex]);
        ThisWindRecord.airTemp = stof(DataArray[TIndex]);
        ThisWindRecord.solarRad = stof(DataArray[SRIndex]);
        WindData.Add(ThisWindRecord);

        //Output data to check visually
        /**
        cout << ThisWindRecord.d << ThisWindRecord.t
        << "Speed          : " << ThisWindRecord.speed << '\n'
        << "Temperature    : " << ThisWindRecord.airTemp << '\n'
        << "Solar Radiation: " << ThisWindRecord.solarRad << endl;
        // */
    }

    //Menu interface
    int MenuOp = 0;
    cout << "Please Select From 1 to 5 To Start." << '\n';
    while(MenuOp != 5){
        if(MenuOp == 0){
            cout
            << "<1> Calculate Average Wind Speed For The Selected Month & Year With(Sample SD).\n"
            << "<2> Calculate Average Ambient Air Temperature For Each Month Of Selected Year With(Sample SD).\n"
            << "<3> Calculate Total Solar Radiation For Each Month Of Selected Year.\n"
            << "<4> Output Above Calculations Of A Specific Month & Year With (SD) To 'WindTempSolar.csv'.\n"
            << "<5> Exit The Program.\n" << endl;
        }
        MenuOp = UserInput();
        if(MenuOp == 1){
            AverageWindSpeed(WindData);
            MenuOp = 0;
        }
        else if(MenuOp == 2){
            AverageAirTemp(WindData);
            MenuOp = 0;
        }
        else if(MenuOp == 3){
            TotalSolarRad(WindData);
            MenuOp = 0;
        }
        else if(MenuOp == 4){
            OutputData(WindData);
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

float MsToKmh(float& speed){
    speed = speed * 3.6;
}

float SumOfSpeed(const WindlogType& log){
    float sum = 0.0;
    for(WindRecType each : log){
        sum += each.speed;
    }
    return sum;
}

float SpeedSD(const WindlogType& log, float& mean){
    float SDBeforeSqrt = 0.0;
    float SD = 0.0;
    for(WindRecType each : log){
        SDBeforeSqrt += pow((each.speed - mean), 2);
    }
    SD = sqrt(SDBeforeSqrt/log.GetSize());
    return SD;
}

void AverageWindSpeed(const WindlogType& log){
    unsigned MonthInput = 0;
    string SelectedMonth = "";
    unsigned YearInput = 0;

    cout << "\nEnter Month(Numerical):" << endl;
    MonthInput = UserInput();
    while(!ValidMonth(MonthInput)){
        cout << "\nThe Month You Entered Is Invalid, Try Again.\n" << endl;
        unsigned TempMonth;
        TempMonth = UserInput();
        ValidMonth(MonthInput);
        if(ValidMonth){
            MonthInput = TempMonth;
        }
    };
    SelectedMonth = ConvertMonth(MonthInput);
    cout << "\nEnter Year:" << endl;
    YearInput = UserInput();

    WindlogType RequestedSpeedInfo;
    for(WindRecType each : log){
        if(each.d.GetMonth() == MonthInput && each.d.GetYear() == YearInput){
            MsToKmh(each.speed);
            RequestedSpeedInfo.Add(each);
        }
    }
    if(RequestedSpeedInfo.GetSize() == 0){
        cout << '\n' << SelectedMonth << " " << YearInput << ": No Data\n"
        << "End\n" << endl;
    }
    else{
        float AvgSpeed = SumOfSpeed(RequestedSpeedInfo)/RequestedSpeedInfo.GetSize();
        float StandardDeviation = SpeedSD(RequestedSpeedInfo, AvgSpeed);
        cout << '\n' << SelectedMonth << " " << YearInput << ":\n"
        << "Average speed : " << fixed << setprecision(2) <<  AvgSpeed << "km/h\n"
        << "Sample SD     : " << fixed << setprecision(2) << StandardDeviation << "km/h\n"
        << "End\n" << endl;
        RequestedSpeedInfo.Clear();
    }
}

float SumOfTemperature(const WindlogType& log){
    float sum = 0.0;
    for(WindRecType each : log){
        sum += each.airTemp;
    }
    return sum;
}

float TemperatureSD(const WindlogType& log, float& mean){
    float SDBeforeSqrt = 0.0;
    float SD = 0.0;
    for(WindRecType each : log){
        SDBeforeSqrt += pow((each.airTemp - mean), 2);
    }
    SD = sqrt(SDBeforeSqrt/log.GetSize());
    return SD;
}

void AverageAirTemp(const WindlogType& log){
    unsigned YearInput = 0;
    unsigned MonthIndex = 0;
    string CurrMonth = "";

    cout << "\nEnter Year:" << endl;
    YearInput = UserInput();
    WindlogType RequestedTemperatureInfo;
    cout << '\n' << YearInput  << ":" << endl;
    for(MonthIndex = 1; MonthIndex < 13; MonthIndex++){
        for(unsigned i = RequestedTemperatureInfo.GetSize(); i > 0; i--){
            RequestedTemperatureInfo.Remove();
        }
        for(WindRecType each : log){
            if(each.d.GetYear() == YearInput && each.d.GetMonth() == MonthIndex){
                RequestedTemperatureInfo.Add(each);
            }
        }
        CurrMonth = ConvertMonth(MonthIndex);
        if(RequestedTemperatureInfo.GetSize() == 0){
            cout << CurrMonth << ": No Data\n" << endl;
        }
        else{
            float AvgTemperature = SumOfTemperature(RequestedTemperatureInfo)/RequestedTemperatureInfo.GetSize();
            float StandardDeviation = TemperatureSD(RequestedTemperatureInfo, AvgTemperature);
            cout << CurrMonth << ":\n"
            << "  Average temperature : " << fixed << setprecision(2) << AvgTemperature << " degrees\n"
            << "  Sample SD           : " << fixed << setprecision(2) << StandardDeviation << " degrees\n"
            << endl;
        }
    }
    RequestedTemperatureInfo.Clear();
    cout << "End\n" << endl;
}

float WhTokWh(float& solarRad){
    solarRad = solarRad/1000;
}

float SumOfRadiation(const WindlogType& log){
    float sum = 0.0;
    for(WindRecType each : log){
        if(each.solarRad >= 0.1){
            sum += (each.solarRad / 3600);
        }
    }
    return sum;
}

void TotalSolarRad(const WindlogType& log){
    unsigned YearInput = 0;
    unsigned MonthIndex = 0;
    string CurrMonth = "";

    cout << "\nEnter Year             : \n" << endl;
    YearInput = UserInput();
    WindlogType RequestedSolarRadiationInfo;
    cout << '\n' << YearInput  << ":" << endl;
    for(MonthIndex = 1; MonthIndex < 13; MonthIndex++){
        for(unsigned i = RequestedSolarRadiationInfo.GetSize(); i > 0; i--){
            RequestedSolarRadiationInfo.Remove();
        }
        for(WindRecType each : log){
            if(each.d.GetYear() == YearInput && each.d.GetMonth() == MonthIndex){
                WhTokWh(each.solarRad);
                RequestedSolarRadiationInfo.Add(each);
            }
        }
        CurrMonth = ConvertMonth(MonthIndex);
        if(RequestedSolarRadiationInfo.GetSize() == 0){
            cout << CurrMonth << ": No Data\n" << endl;
        }
        else{
            float TotalRadiation = SumOfRadiation(RequestedSolarRadiationInfo);
            cout << CurrMonth << ":\n"
            << fixed << setprecision(4) << "  Total Radiation : " << TotalRadiation << " kWh/m^2\n"
            << endl;
        }
    }
    RequestedSolarRadiationInfo.Clear();
    cout << "End\n" << endl;
}

void OutputData(const WindlogType& log){
    unsigned YearInput = 0;
    unsigned MonthIndex = 0;
    string CurrMonth = "";
    ofstream outFile("data/WindTempSolar.csv");

    cout << "\nEnter Year:" << endl;
    YearInput = UserInput();

    if(outFile.is_open()){
        outFile << YearInput << endl;
        WindlogType OutputRequestData;
        for(MonthIndex = 1; MonthIndex < 13; MonthIndex++){
            for(unsigned i = OutputRequestData.GetSize(); i > 0; i--){
                OutputRequestData.Remove();
            }
            for(WindRecType each : log){
                if(each.d.GetYear() == YearInput && each.d.GetMonth() == MonthIndex){
                    MsToKmh(each.speed);
                    WhTokWh(each.solarRad);
                    OutputRequestData.Add(each);
                }
            }
            CurrMonth = ConvertMonth(MonthIndex);
            if(OutputRequestData.GetSize() > 0){
                float AvgSpd = SumOfSpeed(OutputRequestData)/OutputRequestData.GetSize();
                float SpdSD = SpeedSD(OutputRequestData, AvgSpd);
                float AvgTemp = SumOfTemperature(OutputRequestData)/OutputRequestData.GetSize();
                float TempSD = TemperatureSD(OutputRequestData, AvgTemp);
                float TotalRad = SumOfRadiation(OutputRequestData);

                outFile << CurrMonth << ','
                << fixed << setprecision(2) << AvgSpd << '(' << SpdSD << "),"
                << AvgTemp << '(' << TempSD << "),"
                << fixed << setprecision(4) << TotalRad << endl;
            }
        }
        cout << "The Data Have Been Saved In: 'WindTempSolar.csv'\n" << endl;
    }
    else{
        cout << "There Was An Error Opening The File, Please Try Again.\n" << endl;
    }
}

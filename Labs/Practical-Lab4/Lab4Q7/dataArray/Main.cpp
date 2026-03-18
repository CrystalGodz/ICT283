#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void CalcMeanAndStdDev(float* dataArray, unsigned index, float& mean, float& stdDev);

int main(){
    ifstream inputFile("data.txt");
    if(!inputFile){
        cout << "Error opening file." << endl;
        return -1;
    }

    unsigned N;
    inputFile >> N;
    if(N < 1){
        cout << "Invalid number of floating-point values." << endl;
        return -1;
    }

    float* m_dataArray = new float[N];
    for(unsigned i = 0; i < N; ++i){
        inputFile >> m_dataArray[i];
    }

    inputFile.close();

    float m_mean;
    float m_stdDev;
    CalcMeanAndStdDev(m_dataArray, N, m_mean, m_stdDev);

    cout << "The number of floating-point values (N): " << N << endl;
    cout << "The mean of the floating-point values: " << m_mean << endl;
    cout << "The sample standard deviation (s): " << m_stdDev << endl;

    delete[] m_dataArray;
    return 0;
}

void CalcMeanAndStdDev(float* dataArray, unsigned index, float& mean, float& stdDev) {
    mean = 0.0f;
    for (unsigned i = 0; i < index; ++i) {
        mean += dataArray[i];
    }
    mean /= index;

    float varianceSum = 0.0f;
    for(unsigned i = 0; i < index; ++i){
        varianceSum += (dataArray[i] - mean) * (dataArray[i] - mean);
    }
    stdDev = sqrt(varianceSum/(index - 1));
}

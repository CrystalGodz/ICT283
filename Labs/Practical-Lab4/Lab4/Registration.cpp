// REGIST.CPP - Registration class implementation.

#include "Registration.h"

Registration::Registration()
{
    m_count = 0;
}

unsigned Registration::GetTotalCredit() const
{
    // for each Result
    //      obtain that unit an retrieve the Credits
    //      add Credits to total
    unsigned sum = 0;
    Unit tempUnit;

    for(unsigned i = 0; i < m_count; i++)
    {
        m_results[i].GetUnit(tempUnit);
        sum += tempUnit.GetCredits();
    }

    return sum;
}


unsigned Registration::GetCount() const
{
    return m_count;
}

long Registration::GetStudentId() const
{
    return m_studentId;
}

unsigned Registration::GetSemester() const
{
    return m_semester;
}


const Result* Registration::GetResults() const
{
    return m_results;
}



void Registration::SetCount(unsigned count)
{
    if(count <= MAX_RESULTS){
        m_count = count;
    }
}

void Registration::SetStudentId(long studentId)
{
    m_studentId = studentId;
}

void Registration::SetSemester(unsigned semester)
{
    m_semester = semester;
}

void Registration::SetResult(unsigned index, Result& result){
    if(index < MAX_RESULTS){
        m_results[index] = result;
    }
}



istream& operator >>(istream& input, Registration& registration)
{
    char delimiter = ',';
    string data;
    getline(input, data, delimiter);
    registration.SetStudentId(stoi(data));
    cout << registration.GetStudentId() << "Student ID" << endl;

    getline(input, data, delimiter);
    registration.SetSemester(stoi(data));
    cout << registration.GetSemester() << "Semester" << endl;

    getline(input, data);
    registration.SetCount(stoi(data));
    cout << registration.GetCount() << "Count" << endl;

    Result tempResult;
    for(unsigned i = 0; i < registration.GetCount(); i++){
        registration.SetResult(i, tempResult);
        input >> tempResult;
    }

    return input;
}


ostream& operator <<(ostream& os, const Registration& registration)
{
    os << "Student ID: " << registration.GetStudentId() << '\n'
       << "Semester:   " << registration.GetSemester() << '\n';

    const Result* results = registration.GetResults();
    for(unsigned i = 0; i < registration.GetCount(); i++)
    {
        os << results[i] << '\n';
    }

    /*
    //Method two for retrieving Result
    Result tempResult;
    for(unsigned i = 0; i < registration.GetCount(); i++){
        registration.GetResult(i, tempResult);
        os << tempResult << '\n';
    }
    */

    return os;
}

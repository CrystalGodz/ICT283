// REGIST.CPP - Registration class implementation.

#include "Registration.h"

Registration::Registration()
{
    m_count = 0;
}

unsigned Registration::GetCredits() const
{
    // for each Result
    //      obtain that unit an retrieve the Credits
    //      add Credits to total
    unsigned sum = 0;
    Unit tempUnit;

    for(unsigned i = 0; i < m_count; i++){
        m_results[i].GetUnit(tempUnit);
        sum += tempUnit.GetCredits();
    }

    return sum;
}

unsigned Registration::GetCount() const
{
    return m_count;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.

istream & operator >>( istream & input, Registration & registration )
{
    input >> registration.m_studentId >> registration.m_semester >> registration.m_count;

    for(unsigned i = 0; i < registration.m_count; i++){
        input >> registration.m_results[i];  // track down which >> operator is called. Hint: look at what is being input.
    }

    return input;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
ostream & operator <<( ostream & os, const Registration & registration )
{
    os << "Student ID : " << registration.m_studentId << '\n'
       << "Semester   : " << registration.m_semester << '\n';

    for(unsigned i = 0; i < registration.m_count; i++){
        os << registration.m_results[i] << '\n';
    }

    return os;
}

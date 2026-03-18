// Registration.h - Registration class definition/interface
// author KRI
// modified smr

#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>

#include "Result.h"


using namespace std;

const unsigned MAX_RESULTS = 10;

class Registration
{
public:
    Registration();

    unsigned GetCredits() const;
    unsigned GetCount() const;


    // These operators have been made friends. They have
    // privileged access to class internals.
    // Very useful for debugging the class, but not very good for class design.
    // We will keep using it for now but you will have a chance in a later lab
    // to redesign this class.
    friend ostream & operator <<( ostream & os, const Registration & registration );

    friend istream & operator >>( istream & input, Registration & registration );

private:
    long m_studentId;             // student ID number
    unsigned m_semester;          // semester year, number
    unsigned m_count;             // number of Units
    Result m_results[MAX_RESULTS]; // array of Units
};

// No implementation (code body) should be found after the line }; above.
// See topic 1 reading “Absolute C++. Pages 284-293. Separate
// Implementation/Interface. Structs vs Classes” available from My Unit Readings

// A .h file is interface or header file. Implementation should exist in
// the implementation file. Implemention file have .cpp extensions.
// Implementation is the body of the routine/method
// Concept is the same as what you did in ict159.
// So the following implementation needs to be moved to the corresponding
// implementation file (Regist.cpp)


#endif


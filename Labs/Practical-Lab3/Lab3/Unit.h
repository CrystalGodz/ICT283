// UNIT.H - Unit class definition/interface
// author KRI
// modified smr

// A .h file is also known as the header file. It is the Interface.
// It should only contain type declarations and prototypes of routines, similar
// to what was done in ict159.

// The implementation will go into the corresponding .cpp file. Implementation is the
// body of the routines.

/**
*Doxygen commenting
*@author KRI
*@version 1.01
*@date 25/5/2024
*/

#ifndef Unit_H
#define Unit_H

#include <iostream>
#include <cstring>

// No routine from string.h is needed in this header file UNIT.H.
// So it has been commented out.
// Do not #include files that are not needed.
// The implementation file Unit.cpp needs string.h, so #include there

// #include <string.h>  // C string library, DO NOT INCLUDE HEADER FILES IF NOT NEEDED HERE

// Is iostream needed in this  file. Easy to check by commenting out the line #include <iostream>

using namespace std;


// Although the usage of unsigned here is fine, usage of unsigned type can be problematic.
// Can you think of what problems can occur?

const unsigned UNIT_NAME_SIZE = 30;
const unsigned UNIT_ID_SIZE = 8;

class Unit
{
public:
    Unit();
    Unit( const char * name, const char * id, unsigned credits );  // name is a pointer to char, revise ict159
    // Construct a Unit from a name, section letter,
    // and number of credits.

    unsigned GetCredits() const;
    // Get the number of credits.

    void SetCredits( unsigned credits );
    // Set the number of credits.

    // These operators have been made friends. They have
    // privileged access to class internals.
    // Very useful for debugging the class, but not very good for class design.
    // We will keep using it for now but you will have a chance in a later lab
    // to redesign this class.
    friend ostream & operator <<( ostream & os, const Unit & unit );
    friend istream & operator >>( istream & input, Unit & unit );

private:
    char m_name[UNIT_NAME_SIZE + 1];  // Unit name, C style string. not a C++ string object
    char m_id[UNIT_ID_SIZE + 1];
    int  m_credits;   // number of credits
};

#endif

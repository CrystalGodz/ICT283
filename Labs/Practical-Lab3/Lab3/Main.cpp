// Count the number of Units taken by the student, calculate total credits
// author KRI
// modified smr

// Main.cpp - Case Study, Student Registration main program

// main program is the application program.
// It would have the main() function at the top, and possibly
// other functions/procedures below, like what you did in ict159

// The library header files
#include <iostream>
#include <fstream>

// These are your header files.
#include "Unit.H"  // Unit class declaration/interface
#include "Registration.h"  // Registration class declaration/interface

// A namespace is used to encapsulate code and data.
// Files/functions/procedures/methods/structs/classes are also
// encapsulation mechanisms. But namespaces go beyond these basics.
// The line below exposes the std namespace. Professional developers and
// Computer Scientists would like such open slather exposure of an
// encapsulation mechanism. However, we are still learning, and this opening
// of the std namespace is for convinience only to save a lot of typing.
using namespace std;  // check textbook for detials of the namespace concept

// Main program:
// Open an input file stream, read a Registration object,
// including its list of Units. Redisplay all information,
// and calculate the total credits taken. Write the results
// to a file stream.

int main()
{
    ifstream infile( "rinput.txt" ); //infile is an object on runtime stack
    if( !infile ) return -1;

    Registration R;  //R is now an object, like what you did in ict167
    // As the keyword new is not used, object R exists
    // on the runtime stack of main() and not on the heap
    // concept of runtime stack, and various memory locations
    // see ict170

    infile >> R;   //This is a subroutine call, to a function operator>>
    // first parameter is infile, second parameter is R.
    // syntax is different to what you have studied before
    // but you will get used to it as the line just says
    // from infile load into R

    ofstream ofile( "routput.txt" );

// Use a debugger and track down the calls made "behind the scene"
    ofile << R        // also a subroutine call. Can you guess what it means?
          << "Number of Units = " << R.GetCount() << '\n'
          << "Total credits   = " << R.GetCredits() << '\n';

    // Declare and initialize a Unit, and modify
    // its credits.


    /**
    For Lab 3, you should comment out this line and the next 3 lines

    Unit aUnit( "MTH_3020", "B", 2 );
    aUnit.SetCredits( 5 );
    cout << aUnit << endl; // the operator << for Unit is called

    */


    return 0;
}


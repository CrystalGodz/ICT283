/**
*Doxygen commenting
*@author KRI
*@version 1.01
*@date 25/5/2024
*/

// The library header files
#include <iostream>
#include <fstream>

// These are your header files.
#include "Unit.H"  // Unit class declaration/interface
#include "Registration.h"  // Registration class declaration/interface
#include "Date.h"

using namespace std;


int main()
{
    ifstream infile("rinput.txt"); //infile is an object on runtime stack
    if(!infile) return -1;

    Registration R;

    infile >> R;   //This is a subroutine call, to a function operator>>
    // first parameter is infile, second parameter is R.
    // syntax is different to what you have studied before
    // but you will get used to it as the line just says
    // from infile load into R

    ofstream ofile( "routput.txt" );

    // Use a debugger and track down the calls made "behind the scene"
    ofile << R        // also a subroutine call. Can you guess what it means?
          << "Number of Units   = " << R.GetCount() << '\n'
          << "Total credits     = " << R.GetTotalCredit() << '\n';


    return 0;
}


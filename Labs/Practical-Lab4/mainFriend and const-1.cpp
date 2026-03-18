//
//
//  testClass  WHAT NOT TO DO
//  How to make friends and violate encapsulation
//  Rules for const parameter, const methods - experiment to find out - see comments in the code

 This is a demo program to experiment with concepts.
 This is NOT HOW YOU WILL WRITE CODE
//  When you write code, the specification and implementation would be
//   in separate files, and, you don't declare friendships easily.
//   The application program such as this one containing main() would be in
//   separate .cpp file.

//  3/2/18 added TRACE macro to trace source code lines in output
//  10/3/13 demo effects of const methods and parameters
//  24/02/13 created by smr  to show effect of friendship

//

#include <iostream>
#include <string>

using namespace std;

// see https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html for more symbols
// Used for debugging in output. Doesn't really replace the debugger that
// comes with the IDE. This TRACE is just for quick and dirty
// debugging in this unit. Tested in codeblocks. Drag/drop in codeblocks, build and run
// prints out the code line and then line is executed

#define TRACE(p) cout<<"\nLine " << __LINE__<<": TRACE("<<(#p)<<"):\n\t" , (p)

// ///////////////////////////////////////////////////////////////////////
class B
{
public:

    B(int d, string s):name(s)
    { // implementation should not be here - for demo purposes only.
        data[0] = d;
        size = 1;
        cout << "Construct " << name <<  ": " << data[0] << endl;
    }


    friend int main(); // Really? violate encapsulation and expose private data to main()
						// Looks bad, but would there be situations where this might be useful?

		// what would happen if the word const is removed?
    int getsz()  const //getter, so has to be const, but what if not there. Can a const method call it?
    {
        return size;
    }

    int getdat(int i) const  //getter, so has to be const
    {
        cout << "const func getDat" << endl;
        getsz();     // would this be legal if getsz() wasn't const? A const method can call methods that are also const, why?
        return data[i];
    }

			// First run with the following method uncommented, examine the output and then
			// comment out the whole method to see which version is being called.
			// /*
    int getdat(int i)    // not const - see which version is called. As the return is not by ref (int &) internal data can't be modified
    {
        cout << "*nonconst func getDat" << endl;
        getsz();     // would this be legal if getsz() wasn't const?
        return data[i];
    }
// */

    void setdat(const int &d) // set only one data per setter
    {
        data[size] = d;

        size++;
    }

private:
    int size;
    string name;
    int data[5];

}; // end of class B

// //////////////////////////////////////////////////////////////////////////

// general routines, global scope

void f1(const B& b) // has const parameter. only const methods can be called for b. investigate by making B::getsz() not const
{
    cout << "const param passing: " << endl;
    cout << b.getsz() << endl;    // what would happen if B::getsz() wasn't const?
    cout << b.getdat(0) << endl;
}

void f2(B& b)  // has non-const parameter, but has similar calls to methods as f1 above.
{
    cout << "non-const param passing: " << endl;
    cout << b.getsz() << endl;
    cout << b.getdat(0) << endl;
}

int main()
{
    B  b1(1,"b1");

    TRACE( cout << "main is a friend: " << b1.size << b1.name << endl );// private data is accessible by main because of friendship

    TRACE( cout << b1.getsz() << endl );
    TRACE( cout << b1.getdat(0) << endl);

    TRACE( f1(b1) );
    TRACE( f2(b1) );

    return 0;
}


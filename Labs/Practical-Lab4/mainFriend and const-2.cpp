//
//  main.cpp
//  testClasses    WHAT NOT TO DO
  How to make friends and violate encapsulation, how create problems/headaches for your real friends in your software dev team.
  Rules for const parameter, const methods - experiment to find out - see comments in the code

// Example where Class B contains Class A

// This is a demo program to experiment with concepts.
// This is NOT HOW YOU WILL WRITE CODE
//  When you write code, the specification and implementation would be
//   in separate files, and, you don't declare friendships easily.
//   The application program such as this one containing main() would be in
//   separate .cpp file.
//  Created by smr on 20/04/13.
//

#include <iostream>
#include <string>

using namespace std;

// Used for debugging in output. Doesn't really replace the debugger that
// comes with the IDE. This TRACE is just for quick and dirty
// debugging in this unit. Tested in codeblocks. Drag/drop in codeblocks, build and run
// Macro prints out the code line number and then line is executed
#define TRACE(p) cout<<"\nLine " << __LINE__<<": TRACE("<<(#p)<<"):\n\t" , (p)

// ////////////////////////// CLASS A //////////////////////
class A
{
    int data; // private by default. normally declared after public with the keyword private:

public:
    A() {}
    A(int d):data(d) {}
    void set(int d)
    {                 // implementation should not be here. This is
					  //	for demo only.
        data = d;
    }
    int& get()      // this is terrible. a getter should be const. What can the caller of get do to the data?
    {
        return (data);
    }

		// Is the following needed? Comment this method out and see. Which of the two get methods is correct?
    const  int& get() const
    {
        return (data);
    }
}; // end of class A

// ////////////////// CLASS B - contains class A ///////////////////

class B
{
    A data[3]; // private by default. normally declared after public with the keyword private:
    int size;
    string name;

public:
    B()
    {
        size = 0;
    }

    B(A d, string s):name(s)
    {
        data[0]=d;
        size = 1;
        cout << "B construt" << d.get() << endl;
    }

    // A& operator[](int i){return data[i];} // read-write access as in normal arrays
    //const A& operator[](int i) const {return data[i];} // readonly

    friend int main();  // Way to go, violate encapsulation and expose private data to main(). Can you thing of a use for this?

    string getName() const
    {
        return name;
    }

    int getsz() const
    {
        return size;
    }

    const A& getdat(int i) const   // a proper getter
    {
        cout << "const A getDat" << endl;
        return data[i];
    }

    A& getdat(int i)    // non const version. what happens if the reference & is deleted?
    {
        cout << "*nonconst A getDat" << endl;
        //data[i].get() = 3333; // A::get() returns reference, so change will happen. Should a getter allow this?
        return data[i];
    }

    void setdat(const A& d, string s)  // setters should only set 1 piece of data. setting 2 for quick and dirty code
    {
        data[size] = d; // no size check
        name =s;
        size++;
    }

}; // end of class B

// ////////////////////////// NON friend and non member

ostream & operator <<(ostream & os,  const B& b)  // const on 2nd param remove const to check
{

    os << "\nin output operator  " << b.getName() << endl;

    for(int i=0; i < b.getsz(); i++)
    {
        os << "i =" << i << "  data=" << b.getdat(i).get() << endl;
    }

    return os;

}

// //////////////////////
int main()
{
    B b1;
    A a;

    TRACE( a.set(5) );  // actual code to be executed is in the brackets in TRACE
    TRACE( cout << a.get() << endl );

    TRACE( b1.setdat(a,"b") );

    TRACE( cout << "main is a friend " << b1.size << b1.name << endl ); // violate encapsulation

    TRACE( cout << b1 << b1.getsz() << endl );

    TRACE( a.set(55) );

    TRACE( cout << b1 << endl ); // object a in b1 is not changed by a.set above, even though obj a was inserted in b1. Why not changed?
    // what would happen if obj a had pointer data and the assignment operator was not defined by the programmer?

    TRACE( b1.getdat(0).get() = 999 ); // non-const B::getdat() and A::get() returns by ref, so change will happen.
    // Think about this. Should getters be allowed to change internal data?
    // The change is possible because of the return by reference in the getters, but should you allow this?

    TRACE( cout << b1 << endl );

    // TRACE( cout << b1.getdat(0).get() << endl );

    TRACE( b1.setdat(a,"b") );  // setters should set one data only. can you see the problem with this version?
    // it does the job but the second parameter is used even when it is not relevant

    TRACE( cout << b1 << endl );

    return 0;
}


The following is deliberately not commented so that you see the message below.

You must first go through the section on "Binary Tree Traversal and Functions
as Parameters" from your textbook. Don't start on the code in this file until
you have finished that section in your textbook. That section is found in 
chapter on trees.

// Demonstrates use of function callback to retrieve and store data from BST
// Function pointers are used to "pass" functions to routines/methods.
// The usual idea is to pass data to routines/methods. 
// In this example, functions are passed, so the called routine/method can
// make use of the functions.

// This example extends the material from the textbook to make the BST useful 
// for assignment 2

// smr v2.5  

// assumes that you have a working binary search tree.
// change the name of the template tree class and file name to suit your circumstance

#include <iostream>

#include "BinarySearchTree.h"  // This is your modified BST from Lab 9 or the minimal but complete BST from lab 10d


using namespace std;

// this is the  object to be stored in the tree
// not the same unit used in the lab/assignment but has enough to show the concepts.
// methods are inline to show what is going on for demonstration purposes only.
// You would normally have a unit.h and a unit.cpp
// This class was created to self-initialise with unique values for each object created. 
//  So there are no setters for convinience of demo.
class unit
{
public:
    unit()
    {
        a = ++c;   // static c is used to generate unique values for each unit object's member int a
    }
    // Normally done using a setter, but this is to demo a concept unrelated
    // to setters. Just saves time not having to write a setter for this demo only.
	// All I want to do with this is automatically put values into the unit object and I don't want to
	// litter the application code with a bunch of setter calls. In this example, the constructor
	// generates a unique value for each object.

    int getA() const
    {
        return a;   // needs to be const for use where the object is declared const
    }
   
private:
    int a;  // this is for the individual objects. not shared
    string st; // not really used, in this demo, but just to show that you can have member values
    static  int c; // all objects will have this shared - just used to generate internal values for a.
    // Just a trick to enable each object to have a unique value for the private member a
	// Just as an aside, if this value starts with 0, you can keep a running total of objects
	// that get created.
};

int unit::c = 5; // every object will share this value, needed for VS 2010
				 // non const static. A static member exists before the object exists.

// The above could be in a separate file unit.h and unit.cpp. The is for demo.
// In actual usage, the class being stored would be in a .h and .cpp files



//The operators below can be in main program file.

// bst needs this for the inserting unit objects. Normally you will have each
// of the comparators == and < operators
// not a friend or a member in this example
bool operator>(  const unit &L,   const unit &R)
{

    int a = L.getA(); // naturally will use the const getA as R and L are const
    int b = R.getA();

    return a > b;
}

// not a friend or a member
ostream& operator<<(ostream &os,   const unit &R)
{

    os << R.getA() << " : Data Printed in operator <<" << endl;

    return os;
}

// similar to the approach used in the textbook but the problem is that
// it doesn't collect the data. Just prints it out. 

// One approach is have a global array or vector and the routine below
// puts data into the global data structure each time it is called
// by the BST. Problem is of course we don't allow global data
// as that is poor program design.

// Const & parameter?
// what if this routine changes the data. Would the BST's invariant property
// be guaranteed?
void f1t(int &data) // should it be const ref parameter?
{
    cout << data << "  ";
}

// Need a better approach than the one in the textbook. The print
// routine when used as a callback just prints, so...
// This class is used to collect the data coming back from the BST
// CollectU can be in a separate file. #include into the main program file
// Contains the callback method f1u. Class is used to collect unit objects as the callback occurs.
// The tree calls static method f1u and puts the data into f1u as a parameter.
// f1u gets the data and stores the data into an array in this case.
// This is a client side program.
// Methods are inline for demonstration purposes only. Normally you would have a .h and .cpp

class CollectU  // collects the unit data from the callback. Collector for Unit objects
{

public:
    static void f1u( unit &data)  // quick and dirty - inlined for demo only. This is the callback called by the tree
								  // the data parameter comes in by reference. The bst sends this data 
								  // when it calls back - calls the client side routine f1u
								  // should the parameter be const &?
    {
        cout << "in CollectU static callback f1u(..), i = " << i << "\t" << "data = " << data << endl; // to trace what is going on

        A[i] = data;   // keeps the data that is returned by bst. static method needs static data
        i++;  // no bounds check - just quick and dirty - improve on this. You have your Vector
    }

    int size()
    {
        return i;
    }
    unit& operator[](int k)
    {
        return A[k];   // used to return the data that has been collected.
    }

private:
    static int i;  // this does not create memory on earlier compilers
    static unit A[100];  // use a vector instead, if you prefer. bst can't have more than 100 data nodes if
						//	a raw array is used this way.
};

int CollectU::i = 0; // this creates memory and initialise it to 0
unit CollectU::A[100]; // 100 objects get created here and unit's value of c would track obj creations.



int test1()
{
    Bst<int>  intTree; // change the name as appropriate for your bst. Shortened name used becaause of the using statement.

    for (int i =0; i< 20; i++)
    {
        intTree.insertElement(i); // yes, it is inserted pre-sorted. not a good thing, but we are just
								  // looking at mechanics. What would the tree look like? balanced?
    }

    intTree.inOrderTraversal(f1t);  // similar to the approach used in the text - just prints, so not very useful

    return 0;

}

int test2()  // extends the approach used in the textbook
{
    Bst<unit>  ut; // the tree for storing units - // change the name as appropriate for your bst
    unit u[20];             // 20 unit objects for storing in the tree. unit constructor generates unique values for each object

    CollectU C;  // for returning the data that is returned in the callback
    // the callback is a static method of this Class

    for (int i =0; i< 20; i++)
    {
        ut.insertElement(u[i]); // insert the 20 unit objs into the tree. don't care if pre-sorted or not. just demo
    }

    ut.inOrderTraversal(CollectU::f1u); // pass the func ptr of the static method of CollectU - collects sorted units
        // ut.inOrderTraversal(C.f1u);  // alternative use through the object. f1u is public static method
        // do not put () on f1u, otherwise the meaning changes. We want a function pointer
        // not a method call.

    cout << endl;
    cout << "checking the values collected from the tree" << endl;
    for (int i =0; i< C.size(); i++){ // check if the data has been collected.
        cout << C[i];  // uses the overloaded [] for CollectU. can't use CollectU::A[i] as A is private
    }

    return 0;
}

int main()
{
	//test1(); // textbook approach

    test2(); // extended 

    int c;
    cin >> c; // pause the screen in visual studio. not needed in codeblocks

    return 0;
}

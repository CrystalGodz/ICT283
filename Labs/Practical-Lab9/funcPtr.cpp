These lines are not commented out so they can be read easily.

Read first before commenting out. Instructions about what to comment out is included below.

See textbook section on “Binary Tree Traversal and Functions as Parameters” before 
examining the code in this file. Chapter on Binary Trees.

This is not part of the assessed lab exercise. You would need
this for later assesed work including assignment 2.

This sample code file shows you how to use pointers to code.

We covered pointers to data early in the semester. You should 
consider revising pointers first.

int f(); // a subroutine
f is a function subroutine that returns an integer. Similar
to what you would have come across in ict159.

int * f(); // a subroutine
f is a function subroutine that returns a pointer to an integer.
f returns pointer to data, in this case integer data.

int (*f)(); //not a subroutine but a pointer variable
f is not a function subroutine any more.
f is now a pointer variable and it is used to point to
any function that takes no parameters and returns an int.
 
The tree should *not* know about the data that it is storing. If it
does, the utility of the tree is reduced. There are certain tree
operations like tree traversals which need to process the tree data.
But for good design the tree should not actually do the processing.
The client program knows about the data, so the data needs to be
sent back to the client.

This is done by call-back routines. The call-back routines are
client routines.

The client informs the tree of the existence of such routines
through a function pointer.

The sample code in this file shows how such a call back can occur.

In the code, instead of single function pointer, a array of
function pointers can be used.

Of course if you can have an array of function pointers, you can have a 
tree of function pointers (tree of sub-routines) instead of the normal 
tree of data. To take this approach with a BST, there must be some way to
compare routines.

Similarly, you can have map where the value is function pointer. So
given a key, you get the subroutine to call.

All sorts of possibilities open up. You can have data structures of
data but now the data can be pointers to functions.  The software
designer or programmer is only limited by his/her imagination.

To build and run, comment out this line and everything above this line.


// modified: smr 2005 - 2022 various examples added.
// created: smr Jan 2005

#include <iostream>

using namespace std;

// int (*f)(); declares f as a pointer to functions which take no
				// parameters and return an int. f is a pointer variable.

typedef int (*f)(); // the typedef makes f into a function pointer type
                    // so that this type can be used.

	// an example of a routine that the function pointer can point to
	// after you understand how this works, try putting a parameter into the function
	// int test(int data)
	// and print out data in the body of test.
	// do the same in test1
	// the function pointer type to be used is now
	// typedef int (*f)(int); as pointer to functions to that take an int parameter
	// and return an int.
int test()
{
    cout << "test called\n" << endl;
    return 0;
}

	// another example of a routine that the function pointer can point to
int test1()
{
    cout << "test1 called\n" << endl;
    return 0;
}

	//look at the main subroutine first before looking at this. See below
int testall(int (*fp[])())    // int testall(f fp[]) {which parameter notation would you prefer?
                            // how would you change this parameter declaration to accept
                            // pointer to functions that accept an int parameter?
{
    int i;
    cout << "\nIn test all\n" << endl;

    for (i=0; i<=1; i++)
        (*fp[i])(); // each function is called in
                    // turn. This is where the call-back happens.
                    // testall could be part of some other source file or a method of a class.
					
                    // Can be abbreviated to fp[i]() which is just syntactic sugar - i.e looks nicer
                    // what is the operator
                    // precedence in (*fp[i])()  ??
                    // ie. In what order do the
                    // operators bind?
                    // After you changed to accept in parameters in the call back
                    // change this to fp[i](i); the call-back with the value of i passed back.
					
		//fp[i](); try this one instead of the code above?

    return 0;
}

int main()
{
      // fp is an array - takes up memory, i.e data, but this data is of addresses of subroutines
    f fp[3]; 		// int (*fp[3])();  see typedef at the top - makes it cleaner

    fp[0] = test;  // fp[0] points to test
    fp[1] = test1;

    fp[0](); // the individual calls via the function pointer.
    fp[1]();

    testall(fp); // pass them all


    return 0;
}

/* In the examples the subroutines/functions had no formal parameters
and returned an int.

If you need to have a pointer to a routine with the prototype shown below

int f1(string a, int b);

the function pointer would need to be declared as:

int (*fp)(string, int); // note fp is a variable that stores addresses of subroutines

then fp can be made to point to f1 using the code

fp = f1;

the call using fp is the same as when you would call the original
routine f1. You need a string and int parameter.

e.g.

string s = "hello";
int a = 5, b;

fp = f1;

b = fp(s, a);


*/

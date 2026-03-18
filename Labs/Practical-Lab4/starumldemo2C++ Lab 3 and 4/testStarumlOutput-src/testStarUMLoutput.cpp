// You need to create this file yourself. It is not created by staruml
// This the test program and it contains function main()

// This file contains the main program to test the stubbed methods
// created by staruml.

// As the methods are stubbed (empty code body), nothing really happens
// but it serves to check that the classes work in their "skeletal form"
// There will be some warnings generated because of missing return statements.

// Note that main is not a class. It is a subroutine.

#include "../A.h"  // to include the header files. i.e. .h files
#include "../B.h"  // do not include .cpp files. The .. refers to the outer folder
                   // as you can see having multiple A.h and B.h can be a source
                   // of confusion to the programmer as to which file is included in
                   // in the build.
                   // So always have just one copy in the build folder. Your backup
                   // copy is kept somewhere else.


int main(){

A a1;
B b1;

a1.set();
b1.set();

// you need to call get to test if the set methods worked.
// but this is just a simplied example to show possibilities


return 0;
}

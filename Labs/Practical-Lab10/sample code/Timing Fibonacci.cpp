// Modified version from http://en.cppreference.com/w/cpp/chrono

// How long does it take to compute a Fibonacci number?
// Examine the code first
// Build and run to see, then implement the iterative version
//		unsigned long iter_fibonacci(unsigned n);

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

// expose only what is needed
using std::cout;
using std::endl;
using std::ofstream;
using std::time_t;

//  function pointer type
//  go through the source file funcPtr.cpp first which shows how function pointers work
//  the textbook also explains how function pointers work. required reading for this topic
//		and needed for assignment 2 and exam
typedef unsigned long (*fib_ptr)(unsigned n);

// Forward declarations
unsigned long rec_fibonacci(unsigned n); // return the nth Fibonacci number computed recursively
unsigned long iter_fibonacci(unsigned n); // return the nth Fibonacci number computed iteratively

void doFibn(unsigned n, fib_ptr fibonacci, ofstream &logfile ); // prints the time taken



int main()
{

    // plot the output in each logfile,  n vs time in seconds
    // what does this experiment show about the runtime performance of
    // iterative versus recursive approaches to Fibonacci
    ofstream rec_logfile( "rec_log.csv" );
    ofstream iter_logfile( "iter_log.csv" );

    for (unsigned i = 0; i < 100; i++)  // how many Fibonacci numbers computed
    {
        cout << endl;

        cout << "\t   RECURSIVE" << endl;
        doFibn(i, rec_fibonacci, rec_logfile);  // to time each one of the recursive version

        cout << "\tITERATIVE **you need to implement iter_fibonacci first**" << endl;
        doFibn(i, iter_fibonacci, iter_logfile);  // to time each one of the iterative version
    }

    return 0;
}

// return the nth Fibonacci number using recursive approach
// examine the run-time complexity of this algorithm
unsigned long rec_fibonacci(unsigned n)
{
    if (n < 2)
        return n;
    return rec_fibonacci(n-1) + rec_fibonacci(n-2);
}


// return the nth Fibonacci number using iterative approach
// examine the run-time complexity of the iterative algorithm
// you implement the iterative version first
unsigned long iter_fibonacci(unsigned n)
{
// implement an iterative version to calculate the nth Fibonacci number

    return n; // constant time in this stub. change it to return the actual computed number.
}


// time the computation of the nth Fibonacci number.
// parameter fibonacci is the function that does the computation
// parameter logfile stores n, Fibonacci(n) and time taken to compute Fibonacci(n)
// create a Stopwatch class that does the timing more cleanly
// enhance the Stopwatch so that a comment can be inserted into the log file to indicate what the time is for
void doFibn(unsigned n, fib_ptr fibonacci, ofstream &logfile)
{
    unsigned long f;  // for storing the calculated Fibonacci(n)

    // how long does it take to work out each number?
    auto start = std::chrono::system_clock::now();
    f = fibonacci(n);              // find the nth number
    auto finish = std::chrono::system_clock::now();  

    cout << "f( "<< n<< ") = " << f << '\n';  // print f(n) to screen

    std::chrono::duration<double> elapsed_seconds = finish - start; // time taken for one number

    time_t start_time = std::chrono::system_clock::to_time_t(start);
    cout << "started computation at " << std::ctime(&start_time);  // prints date/day/time

    time_t end_time = std::chrono::system_clock::to_time_t(finish);
    cout << "finished computation at " << std::ctime(&end_time);  // prints date/day/time

    cout << "TIME TAKEN: " << elapsed_seconds.count() << "s\n";

    // once completed, plot the output that is the CSV logfile,  n vs time taken in seconds
    // what does this experiment show about the runtime performance?

    logfile << n << ',' << f << ',' << elapsed_seconds.count() << endl; //n, f(n), time taken into log file
}



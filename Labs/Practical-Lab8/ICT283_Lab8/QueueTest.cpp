// IntQueueTest Program
//
// Version
//   original by Nicola Ritter
//   modified by smr
// uses our own Queue class that encapsulates the STL queue.
// The client program should not take the implementation into
// account as that will create dependencies on how the Queue class
// is implemented. The client relies only on the public
// interface/specification of our Queue.

// This means that if the Queue class's internal data structure is
// changed to your Vector, this main (application) program should
// not require change in code.
// To make sure, change the Queue to use your Vector and
// build and run this application program.
//---------------------------------------------------------

// #include our own .h files first
#include "Queue1.h"

// then #include the system files. Separate into two blocks.
#include <iostream>
#include <cstdlib>
#include <ctime>



using namespace std;

//---------------------------------------------------------

const int EVENT_COUNT = 30;
const int MAX_NUM = 100;

//---------------------------------------------------------

typedef Queue<int> IntQueue; //gives a nicer name for the type

//---------------------------------------------------------

void DoEvents ();
void AddNumber (IntQueue &aqueue);
void DeleteNumber (IntQueue &aqueue);
void TestOverflow();  // will take a while to run - examine the code.

//---------------------------------------------------------

int main()
{   char ch;
	DoEvents ();

	cout << endl;
	cout << "Do not run without reading the code!!" << endl;
	cout << "once you have read the code, type in a character and press enter" << endl;
	cout << "sit back and enjoy the scroooooling" << endl;
	cout << "Watch the memory being chewed up by opening Task or Process Manager" << endl;
	cout  << "find this program there and watch as memory usage goes up" << endl;
	cout << "On Windows, press Ctrl-Shift-Esc to get process manager" << endl;
	cin >> ch;
	cout << endl;

	TestOverflow(); // this will take some time
	// TestOverflow(); // uncomment this call to see what happens when the call is made twice
                        // first examine the code of this routine to see what is going on

	cout << endl;

	cout << "What is the value of count and how much memory being used?" << endl;

	cout << "type a character and press the enter key to finish" << endl;

	// check for any differences in memory use when using stack or heap in testoverflow.
	// explain what is going on.
    cin >> ch;  // pause so that main doesn't terminate until you are ready
	cout << endl;

	return 0;
}

//---------------------------------------------------------

void DoEvents ()
{
	IntQueue aqueue;

	// Seed random number generator
	srand (time(NULL)); // https://www.cplusplus.com/reference/cstdlib/srand/

	for (int count = 0; count < EVENT_COUNT; count++)
	{
		// Choose a random event
		int event = rand() % 5; // mod 5, means event will have one of the following:1,2,3, 4 or 5

		// Do something based on that event value, biasing
		//   it towards Adding
		if (event <= 2) // event = 0, 1 or 2
		{
			AddNumber (aqueue);
		}
		else // event = 3 or 4
		{
			DeleteNumber (aqueue);
		}
	}
}

//---------------------------------------------------------

void AddNumber (IntQueue &aqueue)
{
	// Get a random number
	int num = rand() % (MAX_NUM+1);

	// Try adding it, testing if the aqueue was full
	if (aqueue.Enqueue(num))
	{
		cout.width(3);
		cout << num << " added to the queue" << endl;
	}
	else
	{
		cout.width(3);
		cout << "Overflow: could not add " << num << endl;
	}
}

//---------------------------------------------------------

void TestOverflow()
{

// use the run-time stack and note memory use
// then comment out the stack version and un-comment the heap version
// and compare. When is the memory given back?

	Queue<double> mqueue; // mqueue is local on the run-time stack (RTS). Would the actual data be on the RTS?
	//Queue<double> * qptr = new Queue<double>; // on the heap. what exactly is on the heap?
												// and what is on the RTS?


	int count = 0;
	//while (qptr->Enqueue(count)) // heap version
	while (mqueue.Enqueue(count)) // local version
	{
		count++;
		if ((count % 10000) == 0){ // screen i/o takes time, so don't print so often
                                   // otherwise you will waiting a while
           cout << "Count is " << count << endl;
		}

	}

    cout << "\n\nEnqueue returned false" << endl;
    cout << " count is " << count << endl;

    cout << "Routine finishing, mqueue will be destructed if local version is used" << endl;
    cout << "In the process manager watch the memory usage go down for the stack version." << endl;

    // the heap version will retain memory unless delete qptr is called or
    // when program finishes. The local version would also use heap memory for the actual data.
    // delete qptr;  // commented out to see what happens when this not called when new is used - check memory usage
}


//---------------------------------------------------------

void DeleteNumber (IntQueue &aqueue)
{
	int num;
	if (aqueue.Dequeue(num))
	{
		cout.width(3);
		cout << num << " deleted from the queue" << endl;
	}
	else
	{
		cout << "IntQueue is empty, cannot delete" << endl;
	}
}

//---------------------------------------------------------


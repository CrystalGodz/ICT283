// Binary Search Tree class
//Doxygen comments needed in the declaration

// Make sure Bst is minimal and complete. 
// Code from Lab 9 can come here too.

template <class T>
struct nodeType  // answer why struct encapsulation is used - rationale
				 // there are other approaches, choose which one is the most
				 // appropriate and provide rationale
{
	// your write the code
};





template <class T>
class Bst // answer why class encapsulation is used - rationale
{

typedef void (*f1Typ)(T &); // you are not restricted to a single parameter. You 
							// decide on how many parameters and provide rationale
							// do you want the caller to have read/write access?

public:

			// you write whatever else is needed. You already have some from Lab 9.
			// insert and search is needed.

	void inOrderTraversal(f1Typ f1 ) const;
	
	void preOrderTraversal() const; // parameter f1 in here too. left as an exercise
	void postOrderTraversal() const; // parameter f1 in here too. left as an exercise

private:
    
    
	nodeType<T> *root;

			// you write the rest

	void inOrder(f1Typ f1, nodeType<T> *p) const;
	// you write whatever else is needed.


};

// you write the rest. You already have some from Lab 9.
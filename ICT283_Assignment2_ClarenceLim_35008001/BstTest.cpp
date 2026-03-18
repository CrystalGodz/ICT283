#include <iostream>
#include <fstream>

#include "Bst.h"

using namespace std;

int main(){
    Bst<int> IntTree;

    ifstream sourceFile("data/Integers.txt");
    if(!sourceFile){
        cout << "Source file not found." << endl;
        return -1;
    }

    string data;
    while(getline(sourceFile, data)){
        cout << data << endl;
        try{
            IntTree.Insert(stoi(data));
        }
        catch(const invalid_argument& err){
            cout << "Invalid Value Inserted!" << endl;
        }
    }
    sourceFile.close();

    IntTree.Insert(20);

    cout << "In Order Traversal\n" << endl;
    IntTree.InOrder();
    cout << '\n' << endl;

    IntTree.Insert(4);

    cout << "In Order Traversal\n" << endl;
    IntTree.PreOrder();
    cout << '\n' << endl;

    IntTree.Insert(99); //test duplicated data.

    cout << "In Order Traversal\n" << endl;
    IntTree.PostOrder();
    cout << '\n' << endl;

    int item = 4;
    if(IntTree.Search(4)){
        cout << "Data: " << item << " found!" << endl;
    }
    else{
        cout << "Item not found!" << endl;
    }

    IntTree.DeleteTree();
    cout << "Tree Deletion has failed if data is displayed after this line" << endl;
    IntTree.InOrder();

    return 0;
}

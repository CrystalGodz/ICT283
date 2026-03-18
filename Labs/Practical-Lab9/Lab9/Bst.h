#ifndef INTBST_H_INCLUDED
#define INTBST_H_INCLUDED

#include <iostream>

/** \class intBst
 * \brief intBst object
 *
 * \author Clarence Lim Xing Yu
 * \version 1.01
 * \date 17/07/2024 Last Modified.
 *
 */

using namespace std;

template <class T>
struct Node{
    T data;
    Node<T>* leftNode;
    Node<T>* rightNode;
};

template <class T>
class Bst{
public:
    Bst();
    /** \brief DeepCopy Constructor
     *
     * \param TreeCopy const intBst<T>&
     *
     */
    Bst(const Bst<T>& TreeCopy);
    /** \brief Destructor
     *
     *
     */
    ~Bst(){DeleteTree();};
    /** \brief An overloaded operator
     *
     * \param TreeCopy intBst<T>&
     * \return intBst<T>&
     *
     */
    Bst<T>& operator = (const Bst<T>& TreeCopy);

    /** \brief Method to insert item into tree
     *
     * \param item const T
     * \return void
     *
     */
    void Insert(const T& item);
    /** \brief Method to search for data that match the item
     *
     * \param item const T
     * \return bool
     *
     */
    bool Search(const T& item) const;
    /** \brief Method to delete a tree
     *
     * \return void
     *
     */
    void DeleteTree();
    /** \brief Method to display tree data in InOrder Traversal
     *
     * \return void
     *
     */
    void InOrder();
    /** \brief Method to display tree data in PreOrder Traversal
     *
     * \return void
     *
     */
    void PreOrder();
    /** \brief Method to display tree data in PostOrder Traversal
     *
     * \return void
     *
     */
    void PostOrder();

protected:
    Node<T>* root = nullptr;

private:
    /** \brief Method where we copy the nodes from the old tree to a new tree
     *
     * \param oldTree Node<T>*&
     * \param newTree Node<T>*&
     * \return void
     *
     */
    void CopyTree(Node<T>*& oldTree, Node<T>*& newTree);
    void Insert(Node<T>*& newNode, Node<T>*& current);
    void DeleteTree(Node<T>*& current);
    void InOrder(Node<T>* current) const;
    void PreOrder(Node<T>* current) const;
    void PostOrder(Node<T>* current) const;
};

template <class T>
Bst<T>::Bst(){
    root = nullptr;
}


template <class T>
Bst<T>::Bst(const Bst<T>& TreeCopy){
    if(TreeCopy.root == nullptr){
        root = nullptr;
    }
    else{
        CopyTree(TreeCopy, root);
    }
}


template <class T>
Bst<T>& Bst<T>::operator = (const Bst<T>& TreeCopy){
    if(this != &TreeCopy){
        if(root != nullptr){
            DeleteTree(root);
        }
        else if(TreeCopy.root == nullptr){
            root = nullptr;
        }
        else{
            CopyTree(TreeCopy.root, root);
        }
    }
}


template <class T>
void Bst<T>::CopyTree(Node<T>*& oldTree, Node<T>*& newTree){
    if(oldTree == nullptr){
        newTree = nullptr;
    }
    else{
        newTree = new Node<T>;
        newTree->data = oldTree->data;
        CopyTree(oldTree->leftNode, newTree->leftNode);
        CopyTree(oldTree->rightNode, newTree->rightNode);
    }
}


template <class T>
void Bst<T>::Insert(const T& item){
    Node<T>* tempNode = new Node<T>;
    tempNode->data = item;
    tempNode->leftNode = nullptr;
    tempNode->rightNode = nullptr;
    if(root == nullptr){
        root = tempNode;
    }
    else{
        Insert(tempNode, root);
    }
}


template <class T>
void Bst<T>::Insert(Node<T>*& newNode, Node<T>*& current){
    if(newNode->data < current->data){
        if(current->leftNode == nullptr){
            current->leftNode = newNode;
        }
        else{
            Insert(newNode, current->leftNode);
        }
    }
    else if(newNode->data > current->data){
        if(current->rightNode == nullptr){
            current->rightNode = newNode;
        }
        else{
            Insert(newNode, current->rightNode);
        }
    }
    else{
        cout << "Insert item failed." << endl;
    }
}


template <class T>
bool Bst<T>::Search(const T& item) const{
    Node<T>* current = root;
    bool found = false;
    if(root == nullptr){
        found = false;
    }
    else{
        while(current != nullptr && !found){
            if(current->data == item){
                found = true;
            }
            else if(current->data > item){
                current = current->leftNode;
            }
            else{
                current = current->rightNode;
            }
        }
    }
    return found;
}


template <class T>
void Bst<T>::DeleteTree(){
    DeleteTree(root);
}


template <class T>
void Bst<T>::DeleteTree(Node<T>*& current){
    if(current != nullptr){
        DeleteTree(current->leftNode);
        DeleteTree(current->rightNode);
        delete current;
        current = nullptr;
    }
}


template <class T>
void Bst<T>::InOrder(){
    InOrder(root);
}

template <class T>
void Bst<T>::InOrder(Node<T>* current) const{
    if(current != nullptr){
        InOrder(current->leftNode);
        cout << current->data << " ";
        InOrder(current->rightNode);
    }
}

template <class T>
void Bst<T>::PreOrder(){
    PreOrder(root);
}

template <class T>
void Bst<T>::PreOrder(Node<T>* current) const{
    if(current != nullptr){
        cout << current->data << " ";
        PreOrder(current->leftNode);
        PreOrder(current->rightNode);
    }
}

template <class T>
void Bst<T>::PostOrder(){
    PostOrder(root);
}

template <class T>
void Bst<T>::PostOrder(Node<T>* current) const{
    if(current != nullptr){
        PostOrder(current->leftNode);
        PostOrder(current->rightNode);
        cout << current->data << " ";
    }
}

#endif // INTBST_H_INCLUDED

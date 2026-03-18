#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>

/** \class Bst
 * \brief Bst object
 *
 * \author Clarence Lim Xing Yu
 * \version 1.01
 * \date 25/07/2024 Last Modified.
 *
 */

using namespace std;

template <class T>
struct Node{
    T data;
    Node<T>* leftNode;
    Node<T>* rightNode;

    //Node Constructor
    Node(const T& item) : data(item), leftNode(nullptr), rightNode(nullptr){};
};

template <class T>
class Bst{
public:
    Bst();
    /** \brief DeepCopy Constructor
     *
     * \param TreeCopy const Bst<T>&
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
     * \param TreeCopy Bst<T>&
     * \return Bst<T>&
     *
     */
    Bst<T>& operator = (const Bst<T>& TreeCopy);

    /** \brief Method to insert item into tree
     *
     * \param item const T
     * \return void
     *
     */
    void Insert(const T item);
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
    /** \brief Method using a functional ponter InOrder Traversal
     *
     * \param  T&
     * \return void
     *
     */
    void InOrder(void(*method)(T &));
    /** \brief Method to display tree data in PreOrder Traversal
     *
     * \return void
     *
     */
    void PreOrder();
    /** \brief Method using a functional ponter PreOrder Traversal
     *
     * \param  T&
     * \return void
     *
     */
    void PreOrder(void(*method)(T &));
    /** \brief Method to display tree data in PostOrder Traversal
     *
     * \return void
     *
     */
    void PostOrder();
    /** \brief Method using a functional ponter PostOrder Traversal
     *
     * \param  T&
     * \return void
     *
     */
    void PostOrder(void(*method)(T &));

protected:
    Node<T>* m_root = nullptr;

private:
    /** \brief Method where we copy the nodes from the old tree to a new tree
     *
     * \param oldTree Node<T>*&
     * \param newTree Node<T>*&
     * \return void
     *
     */
    void CopyTree(Node<T>*& oldTree, Node<T>*& newTree);
    void Insert(Node<T>*& current, const T item);
    void DeleteTree(Node<T>*& current);
    void InOrder(Node<T>* current) const;
    void InOrder(Node<T>* current, void(*method)(T &)) const;
    void PreOrder(Node<T>* current) const;
    void PreOrder(Node<T>* current, void(*method)(T &)) const;
    void PostOrder(Node<T>* current) const;
    void PostOrder(Node<T>* current, void(*method)(T &)) const;
};

template <class T>
Bst<T>::Bst(){
    m_root = nullptr;
}


template <class T>
Bst<T>::Bst(const Bst<T>& TreeCopy){
    if(TreeCopy.m_root == nullptr){
        m_root = nullptr;
    }
    else{
        CopyTree(TreeCopy, m_root);
    }
}


template <class T>
Bst<T>& Bst<T>::operator = (const Bst<T>& TreeCopy){
    if(this != &TreeCopy){
        if(m_root != nullptr){
            DeleteTree(m_root);
        }
        else if(TreeCopy.m_root == nullptr){
            m_root = nullptr;
        }
        else{
            CopyTree(TreeCopy.m_root, m_root);
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
void Bst<T>::Insert(const T item){
    Insert(m_root, item);
}


template <class T>
void Bst<T>::Insert(Node<T>*& current, const T item){
    if(current == nullptr){
        current = new Node<T>(item);
    }
    else if(item < current->data){
        Insert(current->leftNode, item);
    }
    else if(item > current->data){
        Insert(current->rightNode, item);
    }
    return;
}


template <class T>
bool Bst<T>::Search(const T& item) const{
    Node<T>* current = m_root;
    bool found = false;
    if(m_root == nullptr){
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
    DeleteTree(m_root);
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
    InOrder(m_root);
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
void Bst<T>::InOrder(void(*method)(T &)){
    InOrder(m_root->data, method);
}

template <class T>
void Bst<T>::InOrder(Node<T>* current, void(*method)(T &)) const{
    if(current == nullptr){
        return;
    }
    if(current->leftNode != nullptr){
        InOrder(current->leftNode, method);
    }
    InOrder(m_root->data);
    if(current->rightNode != nullptr){
        InOrder(current->rightNode, method);
    }
}

template <class T>
void Bst<T>::PreOrder(){
    PreOrder(m_root);
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
void Bst<T>::PreOrder(void(*method)(T &)){
    PreOrder(m_root->data, method);
}

template <class T>
void Bst<T>::PreOrder(Node<T>* current, void(*method)(T &)) const{
    if(current == nullptr){
        return;
    }
    InOrder(m_root->data);
    if(current->leftNode != nullptr){
        InOrder(current->leftNode, method);
    }
    if(current->rightNode != nullptr){
        InOrder(current->rightNode, method);
    }
}

template <class T>
void Bst<T>::PostOrder(){
    PostOrder(m_root);
}

template <class T>
void Bst<T>::PostOrder(Node<T>* current) const{
    if(current != nullptr){
        PostOrder(current->leftNode);
        PostOrder(current->rightNode);
        cout << current->data << " ";
    }
}

template <class T>
void Bst<T>::PostOrder(void(*method)(T &)){
    PostOrder(m_root->data, method);
}

template <class T>
void Bst<T>::PostOrder(Node<T>* current, void(*method)(T &)) const{
    if(current == nullptr){
        return;
    }
    if(current->leftNode != nullptr){
        PostOrder(current->leftNode, method);
    }
    if(current->rightNode != nullptr){
        PostOrder(current->rightNode, method);
    }
    PostOrder(m_root->data);
}
#endif // BST_H_INCLUDED

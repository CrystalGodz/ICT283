#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

/** \class Vector
 * \brief Vector object
 *
 * \author Clarence Lim Xing Yu
 * \version 1.01
 * \date 23/06/2024 Last Modified.
 *
 */

using namespace std;

template <class T>
class Vector{
public:
    Vector();
    ~Vector(){Clear();};
    void Clear();


    /** \brief Adds item to the end of the array
     *
     *
     * \param item const T&
     * \return bool
     *
     */
    bool Add(const T& item);
    /** \brief Remove item from end of array
     *
     * \return bool
     *
     */
    bool Remove();

    /** \brief Insert an item at specified index
     *
     * \param item const T&
     * \param n const unsigned
     * \return bool
     *
     */
    bool Insert(const T& item, const unsigned n);
    /** \brief Delete item from specified index
     *
     * \param n const unsigned
     * \return bool
     *
     */
    bool Delete(const unsigned n);

    /** \brief Retrieve the value from the index position
     *
     * \param n const unsigned
     * \return T&
     *
     */
    T& At(const unsigned n);
    /** \brief Modify value at index position
     *
     * \param item const T&
     * \param n const unsigned
     * \return T&
     *
     */
    T& Modify(const T& item, const unsigned n);

    /** \brief Return the size of the current array
     *
     * \return unsigned
     *
     */
    unsigned GetSize() const;
    /** \brief Return the capacity of the current array
     *
     * \return unsigned
     *
     */
    unsigned GetCapacity() const;

    /** \brief Used for testing by calling the vector array[n]
     *
     * \param n const unsigned
     * \return T&
     *
     */
    T& operator[](const unsigned n);

private:
    /** \brief Private method to expand the capacity of array
     *
     * \return bool
     *
     */
    bool Resize();

    /** \brief private constructors
     *
     * \param INITIAL_CAPACITY const unsigned
     * \param m_array T*
     * \param m_size int
     * \param m_capacity int
     *
     */
    const unsigned INITIAL_CAPACITY = 2;
    T* m_array;
    int m_size;
    int m_capacity;
};


template <class T>
Vector<T>::Vector(){
    m_array = new T[INITIAL_CAPACITY];
    m_capacity = 0;
    m_size = 0;
    if(m_array != nullptr){
        m_capacity = INITIAL_CAPACITY;
    }
}


template <class T>
void Vector<T>::Clear(){
    delete[] m_array;
    m_array = nullptr;
}


template <class T>
bool Vector<T>::Add(const T& item){
    if(m_size > m_capacity/2){
        Resize();
    }
    if(m_size > m_capacity){
        return false;
    }
    m_array[m_size] = item;
    m_size++;
    return true;
}


template <class T>
bool Vector<T>::Remove(){
    if(m_size <= 0){
        return false;
    }
    m_size--;
    return true;
}


template <class T>
bool Vector<T>::Insert(const T& item, const unsigned n){
    if(m_size > m_capacity/2){
        Resize();
    }
    if(m_size > m_capacity){
        return false;
    }
    for(unsigned i = m_size; i > n; i--){
        m_array[i] = m_array[i - 1];
    }
    m_array[n] = item;
    m_size++;
    return true;
}


template <class T>
bool Vector<T>::Delete(const unsigned n){
    if(n < 0 && n >= m_size){
        return false;
    }
    for(unsigned i = n; i < m_size; i++){
        m_array[i] = m_array[i + 1];
    }
    m_size--;
    return true;
}


template <class T>
T& Vector<T>::At(const unsigned n){
    if(n < 0 && n >= m_size){
        throw -1;
    }
    return m_array[n];
}


template <class T>
T& Vector<T>::Modify(const T& item, const unsigned n){
    if(n >= 0 && n < m_size){
        m_array[n] = item;
    }
    return m_array[n];
}


template <class T>
unsigned Vector<T>::GetSize() const{
    return m_size;
}


template <class T>
unsigned Vector<T>::GetCapacity() const{
    return m_capacity;
}

template <class T>
T& Vector<T>::operator[](const unsigned n){
    return m_array[n];
}


template <class T>
bool Vector<T>::Resize(){
    m_capacity = m_capacity*2;
    T* ExpandedArray = new T[m_capacity*2];
    if(ExpandedArray){
        for(unsigned i = 0; i < m_size; i++){
            ExpandedArray[i] = m_array[i];
        }
        delete[] m_array;
        m_array = ExpandedArray;
        m_capacity = m_capacity*2;
    }
    else{
        return false;
    }
    return true;
}
#endif // VECTOR_H_INCLUDED

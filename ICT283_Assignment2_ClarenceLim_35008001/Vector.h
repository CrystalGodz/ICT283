#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

/** \class Vector
 * \brief Vector object
 *
 * \author Clarence Lim Xing Yu
 * \version 1.01
 * \date 05/08/2024 Last Modified.
 *
 */

using namespace std;

template <class T>
class Vector{
public:
    Vector();
    Vector(const Vector& current);
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
     * \param index const unsigned
     * \return bool
     *
     */
    bool Insert(const T& item, const unsigned index);
    /** \brief Delete item from specified index
     *
     * \param index const unsigned
     * \return bool
     *
     */
    bool Delete(const unsigned index);

    /** \brief Retrieve the value from the index position
     *
     * \param index const unsigned
     * \return T&
     *
     */
    T& At(const unsigned index);
    /** \brief Modify value at index position
     *
     * \param item const T&
     * \param index const unsigned
     * \return T&
     *
     */
    T& Modify(const T& item, const unsigned index);

    /** \brief Return the size of the current array
     *
     * \return unsigned
     *
     */
    unsigned GetSize() const;
    /** \brief Return the capacity of the current array
     * used for testing the class Vector
     *
     * \return unsigned
     *
     */
    unsigned GetCapacity() const;

    /** \brief To declare the start of the For-Loop of the array
     *
     * \return T*
     *
     */
    T* begin() const;
    /** \brief To declare the end of the For-Loop of the array.
     *
     * \return T*
     *
     */
    T* end() const;

    /** \brief Used for testing to allow calling of vector array[index]
     *
     * \param index const unsigned
     * \return T&
     *
     */
    T& operator[](const unsigned index);
    /** \brief Copy operator for deep copying
     *
     * \param other const Vector<T>&
     * \return Vector<T>&
     *
     */
    Vector<T>& operator=(Vector<T>& other);

private:
    /** \brief Method to deep copy the vector
     *
     * \param other const Vector&
     * \return bool
     *
     */
    bool DeepCopy(Vector& other);
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
    T* m_array = new T[0];
    int m_size = 0;
    int m_capacity = 0;
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


template<class T>
Vector<T>::Vector(const Vector& current){
    DeepCopy(current);
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
bool Vector<T>::Insert(const T& item, const unsigned index){
    if(m_size > m_capacity/2){
        Resize();
    }
    if(m_size > m_capacity){
        return false;
    }
    for(unsigned i = m_size; i > index; i--){
        m_array[i] = m_array[i - 1];
    }
    m_array[index] = item;
    m_size++;
    return true;
}


template <class T>
bool Vector<T>::Delete(const unsigned index){
    if(index < 0 && index >= m_size){
        return false;
    }
    for(unsigned i = index; i < m_size; i++){
        m_array[i] = m_array[i + 1];
    }
    m_size--;
    return true;
}


template <class T>
T& Vector<T>::At(const unsigned index){
    if(index < 0 && index >= m_size){
        throw -1;
    }
    return m_array[index];
}


template <class T>
T& Vector<T>::Modify(const T& item, const unsigned index){
    if(index >= 0 && index < m_size){
        m_array[index] = item;
    }
    return m_array[index];
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
T* Vector<T>::begin() const{
    return m_array;
}


template <class T>
T* Vector<T>::end() const{
    return m_array + m_size;
}


template <class T>
T& Vector<T>::operator[](const unsigned index){
    return m_array[index];
}


template <class T>
Vector<T>& Vector<T>::operator=(Vector<T>& other){
    if(DeepCopy(other)){
        return *this;
    }
}


template<class T>
bool Vector<T>::DeepCopy(Vector<T>& other){
    T* NewVector = new T[other.GetCapacity()];
    for(unsigned i = 0; i < other.GetSize(); i++){
        NewVector[i] = other[i];
    }
    return true;
}


template <class T>
bool Vector<T>::Resize(){
    m_capacity = m_capacity*2;
    T* ExpandedArray = new T[m_capacity*2];
    if(ExpandedArray){
        for(int i = 0; i < m_size; i++){
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

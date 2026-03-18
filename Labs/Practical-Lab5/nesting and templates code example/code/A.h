/// Simple template class that stores (wraps) any type
/// Do not #include anything that is not referred to .h files


template <class T>
class A
{
public:
    const T& get() const;  /// accessor/getter is const. Why const twice?

        /// mutator/setter is not const. parameter is const as setter shouldn't
        /// modify the parameter sent by caller
    void set(const T& in);

private:
    T dat; /// any type can be stored
};

template <class T>
const T& A<T>::get() const  // accessor/getter is const. Why const twice?
{
    return dat;
}

// mutator/setter is not const. parameter is const as setter shouldn't modify the parameter sent by caller
template <class T>
void A<T>::set(const T& in)
{
    dat = in;
}

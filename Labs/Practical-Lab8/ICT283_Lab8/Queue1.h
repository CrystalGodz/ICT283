#ifndef QUEUE1_H_INCLUDED
#define QUEUE1_H_INCLUDED

const int CAPACITY = 6;

template <class T>
class Queue
{
public:
	Queue();
	~Queue(){};
	bool Enqueue(const T& data);
	bool Dequeue(T& data);
	bool Empty();
	bool Full();

private:
	int m_size;
	int m_front;
	int m_back;
	T m_queue[CAPACITY];

};


template<class T>
Queue<T>::Queue(){
    m_size = 0;
    m_front = -1;
    m_back = -1;
}


template<class T>
bool Queue<T>::Empty()
{
	return m_size == 0;
}


template<class T>
bool Queue<T>::Full()
{
	return m_size == CAPACITY;
}


template<class T>
bool Queue<T>::Enqueue(const T &data)
{
    if(Full()){
        return false;
    }
    else{
        if(Empty()){
            m_front = 0;
        }
        m_size++;
        m_back++;
        m_back = m_back % CAPACITY;
        m_queue[m_back] = data;
        return true;
    }

    /** Lecture 22 Topic 8 Slide 24
	IF m_size >= ARRAY_SIZE (0 >= 3)
		return FALSE
	ELSE
             	if(m_size == 0)
             		m_front = 0;
 		ENDIF
		Increment m_size
		Increment m_back MOD ARRAY_SIZE [1]
		Place data at position m_back
		return TRUE
	ENDIF
    */
}


template<class T>
bool Queue<T>::Dequeue(T &data)
{
	if(Empty()){
        return false;
	}
	else{
        data = m_queue[m_front];
        m_front++;
        m_front = m_front % CAPACITY;
        m_size--;
        if(Empty()){        //if queue is Empty() due to Dequeing
            m_front = -1;   //reset m_front and m_back to -1
            m_back = -1;
        }
        return true;
	}
	/** Lecture 22 Topic 8 Slide 25
	IF m_size == 0
		return FALSE
	ELSE
		data = data at position m_front
		Increment m_front MOD ARRAY_SIZE
		Decrement m_size
		IF m_size == 0
			m_front = -1
			m_back = -1
		ENDIF
		return TRUE
	ENDIF
    */
}

#endif // QUEUE1_H_INCLUDED

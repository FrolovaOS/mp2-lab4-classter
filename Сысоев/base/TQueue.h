
#ifndef __TQueue_H__
#define __TQueue_H__


const int MaxTQueueSize = 100;

template <class T>
class TQueue
{
	T* pMem;
	int size;
	int top;
public:
	TQueue(int _size);
	~TQueue() { delete[] pMem; }
	void Push(T elem);                             //добавить элемент 
	T Pop();                                       //удаление 
	bool IsEmpty() { return top == -1; }		   //проверка на пустоту 
	bool IsFull() { return top == size - 1; }	   // полнота 
	T GetTop() { return pMem[0]; }				   //получить элемент
	int TQueueLength() { return top + 1; }         //количество элементов в стеке
};
template<class T>
inline TQueue<T>::TQueue(int _size)
{
	{
		if ((_size < 1) || (_size > MaxTQueueSize))
			throw "Error";

		size = _size;
		top = -1;
		pMem = new T[size];

	}
}
template <class T>
void TQueue<T>::Push(T elem)
{
	if (IsFull())
		throw "Stack is full";
	else
	{
		top++;
		pMem[top] = elem;
	}
}
template <class T>
T TQueue<T>::Pop()
{
	if (IsEmpty())
		throw "Stack is empty";
	else {
		T top1 = pMem[0];
		for (int i = 0; i < top; i++)
		{
			pMem[i] = pMem[i + 1];
		}
		top--;
		return top1;
	}
}
#endif
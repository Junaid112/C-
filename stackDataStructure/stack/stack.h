#include<iostream>
using namespace std;



#ifndef STACK_H
#define STACK_H
template <class T>
class Stack
{
	private:
		T *data;
		int capacity;
		int top;
	public:
		Stack(int);
		int isFull();
		int isEmpty();
		void push(T);
		T pop();
		T StackTop();
		int getTheNoOfElements();
};
#endif
template <class T>
Stack<T>::Stack(int cap)
{
	capacity=cap;
	top=0;
	data = new T [capacity];
}
template <class T>
int Stack<T>::isFull()
{
	if(top>=capacity)
		return 1;
	return 0;
}
template <class T>
int Stack<T>::isEmpty()
{
	if(top==0)
		return 1;
	return 0;
}
template <class T>
void Stack<T>:: push(T val)
{
	if(isFull())
		throw exception("Stack is full");
	data[top++]=val;
}
template <class T>
T Stack<T> :: pop()
{
	if(isEmpty())
		throw exception("Stack is empty");
	return data[--top];
}
template <class T>
T Stack<T>:: StackTop()
{
	if(isEmpty())
		throw exception("Stack is empty");
	return data[top-1];
}
template <class T>
int Stack<T>::getTheNoOfElements()
{
	return top;
}


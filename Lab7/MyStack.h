#pragma once
#include<iostream>
using namespace std;


 
template<typename T, size_t size = 10> //f
class MyStack
{
private:
	int m_len;
	T m_data[size];
	
public:
	MyStack() { m_len = 0; 
	for (size_t i = 0; i < size; i++)
	{
		m_data[i] = T();
	}
	
	}
	MyStack(int len,T data):m_len(len)
	{
		for (size_t i = 0; i < m_len; i++)
		{
			m_data[i] = data;
		}
		
		
	}
	~MyStack()
	{
		
	}

	T& operator[](int index)//f
	{
		if (index >=0 && index <= m_len) {
			return m_data[index];
		}
		else {
			throw "The Value is`t correct";
		}
	}
	int getLen()
	{
		return m_len;
	}
	void push( const T& data)//f
	{
		if (size < m_len) {
			m_data[m_len] = data;
			m_len++;
		}
		else {
			throw "The Value is`t correct";
		}
		
	}
	T pop( )
	{
		
		if (m_len > 0) {
			m_len--;
			return m_data[m_len];
			
		}
		else {
			throw "The Value is`t correct";
		}
	}
	
};

//template<typename T>
//int MyStack::getLen() { return m_len; }
//template<typename T>
//void MyStack<T>::push_back(const T& x)
//{
//	for (size_t i = 0; i < m_len; i++)
//	{
//		m_data[i] = x;
//	}
//}
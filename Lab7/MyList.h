#pragma once
template<class T>
class MyList
{
private:
	class Node
	{
	private:
		T m_data;
		Node* m_next;
	public:
		friend class MyList;
		Node():m_next(nullptr){}
		Node(const T& data):m_data(data), m_next(nullptr){}
		
	};
	Node* Head;
	Node* Tail;
	int Size;
public:
	MyList(): Head (nullptr), Tail(Head) {}
	~MyList() {
		
		while (Head != nullptr)
		{
			Node* cur = Head->m_next;
			delete Head;
			Head = cur;
		}

	}
	MyList(const MyList<T>& other);
	MyList(MyList<T>&& other);
	MyList<T>& operator=(const MyList<T>& ls);
	MyList<T>& operator=(MyList<T>&& ls);
	bool is_empty();
	void push(const T& data);
	//void pop(const T& data);
	//typedef T* iterator;
	//iterator end(return Size);
	void print();
	//void print_end();
};

template<typename  T>
inline MyList<T>::MyList(const MyList<T>& other): Size(other.Size)
{
	
	if (!other.Head) {
		Size = 0;
		Head = nullptr;
		return;
	}

	Head = new Node(*other.Head);
	Node* cur = Head;
	Size = 1;

	for (Node* t = other.Head->m_next; t != nullptr; t = t->m_next) {
		cur->m_next = new Node(*t);
		cur = cur->m_next;
		++Size;
	}
	cur->m_next = nullptr;
}

template<typename T>
inline MyList<T>::MyList(MyList<T>&& other) : Size(other.Size)
{
	Head = other.Head;
	other.Head = nullptr;
	other.Size = 0;
}

template<typename T>
inline MyList<T>& MyList<T>::operator=(const MyList<T>& ls)//f
{
	if (this == &ls)
	{
		return *this;
	}
	this->~MyList();
	//delete this;
	Node* cur = ls.Head;
	while (cur != nullptr)
	{
		this->push(cur->m_data);
		cur = cur->m_next; 
	}
	return *this;
	/*if (Size < ls.Size) {
		Size = ls.Size;
		Node* cur = ls.Head;
		while (cur != nullptr)
		{
			this->Add(cur->m_data);
			cur = cur->m_next; 
			
		}
	}
	return *this;*/
}

template<typename T>
inline MyList<T>& MyList<T>::operator=(MyList<T>&& ls)//f
{
	if (this == &ls)
	{
		return *this;
	}
	this->~MyList();
			Head->m_next = ls.Head->m_next;
			ls.Head->m_next = ls.Head;
			ls.Size = 0;
		
	return *this;
}
template<typename  T>
inline bool MyList<T>:: is_empty() {
	return Head == nullptr;
}
template<typename  T>
inline void MyList<T>::push(const T& data)
{
	/*Node* tmp = new Node(data);
	tmp->m_next = Head;
	Head = tmp;
	Size++;*/
	Node* cur = new Node(data);
	if (is_empty()) {
		Head = cur;
		Tail = cur;
		return;
	}
	Tail->m_next = cur;
	Tail = cur;
}

	

//template<typename T>
//inline void MyList<T>::pop(const T& data)
//{
//	Node* cur = Head;
//	while (cur->m_data != data)
//	{
//		cur = cur->m_next;
//	}
//	cur->m_data = cur->m_next->m_data;
//	delete cur->m_next;
//	cur->m_next = Tail;
//	/*delete Head;
//	Head = cur->m_next;*/
//	
//	Size--;
//	/*Node* p = first;
//	first = p->next;
//	delete p;
//
//	Node* p = first;
//	while (p->next != last) p = p->next;
//	p->next = nullptr;
//	delete last;
//	last = p;*/
//}

template<typename  T>
inline void MyList<T>::print()//f
{
	Node *cur = Head;
	while (cur)
	{
		cout << cur->m_data << " ";
		cur = cur->m_next;
	}
	cout << endl;
}

//template<class T>
//inline void MyList<T>::print_end()
//{
//
//	Node* cur = Tail;
//	while (cur)
//	{
//		cout << cur->m_data << " ";
//		cur = cur->m_next;
//	}
//}

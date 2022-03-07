//����������

//�������: 
	//		������� �������,
	//		������� �������,


#include <tchar.h>
#include"MyStack.h"
#include"MyList.h"
#include"MyString.h"
	//#include <stdexcept>


#define stop __asm nop
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<>
void Swap(MyString& a, MyString& b)
{
	MyString tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);


}

int _tmain(int argc, _TCHAR* argv[])
{
	


////////////////////////////////////////////////////////////////////////////
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.

	int iX = 1, iY = -1;
	cout << iX << " " << iY << endl;
	Swap(iX, iY);
	cout << iX << " " << iY << endl;


	double dX = 0.5, dY = -5.5;
	cout << dX << " " << dY << endl;
	Swap(dX, dY);
	cout << dX << " " << dY << endl;



	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	MyString str1("One"), str2("Two");
	cout << str1 << " " << str2 << endl;
	Swap(str1, str2);//f
	cout << str1 << " " << str2 << endl;


/////////////////////////////////////////////////////////////////////
	
	//����. ������� �������.
	//������� 1.
	//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
	//			��� �������� ��������������� ������������� � ������ ���������
	//			�������� ������, 
	//			2.��� ������� ������������� ������� ����� ����� ���� �����������
	//			��������-��������� �������
	//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
	//			����, ����� ������������� ���������� ���������� ���� �������� 
	//			������ ���� �� ������������ ���������� � ��������� ��������
	//			4. ������������� ���������� operator[] ����� �������, ����� ������������
	//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������

	
	//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
	//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
	//push() � pop(), operator[]

 	MyStack<int> intStack(5,3);
	



	try
	{
		intStack.push(3);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	
	try
	{
		intStack.push(6);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	try
	{
		intStack.push(9);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	
	
	//intStack.push_back(12);
	//intStack.push_back(15);
	try
	{
		intStack.pop();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	try
	{
		intStack.pop();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	

	
	for (int i = 0; i < intStack.getLen(); i++)
	{
		cout << intStack[i] << " ";
	}
	cout << endl;
	MyStack<MyString> MyStrungStack(10, "yo");
	try
	{
		MyStrungStack.push( "go");
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	try
	{
		MyStrungStack.push( "hi");
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	try
	{
		MyStrungStack.pop();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	try
	{
		MyStrungStack.pop();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	
	
	
	
	for (int i = 0; i < MyStrungStack.getLen(); i++)
	{
		cout << MyStrungStack[i] << " ";
	}
	cout << endl;

	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������

	MyList<int> list_int;
	MyList<int> list_int1;
	MyList<int> list_int2;
	MyList<string> list_str;
	MyList<MyString> listMyString;

	list_int.push(4);
	list_int.push(8);
	list_int.push(12);
	list_int1.push(66);
	list_int2.push(77);
	list_int = list_int1;
	cout << "=";
	list_int.print();
	list_str.push("go");
	list_str.push("hi");
	list_str.push("my");
	listMyString.push("Mygo");
	listMyString.push("Myhi");
	listMyString.push("Mymy");
	


	/*MyList<int> list234(list);
	list1.push("hello");
	MyList<string> list136(list1);
	MyList<MyString> listMyString;
	listMyString.push("qwerty");
	MyList<MyString> listMyStrin1(listMyString);
	listMyString = listMyStrin1;
	cout << "print" << endl;*/
	cout << "Print List_int" << endl;
	list_int.print();
	cout << "Print List_str" << endl;
	list_str.print();
	cout << "Print List_Mystr" << endl;
	listMyString.print();
	
	
	//listMyString.print();

	

	return 0;
}


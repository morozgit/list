//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,


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
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

	int iX = 1, iY = -1;
	cout << iX << " " << iY << endl;
	Swap(iX, iY);
	cout << iX << " " << iY << endl;


	double dX = 0.5, dY = -5.5;
	cout << dX << " " << dY << endl;
	Swap(dX, dY);
	cout << dX << " " << dY << endl;



	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
	MyString str1("One"), str2("Two");
	cout << str1 << " " << str2 << endl;
	Swap(str1, str2);//f
	cout << str1 << " " << str2 << endl;


/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал

	
	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]

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

	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь

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


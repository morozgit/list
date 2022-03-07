//#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
//#define _CRT_SECURE_NO_WARNINGS 

// ����������� ������������.
MyString::MyString() {
	m_pStr = new char[1];
	m_pStr[0] = '\0';
}

MyString::MyString(const char* pStr) {
	int n = 0;
	while (*(pStr + n)) {
		n++;
	}
	m_pStr = new char[n + 1];
	for (size_t i = 0; i < n; i++)
	{
		m_pStr[i] = pStr[i];
	}
	m_pStr[n] = '\0';
	//delete[] m_pStr;
}

MyString::MyString(const MyString& other) {
	m_pStr = new char[strlen(other.m_pStr) + 1];
	strcpy(m_pStr, other.m_pStr);
}

const char* MyString::GetString()
{
	return m_pStr;
}

void MyString::SetNewString(const char* pString) {
	int n = 0;
	while (*(pString + n)) {
		n++;
	}

	/*if (m_pStr)
		delete []m_pStr;*/

	m_pStr = new char[n + 1];
	for (size_t i = 0; i < n; i++)
	{
		m_pStr[i] = pString[i];
	}
	m_pStr[n] = '\0';
	delete[] m_pStr;
}

MyString& MyString::operator = (const MyString& p) {
	if (this != &p) {
		delete[] m_pStr;


		m_pStr = new char[strlen(p.m_pStr) + 1];
		strcpy(m_pStr, p.m_pStr);
	}
	//m_pStr = p.m_pStr;
	return *this;


}

MyString& MyString::operator = (const char* a) {
	if (this->m_pStr != nullptr)
	{
		delete[] m_pStr;
	}
	m_pStr = new char[strlen(a) + 1];
	strcpy(m_pStr, a);
	return *this;
}

bool operator == (const MyString& Mstr, const char* str)
{
	return !strcmp(Mstr.m_pStr,str);
}

MyString MyString::operator + (MyString& str1) {

	char* sub = new char[strlen(m_pStr) + strlen(str1.m_pStr) + 1];
	strcpy(sub, this->m_pStr);
	strcat(sub, str1.m_pStr);
	//return  MyString(sub);
	//delete[] m_pStr;
	  MyString ret(sub);
	 delete[] sub;
	 return ret;
}

MyString& MyString::operator+=(const MyString& rvalue) {   //���������� +=

	char* sub = new char[strlen(m_pStr) + strlen(rvalue.m_pStr) + 1];
	strcpy(sub, this->m_pStr);
	strcat(sub, rvalue.m_pStr);
	//this->operator=(sub);
	delete[] m_pStr;
	m_pStr = sub;
	return *this;
	// return  MyString(sub);
	 /*delete[] m_pStr;
	 MyString ret(sub);
	 delete[] sub;
	 return ret;*/
	 //return Point(ra.x += n, ra.y += n);
}

MyString& MyString::operator= (MyString&& p)
{
	if (this != &p)
	{
		delete[] m_pStr;
		m_pStr = p.m_pStr;
		p.m_pStr = nullptr;
	}
	return *this;
}


ostream& operator << (ostream& os, const MyString& an) {
	os << " " << an.m_pStr;
	return os;
}



// ����������� �����������.
MyString::~MyString() {

	delete[] m_pStr;
	m_pStr = nullptr;
}
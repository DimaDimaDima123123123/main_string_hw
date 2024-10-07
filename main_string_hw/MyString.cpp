#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
#include <iostream>

using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		str[i] = '*';
	}
	str[length] = '\0';
}

MyString::MyString(bool askSize)
{
	cout << "Введите желаемый размер строки: ";
	cin >> length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		str[i] = '*';
	}
	str[length] = '\0';
}
MyString::MyString(const char* initializedString)
{
	length = static_cast<int>(strlen(initializedString));
	str = new char[length + 1];
	strcpy_s(str, length + 1, initializedString);
}
MyString::~MyString()
{
	delete[] str;
}
int MyString::getLength() const
{
	return length;
}
const char* MyString::getString() const
{
	return str;
}
void MyString::inputString()
{
	cout << "Введите строку: ";
	char buffer[1000];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(buffer, 1000);
	length = strlen(buffer);
	delete[] str;
	str = new char[length + 1];
	strcpy(str, buffer);
}
void MyString::printString() const
{
	cout << str << endl;
}
void MyString::MyStrcpy(MyString& obj)
{
	delete[] str;
	length = obj.getLength();
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.getString());
}
bool MyString::MyStrStr(const char* substring)
{
	return strstr(str, substring) != nullptr;
}
int MyString::MyChr(char c)
{
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	int newLength = length + b.getLength();
	char* newStr = new char[newLength + 1];
	strcpy_s(newStr, newLength + 1, str);
	strcat_s(newStr, newLength + 1, b.getString());
	delete[] str;
	str = newStr;
	length = newLength;
}
void MyString::MyDelChr(char c)
{
	int newLength = 0;
	for (int i = 0; i < length; ++i)
	{
		if (str[i] != c)
		{
			str[newLength++] = str[i];
		}
	}
	str[newLength] = '\0';
	length = newLength;
}
int MyString::MyStrCmp(MyString& b)
{
	int comparison = strcmp(str, b.getString());
	if (comparison < 0)
	{
		return -1;
	}
	else if (comparison > 0)
	{
		return 1;
	}
	return 0;
}
// конструктор копирование
MyString::MyString(const MyString& other) 
{
	length = other.length;
	str = new char[length + 1]; 
	strcpy_s(str, length + 1, other.str); 
}


MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{ // проверка на самоприсваивание
		delete[] str; // удаление старого массив
		length = other.length;
		str = new char[length + 1];
		strcpy_s(str, length + 1, other.str);
	}
	return *this;
}

// реализация оператора индексирования
char& MyString::operator[](int index)
{
	if (index < 0 || index >= length)
	{
		throw out_of_range("Индекс вне диапазона"); // исключение при неправильном индексе
	}
	return str[index];
}

// реализация оператора вызова функции
void MyString::operator()() const
{
	cout << str << endl; // вывод строки в консоль
}



// (1) Move semantic
MyString::MyString(MyString&& other) noexcept
{
	str = other.str;
	length = other.length;
	other.str = nullptr;
	other.length = 0;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		delete[] str;
		str = other.str;
		length = other.length;
		other.str = nullptr;
		other.length = 0;
	}
	return *this;
}

// 2) Перегрузку ввода-вывода (friend function)
ostream& operator<<(std::ostream& os, const MyString& obj)
{
	os << obj.getString();  // Использование метода getString() для доступа к str
	return os;
}

istream& operator>>(std::istream& is, MyString& obj)
{
	char buffer[1000];
	is.getline(buffer, 1000);
	delete[] obj.str;
	obj.length = strlen(buffer);
	obj.str = new char[obj.length + 1];
	strcpy_s(obj.str, obj.length + 1, buffer);
	return is;
}

// 3) a += "Hello world";  // методом
MyString& MyString::operator+=(const char* other)
{
	int otherLength = strlen(other);
	int newLength = length + otherLength;
	char* newStr = new char[newLength + 1];
	strcpy_s(newStr, newLength + 1, str);
	strcat_s(newStr, newLength + 1, other);
	delete[] str;
	str = newStr;
	length = newLength;
	return *this;
}

// 4) MyString b; b = "Hello" + a; // перегрузка через функцию
MyString operator+(const char* lhs, const MyString& rhs)
{
	int lhsLength = strlen(lhs);
	int newLength = lhsLength + rhs.getLength();
	char* newStr = new char[newLength + 1];
	strcpy_s(newStr, newLength + 1, lhs);
	strcat_s(newStr, newLength + 1, rhs.getString()); 

	MyString result(newStr);
	delete[] newStr;
	return result;
}

#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
class MyString
{
private:
    char* str;
    int length;

public:
    MyString();
    MyString(bool askSize);
    MyString(const char* initializedString);
    ~MyString();

    int getLength() const;
    const char* getString() const;

    void inputString();
    void printString() const;

    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* str);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);

    MyString(const MyString& other); 


    MyString& operator=(const MyString& other);

    char& operator[](int index);
 
    void operator()() const;



    // (1) Move semantic
    MyString(MyString&& other) noexcept;  // ����������� �����������
    MyString& operator=(MyString&& other) noexcept;  // �������� ������������ � ���������

    // 2) ���������� �����-������ (friend function)
    friend ostream& operator<<(ostream& os, const MyString& obj);
    friend istream& operator>>(istream& is, MyString& obj);

    // 3) a += "Hello world";  // ������� �������
    MyString& operator+=(const char* other);

    // 4) MyString b; b = "Hello" + a; // ���������� ����� �������!!
    friend MyString operator+(const char* lhs, const MyString& rhs);


};

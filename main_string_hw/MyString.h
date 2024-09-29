#pragma once
#define _CRT_SECURE_NO_WARNINGS

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
};

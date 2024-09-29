
#include <iostream>
#include <C:\Users\Admin\source\repos\main_string_hw\main_string_hw\MyString.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    MyString origstr("Строка строченька");
    cout << "Оригинальная строка: " << origstr.getString() << endl;

    MyString copystr = origstr;
    cout << "Копия строки: " << copystr.getString() << endl;

    // использование оператора индексирования
    cout << "Первый символ копии: " << copystr[0] << endl;

    // использование оператора вызова функции
    copystr(); // вывод строки в консоль

    /*MyString firstString;
    cout << "Строка длинной 80: '" << firstString.getString() << "'\n";

    MyString secondString(true);
    cout << secondString.getLength() << "-длинна строки: '" << secondString.getString() << "'\n";

    MyString initializedString("Здрасьте");
    cout << "Строка инициализированная конструктором: " << initializedString.getString() << "'\n";

    MyString inputStr;
    inputStr.inputString();
    inputStr.printString();

    MyString str1("Дерево");
    MyString str2;
    str2.MyStrcpy(str1);
    str2.printString();

    if (str1.MyStrStr("пту"))
    {
        cout << "Подстрока найдена\n";
    }
    else
    {
        cout << "Подстрока не найдена\n";
    }

    int index = str1.MyChr('р');
    if (index != -1)
    {
        cout << "Символ найден по индексу " << index << endl;
    }
    else
    {
        cout << "Символ не найден\n";
    }

    cout << "Длинна str1: " << str1.MyStrLen() << endl;
    cout << "Длинна str2: " << str2.MyStrLen() << endl;

    MyString str3(" Досвиданья");
    str1.MyStrCat(str3);
    str1.printString();
    cout << "Длина содержимого str1: " << str1.MyStrLen() << endl;

    str1.MyDelChr('о');
    str1.printString();
    cout << "Длинна str1 после удаления 'о': " << str1.MyStrLen() << endl;

    int cmp = str1.MyStrCmp(str2);
    if (cmp == 0) {
        cout << "0" << endl;
    }
    else if (cmp > 0) {
        cout << "1" << endl;
    }
    else {
        cout << "-1" << endl;
    }
    */

    return 0;
};
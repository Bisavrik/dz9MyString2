#include "MyString.h"
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

int MyString::objectCount = 0;

MyString::MyString()
{
    length = 80;
    str = new char[length + 1];
    memset(str, 0, length + 1);
    objectCount++;
}

MyString::MyString(int size)
{
    length = size;
    str = new char[length + 1];
    memset(str, 0, length + 1);
    objectCount++;
}

MyString::MyString(const char* inputStr)
{
    length = strlen(inputStr);
    str = new char[length + 1];
    strcpy(str, inputStr);
    objectCount++;
}

MyString::~MyString()
{
    delete[] str;
    objectCount--;
}

void MyString::input()
{
    cin.getline(str, length + 1);
}

void MyString::output() const
{
    cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
    if (this != &obj)
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }
}

bool MyString::MyStrStr(const char* substr)
{
    return strstr(str, substr) != nullptr;
}

int MyString::MyChr(char c)
{
    char* pos = strchr(str, c);
    return pos ? pos - str : -1;
}

int MyString::MyStrLen() const
{
    return length;
}

void MyString::MyStrCat(MyString& b)
{
    char* newStr = new char[length + b.length + 1];
    strcpy(newStr, str);
    strcat(newStr, b.str);
    delete[] str;
    str = newStr;
    length += b.length;
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
    int cmp = strcmp(str, b.str);
    if (cmp < 0) return -1;
    if (cmp > 0) return 1;
    return 0;
}

MyString MyString::operator+(const MyString& b)
{
    MyString newStr(length + b.length);
    strcpy(newStr.str, str);
    strcat(newStr.str, b.str);
    return newStr;
}

MyString& MyString::operator++()
{
    char* newStr = new char[length + 2];
    newStr[0] = ' ';
    strcpy(newStr + 1, str);
    delete[] str;
    str = newStr;
    length++;
    return *this;
}

MyString& MyString::operator--()
{
    if (length > 0)
    {
        str[length - 1] = '\0';
        length--;
    }
    return *this;
}

char& MyString::operator
{
    if (index >= 0 && index < length)
    {
        return str[index];
    }
    throw out_of_range("Index out of range");
}

MyString& MyString::operator+=(char c)
{
    char* newStr = new char[length + 2];
    strcpy(newStr, str);
    newStr[length] = c;
    newStr[length + 1] = '\0';
    delete[] str;
    str = newStr;
    length++;
    return *this;
}

MyString& MyString::operator+=(int n)
{
    char* newStr = new char[length + n + 1];
    strcpy(newStr, str);
    memset(newStr + length, ' ', n);
    newStr[length + n] = '\0';
    delete[] str;
    str = newStr;
    length += n;
    return *this;
}

MyString operator+(char c, MyString& obj)
{
    MyString newStr(obj.length + 1);
    newStr.str[0] = c;
    strcpy(newStr.str + 1, obj.str);
    return newStr;
}

MyString operator+(int n, MyString& obj)
{
    MyString newStr(obj.length + n);
    memset(newStr.str, ' ', n);
    strcpy(newStr.str + n, obj.str);
    return newStr;
}

int MyString::getObjectCount()
{
    return objectCount;
}

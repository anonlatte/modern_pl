#include <cstring>
#include <iostream>
#include "6.h"
#include <ostream>

using namespace std;

namespace stringNamespace {
    static int length(const char *s1) {
        int i = 0;
        while (*s1++ != '\0') {
            i++;
        }
        return i;
    }

    static void copy(char *s1, const char *s2) {

        int len = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);

        for (int i = 0; i <= len; i++) {
            s1[i] = s2[i];
        }
    }

    static int compare(char *str1, char *str2) {
        int maxLength = min(length(str1), length(str2));
        for (int i = 0; i < maxLength; i++) {
            if (str1[i] != str2[i]) return -1;
        }

        return 0;
    }

    static void concat(char *str1, char *str2) {
        int size1 = length(str1);
        char *r = new char[size1 + length(str2)];

        int i = 0;
        for (; i < size1; i++)
            r[i] = str1[i];

        int j = 0;
        while (str2[j] != '\0') r[i++] = str2[j++];

        copy(str1, r);
    }

}

// region Constructors
String::String(const char *s) {
    char *newStr = new char[stringNamespace::length(s)];
    str = newStr;
    stringNamespace::copy(str, s);
}

String::String(const String &s) {
    char *newStr = new char[stringNamespace::length(s.str)];
    str = newStr;
    stringNamespace::copy(str, s.str);
}
// endregion

String &String::operator=(const String &s) {
    char *newStr = new char[stringNamespace::length(s.str)];
    str = newStr;
    stringNamespace::copy(str, s.str);
    return *this;
}

String &String::operator+(const String &s) {
    stringNamespace::concat(str, s.str);
    return *this;
}

int String::operator==(const String &s) {
    return stringNamespace::compare(str, (char *) s.str) == 0;
}

int String::length() {
    return stringNamespace::length(str);
}

void String::input() {
    cout << "Enter string: ";
    cin.getline(str, 50);
}

void String::output() {
    cout << str << endl;
}

// >> Дополнение для ЛР №8
istream &operator>>(istream &is, String &s) {
    char buff[1024];
    cin >> buff;
    s.str = new char[strlen(buff)];
    stringNamespace::copy(s.str, buff);
    return is;
}

ostream &operator<<(ostream &os, String &s) {
    cout << s.str;
    return os;
}
#include <cstring>
#include <iostream>

using namespace std;

/*
 * Первый способ определения длины строки.
 * Цикл ссылочно проходит по всем символам строки и считает их количество,
 * заканчивая на символе конца строки '\0'.
 */
int dlina1(char *str) {
    int i = 0;
    while (*str++ != '\0') i++;
    return i;
}

/*
 * Второй способ определения длины строки.
 * Цикл проходит по всем символам строки и считает их количество,
 * заканчивая на символе конца строки '\0'.
 */
int dlina2(const char *str) {
    int i = 0, size = 0;
    while (str[i++] != '\0') size++;
    return size;
}

/*
 * Третий способ определения длины строки.
 * Цикл проходит по всем символам строки и считает их количество,
 * заканчивая на символе конца строки '\0'.
 */
int dlina3(char *p) {

    char *q = p;

    while (*q++ != '\0');

    return q - p - 1;
}

/*
 * Функция копирования строки s2 в строку s1.
 * При этом, если длина s2 больше длины s1, то копируется длина s1,
 * иначе копируется длина s2.
 */
void copy(char *s1, char *s2) {

    int len = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);

    for (int i = 0; i <= len; i++) {
        s1[i] = s2[i];
    }
}

/*
 * Сравнение строк.
 * Сравнивается длина строк и их содержимое.
 */
int compare(char *str1, char *str2) {
    int maxLength = min(dlina1(str1), dlina1(str2));
    for (int i = 0; i < maxLength; i++) {
        if (str1[i] != str2[i]) return -1;
    }

    return 0;
}

// Сцепление строк
void concat(char *str1, char *str2) {
    int size1 = dlina1(str1);
    char *r = new char[size1 + dlina1(str2)];

    int i = 0;
    for (; i < size1; i++)
        r[i] = str1[i];

    int j = 0;
    while (str2[j] != '\0') r[i++] = str2[j++];

    copy(str1, r);
}

// Вывод результатов работы функций
void process(char str1[], char str2[]) {
    cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

    cout << "dlina1: str1 = " << dlina1(str1) << ", str2 = " << dlina1(str2) << endl;
    cout << "dlina2: str1 = " << dlina2(str1) << ", str2 = " << dlina2(str2) << endl;
    cout << "dlina3: str1 = " << dlina3(str1) << ", str2 = " << dlina3(str2) << endl;

    copy(str1, str2);
    cout << "copy: str1 = " << str1 << ", str2 = " << str2 << endl;

    cout << "compare: str1 " << (compare(str1, str2) == 0 ? "==" : "!=") << " s2 " << endl;

    concat(str1, str2);
    cout << "concat: str1 = " << str1 << ", str2 = " << str2 << endl;
}

/*
 * Использующие динамическую память функции
 */
void malloc() {
    char *str1, *str2;

    str1 = (char *) malloc(100);
    str2 = (char *) malloc(100);

    process(str1, str2);

    free(str1);
    free(str2);
}

/*
 * Использующие динамическую память функции.
 * Отличается от malloc тем, что обнуляет выделенную память.
 */
void calloc() {
    char *str1, *str2;

    str1 = (char *) calloc(100, sizeof(char));
    str2 = (char *) calloc(100, sizeof(char));

    process(str1, str2);

    free(str1);
    free(str2);
}

void stringArr() {
    char *strs[] = {"123", "456", "789"};

    for (char *s: strs) {
        cout << "dlina1: s = " << dlina1(s) << endl;
        cout << "dlina2: s = " << dlina2(s) << endl;
        cout << "dlina3: s = " << dlina3(s) << endl;
    }

    compare(strs[0], strs[1]);
    cout << "after compare: strs[0] = " << strs[0] << ", strs[1] = " << strs[1] << endl;

    concat(strs[0], strs[1]);
    cout << "after concat: strs[0] = " << strs[0] << ", strs[1] = " << strs[1] << endl;

    copy(strs[0], strs[1]);
    cout << "after copying: strs[0] = " << strs[0] << ", strs[1] = " << strs[1] << endl;

}

int main() {
    char str1[] = "testStroke", str2[] = "qweqwe";
    process(str1, str2);

    cout << "----- malloc -----" << endl;
    malloc();

    cout << "----- calloc -----" << endl;
    calloc();

    cout << "----- stringArr -----" << endl;
    stringArr();

    return 0;
}


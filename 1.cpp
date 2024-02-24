#include <iostream>
#include <cstdio>

int pow(int x, int n) {
    int p = 1;
    for (int i = 0; i < n; ++i) {
        p *= x;
    }
    return p;
}

// Модифицированная программа с вычислением степени с любым основанием
int first_task() {
    int powResult, base;
    std::cin >> base;
    for (int i = 0; i < 10; ++i) {
        powResult = pow(base, i);
        std::cout << "i = " << i << ", powResult = " << powResult << std::endl;
    }
    return 0;
}

// region Второе задание
#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)

void second_task_source() {
    int mas[] = {100, 200, 300};
    int *ptr1, *ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
}

void second_task_var2() {
    float mas[] = {100.0, 200.0, 300.0};
    float *ptr1, *ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
}

void change1(int a, int b) {
    // обмен не случится, т.к. работа происходит с копиями
}

void change2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void change3(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
// endregion

// Третье задание
void third_task() {
    int a = 2, b = 5;
    std::cout << "before change: a = " << a << ", b = " << b << std::endl;
    change1(a, b);
    std::cout << "after change 1: a = " << a << ", b = " << b << std::endl;
    change2(&a, &b);
    std::cout << "after change 2: a = " << a << ", b = " << b << std::endl;
    change3(a, b);
    std::cout << "after change 3: a = " << a << ", b = " << b << std::endl;
    /*
     * before change: a = 2, b = 5
     * after change 1: a = 2, b = 5 // не поменялось, т.к. передается копия
     * after change 2: a = 5, b = 2
     * after change 3: a = 2, b = 5
     */
}

int main() {
    first_task();
    second_task_source();
    second_task_var2();
    third_task();
    return 0;
}
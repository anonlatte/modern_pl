#include <iostream>
#include "9.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


// Функция сортировки вагонов
template<class T>
void sortWagons(TStack<T> &wagonStack) {
    TStack<T> tempStack;  // Временный стек для сортировки
    T tempWagon;  // Временная переменная для вагона

    while (!wagonStack.isEmpty()) {
        tempWagon = wagonStack.pop();

        // Перемещаем элементы из tempStack в wagonStack если они больше tempWagon
        while (!tempStack.isEmpty() && tempStack.peek() < tempWagon) {
            wagonStack.push(tempStack.pop());
        }

        // Помещаем tempWagon в tempStack
        tempStack.push(tempWagon);
    }

    // Перемещаем отсортированные вагоны обратно в wagonStack
    while (!tempStack.isEmpty()) {
        wagonStack.push(tempStack.pop());
    }
}

int main() {
    TStack<int> wagonStack;
    int wagonNumber;
    string line;

    // Добавление вагонов в стек
    cout << "Enter wagon numbers split by space: ";
    getline(cin, line);
    istringstream stream(line);
    while (stream >> wagonNumber) {
        wagonStack.push(wagonNumber);
    }
    cout << endl;

    // Сортировка вагонов
    sortWagons(wagonStack);

    // Вывод отсортированных вагонов
    while (!wagonStack.isEmpty()) {
        std::cout << wagonStack.pop() << " ";
    }

    return 0;
}

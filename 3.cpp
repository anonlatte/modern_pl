#include <iostream>

using namespace std;

void printArray(int m[], int size) {
    for (int i = 0; i < size; i++) cout << m[i] << ' ';
    cout << endl;
}

void swap(int mas[], int i, int j) {
    int temp = mas[i];
    mas[i] = mas[j];
    mas[j] = temp;
}

// Сортировка методом мини-макса
void minMaxSort(int mas[], int size) {
    int imin;

    for (int i = 0; i < size - 1; i++) {
        imin = i;

        for (int j = i + 1; j < size; j++) {
            if (mas[j] < mas[imin]) imin = j;
        }

        swap(mas, i, imin);
    }
}

// Сортировка пузырьком
void bubbleSort(int mas[], int size) {

    for (int i = 0; i < size - 1; i++) {

        for (int j = size - 1; j > i; j--) {
            if (mas[j] < mas[i])
                swap(mas, i, j);
        }
    }
}

int partition(int mas[], int l, int r, bool asc) {
    int pivot = mas[r];

    int w = l;
    for (int j = l; j < r; j++) {

        bool needSwap = (asc && mas[j] <= pivot) || (!asc && mas[j] > pivot);

        if (needSwap) {
            swap(mas, w, j);
            w++;
        }
    }

    swap(mas, w, r);
    return w;
}

// Быстрая сортировка
void qSort(int mas[], int l, int r, bool asc) {

    if (l < r) {
        int pivot = partition(mas, l, r, asc);
        qSort(mas, l, pivot - 1, asc);
        qSort(mas, pivot + 1, r, asc);
    }
}

// Сортировка по возрастания четных и по убыванию нечетных значений
void evenAscOddDesc(int a[], int n) {

    // сдвигаем все четные числа в начало массива
    // и нечетные в конец
    int w = 0;
    for (int i = w; i < n - 1; i++)
        if (a[i] % 2 == 0) {
            int tmp = a[i];
            a[i] = a[w];
            a[w] = tmp;
            w++;
        }

    swap(a, w, n - 1);

    // находим индекс первого нечетного числа
    int firstOddIdx = -1;
    for (int i = 0; i < n - 1; i++)
        if (a[i] % 2 != 0) {
            firstOddIdx = i;
            break;
        }

    // сортируем все четные числа по возрастанию, от 0 до firstOddIdx если он не равен -1
    int maxIdxToSortAsc = firstOddIdx != -1 ? firstOddIdx - 1 : n - 1;
    if (firstOddIdx != -1)
        qSort(a, 0, maxIdxToSortAsc, true);

    // сортируем все нечетные числа по убыванию, если они есть в массиве
    if (firstOddIdx != -1) qSort(a, firstOddIdx, n - 1, false);
}

int main() {

    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    const int size = sizeof(mas) / sizeof(*mas);

    printArray(mas, size);

    // minMaxSort(mas, size);

    // bubbleSort(mas, size);

    // qSort(mas, 0, size - 1, false);

    evenAscOddDesc(mas, size);

    printArray(mas, size);

    return 0;
}
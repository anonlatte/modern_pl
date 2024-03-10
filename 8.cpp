#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

// Изменение состояния  выходного потока-файла: переместили указатель и дописываем данные в конец файла
int main() {
    ofstream ofs("8.txt", ios::in | ios::ate);
    if (!ofs) {
        printf("file not opened");
        return -1;
    }

    char chars[] = {'\n', 'a', 'b', 'c'};
    for (char ch: chars) {
        ofs.put(ch);
    }

    return 0;
}

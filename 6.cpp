#include <iostream>
#include "6_string.cpp"

using namespace std;

int main() {
    String s1("test"), s3, s4(s1), s5;

    s3.input();
    s3.output();

    cout << "s5.length = " << s5.length() << ", ";
    s5.output();

    if (s1 == s5) {
        cout << "s1 == s5";
    } else if (s1 == s4) {
        cout << "s1 == s4";
    }

    return 0;
}

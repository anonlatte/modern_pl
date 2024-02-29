using namespace std;

class String {
    char *str;

public:
    String() {
        str = new char[50];
    };

    explicit String(const char *);

    String(const String &);

    String &operator=(const String &);

    String &operator+(const String &);

    int operator==(const String &);

    int length();

    void input();

    void output();

    // >> Дополнение для ЛР №8
    friend istream &operator>>(istream &s, String &str);

    friend ostream &operator<<(ostream &s, String &str);
};

// >> Дополнение для ЛР №8
istream &operator>>(istream &s, String &str);

ostream &operator<<(ostream &s, String &str);

#ifndef BUS_H
#define BUS_H

struct Bus {
    int number{};
    const char *driver{};
    int route{};

public:
    Bus() = default;

    Bus(int _number, const char *_driver, int _route) {
        number = _number;
        driver = _driver;
        route = _route;
    }
};

#endif
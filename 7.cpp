#include "graphics.h"
#include <conio.h>
#include <cmath>

class Point {
public:
    int x, y;
    int color;

    Point(int XN, int YN, int Color) : x(XN), y(YN), color(Color) {}

    virtual void Show() {}

    virtual void Hide() {}

    void Locate(int XL, int YL) {
        x = XL;
        y = YL;
    }

    void Fly(int Cost) {
        // Реализация метода Fly не представлена в исходном коде
    }
};

class Circle : public Point {
public:
    int radius;

    Circle(int XN, int YN, int R, int Color) : Point(XN, YN, Color), radius(R) {}

    void Show() override {
        setcolor(color);
        setfillstyle(1, color);
        pieslice(x, y, 0, 360, radius);
    }

    void Hide() override {
        setcolor(getbkcolor());
        setfillstyle(1, getbkcolor());
        pieslice(x, y, 0, 360, radius);
    }
};

class Ring : public Circle {
public:
    int width;

    Ring(int XN, int YN, int R, int W, int Color) : Circle(XN, YN, R, Color), width(W) {}

    void Show() override {
        Circle::Show();
        setfillstyle(10, getbkcolor());
        pieslice(x, y, 0, 360, radius - width);
    }
};

int main() {
    int gd = DETECT, gm;
    char *path = (char *) "";
    initgraph(&gd, &gm, path);

    setbkcolor(80);

    Circle testCircle(150, 40, 50, 1);
    Ring testRing(450, 80, 90, 10, 50);

    testCircle.Show();
    delay(1000); // задержка в миллисекундах
    testCircle.Fly(100);
    testRing.Show();
    delay(1000);
    testRing.Fly(60);

    getch(); // ожидание нажатия клавиши

    testCircle.Hide();
    testRing.Hide();

    getch(); // ожидание нажатия клавиши

    closegraph();
    return 0;
}

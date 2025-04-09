#pragma once    //Уникнення повторного включення файлу
#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

// Перевантаження оператора >>
std::istream& operator>>(std::istream& is, Point& p);

struct Triangle {
    Point A, B, C;

    double area() const;
    bool contains(const Point& P) const;
};

double distance(const Point& p1, const Point& p2);
double heronArea(const Triangle& t);

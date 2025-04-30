#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>

struct Point {
    double x, y;
    void read();    // метод для зчитування координат точки

    friend std::istream& operator>>(std::istream& is, Point& p);
};

struct Triangle {
    Point A, B, C;
    void read();

    bool exists() const;
    bool existsBySides() const;
    bool existsByArea() const;
    double areaHeron() const;
    double areaDeterminant() const;
};

// Загальні утиліти
void checkInputStream(std::istream& is);
double distance(const Point& p1, const Point& p2);
double area(const Point& A, const Point& B, const Point& C);

// Методи перевірки точки
void methodByHeron(const Triangle& t, const Point& p);
void methodByAreaFormula(const Triangle& t, const Point& p);

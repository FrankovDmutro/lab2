#pragma once
#include <iostream>
#include <cmath>    
#include <limits>   // для std::numeric_limits

struct Point {
    double x, y;
    void read();    // метод для зчитування координат точки

// Дружня функція для введення координат точки через оператор >>.
// Оператор перевантажується для зручного введення об'єктів типу Point.
// Використання friend дозволяє функції мати доступ до приватних полів структури, якщо такі є.
// Повертає посилання на потік вводу для можливості ланцюжкових операцій (cin >> p1 >> p2).
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
double distance(const Point& p1, const Point& p2);
double area(const Point& A, const Point& B, const Point& C);

// Методи перевірки точки
void methodByHeron(const Triangle& t, const Point& p);
void methodByAreaFormula(const Triangle& t, const Point& p);

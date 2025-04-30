#pragma once
#include <iostream>

// ===== Структури =====

struct Point {
    double x, y;
    friend std::istream& operator>>(std::istream& is, Point& p);
};

struct Triangle {
    Point A, B, C;
};

// ===== Загальні функції =====

// Перевірка валідності потоку
void checkInputStream(std::istream& is);

// Обчислення відстані між двома точками
double distance(const Point& p1, const Point& p2);

// Перевірка існування трикутника (по сторонам)
bool isExist(const Triangle& t);

// Перевірка існування трикутника (по площі через векторний добуток)
bool triangleExistByCrossProduct(const Triangle& t);

// Геронова формула для площі
double heronArea(const Triangle& t);

// Площа трикутника через визначник
double triangleArea(const Point& A, const Point& B, const Point& C);

// ===== Основні методи перевірки приналежності точки =====

void methodByHeron(const Triangle& t, const Point& p);
void methodByAreaFormula(const Triangle& t, const Point& p);

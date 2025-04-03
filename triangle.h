#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double area() const;
    bool isDegenerate() const;
    bool contains(const Point &P) const;
    bool containsUsingVectors(const Point &P) const;
};

#endif

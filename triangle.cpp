#include "triangle.h"

double Triangle::area() const {
    return 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

bool Triangle::isDegenerate() const {
    return area() == 0;
}

bool Triangle::contains(const Point &P) const {
    double S_main = area();
    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};
    double S_sum = T1.area() + T2.area() + T3.area();
    return fabs(S_main - S_sum) < 1e-9;
}

bool Triangle::containsUsingVectors(const Point &P) const {
    auto crossProduct = [](const Point &A, const Point &B, const Point &C) {
        return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    };

    double d1 = crossProduct(A, B, P);
    double d2 = crossProduct(B, C, P);
    double d3 = crossProduct(C, A, P);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}

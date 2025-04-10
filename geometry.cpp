#include "geometry.h"

double isExist(const Triangle& t){
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);

    return (a + b > c && a + c > b && b + c > a);
}

double distance(const Point& p1, const Point& p2) {
    return sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::area() const {
    return heronArea(*this);
}

bool Triangle::contains(const Point& P) const {
    Triangle T1{A, B, P};
    Triangle T2{B, C, P};
    Triangle T3{C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    return fabs(S_main - S_sum) < 1e-9; 
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
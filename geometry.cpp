#include "geometry.h"
#include <cmath>
#include <cstdlib>  //Для std::exit

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

void checkInputStream(std::istream& is) {
    if (is.fail()) {
        std::cerr << "Помилка вводу. Завершення програми.\n";
        std::exit(1);
    }
}

double distance(const Point& p1, const Point& p2) {
    return sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

bool isExist(const Triangle& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    return (a + b > c && a + c > b && b + c > a);
}

bool triangleExistByCrossProduct(const Triangle& t) {
    double area = (t.B.x - t.A.x)*(t.C.y - t.A.y) - (t.C.x - t.A.x)*(t.B.y - t.A.y);
    const double eps = 1e-9;
    return std::abs(area) > eps;
}

double heronArea(const Triangle& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double triangleArea(const Point& A, const Point& B, const Point& C) {
    return std::abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

// ===== Метод 1: Перевірка за героновою формулою =====
void methodByHeron(const Triangle& t, const Point& p) {
    if (!isExist(t)) {
        std::cout << "Трикутник не існує за сторонами.\n";
        return;
    }

    Triangle T1{t.A, t.B, p};
    Triangle T2{t.B, t.C, p};
    Triangle T3{t.C, t.A, p};

    double mainArea = heronArea(t);
    double sumAreas = heronArea(T1) + heronArea(T2) + heronArea(T3);

    const double eps = 1e-9;

    if (std::abs(mainArea - sumAreas) < eps) {
        std::cout << "Точка належить трикутнику (метод Герона).\n";
    } else {
        std::cout << "Точка не належить трикутнику (метод Герона).\n";
    }
}

// ===== Метод 2: Перевірка через площу =====
void methodByAreaFormula(const Triangle& t, const Point& p) {
    if (!triangleExistByCrossProduct(t)) {
        std::cout << "Трикутник вироджений (площа ≈ 0).\n";
        return;
    }

    double totalArea = triangleArea(t.A, t.B, t.C);
    double area1 = triangleArea(p, t.B, t.C);
    double area2 = triangleArea(t.A, p, t.C);
    double area3 = triangleArea(t.A, t.B, p);

    const double eps = 1e-9;

    if (area1 < eps || area2 < eps || area3 < eps) {
        std::cout << "Точка лежить на межі трикутника (метод площ).\n";
        return;
    }

    if (std::abs(totalArea - (area1 + area2 + area3)) < eps) {
        std::cout << "Точка всередині трикутника (метод площ).\n";
    } else {
        std::cout << "Точка ззовні трикутника (метод площ).\n";
    }
}

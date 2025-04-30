#include "geometry.h"
#include <cmath>
#include <cstdlib>
#include <limits>

// ===== Метод зчитування координат точки =====
// Виводить підказку та читає точку через operator>>, з повторним вводом при помилці
void Point::read() {
    std::cout << "Введіть координати точки (x, y): ";
    while (!(std::cin >> *this)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Невірний ввід. Спробуйте ще раз: ";
    }
}

// ===== Оператор введення для Point =====
// Дозволяє читати координати точки через std::cin >> point;
std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

// ===== Метод зчитування координат трикутника =====
// Читає вершини A, B, C через operator>>, з повторним вводом при помилці
void Triangle::read() {
    std::cout << "Введіть координати трикутника (A, B, C):\n";
    std::cout << "A: ";
    while (!(std::cin >> A)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Невірний ввід. Спробуйте ще раз для A: ";
    }
    std::cout << "B: ";
    while (!(std::cin >> B)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Невірний ввід. Спробуйте ще раз для B: ";
    }
    std::cout << "C: ";
    while (!(std::cin >> C)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Невірний ввід. Спробуйте ще раз для C: ";
    }
}

// ===== Перевірка існування трикутника загалом =====
bool Triangle::exists() const {
    return existsBySides() && existsByArea();
}

// ===== Перевірка існування трикутника за довжинами сторін =====
bool Triangle::existsBySides() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);
    return (a + b > c && a + c > b && b + c > a);
}

// ===== Перевірка невиродженості через векторний добуток (площу) =====
bool Triangle::existsByArea() const {
    double ar = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    const double eps = 1e-9;
    return std::abs(ar) > eps;
}

// ===== Площа за формулою Герона =====
double Triangle::areaHeron() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);
    double s = (a + b + c) / 2.0;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

// ===== Площа через детермінант (метод площ) =====
double Triangle::areaDeterminant() const {
    return area(A, B, C);
}

// ===== Перевірка стану потоку після вводу =====
// Залишена для інших викликів, але не потрібна в read()
void checkInputStream(std::istream& is) {
    while (is.fail()) {
        is.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Невірний ввід. Спробуйте ще раз: ";
        is >> std::ws;
    }
}

// ===== Відстань між двома точками =====
double distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

// ===== Допоміжна функція обчислення площі трикутника =====
// Через детермінант координат A, B, C
double area(const Point& A, const Point& B, const Point& C) {
    return std::abs(
        (A.x * (B.y - C.y) +
         B.x * (C.y - A.y) +
         C.x * (A.y - B.y)) / 2.0
    );
}

// ===== Перевірка приналежності точки методом Герона =====
void methodByHeron(const Triangle& t, const Point& p) {
    if (!t.existsBySides()) {
        std::cout << "Трикутник не існує за сторонами.\n";
        return;
    }

    Triangle T1{t.A, t.B, p};
    Triangle T2{t.B, t.C, p};
    Triangle T3{t.C, t.A, p};

    double mainArea = t.areaHeron();
    double a1 = T1.areaHeron();
    double a2 = T2.areaHeron();
    double a3 = T3.areaHeron();
    const double eps = 1e-9;

    if (a1 < eps || a2 < eps || a3 < eps) {
        std::cout << "Точка лежить на межі трикутника (метод Герона).\n";
        return;
    }

    double sumAreas = a1 + a2 + a3;
    if (std::abs(mainArea - sumAreas) < eps)
        std::cout << "Точка належить трикутнику (метод Герона).\n";
    else
        std::cout << "Точка не належить трикутнику (метод Герона).\n";
}

// ===== Перевірка приналежності точки через площу (детермінант) =====
void methodByAreaFormula(const Triangle& t, const Point& p) {
    if (!t.existsByArea()) {
        std::cout << "Трикутник вироджений (площа ≈ 0).\n";
        return;
    }

    double totalArea = t.areaDeterminant();
    double a1 = area(p, t.B, t.C);
    double a2 = area(t.A, p, t.C);
    double a3 = area(t.A, t.B, p);
    const double eps = 1e-9;

    if (a1 < eps || a2 < eps || a3 < eps) {
        std::cout << "Точка лежить на межі трикутника (метод площ).\n";
        return;
    }

    if (std::abs(totalArea - (a1 + a2 + a3)) < eps)
        std::cout << "Точка всередині трикутника (метод площ).\n";
    else
        std::cout << "Точка ззовні трикутника (метод площ).\n";
}

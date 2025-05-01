#include "geometry.h"

// ===== Метод зчитування координат точки =====
// Виводить підказку та читає точку через operator>>, з повторним вводом при помилці
void Point::read() {
    std::cout << "Введіть координати точки (x, y): ";
    // Повторюємо спробу введення об’єкта Point (*this) через оператор >>,
    // доки користувач не введе коректні числа.
    while (!(std::cin >> *this)) {
        // Якщо сталася помилка (не число, зайві символи тощо) — очищаємо стан потоку
        std::cin.clear();
        // Видаляємо з буфера всі символи до кінця рядка,
        // щоб некоректний ввід не заважав наступній спробі
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Повідомляємо користувача про помилку та просимо повторити ввід
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

bool onSegment(const Point& U, const Point& V, const Point& P) {
    const double eps = 1e-9;
    
    //Cпочатку колінеарність (площа U,V,P ≈ 0)
    double cross = (V.x - U.x)*(P.y - U.y) - (V.y - U.y)*(P.x - U.x);
    if (std::abs(cross) > eps) 
        return false;

    // 2) перевіряємо, що P між U і V за координатами
    if (P.x < std::min(U.x, V.x) - eps || P.x > std::max(U.x, V.x) + eps)   //std::min це
        return false;
    if (P.y < std::min(U.y, V.y) - eps || P.y > std::max(U.y, V.y) + eps) 
        return false;

    return true;
}

// ===== Перевірка приналежності точки методом Герона =====
void methodByHeron(const Triangle& t, const Point& p) {
    // 1. Перевірка “на ребрі”
    if ( onSegment(t.A, t.B, p) ||
         onSegment(t.B, t.C, p) ||
         onSegment(t.C, t.A, p) )
    {
        std::cout << "Точка лежить на межі трикутника (метод Герона).\n";
        return;
    }

    // 2. Обчислюємо площі за Героном
    double mainArea = t.areaHeron();
    Triangle T1{t.A, t.B, p}, T2{t.B, t.C, p}, T3{t.C, t.A, p};
    double a1 = T1.areaHeron(), a2 = T2.areaHeron(), a3 = T3.areaHeron();
    const double eps = 1e-9;

    // 3. Всередині або зовні
    if (std::abs(mainArea - (a1 + a2 + a3)) < eps)
        std::cout << "Точка належить трикутнику (метод Герона).\n";
    else
        std::cout << "Точка не належить трикутнику (метод Герона).\n";
}

// ===== Перевірка приналежності точки через площу (детермінант) =====
void methodByAreaFormula(const Triangle& t, const Point& p) {
    const double eps = 1e-9;
    // 1. Перевірка “на ребрі”
    if ( onSegment(t.A, t.B, p) ||
         onSegment(t.B, t.C, p) ||
         onSegment(t.C, t.A, p) )
    {
        std::cout << "Точка лежить на трикутнику(метод площ).\n";
        return;
    }

    // 2. Обчислюємо детермінантні площі
    double totalArea = t.areaDeterminant();
    if (std::abs(totalArea) < eps) {
        std::cout << "Точка не належить трикутинку (метод площ).\n";
        return;
    }
    double a1 = area(p, t.B, t.C), a2 = area(t.A, p, t.C), a3 = area(t.A, t.B, p);
    


    // 3. Всередині або зовні
    if (std::abs(totalArea - (a1 + a2 + a3)) < eps)
        std::cout << "Точка всередині трикутника (метод площ).\n";
    else
        std::cout << "Точка ззовні трикутника (метод площ).\n";
}



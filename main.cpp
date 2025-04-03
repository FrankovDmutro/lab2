#include "triangle.h"

int main() {
    Triangle t;
    std::cout << "Введіть координати трикутника (A, B, C): ";
    std::cin >> t.A.x >> t.A.y >> t.B.x >> t.B.y >> t.C.x >> t.C.y;

    if (t.isDegenerate()) {
        std::cout << "Це вироджений трикутник (точки лежать на одній прямій)." << std::endl;
        return 1;
    }

    int numPoints;
    std::cout << "Введіть кількість точок для перевірки: ";
    std::cin >> numPoints;

    for (int i = 0; i < numPoints; i++) {
        Point p;
        std::cout << "Введіть координати точки: ";
        std::cin >> p.x >> p.y;

        if (t.containsUsingVectors(p)) {
            std::cout << "Точка (" << p.x << ", " << p.y << ") знаходиться всередині трикутника." << std::endl;
        } else {
            std::cout << "Точка (" << p.x << ", " << p.y << ") знаходиться ЗОВНІ трикутника." << std::endl;
        }
    }

    return 0;
}

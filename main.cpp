#include "geometry.h"

using namespace std

int main() {
    Triangle t;
    Point p;

    cout << "Введіть координати трикутника (A): ";
    cin >> t.A
    cout << "B: ";
    cin >> t.B;
    cout << "C: ";

    checkInputStream(cin);

    cout << "Введіть координати точки (x y): ";
    cin >> p;
    checkInputStream(cin);

    cout << "\nПеревірка методом Герона:\n";
    methodByHeron(t, p);

    cout << "\nПеревірка методом площ:\n";
    methodByAreaFormula(t, p);

    return 0;
}

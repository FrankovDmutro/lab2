#include "geometry.h"

using namespace std;

int main() {
    Triangle t;
    Point p;

    t.read(); //Ввід точок трикутника

    //Перевірка на існування трикутника
    if (!t.exists()) {
        cout << "Трикутник не існує.\n";
        return 1;
    }

    p.read(); //Ввід точки

    cout << "==========================" << endl;

    bool again = true;
    int chooseMethod, chooseOperation;
    while (again) {
        cout << "=============================================\n";
        cout << "Оберіть метод перевірки:\n" 
                << "1. Метод Герона\n"
                << "2. Формула площі\n"
                << "3. Два методи перевірки трикутника на існування.\n"
                << "=============================================\n"
                << ":";
        cin >> chooseMethod;
        checkInputStream(cin);

        cout << "============ Результат виконання ============\n";

        switch (chooseMethod)
        {
        case(1):
            methodByHeron(t, p);
            break;
        case(2):
            methodByAreaFormula(t, p);
            break;
        case(3):
            methodByAreaFormula(t, p);
            methodByHeron(t, p);
        default:
            break;
        }
        cout << "!!=========================================!!\n";
        cout << "Що робимо далі?\n"
                << "1. Змінити трикутник\n"
                << "2. Змінити точку\n"
                << "3. Змінити трикутник і точку\n"
                << "4. Закіньчити роботу програми\n"
                << ":";
        cin >> chooseOperation;
        checkInputStream(cin);

        cout << "=============================================\n";

        switch (chooseOperation)
        {
        case(1):
            t.read();
            break;
        case(2):
            p.read();
            break;
        case(3):
            t.read();
            p.read();
            break;
        case(4):
            again = false;
            cout << "OK, computer" << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    }
    return 0;
}

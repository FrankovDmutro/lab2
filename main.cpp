#include "geometry.h"

using namespace std;

int main() {
    Triangle t;
    Point p;

    // Читаємо трикутник
    t.read();

    // Перевірка на існування трикутника
    if (!t.exists()) {
        cout << "Трикутник вироджений .\n";

    }

    // Читаємо точку
    p.read();

    

    bool again = true;
    int chooseMethod, chooseOperation;

    while (again) {
        // --- вибір методу перевірки ---
        cout << "=============================================\n"
             << "Оберіть метод перевірки:\n"
             << "1. Метод Герона\n"
             << "2. Формула детермінанту\n"
             << "3. Два методи перевірки.\n"
             << "=============================================\n"
             << ": ";

        // цикл повторного вводу для chooseMethod
        while (!(cin >> chooseMethod) || chooseMethod < 1 || chooseMethod > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Невірний вибір. Введіть 1, 2 або 3: ";
        }

        cout << "============ Результат виконання ============\n";
        switch (chooseMethod) {
            case 1: methodByHeron(t, p); break;
            case 2: methodByAreaFormula(t, p); break;
            case 3:
                methodByAreaFormula(t, p);
                methodByHeron(t, p);
                break;
        }
        cout << "!!=========================================!!\n";

        // --- вибір наступної операції ---
        cout << "Що робимо далі?\n"
             << "1. Змінити трикутник\n"
             << "2. Змінити точку\n"
             << "3. Змінити трикутник і точку\n"
             << "4. Закінчити роботу програми\n"
             << ": ";

        // цикл повторного вводу для chooseOperation
        while (!(cin >> chooseOperation) || chooseOperation < 1 || chooseOperation > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Невірний вибір. Введіть 1–4: ";
        }

        switch (chooseOperation) {
            case 1: t.read(); break;
            case 2: p.read(); break;
            case 3: t.read(); p.read(); break;
            case 4: again = false; cout << "OK, computer\n"; break;
        }
        cout << "=============================================\n";
    }

    return 0;
}

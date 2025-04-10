#include <iostream>
#include "geometry.h"

using namespace std;

int main() {

    Triangle t{{0, 0}, {0, 0}, {0, 0}};
    Point p{0, 0};

    //Ввід точок
    cout << "Введіть точки трикутника:" << endl;

    cout << "A:";
    cin >> t.A;

    cout << "B:";
    cin >> t.B;

    cout << "C:";
    cin >> t.C;

    bool choice = 0;
    while (true) {
    
        if (!isExist(t)) {
            cout << "Трикутник не існує" << endl;
            return 1;
        }
    
        cout << "Введіть координати точки:";
        cin >> p;
        if (t.contains(p)) {
            cout << "Точка належить трикутнику" << endl;
        } 
        else {        
            cout << "Точка не належить трикутнику" << endl;
        }
        
        cout << "Повторити операцію?(0 або 1):";
        
        cin >> choice;
        if (!choice){
            break;
        }
    }
    return 0;
}
    
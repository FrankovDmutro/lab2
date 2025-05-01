🧠 Метод 1: Перевірка через площу (Формула Герона)
📋 Алгоритм:

Маємо координати трикутника: A(x1, y1), B(x2, y2), C(x3, y3)
і координати точки P(x, y).

Обчислюємо довжини сторін:

    double AB = length(A, B);
    double BC = length(B, C);
    double CA = length(C, A);

Обчислюємо площу основного трикутника ABC:

    double s = (AB + BC + CA) / 2;
    double S = sqrt(s * (s - AB) * (s - BC) * (s - CA));

Аналогічно — площі трикутників ABP, BCP, CAP:

    double S1 = heron(A, B, P);
    double S2 = heron(B, C, P);
    double S3 = heron(C, A, P);

Якщо:

    abs(S - (S1 + S2 + S3)) < EPS

— точка всередині або на межі трикутника.


🧮 Метод 2: Векторний добуток (орієнтований)
📋 Алгоритм:

Створюємо вектори відносно точки:

    Vector AB = B - A;
    Vector AP = P - A;
    Vector BC = C - B;
    Vector BP = P - B;
    Vector CA = A - C;
    Vector CP = P - C;

Обчислюємо орієнтований векторний добуток (псевдоскаляр):

    double cross1 = AB ^ AP;
    double cross2 = BC ^ BP;
    double cross3 = CA ^ CP;

Якщо всі три добутки одного знаку або дорівнюють нулю (тобто не змінюють орієнтацію) — точка всередині або на межі.

Перевірка виглядає так:

    bool sameSign = (cross1 >= 0 && cross2 >= 0 && cross3 >= 0) ||
                    (cross1 <= 0 && cross2 <= 0 && cross3 <= 0);
                    

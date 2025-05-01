# Документація до проєкту: Перевірка приналежності точки трикутнику

Цей проєкт складається з трьох файлів:
- **main.cpp** — взаємодія з користувачем, меню вибору.
- **geometry.h** — оголошення структур та функцій.
- **geometry.cpp** — реалізація методів та алгоритмів.

---

## Структура файлів

```text
├── main.cpp
├── geometry.h
└── geometry.cpp
```

---

## Опис файлів

### main.cpp
- Зчитує координати трикутника та точки.
- Перевіряє, чи існує трикутник.
- Надає меню для вибору методу перевірки:
  1. Метод Герона
  2. Метод детермінанту (векторний добуток)
  3. Обидва методи
- Після виконання пропонує змінити трикутник, точку або завершити роботу.

---

### geometry.h
- Оголошує структуру **Point** з полями `x, y` та методом `read()`.
- Оголошує структуру **Triangle** з вершинами `A, B, C` та методами:
  - `read()`
  - `exists()`, `existsBySides()`, `existsByArea()`
  - `areaHeron()`, `areaDeterminant()`
- Прототипи допоміжних функцій:
  - `distance()`, `area()`, `onSegment()`
  - `methodByHeron()`, `methodByAreaFormula()`

---

### geometry.cpp
- Реалізує зчитування (`Point::read()`, `Triangle::read()`).
- Перевірку існування трикутника:
  - За довжинами сторін (`existsBySides`)
  - За невиродженістю (векторний добуток — `existsByArea`)
- Обчислення площ:
  - **Герон** (`areaHeron`)
  - **Детермінант** (`areaDeterminant`)
- Функція `onSegment` — перевірка, чи точка лежить на відрізку.
- Методи перевірки приналежності точки:
  - `methodByHeron`
  - `methodByAreaFormula`

---

## Опис функцій

### `void Point::read()`
Читає координати точки з консолі з повторними спробами при некоректному вводі.

### `std::istream& operator>>(std::istream& is, Point& p)`
Перевантажений оператор введення: зчитує `p.x` і `p.y`.

### `void Triangle::read()`
Читає вершини `A`, `B`, `C` з консолі, перевіряє коректність вводу.

### `bool Triangle::existsBySides() const`
Перевіряє, чи задовольняють довжини сторін нерівності трикутника:
```
a + b > c, a + c > b, b + c > a
```

### `bool Triangle::existsByArea() const`
Обчислює векторний добуток `(B-A)×(C-A)` і перевіряє, що його абсолютне значення > ε (не вироджений).

### `bool Triangle::exists() const`
Повертає `existsBySides() && existsByArea()`.

### `double distance(const Point& p1, const Point& p2)`
Евклідова відстань між `p1` і `p2`.

### `double Triangle::areaHeron() const`
Площа за формулою Герона:
1. a, b, c — довжини сторін
2. s = (a+b+c)/2
3. √(s(s-a)(s-b)(s-c))

### `double Triangle::areaDeterminant() const`
Площа через детермінант (векторний добуток):
```
| (Ax(By−Cy) + Bx(Cy−Ay) + Cx(Ay−By)) / 2 |
```

### `double area(const Point& A, const Point& B, const Point& C)`
Допоміжна функція для обчислення площі детермінантом.

### `bool onSegment(const Point& U, const Point& V, const Point& P)`
1. Перевіряє колінеарність U, V, P (cross ≈0).
2. Перевіряє, що P.x, P.y в межах від U до V.

### `void methodByHeron(const Triangle& t, const Point& p)`
1. Перевірка існування за сторонами.
2. Перевірка onSegment для ребра.
3. Обчислення площ трох підтрикутників Героном.
4. Порівняння суми з основною площею.

### `void methodByAreaFormula(const Triangle& t, const Point& p)`
1. Перевірка невиродженості.
2. Перевірка onSegment для ребра.
3. Обчислення площ детермінантом.
4. Порівняння суми з основною площею.

---

## Алгоритмічна суть методів

| Метод               | Формула                                 | Умова “всередині”                     | Умова “на ребрі”                 |
|---------------------|-----------------------------------------|---------------------------------------|----------------------------------|
| Герона              | √(s(s−a)(s−b)(s−c))                     | ΣS_i ≈ S                              | onSegment(U,V,P)                 |
| Векторний добуток   | cross = (V−U)×(P−U)                     | всі cross однаковий знак              | cross≈0 та onSegment(U,V,P)      |

---

## Як зібрати

```bash
g++ main.cpp geometry.cpp -o triangle_check
./triangle_check
```

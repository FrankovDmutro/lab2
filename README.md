<<<<<<< HEAD
<<<<<<< HEAD
# Опис програми для перевірки приналежності точки трикутнику

Ця програма дозволяє перевірити, чи належить задана точка трикутнику, використовуючи два методи:
1. **Метод Герона** (обчислення площі трикутника за формулою Герона).
2. **Метод площі через детермінант** (обчислення площі через векторний добуток).

Програма також дозволяє користувачеві змінювати координати трикутника та точки, а також вибирати метод перевірки.
=======
# Документація до проєкту: Перевірка приналежності точки трикутнику
=======
# Опис програми для перевірки приналежності точки трикутнику
>>>>>>> 4214136ba68fa36e8c6e4dab1066a893706299af

Ця програма дозволяє перевірити, чи належить задана точка трикутнику, використовуючи два методи:
1. **Метод Герона** (обчислення площі трикутника за формулою Герона).
2. **Метод площі через детермінант** (обчислення площі через векторний добуток).

Програма також дозволяє користувачеві змінювати координати трикутника та точки, а також вибирати метод перевірки.

---

## Опис функцій

### Структура `Point`
```cpp
struct Point {
    double x, y;
    void read();
    friend std::istream& operator>>(std::istream& is, Point& p);
};
```
- **`read()`**: Зчитує координати точки з введення користувача.
- **`operator>>`**: Перевантажений оператор для зручного введення координат точки.

---

<<<<<<< HEAD
## Опис файлів

### main.cpp
- Зчитує координати трикутника та точки.
- Перевіряє, чи існує трикутник.
- Надає меню для вибору методу перевірки:
  1. Метод Герона
  2. Метод детермінанту (векторний добуток)
  3. Обидва методи
- Після виконання пропонує змінити трикутник, точку або завершити роботу.

### geometry.h
- Оголошує структуру **Point** з полями `x, y` та методом `read()`.
- Оголошує структуру **Triangle** з вершинами `A, B, C` та методами:
  - `read()`
  - `exists()`, `existsBySides()`, `existsByArea()`
  - `areaHeron()`, `areaDeterminant()`
- Прототипи допоміжних функцій:
  - `distance()`, `area()`, `onSegment()`
  - `methodByHeron()`, `methodByAreaFormula()`

### geometry.cpp
- Реалізує зчитування (`Point::read()`, `Triangle::read()`).
- Перевірку існування трикутника:
  - За довжинами сторін (`existsBySides`): **\(a + b > c\), \(a + c > b\), \(b + c > a\)**
  - За невиродженістю (векторний добуток — `existsByArea`): **\(\lvert (B-A) \times (C-A) \rvert > \varepsilon\)**
- Обчислення площ:
  - **Герон** (`areaHeron`)
  - **Детермінант** (`areaDeterminant`)
- Функція `onSegment` — перевірка, чи точка лежить на відрізку.
- Методи перевірки приналежності точки:
  - `methodByHeron`
  - `methodByAreaFormula`
>>>>>>> 018da30240c07825cc9f7c14aff6e9160db21265

---

## Детальний опис алгоритмів

<<<<<<< HEAD
### Структура `Point`
```cpp
struct Point {
    double x, y;
    void read();
    friend std::istream& operator>>(std::istream& is, Point& p);
};
```
- **`read()`**: Зчитує координати точки з введення користувача.
- **`operator>>`**: Перевантажений оператор для зручного введення координат точки.

---

=======
>>>>>>> 4214136ba68fa36e8c6e4dab1066a893706299af
### Структура `Triangle`
```cpp
struct Triangle {
    Point A, B, C;
    void read();
    bool exists() const;
    bool existsBySides() const;
    bool existsByArea() const;
    double areaHeron() const;
    double areaDeterminant() const;
};
<<<<<<< HEAD
```
- **`read()`**: Зчитує координати вершин трикутника з введення користувача.
- **`exists()`**: Перевіряє, чи існує трикутник (не вироджений).
- **`existsBySides()`**: Перевіряє існування трикутника за довжинами сторін (умова трикутника).
- **`existsByArea()`**: Перевіряє, чи площа трикутника не дорівнює нулю.
- **`areaHeron()`**: Обчислює площу трикутника за формулою Герона.
- **`areaDeterminant()`**: Обчислює площу трикутника через детермінант.

---

### Утиліти
```cpp
double distance(const Point& p1, const Point& p2);
double area(const Point& A, const Point& B, const Point& C);
bool onSegment(const Point& U, const Point& V, const Point& P);
```
- **`distance()`**: Обчислює відстань між двома точками.
- **`area()`**: Обчислює площу трикутника через детермінант.
- **`onSegment()`**: Перевіряє, чи лежить точка на відрізку між двома іншими точками.

---

### Методи перевірки точки
```cpp
void methodByHeron(const Triangle& t, const Point& p);
void methodByAreaFormula(const Triangle& t, const Point& p);
```
- **`methodByHeron()`**: Використовує формулу Герона для перевірки приналежності точки трикутнику.
- **`methodByAreaFormula()`**: Використовує площу через детермінант для перевірки приналежності точки трикутнику.

---

## Математичні формули

### 1. Формула Герона
Формула Герона використовується для обчислення площі трикутника за довжинами його сторін.

#### Кроки:
1. Обчислюємо довжини сторін трикутника:
   \[
   a = \sqrt{(B_x - A_x)^2 + (B_y - A_y)^2}
   \]
   \[
   b = \sqrt{(C_x - B_x)^2 + (C_y - B_y)^2}
   \]
   \[
   c = \sqrt{(A_x - C_x)^2 + (A_y - C_y)^2}
   \]

2. Обчислюємо півпериметр:
   \[
   s = \frac{a + b + c}{2}
   \]

3. Обчислюємо площу:
   \[
   \text{Area} = \sqrt{s \cdot (s - a) \cdot (s - b) \cdot (s - c)}
   \]

#### Умови:
- Трикутник існує, якщо виконується умова:
  \[
  a + b > c, \quad a + c > b, \quad b + c > a
  \]

---

### 2. Формула площі через детермінант
Цей метод використовує векторний добуток для обчислення площі трикутника.

#### Кроки:
1. Обчислюємо площу трикутника через детермінант:
   \[
   \text{Area} = \frac{1}{2} \cdot \left| A_x \cdot (B_y - C_y) + B_x \cdot (C_y - A_y) + C_x \cdot (A_y - B_y) \right|
   \]

2. Для перевірки приналежності точки:
   - Обчислюємо площі трьох трикутників:
     \[
     \text{Area}_1 = \text{area}(P, B, C)
     \]
     \[
     \text{Area}_2 = \text{area}(A, P, C)
     \]
     \[
     \text{Area}_3 = \text{area}(A, B, P)
     \]

   - Якщо сума цих площ дорівнює площі основного трикутника (з точністю до `eps`), точка належить трикутнику:
     \[
     \text{Area} \approx \text{Area}_1 + \text{Area}_2 + \text{Area}_3
     \]

#### Умови:
- Трикутник не вироджений, якщо його площа не дорівнює нулю:
  \[
  \text{Area} > \text{eps}
  \]

---

### 3. Перевірка точки на межі трикутника
Для перевірки, чи лежить точка на межі трикутника:
1. Перевіряємо, чи точка колінеарна з відрізком (площа ≈ 0):
   \[
   \text{Cross} = (V_x - U_x) \cdot (P_y - U_y) - (V_y - U_y) \cdot (P_x - U_x)
   \]
   Якщо \(\text{Cross} \approx 0\), точки колінеарні.

2. Перевіряємо, чи точка знаходиться між кінцями відрізка:
   \[
   \min(U_x, V_x) - \text{eps} \leq P_x \leq \max(U_x, V_x) + \text{eps}
   \]
   \[
   \min(U_y, V_y) - \text{eps} \leq P_y \leq \max(U_y, V_y) + \text{eps}
   \]

---

## Умови виконання функцій
1. **`existsBySides()`**: Виконується, якщо трикутник задовольняє умову існування за сторонами.
2. **`existsByArea()`**: Виконується, якщо площа трикутника більше за `eps`.
3. **`onSegment()`**: Виконується, якщо точка колінеарна з відрізком і лежить між його кінцями.

---

## Приклад роботи програми
1. Введення координат трикутника:
   ```
   A: 0 0
   B: 5 0
   C: 0 5
   ```

2. Введення координат точки:
   ```
   P: 2 2
   ```
=======
### Метод Герона (через площі)

1. **Обчислення довжин сторін**  
   Для трикутника \(ABC\):
   $$
     a = |BC| = \sqrt{(C_x - B_x)^2 + (C_y - B_y)^2},\
     b = |AC| = \sqrt{(C_x - A_x)^2 + (C_y - A_y)^2},\
     c = |AB| = \sqrt{(B_x - A_x)^2 + (B_y - A_y)^2}.
   $$

2. **Перевірка нерівностей трикутника**  
   Перед обчисленням площі перевіряємо:
   $$
     a + b > c,\quad a + c > b,\quad b + c > a.
   $$
   Якщо хоча б одне з цих не виконується, трикутник не існує.

3. **Півпериметр**  
   $$
     p = rac{a + b + c}{2}.
   $$

4. **Площа за формулою Герона**  
   $$
     S = \sqrt{p(p - a)(p - b)(p - c)}.
   $$
   Якщо підкореневий вираз негативний (через числові похибки) — вважаємо \(S = 0\).

5. **Площі підтрикутників з точкою \(P\)**  
   Аналогічно обчислюємо:
   $$
     S_1 = \sqrt{p_1(p_1 - a_1)(p_1 - b_1)(p_1 - c_1)},\quad
     S_2,\quad
     S_3,
   $$
   де \(p_i\) — півпериметр трикутників \(PBC\), \(PCA\), \(PAB\).

6. **Умова належності**  
   З фіксованим \(arepsilon\):
   - **Всередині або на межі** якщо  
     $$
       |(S_1 + S_2 + S_3) - S| < arepsilon.
     $$
   - **На межі** якщо додатково хоча б одне \(S_i < arepsilon\) **та** `onSegment` повертає true.
   - **Ззовні** інакше.

---

### Метод векторного добутку (детермінант)

1. **Вектори від вершин до точки**  
   Для сторони \(AB\):
   $$
     ec{v} = B - A = (B_x - A_x,\; B_y - A_y),\
     ec{w} = P - A = (P_x - A_x,\; P_y - A_y).
   $$

2. **Векторний добуток у 2D**  
   $$
     	ext{cross}_1 = v_x w_y - v_y w_x.
   $$
   Аналогічно для \(BC\) і \(CA\).

3. **Умова всередині**  
   - Якщо всі \(	ext{cross}_i > arepsilon\) або всі \(	ext{cross}_i < -arepsilon\), точка всередині.

4. **Умова на межі**  
   - Якщо будь‑який \(|	ext{cross}_i| < arepsilon\) **і** `onSegment` для відповідної сторони.

5. **Ззовні**  
   - Інакше.

---

## Функція `onSegment(U, V, P)`

Перевіряє, чи лежить \(P\) на відрізку \(UV\):

1. **Колінеарність**:  
   $$
     	ext{cross} = (V_x - U_x)(P_y - U_y) - (V_y - U_y)(P_x - U_x),\
     |	ext{cross}| < arepsilon.
   $$
2. **Координатний “короб”**:  
   $$
     \min(U_x, V_x) - arepsilon \le P_x \le \max(U_x, V_x) + arepsilon,\
     \min(U_y, V_y) - arepsilon \le P_y \le \max(U_y, V_y) + arepsilon.
   $$

---

## Умови виклику методів

- **methodByHeron**: лише якщо `existsBySides() == true`.
- **methodByAreaFormula**: лише якщо `existsByArea() == true`.

---

## Як зібрати

```bash
g++ main.cpp geometry.cpp -o triangle_check
./triangle_check
```
>>>>>>> 018da30240c07825cc9f7c14aff6e9160db21265
=======
```
- **`read()`**: Зчитує координати вершин трикутника з введення користувача.
- **`exists()`**: Перевіряє, чи існує трикутник (не вироджений).
- **`existsBySides()`**: Перевіряє існування трикутника за довжинами сторін (умова трикутника).
- **`existsByArea()`**: Перевіряє, чи площа трикутника не дорівнює нулю.
- **`areaHeron()`**: Обчислює площу трикутника за формулою Герона.
- **`areaDeterminant()`**: Обчислює площу трикутника через детермінант.
>>>>>>> 4214136ba68fa36e8c6e4dab1066a893706299af

3. Вибір методу перевірки:
   ```
   1. Метод Герона
   2. Формула площі
   3. Два методи перевірки
   ```

<<<<<<< HEAD
4. Результат:
   ```
   Точка належить трикутнику (метод Герона).
   Точка всередині трикутника (метод площ).
   ```

<<<<<<< HEAD
--- 

Ця програма є корисним інструментом для геометричних обчислень і демонструє використання математичних формул у програмуванні.
=======
> Франков Дмитро, студент ФЕКТ, 2025
>>>>>>> 018da30240c07825cc9f7c14aff6e9160db21265
=======
### Утиліти
```cpp
double distance(const Point& p1, const Point& p2);
double area(const Point& A, const Point& B, const Point& C);
bool onSegment(const Point& U, const Point& V, const Point& P);
```
- **`distance()`**: Обчислює відстань між двома точками.
- **`area()`**: Обчислює площу трикутника через детермінант.
- **`onSegment()`**: Перевіряє, чи лежить точка на відрізку між двома іншими точками.

---

### Методи перевірки точки
```cpp
void methodByHeron(const Triangle& t, const Point& p);
void methodByAreaFormula(const Triangle& t, const Point& p);
```
- **`methodByHeron()`**: Використовує формулу Герона для перевірки приналежності точки трикутнику.
- **`methodByAreaFormula()`**: Використовує площу через детермінант для перевірки приналежності точки трикутнику.

---

## Математичні формули

### 1. Формула Герона
Формула Герона використовується для обчислення площі трикутника за довжинами його сторін.

#### Кроки:
1. Обчислюємо довжини сторін трикутника:
   \[
   a = \sqrt{(B_x - A_x)^2 + (B_y - A_y)^2}
   \]
   \[
   b = \sqrt{(C_x - B_x)^2 + (C_y - B_y)^2}
   \]
   \[
   c = \sqrt{(A_x - C_x)^2 + (A_y - C_y)^2}
   \]

2. Обчислюємо півпериметр:
   \[
   s = \frac{a + b + c}{2}
   \]

3. Обчислюємо площу:
   \[
   \text{Area} = \sqrt{s \cdot (s - a) \cdot (s - b) \cdot (s - c)}
   \]

#### Умови:
- Трикутник існує, якщо виконується умова:
  \[
  a + b > c, \quad a + c > b, \quad b + c > a
  \]

---

### 2. Формула площі через детермінант
Цей метод використовує векторний добуток для обчислення площі трикутника.

#### Кроки:
1. Обчислюємо площу трикутника через детермінант:
   \[
   \text{Area} = \frac{1}{2} \cdot \left| A_x \cdot (B_y - C_y) + B_x \cdot (C_y - A_y) + C_x \cdot (A_y - B_y) \right|
   \]

2. Для перевірки приналежності точки:
   - Обчислюємо площі трьох трикутників:
     \[
     \text{Area}_1 = \text{area}(P, B, C)
     \]
     \[
     \text{Area}_2 = \text{area}(A, P, C)
     \]
     \[
     \text{Area}_3 = \text{area}(A, B, P)
     \]

   - Якщо сума цих площ дорівнює площі основного трикутника (з точністю до `eps`), точка належить трикутнику:
     \[
     \text{Area} \approx \text{Area}_1 + \text{Area}_2 + \text{Area}_3
     \]

#### Умови:
- Трикутник не вироджений, якщо його площа не дорівнює нулю:
  \[
  \text{Area} > \text{eps}
  \]

---

### 3. Перевірка точки на межі трикутника
Для перевірки, чи лежить точка на межі трикутника:
1. Перевіряємо, чи точка колінеарна з відрізком (площа ≈ 0):
   \[
   \text{Cross} = (V_x - U_x) \cdot (P_y - U_y) - (V_y - U_y) \cdot (P_x - U_x)
   \]
   Якщо \(\text{Cross} \approx 0\), точки колінеарні.

2. Перевіряємо, чи точка знаходиться між кінцями відрізка:
   \[
   \min(U_x, V_x) - \text{eps} \leq P_x \leq \max(U_x, V_x) + \text{eps}
   \]
   \[
   \min(U_y, V_y) - \text{eps} \leq P_y \leq \max(U_y, V_y) + \text{eps}
   \]

---

## Умови виконання функцій
1. **`existsBySides()`**: Виконується, якщо трикутник задовольняє умову існування за сторонами.
2. **`existsByArea()`**: Виконується, якщо площа трикутника більше за `eps`.
3. **`onSegment()`**: Виконується, якщо точка колінеарна з відрізком і лежить між його кінцями.

---

## Приклад роботи програми
1. Введення координат трикутника:
   ```
   A: 0 0
   B: 5 0
   C: 0 5
   ```

2. Введення координат точки:
   ```
   P: 2 2
   ```

3. Вибір методу перевірки:
   ```
   1. Метод Герона
   2. Формула площі
   3. Два методи перевірки
   ```

4. Результат:
   ```
   Точка належить трикутнику (метод Герона).
   Точка всередині трикутника (метод площ).
   ```

--- 

Ця програма є корисним інструментом для геометричних обчислень і демонструє використання математичних формул у програмуванні.
>>>>>>> 4214136ba68fa36e8c6e4dab1066a893706299af

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Triangle {
private:
    double a, b, c;

    bool isValid() const {
        return (a + b > c && a + c > b && b + c > a);
    }

    double semiperimeter() const {
        return (a + b + c) / 2;
    }

public:
    // === Конструктори ===
    Triangle() {
        a = b = c = 0;
        cout << "[Default constructor called]" << endl;
    }

    Triangle(double side) {
        a = b = c = side;
        cout << "[Single-parameter constructor called]" << endl;
    }

    Triangle(double side1, double side2, double side3) {
        a = side1; b = side2; c = side3;
        cout << "[Three-parameter constructor called]" << endl;
    }

    // === Деструктор ===
    ~Triangle() {
        cout << "[Destructor called]" << endl;
    }

    // === Методи ===
    void Init(double side1, double side2, double side3) {
        a = side1; b = side2; c = side3;
    }

    void Read() {
        cout << "Enter 3 sides: ";
        cin >> a >> b >> c;
    }

    void Display() const {
        cout << toString() << endl;
    }

    string toString() const {
        string s = "Triangle: (" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")";
        s += " | Perimeter = " + to_string(perimeter());
        s += " | Area = " + to_string(area());
        s += " | Type = " + getType();
        return s;
    }

    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        if (!isValid()) return 0;
        double s = semiperimeter();
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    string getType() const {
        if (!isValid()) return "Not a triangle";
        if (a == b && b == c) return "Equilateral";
        if (a == b || a == c || b == c) return "Isosceles";
        if (fabs(a * a + b * b - c * c) < 1e-6 || fabs(a * a + c * c - b * b) < 1e-6 || fabs(b * b + c * c - a * a) < 1e-6)
            return "Right";
        return "Scalene";
    }

    // === Перевантаження операторів ===

    // 1. Оператор рівності ==
    bool operator==(const Triangle& other) const {
        return (fabs(a - other.a) < 1e-6 &&
            fabs(b - other.b) < 1e-6 &&
            fabs(c - other.c) < 1e-6);
    }

    // 2. Оператор додавання +
    Triangle operator+(const Triangle& other) const {
        return Triangle(a + other.a, b + other.b, c + other.c);
    }

    // 3. Оператор порівняння >
    bool operator>(const Triangle& other) const {
        return this->area() > other.area();
    }

    // 4. Оператор виведення <<
    friend ostream& operator<<(ostream& os, const Triangle& t) {
        os << "Triangle(" << t.a << ", " << t.b << ", " << t.c << ")"
            << " | Area: " << fixed << setprecision(2) << t.area()
            << " | Perimeter: " << t.perimeter();
        return os;
    }
};

// === Головна функція ===
int main() {
    cout << fixed << setprecision(3);

    Triangle t1(3, 4, 5);
    Triangle t2(5);
    Triangle t3(6, 8, 10);

    cout << "\n--- Display triangles ---" << endl;
    cout << t1 << endl;
    cout << t2 << endl;
    cout << t3 << endl;

    cout << "\n--- Operator == ---" << endl;
    if (t1 == t2)
        cout << "t1 and t2 are equal." << endl;
    else
        cout << "t1 and t2 are different." << endl;

    cout << "\n--- Operator + ---" << endl;
    Triangle t4 = t1 + t2;
    cout << "t4 = t1 + t2 -> " << t4 << endl;

    cout << "\n--- Operator > ---" << endl;
    if (t3 > t1)
        cout << "t3 has a larger area than t1" << endl;
    else
        cout << "t1 has a larger area than t3" << endl;

    return 0;
}
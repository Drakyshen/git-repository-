#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Triangle {
private:
    double a, b, c;      // сторони трикутника
    double A, B, C;      // кути трикутника (у градусах)

    // Константа π
    const double PI = 3.14159265358979323846;

public:
    // Конструктор за замовчуванням
    Triangle() : a(0), b(0), c(0), A(0), B(0), C(0) {}

    // Метод ініціалізації
    void Init(double sideA, double sideB, double sideC) {
        if (sideA > 0 && sideB > 0 && sideC > 0 &&
            sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {
            a = sideA;
            b = sideB;
            c = sideC;

            // Обчислення кутів за теоремою косинусів
            A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI;
            B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;
            C = 180 - A - B;
        }
        else {
            cout << "Error: such triangle does not exist!" << endl;
            a = b = c = A = B = C = 0;
        }
    }

    // Метод введення з клавіатури
    void Read() {
        double sideA, sideB, sideC;
        cout << "Enter side a: ";
        cin >> sideA;
        cout << "Enter side b: ";
        cin >> sideB;
        cout << "Enter side c: ";
        cin >> sideC;
        Init(sideA, sideB, sideC);
    }

    // Метод виведення на екран
    void Display() const {
        cout << toString() << endl;
    }

    // Метод перетворення в рядок
    string toString() const {
        string type = triangleType();
        string result = "Sides: a=" + to_string(a) + ", b=" + to_string(b) + ", c=" + to_string(c) + "\n";
        result += "Angles: A=" + to_string(A) + "°, B=" + to_string(B) + "°, C=" + to_string(C) + "°\n";
        result += "Perimeter: " + to_string(perimeter()) + "\n";
        result += "Area: " + to_string(area()) + "\n";
        result += "Heights: ha=" + to_string(heightA()) + ", hb=" + to_string(heightB()) + ", hc=" + to_string(heightC()) + "\n";
        result += "Triangle type: " + type + "\n";
        return result;
    }

    // Обчислення периметра
    double perimeter() const {
        return a + b + c;
    }

    // Обчислення площі (за формулою Герона)
    double area() const {
        double p = perimeter() / 2;
        // Додаємо перевірку на коректність для уникнення NaN
        if (p <= 0 || p <= a || p <= b || p <= c) {
            return 0;
        }
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // Обчислення висот
    double heightA() const {
        if (a == 0) return 0;
        return (2 * area()) / a;
    }

    double heightB() const {
        if (b == 0) return 0;
        return (2 * area()) / b;
    }

    double heightC() const {
        if (c == 0) return 0;
        return (2 * area()) / c;
    }

    // Визначення типу трикутника
    string triangleType() const {
        const double epsilon = 0.001;

        if (a == 0 || b == 0 || c == 0) return "Invalid";

        // Перевірка на рівносторонній
        if (fabs(a - b) < epsilon && fabs(b - c) < epsilon)
            return "Equilateral";

        // Перевірка на рівнобедрений
        else if (fabs(a - b) < epsilon || fabs(a - c) < epsilon || fabs(b - c) < epsilon)
            return "Isosceles";

        // Перевірка на прямокутний
        else if (fabs(A - 90) < epsilon || fabs(B - 90) < epsilon || fabs(C - 90) < epsilon)
            return "Right-angled";

        // Перевірка за теоремою Піфагора
        else if (fabs(a * a + b * b - c * c) < epsilon ||
            fabs(a * a + c * c - b * b) < epsilon ||
            fabs(b * b + c * c - a * a) < epsilon)
            return "Right-angled";

        else
            return "Scalene";
    }

    // Гетери для отримання значень сторін
    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }

    // Гетери для отримання значень кутів
    double getAngleA() const { return A; }
    double getAngleB() const { return B; }
    double getAngleC() const { return C; }

    // Сетери для зміни значень сторін
    void setSideA(double sideA) {
        if (sideA > 0 && sideA + b > c && sideA + c > b && b + c > sideA) {
            a = sideA;
            // Перерахувати кути
            A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI;
            B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;
            C = 180 - A - B;
        }
    }

    void setSideB(double sideB) {
        if (sideB > 0 && a + sideB > c && a + c > sideB && sideB + c > a) {
            b = sideB;
            // Перерахувати кути
            A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI;
            B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;
            C = 180 - A - B;
        }
    }

    void setSideC(double sideC) {
        if (sideC > 0 && a + b > sideC && a + sideC > b && b + sideC > a) {
            c = sideC;
            // Перерахувати кути
            A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI;
            B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;
            C = 180 - A - B;
        }
    }
};

int main() {
    Triangle T;       // створення об'єкта класу
    T.Read();         // введення даних з клавіатури
    cout << endl;
    T.Display();      // виведення результатів на екран

    // Демонстрація роботи гетерів та сетерів
    cout << "\nDemonstration of getters and setters:" << endl;
    cout << "Current side A: " << T.getSideA() << endl;
    T.setSideA(6.0);
    cout << "After changing side A to 6.0:" << endl;
    T.Display();

    return 0;
}
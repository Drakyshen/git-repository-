#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Triangle {
private:
    double side1;
    double side2;
    double side3;

    // Перевірка чи існує трикутник
    bool isValid() const {
        return (side1 + side2 > side3 &&
            side1 + side3 > side2 &&
            side2 + side3 > side1);
    }

public:
    // --- Метод ініціалізації ---
    void Init(double a, double b, double c) {
        side1 = a;
        side2 = b;
        side3 = c;
    }

    // --- Метод введення ---
    void Read() {
        cout << "Enter 3 sides of triangle: ";
        cin >> side1 >> side2 >> side3;
    }

    // --- Метод виведення ---
    void Display() const {
        cout << toString() << endl;
    }

    // --- Перетворення у рядок ---
    string toString() const {
        string info = "Triangle:\n";
        info += "  sides: (" + to_string(side1) + ", " + to_string(side2) + ", " + to_string(side3) + ")\n";
        info += "  perimeter: " + to_string(perimeter()) + "\n";
        info += "  area: " + to_string(area()) + "\n";
        info += "  type: " + getType() + "\n";
        return info;
    }

    // --- Методи обчислення ---
    double perimeter() const {
        return side1 + side2 + side3;
    }

    double area() const {
        if (!isValid()) return 0;
        double s = perimeter() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double heightToSide1() const {
        if (!isValid()) return 0;
        return (2 * area()) / side1;
    }

    double heightToSide2() const {
        if (!isValid()) return 0;
        return (2 * area()) / side2;
    }

    double heightToSide3() const {
        if (!isValid()) return 0;
        return (2 * area()) / side3;
    }

    string getType() const {
        if (!isValid()) return "Not a triangle";

        if (side1 == side2 && side2 == side3)
            return "Equilateral";
        else if (side1 == side2 || side1 == side3 || side2 == side3)
            return "Isosceles";
        else if (fabs(side1 * side1 + side2 * side2 - side3 * side3) < 1e-6 ||
            fabs(side1 * side1 + side3 * side3 - side2 * side2) < 1e-6 ||
            fabs(side2 * side2 + side3 * side2 - side1 * side1) < 1e-6)
            return "Right";
        else
            return "Scalene";
    }
};

// --- Основна функція ---
int main() {
    cout << fixed << setprecision(3);

    Triangle t1;
    t1.Read();
    t1.Display();

    Triangle t2;
    t2.Init(5, 5, 5);
    t2.Display();

    Triangle t3;
    t3.Init(3, 4, 5);
    cout << "\nThird triangle info:\n";
    t3.Display();
    cout << "Height to side 3: " << t3.heightToSide3() << endl;

    return 0;
}
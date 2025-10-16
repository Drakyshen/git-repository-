#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Triangle {
private:
    double a, b, c;     // sides
    double A, B, C;     // angles (in degrees)

public:
    // ===== Initialization method =====
    void Init(double s1, double s2, double s3) {
        a = s1;
        b = s2;
        c = s3;
        calculateAngles();
    }

    // ===== Input from keyboard =====
    void Read() {
        cout << "Enter sides a, b, c: ";
        cin >> a >> b >> c;
        calculateAngles();
    }

    // ===== Display method =====
    void Display() {
        cout << toString() << endl;
    }

    // ===== Convert to string =====
    string toString() {
        string type = getType();
        return "Triangle: sides = (" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) +
            "), angles = (" + to_string(A) + ", " + to_string(B) + ", " + to_string(C) +
            "), perimeter = " + to_string(perimeter()) +
            ", area = " + to_string(area()) +
            ", type = " + type;
    }

    // ===== Getters and setters =====
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void setA(double value) { a = value; calculateAngles(); }
    void setB(double value) { b = value; calculateAngles(); }
    void setC(double value) { c = value; calculateAngles(); }

    // ===== Computation methods =====
    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        double s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void calculateAngles() {
        if (a > 0 && b > 0 && c > 0) {
            A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
            B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / M_PI;
            C = 180 - (A + B);
        }
        else {
            A = B = C = 0;
        }
    }

    double heightA() const {
        return 2 * area() / a;
    }

    double heightB() const {
        return 2 * area() / b;
    }

    double heightC() const {
        return 2 * area() / c;
    }

    string getType() const {
        if (a == b && b == c)
            return "Equilateral";
        else if (a == b || b == c || a == c)
            return "Isosceles";
        else if (fabs(pow(a, 2) + pow(b, 2) - pow(c, 2)) < 0.0001 ||
            fabs(pow(a, 2) + pow(c, 2) - pow(b, 2)) < 0.0001 ||
            fabs(pow(b, 2) + pow(c, 2) - pow(a, 2)) < 0.0001)
            return "Right";
        else
            return "Scalene";
    }
};

int main() {
    cout << "=== Triangle Example ===" << endl;

    Triangle t1;
    t1.Read();
    t1.Display();

    cout << "Height to side a: " << t1.heightA() << endl;
    cout << "Height to side b: " << t1.heightB() << endl;
    cout << "Height to side c: " << t1.heightC() << endl;

    return 0;
}
#include <iostream>
using namespace std;

struct Pair {
    double first;   // ціна товару (дробове додатнє число)
    int second;     // кількість товару (ціле додатнє число)

    // Метод ініціалізації
    void Init(double price, int quantity) {
        if (price > 0 && quantity > 0) {
            first = price;
            second = quantity;
        }
        else {
            cout << "Error: price and quantity must be positive values!" << endl;
            first = 0;
            second = 0;
        }
    }

    // Метод введення з клавіатури
    void Read() {
        double price;
        int quantity;
        cout << "Enter product price: ";
        cin >> price;
        cout << "Enter quantity: ";
        cin >> quantity;
        Init(price, quantity);
    }

    // Метод виведення на екран
    void Display() const {
        cout << "Product price: " << first << " UAH" << endl;
        cout << "Quantity: " << second << " pcs" << endl;
        cout << "Total cost: " << cost() << " UAH" << endl;
    }

    // Метод обчислення вартості
    double cost() const {
        return first * second;
    }
};

int main() {
    Pair product;       // створення об'єкта структури
    product.Read();     // введення з клавіатури
    cout << endl;
    product.Display();  // виведення результатів
    return 0;
}

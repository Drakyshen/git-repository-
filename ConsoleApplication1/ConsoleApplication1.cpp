#include <iostream>
using namespace std;

struct Pair {
    double first;   // ���� ������ (������� ������ �����)
    int second;     // ������� ������ (���� ������ �����)

    // ����� �����������
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

    // ����� �������� � ���������
    void Read() {
        double price;
        int quantity;
        cout << "Enter product price: ";
        cin >> price;
        cout << "Enter quantity: ";
        cin >> quantity;
        Init(price, quantity);
    }

    // ����� ��������� �� �����
    void Display() const {
        cout << "Product price: " << first << " UAH" << endl;
        cout << "Quantity: " << second << " pcs" << endl;
        cout << "Total cost: " << cost() << " UAH" << endl;
    }

    // ����� ���������� �������
    double cost() const {
        return first * second;
    }
};

int main() {
    Pair product;       // ��������� ��'���� ���������
    product.Read();     // �������� � ���������
    cout << endl;
    product.Display();  // ��������� ����������
    return 0;
}

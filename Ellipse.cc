#include <iostream>
#include "Ellipse.h"

using namespace std;

Ellipse::Ellipse(Vector2D A, Vector2D B, Vector2D C) :
        A(A), B(B), C(C)
{
}

Ellipse::Ellipse() {
}

double Ellipse::mass() const {
    return this->square();
}

Vector2D Ellipse::position() const {
    return (A + B + C * 4) / 3;
}

bool Ellipse::operator== (const IPhysObject& other) const {
    return mass() == other.mass();
}

bool Ellipse::operator< (const IPhysObject& other) const {
    return mass() < other.mass();
}

double Ellipse::square() const {
    return M_PI * length_a * length_b;
}

double Ellipse::perimeter() const {
    return 4 * (M_PI + (length_a - length_b)) / (length_a + length_b);
}

unsigned Ellipse::size() {
    return sizeof(*this);
}

const char* Ellipse::className() {
    return "Ellipse";
}

void Ellipse::initFromDialog() {
    cout << "Создание объекта 'эллипс' " << endl;
    cout << "Введите координаты точки центра через пробел: ";
    cin >> x_c >> y_c;
    C = Vector2D(x_c, y_c);
    cout << "Введите координаты точки a через пробел: (точка a > b)! :";
    cin >> x_a >> y_a;
    length_a = sqrt(pow(x_c - x_a,2)+pow(y_c - y_a,2));
    A = Vector2D(x_a, y_a);
    cout << "Введите координаты точки b через пробел: ";
    cin >> x_b >> y_b;
    length_b = sqrt(pow(x_c - x_b,2)+pow(y_c - y_b,2));
    B = Vector2D(x_b, y_b);
    if (length_a < length_b) {
        cout << "Неверный размер эллипса";
        exit(-1);
    }
    B = Vector2D(x_b, y_b);
}

void Ellipse::draw() {
    cout << "Эллипс на точках: " << endl;
    cout << "Центр: " << C << endl;
    cout << "Большая полуось: " << A << endl;
    cout << "Меньшая полуось: " << B << endl;
    cout << "С размером болльше полуоси: " << length_a << endl << "Меньшей полуоси :" << length_b << endl;
}
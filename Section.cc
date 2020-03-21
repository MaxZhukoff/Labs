#include <iostream>
#include "Section.h"

using namespace std;

Section::Section(Vector2D A, Vector2D B) :
        A(A), B(B)
{
}

Section::Section() {
}

double Section::mass() const {
    return this->square();
}

Vector2D Section::position() const {
    return (A + B) / 2;
}

bool Section::operator==(const IPhysObject& other) const {
    return mass() == other.mass();
}

bool Section::operator<(const IPhysObject& other) const {
    return mass() < other.mass();
}

double Section::square() const {
    return 0;
}

double Section::perimeter() const {
    return length;
}

unsigned Section::size() {
    return sizeof(*this);
}

const char* Section::className() {
    return "Section";
}

void Section::initFromDialog() {
    cout << "Создание объекта 'отрезок' " << endl;
    cout << "Введите координаты первой точки через пробел: ";
    cin >> x1 >> y1;
    A = Vector2D(x1, y1);
    cout << "Введите координаты второй точки через пробел: ";
    cin >> x2 >> y2;
    B = Vector2D(x2, y2);
    length = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void Section::draw() {
    cout << "Отрезок на точках: " << endl;
    cout << A << " " << B <<  " " << endl;
    cout << "Длина отрезка: " << length << endl;
}
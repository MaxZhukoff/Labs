#include "Vector.h"

Vector::Vector(double x1, double y1, double x2, double y2) {
    SetCoordVec(x1, y1, x2, y2);
    SetLenght(this->X, this->Y);
}
Vector::Vector(double x) {
    lenght = x;
}

double Vector::GetCoordVecX()const {
    return X;
}

double Vector::GetCoordVecY()const {
    return Y;
}

void Vector::GetCoordVec()const {
    std::cout << "(" << X << ", " << Y << ")";
}

double Vector::GetlenghtVec()const {
    return this->lenght;
}

bool Vector::operator >(const Vector &other) {
    return this->lenght > other.lenght;
}

bool Vector::operator <(const Vector &other) {
    return this->lenght < other.lenght;
}

bool Vector::operator >=(const Vector &other) {
    return this->lenght >= other.lenght;
}

bool Vector::operator <=(const Vector &other) {
    return this->lenght <= other.lenght;
}

bool Vector::operator ==(const Vector &other) {
    return this->lenght == other.lenght;
}

bool Vector::operator !=(const Vector &other) {
    return this->lenght != other.lenght;
}

void Vector::SetLenght(double X, double Y) {
    this->lenght = sqrt((X * X) + (Y * Y));
}

void Vector::SetCoordVec(double x1, double y1, double x2, double y2) {
    this->X = x2 - x1;
    this->Y = y2 - y1;
}
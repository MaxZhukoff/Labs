#include "Base.h"

Vector2D::Vector2D(double x, double y) :
        x(x), y(y)
{
}

Vector2D Vector2D::operator+ (const Vector2D& other) const {
    return {x + other.x, y + other.y};
}

Vector2D Vector2D::operator- (const Vector2D& other) const {
    return {x - other.x, y - other.y};
}

Vector2D Vector2D::operator* (const double k) const {
    return {x * k, y * k};
}

double Vector2D::operator* (const Vector2D& other) const {
    return x * other.x + y * other.y;
}

Vector2D Vector2D::operator/ (const double k) const {
    return {x / k, y / k};
}

std::ostream& operator << (std::ostream& os, const Vector2D& v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

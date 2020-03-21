#ifndef PRG_4_ELLIPSE_H
#define PRG_4_ELLIPSE_H

#include <iostream>
#include <cmath>
#include <vector>
#include "Base.h"

class Ellipse : public BaseClass {
public:
    Vector2D A, B, C;
    Ellipse(Vector2D, Vector2D, Vector2D);
    Ellipse();
    double mass() const override;
    Vector2D position() const override;
    bool operator==(const IPhysObject&) const override;
    bool operator< (const IPhysObject&)const override;
    double square() const override;
    double perimeter() const override;
    unsigned size() override;
    const char *className() override;
    void initFromDialog() override;
    void draw() override;
private:
    double x_c, y_c;
    double x_a, y_a;
    double x_b, y_b;
    double length_a, length_b;
};

#endif //PRG_4_ELLIPSE_H

#ifndef PRG_4_SECTION_H
#define PRG_4_SECTION_H

#include <iostream>
#include <cmath>
#include <vector>
#include "Base.h"

class Section : public BaseClass {
public:
    Vector2D A, B;
    Section(Vector2D, Vector2D);
    Section();
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
    double x1, y1;
    double x2, y2;
    double length;
};


#endif //PRG_4_SECTION_H

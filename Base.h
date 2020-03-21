#ifndef PRG_4_BASE_H
#define PRG_4_BASE_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class IGeoFig {
public:
    virtual double square() const = 0;
    virtual double perimeter() const = 0;
};

class Vector2D {
public:
    double x, y;
    Vector2D(double = 0, double = 0);
    Vector2D operator+ (const Vector2D&) const;
    Vector2D operator- (const Vector2D&) const;
    Vector2D operator* (const double) const;
    double operator* (const Vector2D&) const;
    Vector2D operator/ (const double) const;
    friend ostream& operator << (ostream&, const Vector2D&);
};

class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual Vector2D position() const = 0;
    virtual bool operator== (const IPhysObject& ob) const = 0;
    virtual bool operator< (const IPhysObject& ob) const = 0;
};

class IPrintable {
public:
    virtual void draw() = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

class BaseObject {
public:
    virtual const char *className() = 0;
    virtual unsigned int size() = 0;
};

class BaseClass : public BaseObject, public IGeoFig, public IDialogInitiable, public IPrintable, public IPhysObject {
};

#endif //PRG_4_BASE_H

#ifndef PRG_6_VECTOR_H
#define PRG_6_VECTOR_H

#include <iostream>
#include <cmath>
#include <vector>

class Vector {
public:
    Vector(double, double, double, double);
    Vector(double);
    double GetCoordVecX()const;
    double GetCoordVecY()const;
    void GetCoordVec()const;
    double GetlenghtVec()const;
    bool operator >(const Vector&);
    bool operator <(const Vector&);
    bool operator >=(const Vector&);
    bool operator <=(const Vector&);
    bool operator ==(const Vector&);
    bool operator !=(const Vector&);
private:
    double lenght;
    double X;
    double Y;
    void SetLenght(double, double);
    void SetCoordVec(double, double, double, double);
};

#endif
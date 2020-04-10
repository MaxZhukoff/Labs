#ifndef PRG_5_DEGREE_H
#define PRG_5_DEGREE_H

#include <cmath>

template <typename T>

T degree(const T &number, const int &power) {
    //return pow(number, power);
    T res = number;
    if (power == 0) {
        return 1;
    }
    if (power > 0) {
        for (int i = 1; i < power; i++) {
            res *= number;
        }
    }
    if (power < 0) {
        for (int i = 1; i > power; i--) {
            res /= number;
        }
    }
    return res;
}

#endif
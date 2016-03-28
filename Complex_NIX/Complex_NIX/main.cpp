//
//  main.cpp
//  Complex_NIX
//
//  Created by Андрей Решетников on 04.10.15.
//  Copyright © 2015 mipt. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

class C {
public:
    double re, im;
    double abs() {
        return sqrt(re*re + im*im);
    }
    C() {}
    ~C() {}
    C(double x, double y) {
        re = x;
        im = y;
    }
    C(pair<double, double> x) {
        re = x.first;
        im = x.second;
    }
    C(double x) {
        re = x;
        im = 0;
    }
    C operator+(const C &x) const {
        C y;
        y.re = re + x.re;
        y.im = im + x.im;
        return y;
    }
    C operator+(const double x) const {
        C y;
        y.re = re + x;
        y.im = im;
        return y;
    }
    C operator-(const C &x) const {
        C y;
        y.re = re - x.re;
        y.im = im - x.im;
        return y;
    }
    C operator-(const double x) const {
        C y;
        y.re = re - x;
        y.im = im;
        return y;
    }
    C operator*(const C &x) const {
        C y;
        y.re = re*x.re - im*x.im;
        y.im = re*x.im + im*x.re;
        return y;
    }
    C operator*(const double x) const {
        C y;
        y.re = re * x;
        y.im = im * x;
        return y;
    }
    C operator/(const C &x) const {
        C y;
        y.re = (re*x.re + im*x.im)/(x.im*x.im + x.re*x.re);
        y.im = (x.re*im - x.im*re)/(x.im*x.im + x.re*x.re);
        return y;
    }
    C operator/(const double x) const {
        C y;
        y.re = re / x;
        y.im = im / x;
        return y;
    }
    /*C& operator++() {
        re += 1;
        return *this;
    }*/
    bool operator==(const C &x) {
        if (x.re == re && x.im == im) return true;
        else return false;
    }
    bool operator!=(const C &x) {
        return !(*this == x);
    }
    friend ostream& operator<<(ostream &stream, const C &x) {
        stream << x.re << " " << x.im;
        return stream;
    }
};

C operator+(const double x, const C y) {
    return C(x + y.re, y.im);
}

C operator-(const double x, const C y) {
    return C(x - y.re, -y.im);
}

C operator*(const double x, const C y) {
    return C(x * y.re, x * y.im);
}

C operator/(const double x, const C y) {
    return C((x * y.re) / (y.re*y.re + y.im*y.im),
             (-x * y.im) / (y.re*y.re + y.im*y.im));
}

bool operator==(const double x, const C y) {
    return (x == y.re && y.im == 0);
}

bool operator!=(const double x, const C y) {
    return !(x == y);
}

bool operator==(const C y, const double x) {
    return (x == y);
}

bool operator!=(const C y, const double x) {
    return !(x == y);
}
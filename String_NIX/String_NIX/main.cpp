//
//  main.cpp
//  String_NIX
//
//  Created by Андрей Решетников on 17.10.15.
//  Copyright © 2015 mipt. All rights reserved.
//

#include <iostream>

using namespace std;

class S {
private:
    char* p;
    size_t size;
public:
    S() {
        p = new char[1];
        p[0] = 0;
        size = 0;
    }
    S(const char c) {
        size = 1;
        p = new char[2];
        p[0] = c;
        p[1] = 0;
        if (!c) {
            size = 0;
        }
    }
    S(const char* s) {
        size = 0;
        const char *ch = s;
        while (*ch) {
            ++size;
            ++ch;
        }
        p = new char[size + 1];
        p[size] = 0;
        for (size_t i = 0; i < size; ++i) {
            p[i] = s[i];
        }
    }
    S(const S &s) {
        size = s.size;
        p = new char[size + 1];
        p[size] = 0;
        for (size_t i = 0; i < size; ++i) {
            p[i] = s.p[i];
        }
    }
    ~S(){
        delete[] p;
    }
    S &operator=(const S &s) {
        if (&s == this)
            return *this;
        delete[] p;
        size = s.size;
        p = new char[size + 1];
        p[size] = 0;
        for (size_t i = 0; i < size; ++i) {
            p[i] = s.p[i];
        }
        return *this;
    }
    S operator+(const S &s) const {
        S result(*this);
        result += s;
        return result;
    }
    S &operator+=(const S &s) {
        char *other_data = s.p;
        size_t other_size = s.size;
        char *left = p;
        size_t old_size = size;
        size = size + other_size;
        p = new char[size + 1];
        p[size] = 0;
        for (size_t i = 0; i < old_size; ++i) {
            p[i] = left[i];
        }
        for (size_t i = 0; i < other_size; ++i) {
            p[i + old_size] = other_data[i];
        }
        delete[] left;
        return *this;
    }
    size_t length() const {
        return size;
    }
    char& operator[](size_t x) {
        return p[x];
    }
    const char* str() const {
        return p;
    }
    friend ostream &operator<<(ostream& stream, const S &x) {
        return stream << x.str();
    }
};

#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP

#include <cstdio>

struct Complex {
    float re_;
    float im_;

    Complex(const Complex &other) = default;
    explicit Complex(float other);
    Complex(float re, float im);

    Complex &operator=(const Complex &other) = default;
    Complex &operator=(float other);

    Complex &operator+=(const Complex &other);
    Complex &operator+=(float other);

    Complex &operator-=(const Complex &other);
    Complex &operator-=(float other);

    Complex &operator*=(const Complex &other);
    Complex &operator*=(float other);

    Complex &operator/=(const Complex &other);
    Complex &operator/=(float other);

    Complex operator+() const;
    Complex operator-() const;

    Complex operator+(const Complex &rhs) const;
    Complex operator+(float rhs) const;

    Complex operator-(const Complex &rhs) const;
    Complex operator-(float rhs) const;

    Complex operator*(const Complex &rhs) const;
    Complex operator*(float rhs) const;

    Complex operator/(const Complex &rhs) const;
    Complex operator/(float rhs) const;

    bool operator==(const Complex &rhs) const;
    bool operator==(float rhs) const;

    bool operator!=(const Complex &rhs) const;
    bool operator!=(float rhs) const;

    void print(FILE *file) const;
    bool scan(FILE *file);

    float abs() const;
    float phase() const;
    float norm() const;
    Complex conj() const;
};

Complex operator+(float lhs, const Complex &rhs);
Complex operator-(float lhs, const Complex &rhs);
Complex operator*(float lhs, const Complex &rhs);
Complex operator/(float lhs, const Complex &rhs);
bool operator==(float lhs, const Complex &rhs);
bool operator!=(float lhs, const Complex &rhs);

Complex polar(float ro, float theta);

#endif // COMPLEX_COMPLEX_HPP

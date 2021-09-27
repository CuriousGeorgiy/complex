#include "complex/Complex.hpp"

#include "flt/Comparison.hpp"

#include <cmath>

Complex::Complex(float other)
: Complex(other, 0) {
}

Complex::Complex(float re, float im)
: re_(re), im_(im) {
}

Complex &Complex::operator=(float other) {
    re_ = other;
    im_ = 0;
    return *this;
}

Complex &Complex::operator+=(const Complex &other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

Complex &Complex::operator+=(float other) {
    re_ += other;
    return *this;
}

Complex &Complex::operator-=(const Complex &other) {
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

Complex &Complex::operator-=(float other) {
    re_ -= other;
    return *this;
}

Complex &Complex::operator*=(const Complex &other) {
    *this = {re_ * other.re_ - im_ * other.im_,
             im_ * other.re_ + re_ * other.im_};
    return *this;
}

Complex &Complex::operator*=(float other) {
    re_ *= other;
    im_ *= other;
    return *this;
}

Complex &Complex::operator/=(const Complex &other) {
    *this *= other.conj() / other.norm();
    return *this;
}

Complex &Complex::operator/=(float other) {
    re_ /= other;
    im_ /= other;
    return *this;
}

Complex Complex::operator+() const {
    return *this;
}

Complex Complex::operator-() const {
    return {-re_, -im_};
}

Complex Complex::operator+(const Complex &rhs) const {
    Complex sum = *this;
    sum += rhs;
    return sum;
}

Complex Complex::operator+(float rhs) const {
    Complex sum = *this;
    sum += rhs;
    return sum;
}

Complex Complex::operator-(const Complex &rhs) const {
    Complex diff = *this;
    diff -= rhs;
    return diff;
}

Complex Complex::operator-(float rhs) const {
    Complex diff = *this;
    diff -= rhs;
    return diff;
}

Complex Complex::operator*(const Complex &rhs) const {
    Complex prod = *this;
    prod *= rhs;
    return prod;
}

Complex Complex::operator*(float rhs) const {
    Complex prod = *this;
    prod *= rhs;
    return prod;
}

Complex Complex::operator/(const Complex &rhs) const {
    Complex quot = *this;
    quot /= rhs;
    return quot;
}

Complex Complex::operator/(float rhs) const {
    Complex quot = *this;
    quot /= rhs;
    return quot;
}

bool Complex::operator==(const Complex &rhs) const {
    return almost_equal(re_, rhs.re_) && almost_equal(im_, rhs.im_);
}

bool Complex::operator==(float rhs) const {
    return almost_equal(re_, rhs) && almost_equal(im_, 0);
}

bool Complex::operator!=(const Complex &rhs) const {
    return !(*this == rhs);
}

bool Complex::operator!=(float rhs) const {
    return !(*this == rhs);
}

void Complex::print(FILE *file) const {
    /* FIXME: how should we handle output errors? */
    fprintf(file, "(%g,%g)", re_, im_);
}

bool Complex::scan(FILE *file) {
    /* FIXME: how should we handle various input errors? */
    return fscanf(file, "(%g,%g)", &re_, &im_) == 2;
}

float Complex::abs() const {
    return sqrt(re_ * re_ + im_ * im_);
}

float Complex::phase() const {
    return atan2(im_, re_);
}

float Complex::norm() const {
    return re_ * re_ + im_ * im_;
}

Complex Complex::conj() const {
    return {re_, -im_};
}

Complex operator+(float lhs, const Complex &rhs) {
    return rhs + lhs;
}

Complex operator-(float lhs, const Complex &rhs) {
    Complex minu{lhs, 0};

    return minu - rhs;
}

Complex operator*(float lhs, const Complex &rhs) {
    return rhs * lhs;
}

Complex operator/(float lhs, const Complex &rhs) {
    Complex divid{lhs, 0};
    return divid / rhs;
}

bool operator==(float lhs, const Complex &rhs) {
    return rhs == lhs;
}

bool operator!=(float lhs, const Complex &rhs) {
    return rhs != lhs;
}

Complex polar(float ro, float theta) {
    return {ro * sin(theta), ro * cos(theta)};
}
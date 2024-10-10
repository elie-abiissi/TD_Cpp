#include "Complex2D.h"
#include <math.h>
using namespace std;
Complex2D::Complex2D() : reel(0.0), img(0.0) {}
Complex2D::Complex2D(double _value) : reel(_value), img(_value) {}
Complex2D::Complex2D(double _reel, double _img) : reel(_reel), img(_img) {}
Complex2D::Complex2D(const Complex2D& _cmp) : reel(_cmp.reel), img(_cmp.img) {}


void Complex2D::setReel(double _reel) { reel = _reel; }
void Complex2D::setImg(double _img) { img = _img; }

double Complex2D::getReel() const { return reel; }
double Complex2D::getImg() const { return img; }

Complex2D operator+(const Complex2D& _c1, const Complex2D& _c2) {
    return Complex2D(_c1.reel + _c2.reel, _c1.img + _c2.img);
}


Complex2D operator-(const Complex2D& c1, const Complex2D& c2) {
    return Complex2D(c1.reel - c2.reel, c1.img - c2.img);
}

Complex2D operator*(const Complex2D& c1, const Complex2D& c2) {
    double reel = c1.reel * c2.reel - c1.img * c2.img;
    double img = c1.reel * c2.img + c1.img * c2.reel;
    return Complex2D(reel, img);
}

Complex2D operator/(const Complex2D& c1, const Complex2D& c2) {
    double module = pow(c2.module(),2);
    return (Complex2D(c1.reel/module , c1.img/ module) * c2.symmetry());
}

bool operator<(const Complex2D& c1, const Complex2D& c2) {
    return c1.module() < c2.module();
}

bool operator>(const Complex2D& c1, const Complex2D& c2) {
    return c1.module() > c2.module();
}

Complex2D Complex2D::symmetry() const {
    return Complex2D(reel, -img);
}

double Complex2D::module() const {
    return sqrt(reel * reel + img * img);
}

void Complex2D::rotation(double theta) {
    double new_reel = reel * cos(theta) - img * sin(theta);
    double new_img = reel * sin(theta) + img * cos(theta);
    reel = new_reel;
    img = new_img;
}

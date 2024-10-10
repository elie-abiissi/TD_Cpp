#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <string>
using namespace  std;


class Complex2D {
private:
    double reel;
    double img;

public:
    Complex2D();
    Complex2D(double );
    Complex2D(double , double );
    Complex2D(const Complex2D& );


    double getReel() const;
    double getImg() const;

    void setReel(double);
    void setImg(double);

    friend Complex2D operator+(const Complex2D&, const Complex2D&);
    friend Complex2D operator-(const Complex2D&, const Complex2D&);
    friend Complex2D operator*(const Complex2D&, const Complex2D&);
    friend Complex2D operator/(const Complex2D&, const Complex2D&);
    friend bool operator<(const Complex2D&, const Complex2D&);
    friend bool operator>(const Complex2D&, const Complex2D&);

    Complex2D symmetry() const;
    void rotation(double);
    double module() const;

};

#endif

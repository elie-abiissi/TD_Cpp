#include <iostream>
#include <cmath>
#include "Complex2D.h"

using namespace std;

int main() {

    Complex2D c1(3, 4);
    Complex2D c2(1, 2);
    Complex2D c3(5, 12);

    cout << "Nombre complexe c1 : " << c1.getReel() << " + " << c1.getImg() << "i" << endl;
    cout << "Nombre complexe c2 : " << c2.getReel() << " + " << c2.getImg() << "i" << endl;
    cout << "Nombre complexe c3 : " << c3.getReel() << " + " << c3.getImg() << "i" << endl;


    cout << "Module de c1 : " << c1.module() << endl;
    cout << "Module de c2 : " << c2.module() << endl;
    cout << "Module de c3 : " << c3.module() << endl;

    Complex2D sum = c1 + c2;
    cout << "c1 + c2 = " << sum.getReel() << " + " << sum.getImg() << "i" << endl;

    Complex2D diff = c1 - c2;
    cout << "c1 - c2 = " << diff.getReel() << " + " << diff.getImg() << "i" << endl;

    Complex2D prod = c1 * c2;
    cout << "c1 * c2 = " << prod.getReel() << " + " << prod.getImg() << "i" << endl;

    Complex2D quot = c1 / c2;
    cout << "c1 / c2 = " << quot.getReel() << " + " << quot.getImg() << "i" << endl;


    if (c1 < c3) {
        cout << "c1 est plus petit que c3" << endl;
    }
    if (c2 < c3) {
        cout << "c2 est plus petit que c3" << endl;
    }
    if (c1 > c2) {
        cout << "c1 est plus grand que c2" << endl;
    }


    Complex2D sym_c1 = c1.symmetry();
    cout << "Symetrie de c1 : " << sym_c1.getReel() << " + " << sym_c1.getImg() << "i" << endl;


    double theta = M_PI / 4; 
    Complex2D c1_rot = c1; 
    c1_rot.rotation(theta);
    cout << "c1 apres rotation de 45 degres : " << c1_rot.getReel() << " + " << c1_rot.getImg() << "i" << endl;

    return 0;
}

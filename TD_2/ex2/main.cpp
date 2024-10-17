#include <iostream>
#include "matrix_num.h"

using namespace std;

int main() {



    MatrixNumerical<int> intMatrix2x2(2, 2);
    intMatrix2x2.addElement(0, 0, 4);
    intMatrix2x2.addElement(0, 1, 7);
    intMatrix2x2.addElement(1, 0, 2);
    intMatrix2x2.addElement(1, 1, 6);

    MatrixNumerical<int> intMatrix2x2_2(2, 2);
    intMatrix2x2_2.addElement(0, 0, 3);
    intMatrix2x2_2.addElement(0, 1, 8);
    intMatrix2x2_2.addElement(1, 0, 4);
    intMatrix2x2_2.addElement(1, 1, 6);

    cout << "2x2 Integer Matrix 1:\n";
    intMatrix2x2.Display();

    cout << "\n2x2 Integer Matrix 2:\n";
    intMatrix2x2_2.Display();

    MatrixNumerical<int> sum2x2 = intMatrix2x2 + intMatrix2x2_2;
    cout << "\nSum of 2x2 Integer Matrices:\n";
    sum2x2.Display();

    MatrixNumerical<int> product2x2 = intMatrix2x2 * intMatrix2x2_2;
    cout << "\nProduct of 2x2 Integer Matrices:\n";
    product2x2.Display();

    cout << "\nDeterminant of 2x2 Integer Matrix 1: " << intMatrix2x2.getDeterminant() << endl;
    cout << "\nDeterminant of 2x2 Integer Matrix 2: " << intMatrix2x2_2.getDeterminant() << endl;

    cout << "\nDivision of 2x2 Integer Matrix 1 by Matrix 2:\n";
    MatrixNumerical<int> divisionResult = intMatrix2x2 / intMatrix2x2_2;
    divisionResult.Display();

    MatrixNumerical<float> floatMatrix2x2(2, 2);
    floatMatrix2x2.addElement(0, 0, 4.1f);
    floatMatrix2x2.addElement(0, 1, 7.3f);
    floatMatrix2x2.addElement(1, 0, 2.2f);
    floatMatrix2x2.addElement(1, 1, 6.0f);

    MatrixNumerical<float> floatMatrix2x2_2(2, 2);
    floatMatrix2x2_2.addElement(0, 0, 3.0f);
    floatMatrix2x2_2.addElement(0, 1, 8.6f);
    floatMatrix2x2_2.addElement(1, 0, 4.5f);
    floatMatrix2x2_2.addElement(1, 1, 6.7f);

    cout << "\n2x2 Float Matrix 1:\n";
    floatMatrix2x2.Display();

    cout << "\n2x2 Float Matrix 2:\n";
    floatMatrix2x2_2.Display();

    MatrixNumerical<float> sum2x2float = floatMatrix2x2 + floatMatrix2x2_2;
    cout << "\nSum of 2x2 Float Matrices:\n";
    sum2x2float.Display();

    MatrixNumerical<float> product2x2float = floatMatrix2x2 * floatMatrix2x2_2;
    cout << "\nProduct of 2x2 Float Matrices:\n";
    product2x2float.Display();

    cout << "\nDeterminant of 2x2 Float Matrix 1: " << floatMatrix2x2.getDeterminant() << endl;
    cout << "\nDeterminant of 2x2 Float Matrix 2: " << floatMatrix2x2_2.getDeterminant() << endl;

    cout << "\nDivision of 2x2 Float Matrix 1 by Matrix 2:\n";
    MatrixNumerical<float> divisionResultfloat = floatMatrix2x2 / floatMatrix2x2_2;
    divisionResultfloat.Display();

    return 0;
}

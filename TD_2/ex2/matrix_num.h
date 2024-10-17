using namespace   std;

#ifndef MATRIX_NUM_H
#define MATRIX_NUM_H

#include "matrix_base.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical(size_t rows, size_t cols);
    T getDeterminant() const;
    MatrixNumerical<T> getInverse() const;
    static MatrixNumerical<T> getIdentity(int size);
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other);
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other);
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other);
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other);

private:
    MatrixNumerical<T> getCoFactor(size_t p, size_t q, size_t n) const;
};

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCoFactor(size_t p, size_t q, size_t n) const {
    MatrixNumerical<T> cofactor(n - 1, n - 1);
    size_t row = 0, col = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            // Skip the row `p` and column `q`
            if (i != p && j != q) {
                cofactor.addElement(row, col, this->getElement(i, j));
                col++;
                // When we reach the end of a row in the cofactor matrix, reset col and increment row
                if (col == n - 1) {
                    col = 0;
                    row++;
                }
            }
        }
    }
    return cofactor;
}



template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols) {
        throw invalid_argument("Determinant can only be calculated for square matrices.");
    }

    size_t n = this->rows;

    // Base case for 1x1 matrix
    if (n == 1) {
        return this->data[0][0];  // The determinant is the single element itself
    }

    // Base case for 2x2 matrix
    if (n == 2) {
        return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
    }

    T determinant = 0;

    // Calculate the determinant for larger matrices
    for (size_t i = 0; i < n; ++i) {
        // Get the cofactor of the element at (0, i)
        MatrixNumerical<T> cofactor = getCoFactor(0, i, n);
        // Add the contribution of the cofactor to the determinant
        determinant += ((i % 2 == 0) ? 1 : -1) * this->data[0][i] * cofactor.getDeterminant();
    }

    return determinant;
}



template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    T det = getDeterminant();

    if (det == 0) {
        throw invalid_argument("Matrix is singular, cannot compute inverse.");
    }

    size_t n = this->rows;
    MatrixNumerical<T> adjoint(n, n);
    MatrixNumerical<T> inverse(n, n);

    // Compute adjoint matrix (transpose of cofactor matrix)
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            // Get cofactor of element (i, j)
            MatrixNumerical<T> cofactor = getCoFactor(i, j, n);
            
            // Calculate the sign for the cofactor
            int sign = ((i + j) % 2 == 0) ? 1 : -1;

            // Calculate the determinant of the cofactor matrix
            T cofactorDet = cofactor.getDeterminant();
            adjoint.addElement(j, i, sign * cofactorDet);
        }
    }

    // Compute the inverse by dividing adjoint elements by the determinant
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            inverse.addElement(i, j, adjoint.getElement(i, j) / static_cast<double>(det));
        }
    }

    return inverse;
}




template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& other) {
    return (*this) * other.getInverse();
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        throw invalid_argument("Matrix dimensions must match for addition.");
    }
    MatrixNumerical<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.addElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        throw invalid_argument("Matrix dimensions must match for subtraction.");
    }
    MatrixNumerical<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.addElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& other) {
    if (this->getCols() != other.getRows()) {
        throw invalid_argument("Matrix dimensions must match for multiplication.");
    }
    MatrixNumerical<T> result(this->getRows(), other.getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < other.getCols(); ++j) {
            T sum = 0;
            for (size_t k = 0; k < this->getCols(); ++k) {
                sum += this->getElement(i, k) * other.getElement(k, j);
            }
            result.addElement(i, j, sum);
        }
    }
    return result;
}

#endif
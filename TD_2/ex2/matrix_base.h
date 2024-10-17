// matrix_base.h
using  namespace std;

#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <vector>
#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
class MatrixBase {
protected:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t, size_t);
    void addElement(size_t, size_t, const T&);
    T getElement(size_t, size_t) const;
    size_t getRows() const;
    size_t getCols() const;
    void Display() const;
};

// Definitions
template <typename T>
MatrixBase<T>::MatrixBase() : data(1, vector<T>(1)), cols(1), rows(1) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t _rows, size_t _cols)
    : rows(_rows), cols(_cols), data(_rows, vector<T>(_cols)) {}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, const T& value) {
    if (row < rows && col < cols) {
        data[row][col] = value;
    } else {
        throw out_of_range("Index out of range");
    }
}

template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const {
    if (row < rows && col < cols) {
        return data[row][col];
    } else {
        throw out_of_range("Index out of range");
    }
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

#endif
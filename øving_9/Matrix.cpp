#include "Matrix.h"

Matrix::Matrix():
rows{0}, columns{0}, matrix{nullptr}
{}

//Hva gjør {} i new double *[nRows] {}
Matrix::Matrix(int nRows, int nColumns):
rows{nRows}, columns{nColumns}, matrix{new double *[nRows]}
{
    for (int i = 0; i < nRows; ++i) {
        matrix[i] = new double[nColumns];
        for (int j = 0; j < nColumns; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int nRows):
Matrix{nRows, nRows} 
{
    for (int i = 0; i < nRows; ++i) {
        matrix[i][i] = 1;
    }
}

double Matrix::get(int row, int column) const {return matrix[row][column];}

void Matrix::set(int row, int column, double value) {matrix[row][column] = value;}

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getColumns(); ++j) {
            cout << m.matrix[i][j] << " ";
        }
        cout << '\n';
    }
    return os;
}

Matrix::~Matrix() {
    if (isValid()) {
        for (int i = 0; i < getRows(); ++i) {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        delete[] matrix;
        matrix = nullptr;
    }
}

Matrix::Matrix(const Matrix &other): Matrix{other.rows, other.columns} {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix& Matrix::operator+=(const Matrix &rhs) {
    if (rows != rhs.rows || columns != rhs.columns) {
        columns = 0;
        rows = 0;
        matrix = nullptr;
        return *this;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return *this;
}

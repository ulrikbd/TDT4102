#pragma once
#include <iostream>

using namespace std;

class Matrix {
    private:
        int rows;
        int columns;
        double** matrix;
    public:
        Matrix();
        Matrix(int nRows, int nColumns);
        explicit Matrix(int nRows);

        double get(int row, int column) const;
        void set(int row, int column, double value);

        int getRows() const {return rows;};
        int getColumns() const {return columns;};
        
        bool isValid() const {return matrix;};

        friend ostream& operator<<(ostream& os, const Matrix& m);

        Matrix(const Matrix &other);

        Matrix& operator=(Matrix rhs) {
            swap(matrix, rhs.matrix);
            swap(rows, rhs.rows);
            swap(columns, rhs.columns);
            return *this;
        }

        Matrix& operator+=(const Matrix &rhs);


        ~Matrix();
};

inline Matrix operator+(Matrix lhs, const Matrix& rhs) {
    lhs += rhs;
    return lhs;
}
#pragma once

#include <iostream>
#include <utility>

class Matrix {
public:
    Matrix();
    explicit Matrix(int nRows);
    Matrix(int nRows, int mCols);
    Matrix(const Matrix& rhs);

    friend std::ostream& operator<<(std::ostream& os, Matrix& m);
    double* operator[](int row) const;
    Matrix& operator=(Matrix rhs);

    Matrix& operator+=(const Matrix& rhs);
    Matrix  operator+(const Matrix& rhs) const;

    Matrix& operator-=(const Matrix& rhs);  
    Matrix  operator-(const Matrix& rhs) const;
    Matrix  operator-();

    Matrix& operator*=(const Matrix& rhs);
    Matrix& operator*=(const double d);
    Matrix  operator*(const Matrix& rhs) const;
    Matrix  operator*(const double d) const;


    bool isValid() const {return matrix != nullptr && rows && cols;}
    int getRows() const {return rows;}
    int getCols() const {return cols;}

    double get(int row, int col) const;
    void set(int row, int col, double value);

    ~Matrix();
private:
    int rows;
    int cols;
    double** matrix;
};


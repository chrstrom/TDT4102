#include "Matrix.h"

std::ostream& operator<<(std::ostream& os, Matrix& m) {
    if(!m.isValid()) {
        return os << "Cannot print invalid matrix.\n";
    }

    for(int row = 0; row < m.rows; row++){
        for(int col = 0; col < m.cols; col++) {
            os << m.matrix[row][col] << '\t';
        }
        os << "\n\n\n";
    }
    return os << '\n';
}

double* Matrix::operator[](int idx) const {
    return matrix[idx];
}

Matrix::Matrix() {
    matrix = nullptr;
}

Matrix::Matrix(int nRows) : Matrix{nRows, nRows} {
    for(int row = 0; row < nRows; row++)
        matrix[row][row] = 1;
}

Matrix::Matrix(int nRows, int mCols) : rows{nRows}, cols{mCols} {
    matrix = new double*[nRows];
    for(int row = 0; row < nRows; row++) {
        matrix[row] = new double[mCols];
        for(int col = 0; col < mCols; col++) {
            matrix[row][col] = 0;
        }
    }
}

Matrix::~Matrix() {
    for(int row = 0; row < rows; row++) 
        delete[] matrix[row];
        
    delete[] matrix;
}

double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}
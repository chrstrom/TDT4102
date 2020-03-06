#include "Matrix.h"


// Constructors and destructor
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

Matrix::Matrix(const Matrix& rhs) {
    int rows = rhs.getRows();
    int cols = rhs.getCols();
    this->matrix = new double*[rows];

     for(int row = 0; row < rows; row++) {
        this->matrix[row] = new double[cols];

        for(int col = 0; col < cols; col++) {
            matrix[row][col] = rhs[row][col];
        }
    }
}

Matrix::~Matrix() {
    for(int row = 0; row < rows; row++) 
        delete[] matrix[row];
        
    delete[] matrix;
}

// Overloads

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


// get and set
double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}
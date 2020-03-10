#include "Matrix.h"


// Constructors and destructor
Matrix::Matrix() : rows{0}, cols{0}, matrix{nullptr} {
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

Matrix::Matrix(const Matrix& rhs) : rows{rhs.rows}, cols{rhs.cols}, matrix{new double*[rhs.rows]} {  
    for(int row = 0; row < rows; row++) {
        matrix[row] = new double[cols];
        for(int col = 0; col < cols; col++) {
            matrix[row][col] = rhs[row][col];
        }
    }
}

Matrix::~Matrix() {
    for(int row = 0; row < rows; row++) {
        delete[] matrix[row];
        matrix[row] = nullptr;
    }   
    delete[] matrix;
    matrix = nullptr;

    rows = 0; cols = 0;
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


Matrix& Matrix::operator=(Matrix rhs) {
    if (!rhs.isValid()) {
		this->~Matrix();
		return *this;
	}

    std::swap(matrix, rhs.matrix);
    rows = rhs.rows;
    cols = rhs.cols; 
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {
    if(rows != rhs.rows || cols != rhs.cols) {
        this->~Matrix();
        return *this;
    }

    for(int row = 0; row < rows; row++) 
        for(int col = 0; col < cols; col++) 
            matrix[row][col] += rhs.matrix[row][col];
 
    return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if(rows != rhs.rows || cols != rhs.cols) {
        return Matrix{};
    }
    
    return Matrix{*this} += rhs;
}


Matrix& Matrix::operator-=(const Matrix& rhs) {
    if(rows != rhs.rows || cols != rhs.cols) {
        this->~Matrix();
        return *this;
    }

    for(int row = 0; row < rows; row++) 
        for(int col = 0; col < cols; col++) 
            matrix[row][col] -= rhs.matrix[row][col];
 
    return *this;
}
Matrix Matrix::operator-() {
	if (!isValid()) {
		return Matrix{};
	}
	return *this * -1;
}
Matrix Matrix::operator-(const Matrix& rhs) const {
    if(rows != rhs.rows || cols != rhs.cols) {
        return Matrix{};
    }
    
    return Matrix{*this} -= rhs;
}

Matrix Matrix::operator*(const Matrix & rhs) const {
	if (cols!= rhs.rows) 
		return Matrix{};
	

	Matrix temp{rows, rhs.cols};
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < rhs.cols; ++col) {
			temp[row][col] = 0.0;
			for (int i = 0; i < cols; ++i) {
				temp[row][col] += matrix[row][i] * rhs.matrix[i][col];
			}
		}
	}
	return temp;

}

Matrix & Matrix::operator*=(const Matrix & rhs) {
	return *this = *this * rhs;
}

Matrix Matrix::operator*(double rhs) const {
	return Matrix{ *this } *= rhs;
}

Matrix& Matrix::operator*=(double rhs) {
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++) 
			matrix[i][j] *= rhs;

	return *this;
}


// get/set
double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}

void testMatrix() {
    Matrix m1{};
    Matrix m2{3};
    Matrix m3{3};
    Matrix m4{2, 3};
    Matrix m5{3, 2};
    
    m3.set(1, 2, 2.5);
    m3.set(0, 2, 2.5);
    m3.set(0, 1, 2.5);

    m4.set(1, 1, 2.0);
    
    m5.set(1, 1, 2.0);

    std::cout << m1 << '\n';
    std::cout << m2 << '\n';
    std::cout << m3 << '\n';
    std::cout << m4 << '\n';
    std::cout << m5 << '\n';

    m4 *= m5;

    std::cout << m4 << '\n';
}

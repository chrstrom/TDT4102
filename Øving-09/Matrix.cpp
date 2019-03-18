#include "Matrix.h"
#include <utility>
#include <iostream>

Matrix::Matrix(int nRow, int nColumns) : nRows{ nRow }, mCol{ nColumns }, valid{ true } {
	//Allocate memory
	matrix = new double*[nRows];
	for (int i = 0; i < nRows; i++) {
		matrix[i] = new double[mCol];
	}

	//Initialize with 0's
	constexpr double init{ 0.0 };
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < mCol; j++) {
			matrix[i][j] = init;
		}
	}
}

Matrix::Matrix(int nRow) : Matrix{ nRow, nRow } {
	constexpr double id{ 1.0 };
	for (int i = 0; i < nRow; i++) {
		matrix[i][i] = id;
	}
};

//Copy constructor
Matrix::Matrix(const Matrix & rhs) : matrix{ nullptr }, nRows{ rhs.getRows() }, mCol{ rhs.getColumns() }, valid{ true } {
	matrix = new double*[nRows];
	for (int i = 0; i < nRows; i++) {
		matrix[i] = new double[mCol];
		for (int j = 0; j < mCol; j++) {
			matrix[i][j] = rhs.get(i, j);
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < nRows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

//Overloads
Matrix& Matrix::operator=(Matrix rhs) {
	std::swap(this->matrix, rhs.matrix);
	std::swap(this->nRows, rhs.nRows);
	std::swap(this->mCol, rhs.mCol);
	std::swap(this->valid, rhs.valid);

	return *this;
}

std::ostream& operator<< (std::ostream& os, Matrix& M) {
	if (M.valid) {
		for (int i = 0; i < M.getRows(); i++) {
			os << "\t ";
			for (int j = 0; j < M.getColumns(); j++) {
				os << M(i, j) << "\t";
			}
			os << "\n";
		}
	}
	else {
		os << "Invalid matrix\n";
	}
	return os;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {							//this-> er strengt tatt unødvendig, men greit for å ikke gå i surr med variabelnavnene
	if (this->nRows == rhs.nRows && this->mCol == rhs.mCol) {
		for (int i = 0; i < this->nRows; i++) {
			for (int j = 0; j < this->mCol; j++) {
				this->matrix[i][j] += rhs.matrix[i][j];
			}
		}
	}
	else {
		std::cout << "Dim(lhs) != Dim(rhs)";
		this->valid = false;
		return *this;
	}
	this->valid = true;
	return *this;
}

Matrix& Matrix::operator+(const Matrix& rhs) {
	static Matrix K{ *this };
	if (K.nRows == rhs.nRows && K.mCol == rhs.mCol) {
		K += rhs;
		return K;
	}
	else {
		std::cout << "Dim(lhs) != Dim(rhs)";
		K.valid = false;
		return K;
	}
}

bool Matrix::isValid() {
	if (matrix) {						//"nullptr" evalueres til false, alt annet er true
		valid = false;
		return valid;
	}
	else {
		valid = true;
		return valid;
	}
};
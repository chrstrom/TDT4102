#pragma once
#include <iostream>

class Matrix {
public:
	
	//Constructors, destructor
	Matrix() : matrix{nullptr} {};
	Matrix(int nRow, int nColumns);
	explicit Matrix(int nRow);

	Matrix(const Matrix & rhs);

	~Matrix();

	//Overloads
	friend std::ostream& operator<< (std::ostream& os, Matrix& M);
	const double& operator()(int row, int col) { return matrix[row][col]; };
	Matrix& operator=(Matrix rhs);
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator+(const Matrix& rhs);


	//Util functions
	double get(int row, int col) const { return matrix[row][col]; }
	void set(int row, int col, double value) { matrix[row][col] = value; }

	int getRows() const { return nRows; };
	int getColumns() const { return mCol;  };
	bool isValid();

private:
	bool valid;
	int nRows;
	int mCol;

	double** matrix;
};




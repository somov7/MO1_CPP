#pragma once

#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>

using namespace std;

class Vector
{
private:
	double* values;
	int size;
public:
	Vector() : size(0), values(nullptr) {}
	Vector(int size){	
		if (size < 0)
			throw out_of_range("Can't create negative-sized vector");
		this->size = size;
		this->values = new double[size];
		for (int i = 0; i < size; i++) {
			values[i] = 0;
		}
	}
	Vector(int size, double *values) {
		if (size < 0)
			throw out_of_range("Can't create negative-sized vector");
		this->size = size;
		this->values = new double[size];
		for (int i = 0; i < size; i++)
			this->values[i] = values[i];
	}
	Vector(const Vector &other) {
		this->size = other.size;	
		this->values = new double[this->size];
		for (int i = 0; i < other.size; i++)
			this->values[i] = other.values[i];
	}

	Vector& operator = (const Vector& other);

	Vector operator += (const Vector& other);
	Vector operator -= (const Vector& other);
	Vector operator *= (double factor);
	Vector operator /= (double factor);

	Vector operator + (const Vector other) const;
	Vector operator - (const Vector other) const;
	Vector operator * (double factor) const;
	Vector operator / (double factor) const;
	Vector operator - () const;

	bool operator < (const Vector& other) const;
	bool operator <= (const Vector& other) const;
	bool operator > (const Vector& other) const;
	bool operator >= (const Vector& other) const;
	bool operator == (const Vector& other) const;
	bool operator != (const Vector& other) const;

	double &operator ()(int index);
	double operator ()(int index) const;

	double length() const;

	int getSize() const {
		return this->size;
	}

	friend std::istream& operator >> (std::istream& is, Vector& vector);
	friend std::ostream& operator << (std::ostream& os, const Vector& vector);


	~Vector() {
		delete[] values;
	}

};

Vector operator * (double factor, const Vector& vector);
Vector operator / (double factor, const Vector& vector);
Vector abs(const Vector &vector);

#include "vector.h"

Vector& Vector::operator = (const Vector& other) {
	delete[] values;
	this->size = other.size;
	values = new double[this->size];
	for (int i = 0; i < this->size; i++)
		this->values[i] = other.values[i];
	return *this;
}

Vector Vector::operator +=(const Vector& other) {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++)
		this->values[i] += other.values[i];
	return *this;
}

Vector Vector::operator -=(const Vector& other) {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++)
		this->values[i] -= other.values[i];
	return *this;
}

Vector Vector::operator *= (double factor) {
	for (int i = 0; i < this->size; i++)
		this->values[i] *= factor;
	return *this;
}

Vector Vector::operator /= (double factor) {
	for (int i = 0; i < this->size; i++)
		this->values[i] /= factor;
	return *this;
}

Vector Vector::operator + (const Vector other) const {
	Vector res = *this;
	res += other;
	return res;
}

Vector Vector::operator - (const Vector other) const {
	Vector res = *this;
	res -= other;
	return res;
}

Vector Vector::operator * (double factor) const {
	Vector res = *this;
	res *= factor;
	return res;
}

Vector Vector::operator / (double factor) const {
	Vector res = *this;
	res /= factor;
	return res;

}

Vector Vector::operator - () const {
	Vector res = (*this) * (-1);
	return res;
}

double& Vector::operator()(int index) {
	if (index < 0 || index >= this->size)
		throw out_of_range("Index is out of range");
	return values[index];
}

double Vector::operator()(int index) const {
	if (index < 0 || index >= this->size)
		throw out_of_range("Index is out of range");
	return values[index];
}

double Vector::length() const {
	double length = 0;
	for (int i = 0; i < this->size; i++) {
		length += values[i] * values[i];
	}
	return sqrt(length);
}



std::istream& operator >> (std::istream& is, Vector& vector) {
	delete[] vector.values;
	is >> vector.size;
	vector.values = new double[vector.size];
	for (int i = 0; i < vector.size; i++) {
		is >> vector.values[i];
	}
	return is;
}

std::ostream& operator << (std::ostream& os, const Vector& vector) {
	os << "(";
	for (int i = 0; i < vector.size - 1; i++) {
		os << vector(i) << ", ";
	}
	os << vector(vector.size - 1) << ")";
	return os;
}

bool Vector::operator < (const Vector& other) const {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++) {
		if ((*this)(i) >= other(i))
			return false;
	}
	return true;
}
bool Vector::operator <= (const Vector& other) const {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++) {
		if ((*this)(i) > other(i))
			return false;
	}
	return true;
}
bool Vector::operator > (const Vector& other) const {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++) {
		if ((*this)(i) <= other(i))
			return false;
	}
	return true;
}
bool Vector::operator >= (const Vector& other) const {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++) {
		if ((*this)(i) < other(i))
			return false;
	}
	return true;
}
bool Vector::operator == (const Vector& other) const {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++) {
		if ((*this)(i) != other(i))
			return false;
	}
	return true;
}
bool Vector::operator != (const Vector& other) const {
	if (this->size != other.size)
		throw out_of_range("Vectors have different sizes");
	for (int i = 0; i < this->size; i++) {
		if ((*this)(i) == other(i))
			return false;
	}
	return true;
}

Vector operator * (double factor, const Vector& vector) {
	return vector * factor;
}

Vector operator / (double factor, const Vector& vector) {
	return vector / factor;
}

Vector abs(const Vector& vector) {
	Vector res = vector;
	for (int i = 0; i < res.getSize(); i++) {
		if (res(i) < 0)
			res(i) = -res(i);
	}
	return res;
}
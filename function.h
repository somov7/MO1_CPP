#pragma once

#include "vector.h"

class Function {
	double (*fn)(double);
public:
	Function(): fn(nullptr) {}
	Function(double (*fn)(double)) : fn(fn) {}
	void setFunction(double (*fn)(double)) {
		this->fn = fn;
	}
	virtual double operator()(double x) {
		return fn(x);
	}
};

class VectorFunction : public Function {
	double (*fn_dir)(Vector);
	Vector dir, start;
public:
	VectorFunction() : fn_dir(nullptr) {}
	VectorFunction(double (*fn_dir)(Vector)) : fn_dir(fn_dir) {}
	VectorFunction(double (*fn_dir)(Vector), Vector start, Vector dir) : fn_dir(fn_dir), start(start), dir(dir) {}
	void setFunction(double (*fn_dir)(Vector)) {
		this->fn_dir = fn_dir;
	}
	void setStart(Vector start) {
		this->start = start;
	}
	void setDir(Vector dir) {
		this->dir = dir;
	}
	double operator()(Vector x) {
		return fn_dir(x);
	}
	double operator()(double t) override {
		return fn_dir(this->point(t));
	}
	Vector point(double t) {
		return start + t * dir;
	}
	Vector gradient(Vector point){
		int n = point.getSize();
		Vector grad(n);
		Vector x_p(n), x_n(n);
		double h = 1e-14;
		for (int i = 0; i < n; i++) {
			x_p = x_n = point;
			x_p(i) += h;
			x_n(i) -= h;
			grad(i) = ((*this)(x_p) - (*this)(x_n)) / (2 * h);
		}
		return grad;
	}
	Vector gradientNorm(Vector point) {
		Vector grad = gradient(point);
		grad /= grad.length();
		return grad;
	}
};
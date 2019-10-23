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
	virtual double operator ()(double x) {
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
	void setStart(Vector start){
		this->start = start;
	}
	void setDir(Vector dir){
		this->dir = dir;
	}
	double operator()(Vector x) {
		return fn_dir(x);
	}
	double operator()(double t) {
		return fn_dir(start + t * dir);
	}
};
#include <cmath>
#include "vector.h"
#include "function.h"
#include "minsearch.h"
#include "2dmin.h"

inline double min(double a, double b) {
	return a < b ? a : b;
}

Vector steepestDescent(VectorFunction& fn, Vector s, Vector eps_x, double eps_f, int &iter){
	bool accuracy = false;
	Vector x, x0;
	Vector dir, diff;
	double fx, fx0;
	double eps, lambda;
	iter = 0;
	x = s;
	fx = fn(x);
	while (!accuracy) {
		iter++;
 		x0 = x;
		fx0 = fx;
		fn.setStart(x0);
		dir = -fn.gradientNorm(x0);
		fn.setDir(dir);
		eps = fabs(eps_x(0) / dir(0));
		for (int i = 1; i < eps_x.getSize(); i++) {
			eps = min(eps, fabs(eps_x(i) / dir(i)));
		}
		lambda = minSearch(fn, eps);
		x = fn.point(lambda);
		fx = fn(x);
		diff = x - x0;
		accuracy = true;
		if (abs(diff) > eps_x || fabs(fx - fx0) > eps_f) {
			accuracy = false;
		}
	}
	return x;
}
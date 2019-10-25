#include <cmath>
#include "vector.h"
#include "function.h"
#include "minsearch.h"
#include "2dmin.h"

Vector steepestDescent(VectorFunction fn, Vector s, Vector eps_x, double eps_f, int &iter){
	bool accuracy = false;
	Vector x, x0;
	double fx, fx0;
	double eps = eps_x(0);
	iter = 0;
	x = s;
	fx = fn.invoke(x);
	while (!accuracy) {
		iter++;
		x0 = x;
		fx0 = fx;
		fn.setStart(x0);
		Vector dir = -fn.gradientNorm(x0);
		fn.setDir(dir);
		x = fn.point(minSearch(fn, eps));
		fx = fn.invoke(x);
		Vector diff = x - x0;
		accuracy = true;
		if (abs(diff) > eps_x || fabs(fx - fx0) > eps_f) {
			accuracy = false;
		}
	}
	return x;
}
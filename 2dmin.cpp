#include <cmath>
#include "vector.h"
#include "function.h"
#include "minsearch.h"
#include "2dmin.h"

int iter2;

inline double min(double a, double b) {
	return a < b ? a : b;
}

Vector steepestDescent(VectorFunction& fn, Vector s, Vector eps_x, double eps_f){
	bool accuracy = false;
	Vector x, x0;
	Vector dir;
	double fx, fx0;
	double eps, lambda = 1.0;
	x = s;
	fx = fn(x);

	func_cnt += 1;
	
	do {
 		x0 = x;
		fx0 = fx;
		fn.setStart(x0);
		dir = -fn.gradient(x0);
		if (dir.length() <= 1e-14) {
			break;
		}
		dir /= dir.length();
		fn.setDir(dir);
		eps = fabs(eps_x(0) / dir(0));
		for (int i = 1; i < eps_x.getSize(); i++) {
			eps = min(eps, fabs(eps_x(i) / dir(i)));
		}
		eps /= 2;
		lambda = minSearch(fn, eps);
		x = fn.point(lambda);
		fx = fn(x);
		
		iter2++;

	} while (!(abs(x - x0) < eps_x) && fx0 - fx >= eps_f);

	return x;
}
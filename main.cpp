#include <iostream>
#include <cmath>
#include "vector.h"
#include "minsearch.h"
#include "function.h"
#include "2dmin.h"

double fn(double x) {
	return x * x + 2 * x - 4;
}

double fnVec(Vector x) {
	return 100 * pow((x(1) - pow(x(0), 3)), 2) + pow(1 - x(0), 2);
}

int main() {
	
	double l, r, eps, ans;
	Function func(fn);
	int iter, func_cnt;
	/*
	cin >> l >> r >> eps;
	ans = dichotomy(func, l, r, eps, iter, func_cnt);
	cout << "Dichotomy: " << ans << " " << "; iterations: " << iter << "; function calculations: " << func_cnt << endl;
	ans = goldenSection(func, l, r, eps, iter, func_cnt);
	cout << "Golden section: " << ans << " " << "; iterations: " << iter << "; function calculations: " << func_cnt << endl;
	ans = fibonacci(func, l, r, eps, iter, func_cnt);
	cout << "Fibonacci: " << ans << " " << "; iterations: " << iter << "; function calculations: " << func_cnt << endl;
	cout << "Line minimum: " << minSearch(func, 1e-3) << endl;
	*/

	VectorFunction vecFunc(fnVec);
	Vector start, eps_x, vecAns;
	double eps_f = 1e-3;

	cin >> start;
	eps_x = Vector(start.getSize());
	for (int i = 0; i < eps_x.getSize(); i++) {
		eps_x(i) = 1e-3;
	}
	vecAns = steepestDescent(vecFunc, start, eps_x, eps_f, iter);
	cout << "Min: " << vecAns << "; iterations: " << iter << endl;
	return 0;
}
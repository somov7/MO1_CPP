#include <iostream>
#include "vector.h"
#include "minsearch.h"
#include "function.h"

double fn(double x) {
	return x * x + 2 * x - 4;
}

int main() {
	double l, r, eps, ans;
	cin >> l >> r >> eps;
	int iter, func_cnt;
	Function func(fn);
	ans = dichotomy(func, l, r, eps, iter, func_cnt);
	cout << "Dichotomy: " << ans << " " << "; iterations: " << iter << "; function calculations: " << func_cnt << endl;
	ans = goldenSection(func, l, r, eps, iter, func_cnt);
	cout << "Golden section: " << ans << " " << "; iterations: " << iter << "; function calculations: " << func_cnt << endl;
	ans = fibonacci(func, l, r, eps, iter, func_cnt);
	cout << "Fibonacci: " << ans << " " << "; iterations: " << iter << "; function calculations: " << func_cnt << endl;
	return 0;
}
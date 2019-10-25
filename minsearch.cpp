#include <cmath>
#include "function.h"
#include "minsearch.h"
#include "vector.h"

using namespace std;

double dichotomy(Function& fn, double l, double r, double eps, int& iter, int& func_cnt) {
	double delta = (eps / 2) * 0.99;
	iter = 0;
	func_cnt = 0;
	while (r - l > eps) {
		double a = (r + l) / 2 - delta;
		double b = (r + l) / 2 + delta;
		double fa = fn(a);
		double fb = fn(b);
		if (fa >= fb) {
			l = a;
		}
		if (fa <= fb) {
			r = b;
		}
		iter++;
		func_cnt += 2;
	}
	return (l + r) / 2;
}

double goldenSection(Function& fn, double l, double r, double eps, int& iter, int& func_cnt) {
	iter = 0;
	func_cnt = 2;
	double phi = (1 + sqrt(5.0)) * 0.5;
	double a = r - (r - l) / phi;
	double b = l + (r - l) / phi;
	double fa = fn(a);
	double fb = fn(b);
	while (r - l > eps) {
		if (fa > fb) {
			l = a;
			a = b;
			b = l + (r - l) / phi;
			fa = fb;
			fb = fn(b);
		}
		else {
			r = b;
			b = a;
			a = r - (r - l) / phi;
			fb = fa;
			fa = fn(a);
		}
		iter++;
		func_cnt++;
	}
	return (l + r) / 2;
}

double fibonacci(Function& fn, double l, double r, double eps, int& iter, int& func_cnt) {
	vector<long long> fib = { 1, 1, 2 };
	while (r - l > fib[fib.size() - 1] * eps) {
		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
	}
	reverse(fib.begin(), fib.end());
	iter = 0, func_cnt = 2;
	double a = l + (double(fib[2]) / fib[0]) * (r - l);
	double b = l + (double(fib[1]) / fib[0]) * (r - l);
	double fa = fn(a);
	double fb = fn(b);
	for (size_t i = 1; i < fib.size() - 2; i++) {
		if (fa > fb) {
			l = a;
			a = b;
			fa = fb;
			b = l + (double(fib[i + 1]) / fib[i]) * (r - l);
			fb = fn(b);
		}
		else {
			r = b;
			b = a;
			fb = fa;
			a = l + (double(fib[i + 2]) / fib[i]) * (r - l);
			fa = fn(a);
		}
		iter++;
		func_cnt++;
	}
	return (l + r) / 2;

}

void minSegment(Function& fn, double s, double &l, double &r, double delta) {
	double fs = fn(s);
	double f_next = fn(s + delta);
	double f_prev = fn(s - delta);
	double h;
	if (f_prev > fs) {
		if (f_next > fs){
			l = s - delta;
			r = s + delta;
			return;
		}
		h = delta;
	}
	else {
		h = -delta;
	}
	double x_prev = s;
	double x = s + h;
	double x_next = s + 2 * h;
	double fx = fn(x);
	f_next = fn(x_next);
	while (fx > f_next) {
		h *= 2;
		x_prev = x;
		x = x_next;
		x_next = x + h;
		fx = f_next;
		f_next = fn(x_next);
	}
	l = x_prev;
	r = x_next;
	if (l > r)
		swap(l, r);
}

double minSearch(Function& fn, double eps, double delta) {
	double l, r;
	minSegment(fn, 0.0, l, r, delta);
	return dichotomy(fn, l, r, eps);
}
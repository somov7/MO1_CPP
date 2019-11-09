#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "vector.h"
#include "minsearch.h"
#include "function.h"
#include "2dmin.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

Vector start, eps_x, vecAns, vec_min, vec_max, vec_step;
double eps_f;
int sz;

double fn(double x) {
	return x * x + 2 * x - 4;
}

double fnVec(Vector x) {
	return 100 * pow((x(1) - pow(x(0), 3)), 2) + pow(1 - x(0), 2);
}

Vector grad(Vector x) {
	Vector ans(2);
	ans(0) = 600 * (pow(x(0), 5)) - 600 * pow(x(0), 2) * x(1) + 2 * x(0) - 2;
	ans(1) = 200 * x(1) - 200 * pow(x(0), 3);
	return ans;
}

void output() {
	fout << "Iterations: " << iter << endl;
	fout << "Function evaluations: " << func_cnt << endl;
	for (int i = 0; i < iter; i++)
		fout << lborder[i] << '\t' << rborder[i] << '\t' << '\t' << '\t' << lpnt[i] << '\t' << rpnt[i] << '\t' << lfn[i] << '\t' << rfn[i] << '\t' << endl;
	fout << lborder[iter] << '\t' << rborder[iter] << endl << endl;
	
	iter = func_cnt = 0;
	lborder.clear();
	rborder.clear();
	lpnt.clear();
	rpnt.clear();
	lfn.clear();
	rfn.clear();
}

void output2() {
	VectorFunction vecFunc(fnVec);
	vecFunc.setGradient(grad);
	fout << defaultfloat;
	for (Vector cur = vec_min; cur <= vec_max; cur = next(cur, vec_min, vec_max, vec_step)){

		iter = func_cnt = 0;
		lborder.clear();
		rborder.clear();
		lpnt.clear();
		rpnt.clear();
		lfn.clear();
		rfn.clear();

		cout << defaultfloat << "(";
		for (int i = 0; i < cur.getSize() - 1; i++) {
			cout << cur(i) << "; ";
		}
		cout << cur(sz - 1) << ")\n";

		Vector ans = steepestDescent(vecFunc, cur, eps_x, eps_f);
		fout << defaultfloat << "(";
		for (int i = 0; i < cur.getSize() - 1; i++) {
			fout << cur(i) << "; ";
		}
		fout << cur(sz - 1) << ")\t";
		fout << fixed << "(";
		for (int i = 0; i < cur.getSize() - 1; i++) {
			fout << ans(i) << "; ";
		}
		fout << ans(sz - 1) << ")\t";
		fout << vecFunc(ans) << '\t' << iter2 << '\t' << func_cnt << '\n';



	}
}

int main() {
	double l, r, eps, ans;
	Function func(fn);

	fout << fixed << setprecision(9);

	fin >> l >> r >> eps;
	ans = dichotomy(func, l, r, eps);
	fout << "Dichotomy: " << ans <<  endl;
	output();
	ans = goldenSection(func, l, r, eps);
	fout << "Golden section: " << ans << endl;
	output();
	ans = fibonacci(func, l, r, eps);
	fout << "Fibonacci: " << ans << endl;
	output();
	fout << "Line minimum: " << minSearch(func, 1e-3) << endl;
	
	// 2 часть

	fin >> sz;
	start = Vector(sz);
	eps_x = Vector(sz);
	vec_min = Vector(sz);
	vec_max = Vector(sz);
	vec_step = Vector(sz);

	for (int i = 0; i < sz; i++)
		fin >> eps_x(i);
	fin >> eps_f;

	for (int i = 0; i < sz; i++)
		fin >> vec_min(i);
	for (int i = 0; i < sz; i++)
		fin >> vec_max(i);
	for (int i = 0; i < sz; i++)
		fin >> vec_step(i);

	output2();

	/*
	cin >> sz;
	eps_x = Vector(sz);
	start = Vector(sz);
	for (int i = 0; i < sz; i++)
		cin >> eps_x(i);
	cin >> eps_f;
	for (int i = 0; i < sz; i++)
		cin >> start(i);

	VectorFunction vecFunc(fnVec);
	vecFunc.setGradient(grad);

	vecAns = steepestDescent(vecFunc, start, eps_x, eps_f);
	cout << "Min: " << vecAns << "; iterations: " << iter2 << endl;
		*/
	return 0;
}
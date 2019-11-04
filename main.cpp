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

double fn(double x) {
	return x * x + 2 * x - 4;
}

double fnVec(Vector x) {
	return 100 * pow((x(1) - pow(x(0), 3)), 2) + pow(1 - x(0), 2);
}

void output() {
	fout << fixed << setprecision(6);
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

int main() {
	double l, r, eps, ans;
	Function func(fn);
	int iter, func_cnt;

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
	
	/*
	int size;
	VectorFunction vecFunc(fnVec);
	Vector start, eps_x, vecAns;
	double eps_f;

	fin >> size;
	start = Vector(size);
	eps_x = Vector(size);
	for (int i = 0; i < size; i++)
		fin >> start(i);
	for (int i = 0; i < size; i++)
		fin >> eps_x(i);
	fin >> eps_f;

	vecAns = steepestDescent(vecFunc, start, eps_x, eps_f, iter);
	cout << "Min: " << vecAns << "; iterations: " << iter << endl;
	*/
	return 0;
}
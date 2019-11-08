#pragma once

#include "function.h"

double dichotomy(Function& fn, double l, double r, double eps);
double goldenSection(Function& fn, double l, double r, double eps);
double fibonacci(Function& fn, double l, double r, double eps);
void minSegment(Function& fn, double s, double& l, double& r, double delta = 1e-3);
double minSearch(Function& fn, double eps, double delta = 1e-3);

//Вот эта штука считает итерации и всё такое

extern vector<double> lborder, rborder, lpnt, rpnt, lfn, rfn;
extern int iter, func_cnt;
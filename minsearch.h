#pragma once

#include "function.h"

static int dummy_iter = 0;
static int dummy_func_cnt = 0;

double dichotomy(Function fn, double l, double r, double eps, int& iter = dummy_iter, int& func_cnt = dummy_func_cnt);
double goldenSection(Function fn, double l, double r, double eps, int& iter = dummy_iter, int& func_cnt = dummy_func_cnt);
double fibonacci(Function fn, double l, double r, double eps, int& iter = dummy_iter, int& func_cnt = dummy_func_cnt);
void minSegment(Function fn, double s, double& l, double& r, double delta, int& iter = dummy_iter, int& func_cnt = dummy_func_cnt);


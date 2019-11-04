#pragma once

#include "vector.h"
#include "function.h"

static int dummy_iter_cnt;

double min(double a, double b);
Vector steepestDescent(VectorFunction& fn, Vector s, Vector eps_x, double eps_f);
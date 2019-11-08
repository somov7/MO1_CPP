#pragma once

#include "vector.h"
#include "function.h"

double min(double a, double b);
Vector steepestDescent(VectorFunction& fn, Vector s, Vector eps_x, double eps_f);

extern int iter2;
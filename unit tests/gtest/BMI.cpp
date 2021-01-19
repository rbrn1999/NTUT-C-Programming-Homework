#include "BMI.hpp"
#include <math.h>
#include <assert.h>
#include <cstdlib>
#include <gtest/gtest.h>

double computeBMI(int kg, int height) {
    double BMI = 0.0, M = height/100.0;
    if (kg<=0 || height<=0)
        return 0;
    BMI = round(100*kg/(M*M))/100;
    if (BMI <18.5)
        return -1;
    if (BMI >24)
        return -2;
    return BMI;
}

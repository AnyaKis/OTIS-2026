#pragma once
#include <cmath>
#include "Model.h"

class model2_1 : public Model{
    private:
        double a;
        double b;
        double c;
        double d;

        double y = 0;
        double y_prev = 0;
        double u_prev = 0;
    public:
        model2_1(double a, double b, double uMin, double uMax)
        : a(a), b(b), c(c), d(d)
        {
        }
        double nextStep(double u) override{
            double y_next = (a * y) - (b * y_prev * y_prev) + (c * u) + (d * std::sin(u_prev));
            y_prev = y;
            y = y_next;
            u_prev = u;  
            return y_next;
        }
        void reset() override{
            y = 0;
            y_prev = 0;
            u_prev = 0;
        }
};
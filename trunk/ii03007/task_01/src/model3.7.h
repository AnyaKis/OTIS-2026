#pragma once
#include <cmath>
#include "Model.h"

class model3_7 : public Model {
    private:
        double a;
        double b;
        double h; 
        double y = 0;

    public:
    model3_7(double a, double b, double h)
    : a(a), b(b), h(h)
    {
    }

    double nextStep(double u) override {
        double f = -std::exp(a) * y + b * u;
        y = y + h * f;
        return y;
    }

    void reset() override {
        y = 0;
    }
};

#include "CurvesAPI/include/CurvesAPI.h"
#include <iostream>
#include <vector>
#include <omp.h>
#include <memory>
#include <random>

int main() {
    //Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel
    //TBB library).


    constexpr size_t SIZE = 1000u;
    std::vector<std::shared_ptr<ICurve>> curves;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> curve_params(1, 153);

    for (size_t i = 0; i < SIZE; ++i) {
        curves.push_back(std::make_shared<Circle>(curve_params(gen)));
    }

    double sumOfRadii = 0.0f;

#pragma omp parallel for // I think Folly, Boost.ThreadPool n QThread better than OMP ^-^
    for (const auto i: curves) {
        sumOfRadii += i->getRadius();
    }

    std::cout << "Sum of radii = " << sumOfRadii << '\n';

    return 0;
}

#include "Curves.h"

#include <algorithm>
#include <memory>
#include <random>
#include <ranges>
#include <vector>

int main() {
    //2nd task: Populate a container (e.g. vector or list) of objects of these types created in random manner with
    //          random parameters.
    std::vector<std::shared_ptr<ICurve>> list_of_curves;
    list_of_curves.resize(20); //any size
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::uint16_t> curve_type(1, 3); //digit's for building objects
    std::uniform_real_distribution<double> curve_params(1, 10872); //any params ^-^

    for (const auto& curve : list_of_curves) {
        std::uint16_t type = curve_type(gen);
        if (type == 1) {
            list_of_curves.emplace_back(std::make_shared<Circle>(curve_params(gen)));
        } else if (type == 2) {
            list_of_curves.emplace_back(std::make_shared<Ellipse>(curve_params(gen), curve_params(gen)));
        } else if (type == 3) {
            list_of_curves.emplace_back(std::make_shared<Helix>(curve_params(gen), curve_params(gen)));
        }
    }


    //3rd task: Print coordinates of points and derivatives of all curves in the container at t=PI/4.
    constexpr double PI = 3.14159265358979323846;
    constexpr double t = PI / 4;

    for (const auto& curve : list_of_curves) {
        if (auto ptr = std::dynamic_pointer_cast<Circle>(curve)) {
            std::cout << "Point and derivative for Circle - " << ptr->getPoint(t) << " " << ptr->getDerivative(t) << "\n";
        } else if (auto ptr = std::dynamic_pointer_cast<Ellipse>(curve)) {
            std::cout << "Point and derivative for Ellipse - " << ptr->getPoint(t) << " " << ptr->getDerivative(t) << "\n";
        } else if (auto ptr = std::dynamic_pointer_cast<Helix>(curve)) {
            std::cout << "Point and derivative for Helix - " << ptr->getPoint(t) << " " << ptr->getDerivative(t) << "\n";
        }
    }


    //4th task: Populate a second container that would contain only circles from the first container. Make sure the
    //          second container shares(i.e. not clones) circles of the first one, e.g.via pointers.
    std::vector<std::shared_ptr<ICurve>> circle_curves;

    circle_curves.reserve(list_of_curves.size() / 2);
    for (const auto& curve : list_of_curves) {
        if (std::dynamic_pointer_cast<Circle>(curve)) {
            circle_curves.push_back(curve);
        }
    }


    //5th task: Sort the second container in the ascending order of circles’ radii. That is, the first element has the
    //          smallest radius, the last - the greatest.
    std::ranges::sort(circle_curves, [](const auto& lhs, const auto& rhs) {
        return lhs->getRadius() < rhs->getRadius();
        });


    //6th task: Compute the total sum of radii of all curves in the second container
    double sum_of_radius = 0.0f;

    for (const auto& circle : circle_curves) {
        sum_of_radius += circle->getRadius();
    }
}

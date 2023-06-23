#ifndef CURVES_CPP
#define CURVES_CPP
#include <compare>
#include <iostream>
#include <math.h>

class Point3D {
public:

    explicit constexpr Point3D(double x, double y, double z) noexcept : X{ x }, Y{ y }, Z{ z } {}

    constexpr Point3D(const Point3D& lhs) noexcept = default;

    constexpr Point3D(Point3D&& rhs) noexcept = default;

    constexpr Point3D& operator=(const Point3D& lhs) noexcept = default;

    constexpr Point3D& operator=(Point3D&& rhs) noexcept = default;

    constexpr auto operator<=>(const Point3D& lhs) const noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, const Point3D& point);

private:
    double X = 0;
    double Y = 0;
    double Z = 0;
};

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
    os << point.X << " " << point.Y << " " << point.Z;
    return os;
}

class Vector3D {
public:

    explicit constexpr Vector3D(double x, double y, double z) noexcept : X{ x }, Y{ y }, Z{ z } {}

    constexpr Vector3D(const Vector3D& lhs) noexcept = default;

    constexpr Vector3D(Vector3D&& rhs) noexcept = default;

    constexpr Vector3D& operator=(const Vector3D& lhs) noexcept = default;

    constexpr Vector3D& operator=(Vector3D&& rhs) noexcept = default;

    constexpr auto operator<=>(const Vector3D& lhs) const noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& point);

private:
    double X = 0;
    double Y = 0;
    double Z = 0;
};

std::ostream& operator<<(std::ostream& os, const Vector3D& point) {
    os << point.X << " " << point.Y << " " << point.Z;
    return os;
}

class ICurve {
public:
    virtual Point3D getPoint(double t) const noexcept = 0;
    virtual Vector3D getDerivative(double t) const noexcept = 0;
    virtual double getRadiusX() const noexcept = 0;
    virtual double getRadiusY() const noexcept = 0;
    virtual ~ICurve() = default;
};

class Circle final : public ICurve {
public:

    explicit Circle(double _radius) noexcept : radius{ _radius } {}

    Circle(const Circle& lhs) noexcept = default;

    Circle(Circle&& rhs) noexcept = default;

    Circle& operator=(const Circle& lhs) noexcept = default;

    Circle& operator=(Circle&& rhs) noexcept = default;

    Point3D getPoint(double t) const noexcept override final {
        return Point3D{ radius * std::cos(t), radius * std::sin(t), 0.0f };
    }
    Vector3D getDerivative(double t) const noexcept override final {
        return Vector3D{ -radius * std::sin(t), radius * std::cos(t), 0.0f };
    }

    double getRadiusX() const noexcept override final {
        return radius;
    }

    double getRadiusY() const noexcept override final {
        return radius;
    }

    ~Circle() override = default;

private:
    double radius = 0;
};

class Ellipse final : public ICurve {
public:

    explicit Ellipse(double radius_x, double radius_y) noexcept : x_radius{ radius_x }, y_radius{ radius_y } {}

    Ellipse(const Ellipse& lhs) noexcept = default;

    Ellipse(Ellipse&& rhs) noexcept = default;

    Ellipse& operator=(const Ellipse& lhs) noexcept = default;

    Ellipse& operator=(Ellipse&& rhs) noexcept = default;

    Point3D getPoint(double t) const noexcept override final {
        return Point3D{ x_radius * std::cos(t), y_radius * std::sin(t), 0.0f };
    }

    Vector3D getDerivative(double t) const noexcept override final {
        return Vector3D{ -x_radius * std::sin(t), y_radius * std::cos(t), 0.0f };
    }

    double getRadiusX() const noexcept override final {
        return x_radius;
    }

    double getRadiusY() const noexcept override final {
        return y_radius;
    }

    ~Ellipse() override = default;

private:
    double x_radius = 0;
    double y_radius = 0;

};

class Helix final : public ICurve {
public:

    explicit Helix(double _radius, double _step) noexcept : radius{ _radius }, step{ _step } {}

    Helix(const Helix& lhs) noexcept = default;

    Helix(Helix&& rhs) noexcept = default;

    Helix& operator=(const Helix& lhs) noexcept = default;

    Helix& operator=(Helix&& rhs) noexcept = default;

    Point3D getPoint(double t) const noexcept override final {
        return Point3D{ radius * std::cos(t), radius * std::sin(t), step * t };
    }

    Vector3D getDerivative(double t) const noexcept override final {
        return Vector3D{ -radius * std::sin(t), radius * std::cos(t), step };
    }

    double getRadiusX() const noexcept override final {
        return radius;
    }

    double getRadiusY() const noexcept override final {
        return radius;
    }

    ~Helix() override = default;

private:
    double radius = 0;
    double step = 0;
};
#endif

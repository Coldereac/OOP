#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Figure {
public:
    [[nodiscard]] virtual double getPerimeter() const = 0;

    [[nodiscard]] virtual double getArea() const = 0;

    virtual ~Figure() = default;

    virtual void display() const = 0;
};

class Triangle : public Figure {
    double a, b, c;

public:
    explicit Triangle(double side1 = 0, double side2 = 0, double side3 = 0) {
        if (side1 + side2 <= side3 ||
            side1 + side3 <= side2 ||
            side2 + side3 <= side1) {
            throw invalid_argument("Invalid sides for a triangle.");
        }
        this->a = side1;
        this->b = side2;
        this->c = side3;
    }

    [[nodiscard]] double getPerimeter() const override {
        return a + b + c;
    }

    [[nodiscard]] double getArea() const override {
        double s = getPerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void display() const override {
        cout << "Triangle: " << a << " " << b << " " << c << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
        cout << "Area: " << getArea() << endl;
    }

    ~Triangle() override = default;
};

class Rectangle : public Figure {
    double a, b;

public:
    explicit Rectangle(double side1 = 0, double side2 = 0) {
        this->a = side1;
        this->b = side2;
    }

    ~Rectangle() override = default;

    [[nodiscard]] double getPerimeter() const override {
        return a + b;
    }

    [[nodiscard]] double getArea() const override {
        return a * b;
    }

    void display() const override {
        cout << "Rectangle: " << a << " " << b << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
        cout << "Area: " << getArea() << endl;
    }
};

class Circle : public Figure {
    double radius;

public:
    ~Circle() override = default;

    explicit Circle(double radius = 0): radius(radius) {
    }

    [[nodiscard]] double getPerimeter() const override {
        return 2 * M_PI * radius;
    }

    [[nodiscard]] double getArea() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle: " << radius << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
        cout << "Area: " << getArea() << endl;
    }
};


int main() {
    Figure *figures[] = {new Circle(20), new Triangle(25, 30, 20), new Rectangle(10, 20)};
    for (auto figure: figures) {
        figure->display();
        cout << endl;
    }
}

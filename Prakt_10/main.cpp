#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Figure { //класс краще робити абстрактним, бо він сам по собі не представляє якусь конкретну фігуру.
public:
    [[nodiscard]] virtual double getPerimeter() const {
        return 0;
    }

    [[nodiscard]] virtual double getArea() const {
        return 0;
    }

    virtual void setSide(int numberOfSide, double side) {
    }

    virtual ~Figure() = default;

    virtual void display() const { cout << "Figure without fields" << endl; }
};

class Triangle : public Figure {
    double a, b, c;

public:
    explicit Triangle(double side1 = 1, double side2 = 1, double side3 = 1) {
        if (side1 + side2 <= side3 ||
            side1 + side3 <= side2 ||
            side2 + side3 <= side1) {
            throw invalid_argument("Invalid sides for a triangle. Triangle with such sides can't exist");
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

    void setSide(int numberOfSide, double side) override {
        if (numberOfSide <= 0 || numberOfSide > 3) {
            throw invalid_argument("Invalid side number. Must be from 1 to 3");
        }
        if (side <= 0) {
            throw invalid_argument("Invalid side size. Equal or less to 0");
        }
        switch (numberOfSide) {
            case 1:
                if (side + b <= c || side + c <= b)
                    throw invalid_argument(
                        "Invalid side size. Triangle with such side can't exist");
                this->a = side;
                break;
            case 2:
                if (side + a <= c || side + c <= a)
                    throw invalid_argument(
                        "Invalid side size. Triangle with such side can't exist");
                this->b = side;
                break;
            case 3:
                if (side + b <= a || side + a <= b)
                    throw invalid_argument(
                        "Invalid side size. Triangle with such side can't exist");
                this->c = side;
                break;
        }
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
    explicit Rectangle(double side1 = 1, double side2 = 1) {
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

    void setSide(int numberOfSide, double side) override {
        if (numberOfSide <= 0 || numberOfSide > 2) {
            throw invalid_argument("Invalid side number. Must be from 1 to 2");
        }
        if (side <= 0) {
            throw invalid_argument("Invalid side size. Less or equals to 0");
        }
        switch (numberOfSide) {
            case 1: this->a = side;
                break;
            case 2: this->b = side;
                break;
        }
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

    explicit Circle(double radius = 1): radius(radius) {
    }

    [[nodiscard]] double getPerimeter() const override {
        return 2 * M_PI * radius;
    }

    [[nodiscard]] double getArea() const override {
        return M_PI * radius * radius;
    }

    void setRadius(double radius) {
        if (radius <= 0) {
            throw invalid_argument("Invalid side size. Radius is less or equals to 0");
        }
        this->radius = radius;
    }

    void display() const override {
        cout << "Circle: " << radius << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
        cout << "Area: " << getArea() << endl;
    }
};


int main() {
    Figure *figures[] = {new Circle(20), new Triangle(25, 30, 20), new Rectangle(10, 20)};
    cout << "Perimeters and Areas of figures before changing their fields: " << endl;
    for (auto figure: figures) {
        figure->display();
        cout << endl;
    }

    cout << "Examples of throwing and catching exceptions: " << endl;
    try {
        ((Circle *) figures[0])->setRadius(12.389);
        ((Circle *) figures[0])->setRadius(-3);
    }catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    try {
        figures[1]->setSide(2, 25.3);
        figures[1]->setSide(2, 5); //Variant with throwing exception
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    figures[2]->setSide(1, 10);
    figures[2]->setSide(2, 50);
    cout << "Perimeters and Areas of figures after changing their fields: " << endl;
    for (auto figure: figures) {
        figure->display();
        cout << endl;
    }
}

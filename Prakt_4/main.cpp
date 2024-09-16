#include <iostream>

using namespace std;

class Rectangle {
private:
    double height;
    double width;
public:
    Rectangle() {
        this->height = 15;
        this->width = 30;
    }

    Rectangle(double high, double width) {
        this->height = high;
        this->width = width;
    }

    void setHeight(double high) {
        if (high > 0) this->height = high;
    }

    void setWidth(double width) {
        if (width > 0) this->width = width;
    }

    double getHeight() {
        return this->height;
    }

    double getWidth() {
        return this->width;
    }

    double getSquare() {
        return (this->height * this->width);
    }


    double getPerimeter() {
        return (this->height + this->width) * 2;
    }
};

int main() {
    Rectangle rect = Rectangle();
    cout << rect.getHeight() << " " << rect.getWidth() << " " << rect.getPerimeter() << " " <<
         rect.getSquare() << endl;
    rect.setHeight(34.5);
    rect.setWidth(20.4);
    cout << rect.getHeight() << " " << rect.getWidth() << " " << rect.getPerimeter() << " " <<
         rect.getSquare() << endl;
    return 0;
}
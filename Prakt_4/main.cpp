#include <iostream>
using namespace std;

class Rectangle {
    double height;
    double width;

public:
    Rectangle() {
        this->height = 20;
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

    double getHeight() const {
        return this->height;
    }

    double getWidth() const {
        return this->width;
    }

    double getSquare() const {
        return (this->height * this->width);
    }


    double getPerimeter() const {
        return (this->height + this->width) * 2;
    }

    void display() const {
        cout << "Height: " << getHeight() << " Width:  " << getWidth() << " Perimeter:  " << getPerimeter() << " Square:  " <<
                getSquare() << endl;
    }
};

int main() {
    Rectangle rect = Rectangle();
    rect.display();
    rect.setHeight(34.5);
    rect.setWidth(20.4);
    rect.display();

    Rectangle arr[3];
    arr[0] = rect;
    arr[1] = Rectangle();
    arr[2] = Rectangle();
    arr[2].setHeight(34.5);
    arr[1].setWidth(67.46);
    for (int i = 0; i < 3; i++) {
        arr[i].display();
    }


    Rectangle *rectPos = new Rectangle(3.0, 6.0);
    rectPos->display();
    rectPos->setHeight(34.5);
    rectPos->setWidth(20.4);
    rectPos->display();
    delete rectPos;

    return 0;
}

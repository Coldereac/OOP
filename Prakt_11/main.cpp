#include <iostream>

class Rectangle {
protected:
    int x, y;
    int width, height;

public:
    explicit Rectangle(int x = 0, int y = 0, int width = 1, int height = 1)
        : x(x), y(y), width(width), height(height) {
    }

    [[nodiscard]] int getArea() const {
        return width * height;
    }

    [[nodiscard]] int getWidth() const {
        return width;
    }

    [[nodiscard]] int getHeight() const {
        return height;
    }

    void moveTo(int newX, int newY) {
        x = newX;
        y = newY;
    }

    void printPosition() const {
        std::cout << "Position: (" << x << ", " << y << ")\n";
    }
};

class Window1 : private Rectangle {
public:
    Window1(int x, int y, int width, int height)
        : Rectangle(x, y, width, height) {
    }

    void moveTo(int newX, int newY) {
        Rectangle::moveTo(newX, newY);
    }

    [[nodiscard]] int getArea() const {
        return Rectangle::getArea();
    }

    void printPosition() const {
        Rectangle::printPosition();
    }

    [[nodiscard]] int getWidth() const {
        return Rectangle::getWidth();
    }

    [[nodiscard]] int getHeight() const {
        return Rectangle::getHeight();
    }
};

class Window2 {
    Rectangle rectangle;

public:
    Window2(int x, int y, int width, int height)
        : rectangle(x, y, width, height) {
    }

    void moveTo(int newX, int newY) {
        rectangle.moveTo(newX, newY);
    }

    [[nodiscard]] int area() const {
        return rectangle.getArea();
    }

    void printPosition() const {
        rectangle.printPosition();
    }

    [[nodiscard]] int getWidth() const {
        return rectangle.getWidth();
    }

    [[nodiscard]] int getHeight() const {
        return rectangle.getHeight();
    }
};

int main() {
    Window1 win1(0, 0, 5, 10);
    Window2 win2(0, 0, 3, 6);

    std::cout << "Window1:\n";
    win1.printPosition();
    std::cout << "Area: " << win1.getArea() << "\n";
    win1.moveTo(10, 10);
    win1.printPosition();

    std::cout << "\nWindow2:\n";
    win2.printPosition();
    std::cout << "Area: " << win2.area() << "\n";
    win2.moveTo(15, 15);
    win2.printPosition();

    return 0;
}

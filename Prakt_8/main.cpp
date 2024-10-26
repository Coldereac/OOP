#include <iostream>
using namespace std;

class Point {
protected:
    int x;
    int y;

public:
    virtual ~Point() = default;

    Point(int x = 0, int y = 0) : x(x), y(y) {
    }

    virtual int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    virtual int hash() const {
        return x + y;
    }

    virtual void display() const {
        cout << "X: " << getX() << ", Y: " << getY() << endl;
    }
};

class PointWithMessage : public Point {
    string message;

public:
    PointWithMessage(int x, int y, const char *str): Point(x, y), message(str) {
    }

    string getMessage() const {
        return message;
    }

    int getX() const override {
        return x - message.length();
    }

    void display() const override {
        Point::display();
        cout << "Message: " << message << endl;
    }

    int hash() const override {
        return getX() * 5 + getY() * 10 + message.length() * 2;
    }

    ~PointWithMessage() override = default;
};

int main() {
    Point *pm = new PointWithMessage(20, 30, "Hello, World");
    cout << ((PointWithMessage *)pm)->getMessage();
    delete pm;
    return 0;
}

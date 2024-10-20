#include <iostream>
using namespace std;

class Point {
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

    friend class PointWithMessage;
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
    cout << "Poińt: " << endl;
    Point *pml = new Point(1, 2);
    pml->display();
    cout << "Hash in Point: " << pml->hash() << endl;

    cout << endl << "Point with message early inheritance:" << endl;
    auto *pm = new PointWithMessage(20, 30, "Hello, World");
    pm->display();
    cout << "Hash in Point with Message: " << pm->hash() << endl;

    delete pml;
    cout << endl << "Point with message late inheritance:" << endl;
    pml = new PointWithMessage(40, 20, "Goodbye, World");

    pml->display();
    cout << "Hash in Point with Message: " << pml->hash() << endl;

    delete pml;
    cout << endl << "Point with message late inheritance one more time:" << endl;
    pml = pm;
    pml->display();
    cout << "Hash in Point with Message: " << pml->hash() << endl;
    delete pm;

    return 0;
}

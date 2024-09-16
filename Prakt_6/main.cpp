#include <iostream>
#include <cmath>

using namespace std;

class Vector {
private:
    int size;
    double *coordinates;

public:
    Vector() {
        this->size = 1;
        this->coordinates = new double[this->size];
        this->coordinates[0] = 0.0;
    }

    Vector(int size) : size(size) {
        this->coordinates = new double[this->size];
        for (int i = 0; i < this->size; i++) {
            this->coordinates[i] = 0.0;
        }
    }

    Vector(Vector &copy) : size(copy.size) {
        this->coordinates = new double[this->size];
        for (int i = 0; i < this->size; i++) {
            this->coordinates[i] = copy.coordinates[i];
        }
    }

    int getSize() {
        return this->size;
    }

    double *getCoords() {
        return this->coordinates;
    }

    void setCoords(int i, double value) {
        this->coordinates[i] = value;
    }

    void output() {
        cout << "Size: " << size << " Coordinates: ";
        for (int i = 0; i < size; i++) {
            cout << coordinates[i] << " ";
        }
        cout << "Length: " << calculateLength() << endl;
    }


    ~Vector() {
        delete[] coordinates;
    }

    double calculateLength() {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += pow(coordinates[i], 2);
        }
        return sqrt(sum);
    }

};

double calculateLength2(Vector &vector) {
    double sum = 0.0;
    for (int i = 0; i < vector.getSize(); i++) {
        sum += pow(vector.getCoords()[i], 2);
    }
    return sqrt(sum);
}

int main() {
    cout << endl << "Object Vector: " << endl;
    Vector vect = Vector(3);
    vect.setCoords(0, 1.4);
    vect.setCoords(1, 5.7);
    vect.setCoords(2, -31.4);
    vect.output();
    cout << "External length calculation: " << calculateLength2(vect) << endl;

    Vector arr[] = {Vector(2), Vector(3), Vector(1)};
    arr[0].setCoords(0, 3.76);
    arr[0].setCoords(1, 8.52);
    arr[1].setCoords(0, 54);
    arr[1].setCoords(1, -3.5);
    arr[1].setCoords(2, 7.54);
    arr[2].setCoords(0, 3);
    cout << endl << "Array of vectors: " << endl;
    for (int i = 0; i < 3; i++) {
        arr[i].output();
        cout << "External length calculation: " << calculateLength2(vect) << endl;
    }

    cout << endl << "Pointer to vector: " << endl;
    Vector *vectPos = new Vector(3);
    vectPos->setCoords(0, 3.1);
    vectPos->setCoords(1, -9.1);
    vectPos->setCoords(2, 5.1);
    vectPos->output();
    cout << "External length calculation: " << calculateLength2(*vectPos) << endl;
    delete vectPos;

    cout << endl << "Example of copying: " << endl;
    Vector copy = Vector(vect);
    copy.output();
    cout << "External length calculation: " << calculateLength2(copy) << endl;
    return 0;
}
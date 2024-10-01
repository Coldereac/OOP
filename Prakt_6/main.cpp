#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>


using namespace std;

class VectorMath {
    int size;
    vector<double> coordinates;

public:
    VectorMath() {
        this->size = 1;
        this->coordinates.reserve(this->size);
        this->coordinates[0] = 0;
    }

    VectorMath(int size) : size(size), coordinates(size) {
        fill(coordinates.begin(), coordinates.end(), 0);
    }

    VectorMath(VectorMath &copyFrom) : size(copyFrom.size), coordinates(copyFrom.coordinates) {
    }

    ~VectorMath() = default;

    int getSize() const {
        return this->size;
    }

    void setSize(int size) {
        this->size = size;
        this->coordinates.reserve(this->size);
    }

    const vector<double> &getCoords() const {
        return this->coordinates;
    }

    void setCoords(int i, double value) {
        if (i >= 0 && i < this->size) {
            this->coordinates[i] = value;
        }
    }

    void output() const {
        cout << "Size: " << size << "\n Coordinates: ";
        for (int i = 0; i < size; i++) {
            cout << coordinates[i] << " ";
        }
        cout << "Length of Vector: " << calculateLength() << endl;
    }


    double calculateLength() const {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += pow(coordinates[i], 2);
        }
        return sqrt(sum);
    }
};

double calculateLengthOutsideClass(VectorMath &vector) {
    double sum = 0.0;
    for (int i = 0; i < vector.getSize(); i++) {
        sum += pow(vector.getCoords()[i], 2);
    }
    return sqrt(sum);

    //or just use vector.calculateLength()
}

int main() {
    cout << fixed << setprecision(2);

    //Object Vector
    VectorMath vectorObject = VectorMath(2);
    cout << endl << "Object Vector: " << endl;
    cout << "Vector just after creation: " << endl;
    vectorObject.output();
    vectorObject.setCoords(0, 5.4);
    vectorObject.setCoords(1, 20.9);
    cout << "Vector with setted coordinates: " << endl;
    vectorObject.output();
    cout << "External length calculation: " << calculateLengthOutsideClass(vectorObject) << endl;

    //Copying
    VectorMath copyExample = VectorMath(vectorObject);
    cout << endl << "Example of copying: " << endl;
    copyExample.output();
    cout << "External length calculation: " << calculateLengthOutsideClass(copyExample) << endl;


    //Pointer
    VectorMath *starVector = new VectorMath(3);
    starVector->setCoords(0, 3.1);
    starVector->setCoords(1, -9.1);
    starVector->setCoords(2, 5.1);
    cout << endl << "Pointer to new vector: " << endl;
    starVector->output();
    cout << "External length calculation: " << calculateLengthOutsideClass(*starVector) << endl;
    delete starVector;
    cout << endl << "Pointer to old vector: " << endl;
    starVector = &vectorObject;
    starVector->output();
    cout << "External length calculation: " << calculateLengthOutsideClass(*starVector) << endl;

    //Array of Vectors
    vector<VectorMath> vectors(4);
    vectors[0].setSize(3);
    vectors[0].setCoords(0, 5.2);
    vectors[0].setCoords(1, 9);
    vectors[0].setCoords(2, 44);

    vectors[1].setSize(2);
    vectors[1].setCoords(0, 999);
    vectors[1].setCoords(1, -1);

    vectors[2].setSize(4);
    vectors[2].setCoords(0, -20);
    vectors[2].setCoords(1, 5);
    vectors[2].setCoords(2, 99);
    vectors[2].setCoords(3, 44);

    vectors[3].setCoords(0, 999);
    cout << endl << "Array of vectors: " << endl;
    for (auto &vector: vectors) {
        vector.output();
        cout << "External length calculation: " << calculateLengthOutsideClass(vector) << endl;
    }

    return 0;
}

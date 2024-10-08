#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>


using namespace std;

class VectorMath {
    vector<double> coordinates;

public:
    VectorMath() {
        this->coordinates.resize(1);
        this->coordinates[0] = 0;
    }

    VectorMath(int size) {
        coordinates.resize(size);
        fill(coordinates.begin(), coordinates.end(), 1);
    }

    VectorMath(VectorMath &copyFrom): coordinates(copyFrom.coordinates) {
    }

    ~VectorMath() = default;

    void setSize(int size) {
        this->coordinates.resize(size);
    }

    const vector<double> &getCoords() const {
        return this->coordinates;
    }

    void setCoord(int i, double value) {
        if (i >= 0 && i < coordinates.capacity()) {
            this->coordinates[i] = value;
        }
    }

    void setCoords(const vector<double> &coordinates) {
        this->coordinates = coordinates;
    }

    void output() const {
        cout << "Size: " << coordinates.size() << "\n Coordinates: ";
        for (double coordinate: coordinates) {
            cout << coordinate << " ";
        }
        cout << "Length of Vector: " << calculateLength() << endl;
    }


    double calculateLength() const {
        double sum = 0.0;
        int size = coordinates.size();
        for (int i = 0; i < size; i++) {
            sum += pow(coordinates[i], 2);
        }
        return sqrt(sum);
    }
};

double calculateLengthOutsideClass(VectorMath &vector) {
    double sum = 0.0;
    int size = vector.getCoords().size();
    for (int i = 0; i < size; i++) {
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
    vectorObject.setCoord(0, 5.4);
    vectorObject.setCoord(1, 20.9);
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
    starVector->setCoords(vector<double>{1.4, 2.9, -3});
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
    vectors[0].setCoords(vector<double>{20, 30, -20});

    vectors[1].setCoords(vector<double>{10, -5});

    vectors[2].setCoords(vector<double>{999, -9999, 0, 294.124});

    vectors[3].setCoord(0, 999);
    cout << endl << "Array of vectors: " << endl;
    for (auto &vector: vectors) {
        vector.output();
        cout << "External length calculation: " << calculateLengthOutsideClass(vector) << endl;
    }

    return 0;
}

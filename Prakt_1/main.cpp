#include <iomanip>
#include <iostream>
using namespace std;
//Test
int main() {
    unsigned int n, m;
    double sum = 0.0;
    int counter = 0;

    // Просим користувача ввести кількість чисел в масиві (N), значення K та L.
    cout << "Submit an amount of numbers in the array(NxM)" << endl;
    cin >> n >> m;

    // Створення масиву на розмірність N для збереження чисел.
    int **arr = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 101;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
    }

    cout << endl;


    // Обчислення суми чисел, які не знаходяться в інтервалі [K, L].
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            sum += arr[i][j];
            counter++;
        }
    }

    // Обчислення середнього значення для відібраних чисел.
    sum /= counter;

    // Виведення середнього значення.
    cout << setprecision(3) << sum << endl;

    delete [] arr;

    // Повернення 0, що вказує на успішне завершення програми.
    return 0;
}

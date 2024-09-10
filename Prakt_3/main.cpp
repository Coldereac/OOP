/*
*У селі Іванівка більшість
мешканців мають прізвище Іванов. При записі на курси трактористів для кожного
вступника зберігається прізвище, початковий рік навчання (за замовчуванням –
перший) та середній бал атестату (float) (у
більшості – 4). Використовуючи перевантаження функцій та параметри за
замовчуванням, реалізувати мінімальну кількість функцій для комфортного
введення інформації про вступників (при виклику функцій задавати лише значення
параметрів, які відрізняються від замовчуваних).
 */

#include <iostream>
#include <string>
using namespace std;

struct Participant {
    string fio;
    int year;
    float avgScore;
};

void init(Participant &p, string fio = "Ivanov", int year = 1, float avgScore = 4) { // 1
    p.fio = fio;
    p.year = year;
    p.avgScore = avgScore;
}

void init(Participant &p, float avgScore, string fio = "Ivanov") { // 2
    p.fio = fio;
    p.year = 1;
    p.avgScore = avgScore;
}

void init(Participant &p, int year, float avgScore = 4) { // 3
    p.fio = "Ivanov";
    p.year = year;
    p.avgScore = avgScore;
}

void displayParticipant(const Participant &p) {
    cout << "Прізвище: " << p.fio << endl;
    cout << "Рік навчання: " << p.year << endl;
    cout << "Середній бал атестату: " << p.avgScore << endl;
}

int main() {
    Participant participant;

    init(participant); // 1 -
    displayParticipant(participant);
    cout << endl;

    init(participant, "Petrov"); // 1 fio
    displayParticipant(participant);
    cout << endl;

    init(participant, 3); // 3 year
    displayParticipant(participant);
    cout << endl;

    init(participant, 5.0f); // 2 avgScore
    displayParticipant(participant);
    cout << endl;

    init(participant, "Sidorov", 2); // 1 fio, year
    displayParticipant(participant);
    cout << endl;

    init(participant, 4.7f, "Nishinov"); // 2 avgScore, fio
    displayParticipant(participant);
    cout << endl;

    init(participant, 2, 4.5f); // 3 year, avgScore
    displayParticipant(participant);
    cout << endl;

    init(participant, "Kuznetsov", 3, 4.8f); // 1 fio, year, avgScore
    displayParticipant(participant);
    cout << endl;

    return 0;
}

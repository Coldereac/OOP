//
// Created by Malinka on 9/14/2024.
//

#ifndef OOP_TEAMACHINE_H
#define OOP_TEAMACHINE_H
/*
    Чайний автомат для особистого користування.
    Автомат має набір передвстановлених рецептів для приготування чаю.
    Користувач може переглядати рецепти, готувати чай за ними, перевіряти
    залишки сировини (чай, цукор тощо), а також стежити за наявністю інгредієнтів.
*/

enum MEASURMENT_TYPE{ML, GRAMS};

struct Ingredient {
    const char* name;               // Назва інгредієнта
    double quantity;                // Кількість інгредієнта (в грамах, мілілітрах тощо)
    double threshold;               // Поріг, при якому інгредієнт вважається закінченим
    MEASURMENT_TYPE measurmentType; // Одиниці, в яких вимірюється кількість інгрідієнта
};

struct Recipe {
    const char* name;          // Назва рецепта чаю
    Ingredient *ingredients;   // Масив інгрідієнтів
    int brewTime;              // Час заварювання (в секундах)
};

struct TeaMachine {
    Recipe* recipes;           // Массив рецептів
    int recipeCount;           // Кількість доступних рецептів
    Ingredient tea;            // Запаси чаю
    Ingredient sugar;          // Запаси цукру
    Ingredient water;          // Запаси води
    Ingredient milk;           // Запаси молока (опціонально)
};

// Функції для роботи з чайним автоматом

// Функція для приготування чаю за рецептом
void prepareTea(const TeaMachine& machine, const Recipe& recipe);

// Функція для перегляду доступних рецептів
void displayRecipes(const TeaMachine& machine);

// Функція для перевірки залишків інгредієнтів
bool checkIngredients(const TeaMachine& machine, const Recipe& recipe);

// Функція для перевірки запасів чаю
double checkTea(const TeaMachine& machine);

// Функція для перевірки запасів цукру
double checkSugar(const TeaMachine& machine);

// Функція для перевірки запасів води
double checkWater(const TeaMachine& machine);

// Функція для перевірки запасів молока
double checkMilk(const TeaMachine& machine);

#endif //OOP_TEAMACHINE_H

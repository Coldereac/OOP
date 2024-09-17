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
    Додатково користувач може додавати, видаляти та редагувати рецепти.
*/

// Одиниці виміру
enum MEASURMENT_TYPE { ML, GRAMS };

// Типи чаю
enum TEA_TYPE { BLACK_TEA, GREEN_TEA, HERBAL_TEA };

struct Ingredient {
    char* name;                     // Назва інгредієнта
    double quantity;                // Кількість інгредієнта (в грамах, мілілітрах тощо)
    MEASURMENT_TYPE measurmentType; // Одиниці виміру інгредієнта
};

struct Recipe {
    char* name;                // Назва рецепта чаю
    Ingredient* ingredients;   // Масив інгрідієнтів
    int brewTime;              // Час заварювання (в секундах)
    TEA_TYPE teaType;          // Тип чаю
    int index;                 // Індекс рецепта
};

struct TeaMachine {
    Recipe* recipes;           // Масив рецептів
    int recipeCount;           // Кількість доступних рецептів
    Ingredient tea;            // Запаси чаю
    Ingredient sugar;          // Запаси цукру
    Ingredient water;          // Запаси води
    Ingredient milk;           // Запаси молока
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

// Додавання нового рецепта
void addRecipe(TeaMachine& machine, const Recipe& newRecipe);

// Видалення рецепта
void removeRecipe(TeaMachine& machine, const int recipeIndex);

// Редагування існуючого рецепта
void editRecipe(TeaMachine& machine, const Recipe& updatedRecipe);

#endif //OOP_TEAMACHINE_H

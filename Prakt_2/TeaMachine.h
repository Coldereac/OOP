//
// Created by Malinka on 9/14/2024.
//

#ifndef OOP_TEAMACHINE_H
#define OOP_TEAMACHINE_H
/*
    Чайний автомат для особистого користування.
    Автомат має набір передвстановлених рецептів для приготування чаю.
    Користувач може переглядати рецепти, готувати чай за ними або без рецепта(з можливістю потім додати це як рецепт),
    перевіряти залишки сировини (чай, цукор тощо), а також стежити за наявністю інгредієнтів.
    Додатково користувач може додавати, видаляти та редагувати рецепти.
*/

// Одиниці виміру
enum MEASURMENT_TYPE { ML, GRAMS };

// Типи чаю
enum TEA_TYPE { BLACK_TEA, GREEN_TEA, HERBAL_TEA };

struct Ingredient {
    char *name;                         // Назва інгредієнта
    double quantity;                    // Кількість інгредієнта (в грамах, мілілітрах тощо)
    MEASURMENT_TYPE measurmentType;     // Одиниці виміру інгредієнта
};

struct Recipe {
    char *name;                 // Назва рецепта чаю
    Ingredient *ingredients;    // Масив інгрідієнтів
    int size;                   // Кількість інгрідієнтів
    int brewTime;               // Час заварювання (в секундах)
    TEA_TYPE teaType;           // Тип чаю
};

struct TeaMachine {
    Recipe *recipes;    // Масив рецептів
    int recipeCount;    // Кількість доступних рецептів
    Ingredient tea;     // Запаси чаю
    Ingredient sugar;   // Запаси цукру
    Ingredient water;   // Запаси води
    Ingredient milk;    // Запаси молока
};

const double MIN_TEA = 10;      //Grams
const double MIN_SUGAR = 20;    //Grams
const double MIN_WATER = 200;   //ML
const double MIN_MILK = 100;    //ML
const double MAX_TEA = 500;     //Grams
const double MAX_SUGAR = 500;   //Grams
const double MAX_WATER = 1000;  //ML
const double MAX_MILK = 500;    //ML

// Функції для роботи з чайним автоматом

// Функція для приготування чаю за рецептом
void prepareTea(const TeaMachine &machine, const Recipe &recipe);

// Функція для перегляду доступних рецептів
void displayRecipes(const TeaMachine &machine);

// Функція для перевірки залишків інгредієнтів
bool checkIngredients(const TeaMachine &machine, const Recipe &recipe);

// Функція для приготування чаю без рецепта, по ходу діла.
void prepareTeaWithoutRecipe(const TeaMachine &machine);

// Функція для перевірки запасів чаю
bool checkTea(const TeaMachine &machine);

// Функція для перевірки запасів цукру
bool checkSugar(const TeaMachine &machine);

// Функція для перевірки запасів води
bool checkWater(const TeaMachine &machine);

// Функція для перевірки запасів молока
bool checkMilk(const TeaMachine &machine);

// Додавання нового рецепта
void addRecipe(TeaMachine &machine, const Recipe &newRecipe);

// Видалення рецепта
void removeRecipe(TeaMachine &machine, const Recipe &recipe);

// Редагування існуючого рецепта
void editRecipe(TeaMachine &machine, const Recipe &updatedRecipe);

//Додавання інгрідієнтів в машину
void refillSupplies(const TeaMachine &machine);

//Додавання чая в машину
void refillTea(const TeaMachine &machine);

//Додавання цукору в машину
void refillSugar(const TeaMachine &machine);

//Додавання води в машину
void refillWater(const TeaMachine &machine);

//Додавання молока в машину
void refillMilk(const TeaMachine &machine);

#endif //OOP_TEAMACHINE_H

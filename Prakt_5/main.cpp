/*
Чайний автомат для особистого користування.
    Автомат має набір передвстановлених рецептів для приготування чаю.
    Користувач може переглядати рецепти, готувати чай за ними або без рецепта(з можливістю потім додати це як рецепт),
    перевіряти залишки сировини (чай, цукор тощо), а також стежити за наявністю інгредієнтів.
    Додатково користувач може додавати, видаляти та редагувати рецепти.
*/

#include <string>
#include <vector>
using namespace std;

// Одиниці виміру
enum MEASURMENT_TYPE { ML, GRAMS };

//Типи інгрідієнтів
enum INGRIDIENT_TYPE { BLACK_TEA, GREEN_TEA, HERBAL_TEA, SUGAR, WATER, MILK };

//Інгрідієнт
class Ingredient {
    INGRIDIENT_TYPE ingridientType; //Тип інгрідієнтів
    MEASURMENT_TYPE measurementType; // Одиниці виміру

public:
    //Стандартний конструктор
    Ingredient() {
        ingridientType = (INGRIDIENT_TYPE) 0;
        measurementType = (MEASURMENT_TYPE) 0;
    }

    //Конструктор за int
    Ingredient(int ingridientType, int measurementType): ingridientType((INGRIDIENT_TYPE) ingridientType),
                                                         measurementType((MEASURMENT_TYPE) measurementType) {
    }

    //Конструктор за enam
    Ingredient(INGRIDIENT_TYPE ingridientType, MEASURMENT_TYPE measurementType): ingridientType(ingridientType),
        measurementType(measurementType) {
    }
};

//Компонент рецепту
class Component {
    Ingredient ingridient; // інгрідієнт
    float amount; // кількість інгрідієнту

public:
    //Стандартний конструктор
    Component() {
        ingridient = Ingredient();
        amount = 0.0f;
    }

    //Конструктор за Ingridient та float
    Component(Ingredient &ingridient, float amount): ingridient(ingridient), amount(amount) {
    }
};

//Рецепт
class Recipe {
    string name; //Назва
    vector<Component> components; //Компоненти/Склад
    int brewTime; //Час заварювання


public:
    Recipe() {
        name = "";
        components.reserve(4);
        brewTime = 0;
    }

    Recipe(string &name): name(name), brewTime(0) {
        components.reserve(4);
    }


    Recipe(string &name, vector<Component> &components, int brewTime = 0): name(name), components(components),
                                                                           brewTime(brewTime) {
    }
};

class TeaMachine {
    vector<Recipe> recipes;
    Component blackTeaStock;
    Component greenTeaStock;
    Component herbalTeaStock;
    Component sugarStock;
    Component waterStock;
    Component milkStock;
    const double MIN_TEA = 5;      //Grams
    const double MIN_SUGAR = 10;    //Grams
    const double MIN_WATER = 200;   //ML
    const double MIN_MILK = 100;    //ML
    const double MAX_TEA = 500;     //Grams
    const double MAX_SUGAR = 500;   //Grams
    const double MAX_WATER = 1000;  //ML
    const double MAX_MILK = 500;    //ML
};

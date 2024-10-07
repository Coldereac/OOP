/*
Чайний автомат для особистого користування.
    Автомат має набір передвстановлених рецептів для приготування чаю.
    Користувач може переглядати рецепти, готувати чай за ними або без рецепта(з можливістю потім додати це як рецепт),
    перевіряти залишки сировини (чай, цукор тощо), а також стежити за наявністю інгредієнтів.
    Додатково користувач може додавати, видаляти та редагувати рецепти.
*/

#include <string>
#include <vector>
#include <bits/stl_algo.h>
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
    //Конструктор за int
    Ingredient(int ingridientType = 0, int measurementType = 0): ingridientType((INGRIDIENT_TYPE) ingridientType),
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
    //Конструктор за Ingridient та float
    Component(Ingredient ingridient, float amount = 0.0f) : ingridient(ingridient), amount(amount) {
    }
};

//Рецепт
class Recipe {
    string name; //Назва
    //Компоненти/Склад
    Component blackTea;
    Component greenTea;
    Component herbalTea;
    Component sugar;
    Component water;
    Component milk;
    int brewTime; //Час заварювання(хв)

public:
    // Минимальные значения
    static constexpr float MIN_TEA = 5.0f; // Grams
    static constexpr float MIN_SUGAR = 0.0f; // Grams
    static constexpr float MIN_WATER = 100.0f; // ML
    static constexpr float MIN_MILK = 0.0f; // ML
    static constexpr int MIN_BREW_TIME = 1; // Minutes

    // Максимальные значения
    static constexpr float MAX_TEA = 10.0f; // Grams
    static constexpr float MAX_SUGAR = 30.0f; // Grams
    static constexpr float MAX_WATER = 500.0f; // ML
    static constexpr float MAX_MILK = 100.0f; // ML
    static constexpr int MAX_BREW_TIME = 10; // Minutes

    Recipe(string name = "", float blackTea = 0, float greenTea = 0, float herbalTea = 0, float sugar = 0,
           float water = 0, float milk = 0, int brewTime = 0)
        : name(name),
          blackTea(Component(Ingredient(BLACK_TEA, GRAMS), std::clamp(blackTea, MIN_TEA, MAX_TEA))),
          greenTea(Component(Ingredient(GREEN_TEA, GRAMS), std::clamp(greenTea, MIN_TEA, MAX_TEA))),
          herbalTea(Component(Ingredient(HERBAL_TEA, GRAMS), std::clamp(herbalTea, MIN_TEA, MAX_TEA))),
          sugar(Component(Ingredient(SUGAR, GRAMS), std::clamp(sugar, MIN_SUGAR, MAX_SUGAR))),
          water(Component(Ingredient(WATER, ML), std::clamp(water, MIN_WATER, MAX_WATER))),
          milk(Component(Ingredient(MILK, ML), std::clamp(milk, MIN_MILK, MAX_MILK))),
          brewTime(std::clamp(brewTime, MIN_BREW_TIME, MAX_BREW_TIME)) {
    }

    void displayRecipe() {
        //cout << name << ... << sugar << milk << brewTime;
    }
};

class TeaMachine {
    vector<Recipe> recipes;
    float blackTeaStock;
    float greenTeaStock;
    float herbalTeaStock;
    float sugarStock;
    float waterStock;
    float milkStock;
    //Значення для максимума та мінімума запасів
    const float MIN_TEA = 10; //Grams
    const float MIN_SUGAR = 30; //Grams
    const float MIN_WATER = 500; //ML
    const float MIN_MILK = 100; //ML
    const float MAX_TEA = 120; //Grams
    const float MAX_SUGAR = 360; //Grams
    const float MAX_WATER = 6000; //ML
    const float MAX_MILK = 1200; //ML

public:
    TeaMachine(vector<Recipe> &recipes, float blackTeaStock = 10, float greenTeaStock = 10, float herbalTeaStock = 10,
               float sugarStock = 30, float waterStock = 500, float milkStock = 100): recipes(recipes),
        blackTeaStock(blackTeaStock), greenTeaStock(greenTeaStock), herbalTeaStock(herbalTeaStock),
        sugarStock(sugarStock), waterStock(waterStock), milkStock(milkStock) {
    }

    TeaMachine(float blackTeaStock = 10, float greenTeaStock = 10, float herbalTeaStock = 10,
               float sugarStock = 30, float waterStock = 500, float milkStock = 100): blackTeaStock(blackTeaStock),
        greenTeaStock(greenTeaStock), herbalTeaStock(herbalTeaStock),
        sugarStock(sugarStock), waterStock(waterStock), milkStock(milkStock) {
        recipes.reserve(5);
    }

    bool checkStocks() {
        //return blackTeaStocks > MIN_TEA && blackTeaStocks < MIN_TEA
    }

    bool checkTea() {
        // return checkBlackTea && checkGreenTea && checkHerbalTea
    }

    bool checkBlackTea() {
        // return blackTeaStock > MIN_TEA && blackTeaStock < MAX_TEA
    }

    bool checkGreenTea() {
        // return greenTeaStock > MIN_TEA && greenTeaStock < MAX_TEA
    }

    bool checkHerbalTea() {
        // return herbalTeaStock > MIN_TEA && herbalTeaStock < MAX_TEA
    }

    bool checkSugar() {
        // return sugarStock > MIN_TEA && sugarStock < MAX_TEA
    }

    bool checkWater() {
        // return waterStock > MIN_TEA && waterStock < MAX_TEA
    }

    bool checkMilk() {
        // return milkStock > MIN_TEA && milkStock < MAX_TEA
    }

    void prepareTea(const Recipe &recipe) {
        /*
         *if(checkStocks()){
         *Brewing Tea
         *} else{
         *cout << "Not enough or too much components in stock"
         *}
         */
    }

    void displayRecipes() {
        /* for(...){
         * Recipe.displayRecipe();
         * }
        */
    }

    Recipe collectInfo() {
        /*Recipe tempRecipe();
         *cout << "Which tea you want(...)";
         *cout << "How much you want ... ";
         *cin >> tempRecipe.someField;
         *if(!(tempRecipe.someField > Recipe::MIN_SOME_FIELD && temp.recipe.someFiled < Recipe::MAX_SOME_FIELD))
         *cout << "Enter this filed again pleas"
         *cin >> tempRecipe.someField;
         *... collect all info for all fields
         *return tempRecipe;
         */
    }

    void addRecipe(const Recipe &newRecipe) {
        /*bool work = true;
         *do{
         *recipes.push_back(newRecipe)
         *cout << "Do you want to add another?"
         *cin >> ...
         *if(no) work = false
         *}while(work);
         */
    }

    void prepareTeaWithoutRecipe() {
        /*Recipe tempRecipe = collectInfo();
         *prepareTea(tempRecipe);
         *cout << "Do you want to add this recipe in the list?"
         *...
         *if(yes){
         *addRecipe(tempRecipe)
         *}
         */
    }

    void removeRecipe(const Recipe &recipe) {
        /*auto it = find(recipe)
         *recipes.erase(it)
         */
    }

    void editRecipe(const Recipe &recipe) {
        /*bool continueToWork = true
         *while(continueToWork){
         *cout << "What you want to change?" << endl << "1. ..." << endl << "2. ..."
         *int choice;
         *cin >> choice;
         *swtich(choice){
         *...
         *}
         *cout << "Do you want to change something else?"
         *cin >> choice
         *if(no) continueToWork = false
         *}
         */
    }

    void refillSupplies() {

        /*bool work = true
         *while(true){
         *print menu with each stock
         *int choice;
         *cin >> choice;
         *switch (choice){
         *case 1: refillBlackTea()
         *...
         *}
         *ask user if he wants to refill something else
         *if(no) work = false
         *}
         */
    }

    void refillBlackTea() {
        /*float maxAdd = MAX_TEA - blackTeaStock
         *cout << "You can add maximum " << maxAdd << " grams of black tea"
         *float addingAmount;
         *cin >> addingAmount;
         *if(addingAmount > maxAdd || addingAmount < 0){
         *tell user to do something whit it
         *}else{
         *adding black tea
         *}
         */ // The same for all other refills
    }

    void refillGreenTea() {
    }

    void refillHerbalTea() {
    }

    void refillSugar() {
    }

    void refillWater() {
    }

    void refillMilk() {
    }
};

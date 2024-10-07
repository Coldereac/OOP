/*
Чайний автомат для особистого користування.
    Автомат має набір передвстановлених рецептів для приготування чаю.
    Користувач може переглядати рецепти, готувати чай за ними або без рецепта (з можливістю потім додати це як рецепт),
    перевіряти залишки сировини (чай, цукор тощо), а також стежити за наявністю інгредієнтів.
    Додатково користувач може додавати, видаляти та редагувати рецепти.
*/

#include <string>
#include <vector>
#include <bits/algorithmfwd.h>
using namespace std;

// Одиниці виміру для інгредієнтів
enum MEASURMENT_TYPE { ML, GRAMS };

// Типи інгредієнтів, які використовуються в рецептах
enum INGRIDIENT_TYPE { BLACK_TEA, GREEN_TEA, HERBAL_TEA, SUGAR, WATER, MILK };

// Клас, що представляє окремий інгредієнт
class Ingredient {
    INGRIDIENT_TYPE ingridientType; // Тип інгредієнта (наприклад, чорний чай, зелений чай тощо)
    MEASURMENT_TYPE measurementType; // Одиниці виміру для інгредієнта (міллілітри або грами)

public:
    // Конструктор за цілими числами (перетворює int на відповідний enum тип)
    Ingredient(int ingridientType = 0, int measurementType = 0)
        : ingridientType(static_cast<INGRIDIENT_TYPE>(ingridientType)),
          measurementType(static_cast<MEASURMENT_TYPE>(measurementType)) {
    }

    // Конструктор за enum типами
    Ingredient(INGRIDIENT_TYPE ingridientType, MEASURMENT_TYPE measurementType)
        : ingridientType(ingridientType), measurementType(measurementType) {
    }

    // Метод для отримання типу інгредієнта (може бути доданий при необхідності)
    INGRIDIENT_TYPE getType() const {
        return ingridientType;
    }

    // Метод для отримання одиниці виміру (може бути доданий при необхідності)
    MEASURMENT_TYPE getMeasurementType() const {
        return measurementType;
    }
};

// Клас, що представляє компонент рецепту (інгредієнт та його кількість)
class Component {
    Ingredient ingridient; // Інгредієнт, що входить до складу рецепту
    float amount; // Кількість інгредієнта

public:
    // Конструктор з параметрами: інгредієнт та його кількість
    Component(Ingredient ingridient, float amount = 0.0f)
        : ingridient(ingridient), amount(amount) {
    }

    // Методи доступу до інгредієнта та кількості (можуть бути додані при необхідності)
    Ingredient getIngredient() const {
        return ingridient;
    }

    float getAmount() const {
        return amount;
    }

    void setAmount(float newAmount) {
        amount = newAmount;
    }
};

// Клас, що представляє рецепт чаю
class Recipe {
    string name; // Назва рецепту
    // Компоненти рецепту (різні типи інгредієнтів)
    Component blackTea;
    Component greenTea;
    Component herbalTea;
    Component sugar;
    Component water;
    Component milk;
    int brewTime; // Час заварювання в хвилинах

public:
    // Мінімальні допустимі значення для інгредієнтів та часу заварювання
    static constexpr float MIN_TEA = 5.0f; // Грами
    static constexpr float MIN_SUGAR = 0.0f; // Грами
    static constexpr float MIN_WATER = 100.0f; // Міллілітри
    static constexpr float MIN_MILK = 0.0f; // Міллілітри
    static constexpr int MIN_BREW_TIME = 1; // Хвилини

    // Максимальні допустимі значення для інгредієнтів та часу заварювання
    static constexpr float MAX_TEA = 10.0f; // Грами
    static constexpr float MAX_SUGAR = 30.0f; // Грами
    static constexpr float MAX_WATER = 500.0f; // Міллілітри
    static constexpr float MAX_MILK = 100.0f; // Міллілітри
    static constexpr int MAX_BREW_TIME = 10; // Хвилини

    // Конструктор з параметрами для ініціалізації рецепту
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

    // Метод для відображення інформації про рецепт
    void displayRecipe() {
        // cout << "Назва: " << name << "Чорний чай: " << blackTea <<  ...;
    }

    // Методи доступу до полів
    string getName() const {
        return name;
    }

    int getBrewTime() const {
        return brewTime;
    }

    void setName(string name) {
        this->name = name;
    }

    Component getBlackTea() const {
        return blackTea;
    }

    Component getGreenTea() const {
        return greenTea;
    }

    Component getHerbalTea() const {
        return herbalTea;
    }

    Component getSugar() const {
        return sugar;
    }

    Component getWater() const {
        return water;
    }

    Component getMilk() const {
        return milk;
    }

    void setName(const string &name) {
        this->name = name;
    }

    void setBlackTea(const Component &blackTea) {
        this->blackTea = blackTea;
    }

    void setGreenTea(const Component &greenTea) {
        this->greenTea = greenTea;
    }

    void setHerbalTea(const Component &herbalTea) {
        this->herbalTea = herbalTea;
    }

    void setSugar(const Component &sugar) {
        this->sugar = sugar;
    }

    void setWater(const Component &water) {
        this->water = water;
    }

    void setMilk(const Component &milk) {
        this->milk = milk;
    }

    void setBrewTime(int brewTime) {
        this->brewTime = brewTime;
    }
};

// Клас, що представляє чайний автомат
class TeaMachine {
    vector<Recipe> recipes; // Список доступних рецептів
    float blackTeaStock; // Запас чорного чаю
    float greenTeaStock; // Запас зеленого чаю
    float herbalTeaStock; // Запас трав'яного чаю
    float sugarStock; // Запас цукру
    float waterStock; // Запас води
    float milkStock; // Запас молока

    // Мінімальні та максимальні запаси для кожного інгредієнта
    const float MIN_TEA = 10; // Грами
    const float MIN_SUGAR = 30; // Грами
    const float MIN_WATER = 500; // Міллілітри
    const float MIN_MILK = 100; // Міллілітри
    const float MAX_TEA = 120; // Грами
    const float MAX_SUGAR = 360; // Грами
    const float MAX_WATER = 6000; // Міллілітри
    const float MAX_MILK = 1200; // Міллілітри

public:
    // Конструктор з параметрами для ініціалізації автомату з рецептами та запасами
    TeaMachine(vector<Recipe> &recipes, float blackTeaStock = 10, float greenTeaStock = 10, float herbalTeaStock = 10,
               float sugarStock = 30, float waterStock = 500, float milkStock = 100)
        : recipes(recipes),
          blackTeaStock(blackTeaStock), greenTeaStock(greenTeaStock), herbalTeaStock(herbalTeaStock),
          sugarStock(sugarStock), waterStock(waterStock), milkStock(milkStock) {
    }

    // Перевантажений конструктор без списку рецептів (рецепти будуть додаватися пізніше)
    TeaMachine(float blackTeaStock = 10, float greenTeaStock = 10, float herbalTeaStock = 10,
               float sugarStock = 30, float waterStock = 500, float milkStock = 100)
        : blackTeaStock(blackTeaStock), greenTeaStock(greenTeaStock), herbalTeaStock(herbalTeaStock),
          sugarStock(sugarStock), waterStock(waterStock), milkStock(milkStock) {
        recipes.reserve(5); // Попереднє резервування місця для рецептів
    }

    // Метод для перевірки запасів інгредієнтів (реалізація потребує завершення)
    bool checkStocks() {
        // Приклад перевірки: всі запаси повинні бути в межах мінімуму та максимуму
        // return blackTeaStock > MIN_TEA && blackTeaStock < MAX_TEA &&
        //        greenTeaStock > MIN_TEA && greenTeaStock < MAX_TEA &&
        //        ...;
    }

    // Метод для перевірки наявності всіх типів чаю
    bool checkTea() {
        // Перевірка, чи достатньо запасів кожного типу чаю
        // return checkBlackTea() && checkGreenTea() && checkHerbalTea();
    }

    // Метод для перевірки запасу чорного чаю
    bool checkBlackTea() {
        // return blackTeaStock > MIN_TEA && blackTeaStock < MAX_TEA;
    }

    // Метод для перевірки запасу зеленого чаю
    bool checkGreenTea() {
        // return greenTeaStock > MIN_TEA && greenTeaStock < MAX_TEA;
    }

    // Метод для перевірки запасу трав'яного чаю
    bool checkHerbalTea() {
        // return herbalTeaStock > MIN_TEA && herbalTeaStock < MAX_TEA;
    }

    // Метод для перевірки запасу цукру
    bool checkSugar() {
        // return sugarStock > MIN_SUGAR && sugarStock < MAX_SUGAR;
    }

    // Метод для перевірки запасу води
    bool checkWater() {
        // return waterStock > MIN_WATER && waterStock < MAX_WATER;
    }

    // Метод для перевірки запасу молока
    bool checkMilk() {
        // return milkStock > MIN_MILK && milkStock < MAX_MILK;
    }

    // Метод для приготування чаю за заданим рецептом
    void prepareTea(const Recipe &recipe) {
        /*
         * Перевірка запасів інгредієнтів перед приготуванням
         * if(checkStocks()){
         *     // Логіка заварювання чаю (зменшення запасів інгредієнтів)
         *     // Наприклад: blackTeaStock -= recipe.blackTea.getAmount();
         *     // Відображення повідомлення про успішне приготування
         * } else{
         *     cout << "Недостатньо або занадто багато компонентів у запасі" << endl;
         * }
         */
    }

    // Метод для відображення всіх доступних рецептів
    void displayRecipes() {
        /*
         * for(const auto &recipe : recipes){
         *     recipe.displayRecipe();
         * }
         */
    }

    // Метод для збору інформації від користувача для створення нового рецепту
    Recipe collectInfo() {
        /*
         * Recipe recipe;
         * cout << "Який чай ви хочете приготувати? ";
         * cin >> recipe.name;
         *
         * cout << "Скільки чорного чаю (грам): ";
         * float temp;
         * cin >> temp;
         * // Перевірка коректності введених даних
         * while(!(temp > Recipe::MIN_TEA && temp < Recipe::MAX_TEA)){
         *     cout << "Введіть коректну кількість чорного чаю" << endl;
         *     cin >> temp;
         * }
         * recipe.getBlackTea().setAmount(temp);
         *
         * // Повторити для інших інгредієнтів: зелений чай, трав'яний чай, цукор, вода, молоко
         *
         * cout << "Час заварювання (хвилини): ";
         * int tempInt;
         * cin >> tempInt;
         * while(!(tempInt > Recipe::MIN_BREW_TIME && tempInt < Recipe::MAX_BREW_TIME)){
         *     cout << "Введіть коректний час заварювання" << endl;
         *     cin >> tempInt;
         * }
         *recipe.setBrewTime(tempInt)
         *
         * return tempRecipe;
         */
    }

    // Метод для додавання нового рецепту до списку рецептів
    void addRecipe(const Recipe &newRecipe) {
        /*
         *     recipes.push_back(newRecipe);
         */
    }

    // Метод для приготування чаю без використання існуючого рецепту
    void prepareTeaWithoutRecipe() {
        /*
         * Recipe tempRecipe = collectInfo(); // Збір інформації від користувача
         * prepareTea(tempRecipe); // Приготування чаю за зібраним рецептом
         * cout << "Бажаєте додати цей рецепт до списку? (1 - Так, 0 - Ні): ";
         * int choice;
         * cin >> choice;
         * if(choice == 1){
         *     addRecipe(tempRecipe); // Додавання нового рецепту
         * }
         */
    }

    // Метод для видалення рецепту зі списку рецептів
    void removeRecipe(const Recipe &recipe) {
        /*
         * auto it = find(recipes.begin(), recipes.end(), recipe)
         * if(it != recipes.end()){
         *     recipes.erase(it);
         *     cout << "Рецепт успішно видалено." << endl;
         * } else {
         *     cout << "Рецепт не знайдено." << endl;
         * }
         */
    }

    // Метод для редагування існуючого рецепту
    void editRecipe(const Recipe &recipe) {
        /*
         * bool continueToWork = true;
         * while(continueToWork){
         *     cout << "Що ви хочете змінити?" << endl;
         *     cout << "1. Назва" << endl;
         *     cout << "2. Чорний чай" << endl;
         *     cout << "3. Зелений чай" << endl;
         *     cout << "4. Трав'яний чай" << endl;
         *     cout << "5. Цукор" << endl;
         *     cout << "6. Вода" << endl;
         *     cout << "7. Молоко" << endl;
         *     cout << "8. Час заварювання" << endl;
         *     int choice;
         *     cin >> choice;
         *     switch(choice){
         *         case 1:
         *             // Зміна назви
         *             break;
         *         case 2:
         *             // Зміна кількості чорного чаю
         *             break;
         *         // Додати інші випадки для решти інгредієнтів та часу
         *         default:
         *             cout << "Некоректний вибір." << endl;
         *     }
         *     cout << "Бажаєте змінити щось ще? (1 - Так, 0 - Ні): ";
         *     int cont;
         *     cin >> cont;
         *     if(cont == 0){
         *         continueToWork = false;
         *     }
         * }
         */
    }

    // Метод для поповнення запасів інгредієнтів
    void refillSupplies() {
        /*
         * bool work = true;
         * while(work){
         *     // Відображення меню поповнення запасів
         *     cout << "Меню поповнення запасів:" << endl;
         *     cout << "1. Чорний чай" << endl;
         *     cout << "2. Зелений чай" << endl;
         *     cout << "3. Трав'яний чай" << endl;
         *     cout << "4. Цукор" << endl;
         *     cout << "5. Вода" << endl;
         *     cout << "6. Молоко" << endl;
         *     cout << "0. Вихід" << endl;
         *     int choice;
         *     cin >> choice;
         *     switch(choice){
         *         case 1:
         *             refillBlackTea();
         *             break;
         *         case 2:
         *             refillGreenTea();
         *             break;
         *         case 3:
         *             refillHerbalTea();
         *             break;
         *         case 4:
         *             refillSugar();
         *             break;
         *         case 5:
         *             refillWater();
         *             break;
         *         case 6:
         *             refillMilk();
         *             break;
         *         case 0:
         *             work = false;
         *             break;
         *         default:
         *             cout << "Некоректний вибір." << endl;
         *     }
         *     if(work){
         *         cout << "Бажаєте поповнити ще щось? (1 - Так, 0 - Ні): ";
         *         int cont;
         *         cin >> cont;
         *         if(cont == 0){
         *             work = false;
         *         }
         *     }
         * }
         */
    }

    // Метод для поповнення запасу чорного чаю
    void refillBlackTea() {
        /*
         * float maxAdd = MAX_TEA - blackTeaStock; // Максимальна кількість, яку можна додати
         * cout << "Ви можете додати максимум " << maxAdd << " грам чорного чаю." << endl;
         * cout << "Введіть кількість для додавання: ";
         * float addingAmount;
         * cin >> addingAmount;
         * if(addingAmount > maxAdd || addingAmount < 0){
         *     cout << "Некоректна кількість. Спробуйте ще раз." << endl;
         * } else{
         *     blackTeaStock += addingAmount; // Додавання чорного чаю до запасу
         *     cout << "Запас чорного чаю поповнено." << endl;
         * }
         */
    }

    // Метод для поповнення запасу зеленого чаю
    void refillGreenTea() {
        /*
         * Аналогічна реалізація як refillBlackTea, але для зеленого чаю
         */
    }

    // Метод для поповнення запасу трав'яного чаю
    void refillHerbalTea() {
        /*
         * Аналогічна реалізація як refillBlackTea, але для трав'яного чаю
         */
    }

    // Метод для поповнення запасу цукру
    void refillSugar() {
        /*
         * Аналогічна реалізація як refillBlackTea, але для цукру
         */
    }

    // Метод для поповнення запасу води
    void refillWater() {
        /*
         * Аналогічна реалізація як refillBlackTea, але для води
         */
    }

    // Метод для поповнення запасу молока
    void refillMilk() {
        /*
         * Аналогічна реалізація як refillBlackTea, але для молока
         */
    }
};

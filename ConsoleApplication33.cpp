#include <iostream>
#include <iomanip>

using namespace std;

const double TAX_RATE = 0.09; // نرخ ارزش افزوده

struct Item {
    int code;
    string name;
    double price;
};

// منوی غذا
Item meals[] = {
    {1, "Burger", 5.99},
    {2, "Pizza", 8.99},
    {3, "Pasta", 7.49},
    {4, "Salad", 4.99},
    {5, "Steak", 12.99}
};

// منوی نوشیدنی
Item drinks[] = {
    {1, "Water", 1.00},
    {2, "Soda", 1.50},
    {3, "Juice", 2.50},
    {4, "Beer", 3.00},
    {5, "Wine", 4.50}
};

// منوی پیش غذا
Item appetizers[] = {
    {1, "Fries", 2.99},
    {2, "Wings", 5.99},
    {3, "Mozzarella Sticks", 4.99},
    {4, "Nachos", 6.49},
    {5, "Garlic Bread", 3.99}
};

void printMenu(const string& category, Item menu[], int size) {
    cout << category << ":" << endl;
    for (int i = 0; i < size; ++i) {
        cout << menu[i].code << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].price << endl;
    }
    cout << endl;
}

double getItemPrice(Item menu[], int size, int code) {
    for (int i = 0; i < size; ++i) {
        if (menu[i].code == code) {
            return menu[i].price;
        }
    }
    return 0.0;
}

string getItemName(Item menu[], int size, int code) {
    for (int i = 0; i < size; ++i) {
        if (menu[i].code == code) {
            return menu[i].name;
        }
    }
    return "Unknown";
}

int main() {
    // چاپ منو
    printMenu("Meals", meals, 5);
    printMenu("Drinks", drinks, 5);
    printMenu("Appetizers", appetizers, 5);

    int mealCode, drinkCode, appetizerCode;

    // دریافت ورودی از کاربر
    cout << "Enter the code for your meal: ";
    cin >> mealCode;
    cout << "Enter the code for your drink: ";
    cin >> drinkCode;
    cout << "Enter the code for your appetizer: ";
    cin >> appetizerCode;

    // محاسبه قیمت‌ها
    double mealPrice = getItemPrice(meals, 5, mealCode);
    double drinkPrice = getItemPrice(drinks, 5, drinkCode);
    double appetizerPrice = getItemPrice(appetizers, 5, appetizerCode);

    double subtotal = mealPrice + drinkPrice + appetizerPrice;
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;

    // چاپ فاکتور
    cout << "\nYour order:" << endl;
    cout << getItemName(meals, 5, mealCode) << " - $" << fixed << setprecision(2) << mealPrice << endl;
    cout << getItemName(drinks, 5, drinkCode) << " - $" << fixed << setprecision(2) << drinkPrice << endl;
    cout << getItemName(appetizers, 5, appetizerCode) << " - $" << fixed << setprecision(2) << appetizerPrice << endl;
    cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "Tax: $" << fixed << setprecision(2) << tax << endl;
    cout << "Total: $" << fixed << setprecision(2) << total << endl;

    return 0;
}


// Taylor Spencer Lab 6 Homework
// This assignement calculates the price of a computer
// July 4, 2024

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function prototypes
void addUserInfo(double &speed, double &storage, double &ram, char &touchScreen);
double calculate(double speed, double storage, double ram, char touchScreen);
void display(double speed, double storage, double ram, char touchScreen, double price);

int main()
{

    // variables
    double speed = 0.0;
    double storage = 0.0;
    double ram = 0.0;
    char touchScreen = '\0';
    double price;
    char repeat;

    cout << endl
         << "  This program calculates the price of a computer. " << endl
         << endl;

    // call the function
    do
    {
        // Get information from user
        addUserInfo(speed, storage, ram, touchScreen);

        // Calculate the price
        price = calculate(speed, storage, ram, touchScreen);

        // Display the information
        display(speed, storage, ram, touchScreen, price);

        // Ask if the user wants to create another computer
        cout << "Do you want to create another computer? (Y/N): ";
        cin >> repeat;
        cout << endl;
    } while (repeat == 'Y' || repeat == 'y');
    cout << endl
         << endl;

    return 0;
}

// get information from user
void addUserInfo(double &speed, double &storage, double &ram, char &touchScreen)
{
    cout << "  Enter the speed of the processor (GHZ): ";
    cin >> speed;
    while (speed <= 0)
    {
        cout << "  Error: Value must be greater than 0! Enter the speed of the processor (GHZ): ";
        cin >> speed;
    }

    cout << "  Enter the storage capacity (GB): ";
    cin >> storage;
    while (storage <= 0)
    {
        cout << "  Error: Value must be greater than 0! Enter the storage capacity (GB): ";
        cin >> storage;
    }

    cout << "  Enter RAM amount (GB): ";
    cin >> ram;
    while (ram <= 0)
    {
        cout << "  Error: Value must be greater than 0! Enter RAM amount (GB): ";
        cin >> ram;
    }

    cout << "  Is the computer touchscreen? (Y/N): ";
    cin >> touchScreen;
    while (touchScreen != 'Y' && touchScreen != 'y' && touchScreen != 'N' && touchScreen != 'n')
    {
        cout << "  Error: Enter 'Y' or 'N'! Is the computer touchscreen (Y/N)? ";
        cin >> touchScreen;
    }
}

double calculate(double speed, double storage, double ram, char touchScreen)
{
    const double BASECOST_COMPUTER = 150.0;      // Base cost in $
    const double ADDITION_GHZ_FEES = 50.0;       // $50 for each additional GHz over 2GHz
    const double ADDITIONAL_STORAGE_COST = 40.0; // $ additional storage cost over 500GB
    const double ADDITIONAL_RAM_COST = 5.0;      // $5 for each RAM GB over 4GB
    const double TOUCHSCREEN_COST = 60.0;        // Touchscreen cost in $

    const double GHZ_MIN = 2.0;
    const double STORAGE_MIN = 500.0;   // GB
    const double MIN_RAM = 4.0;         // GB
    const double MARKUP_PERCENT = 0.75; // 75% markup

    double total_GHZ_Fees = 0.0;
    double total_storage_fee = 0.0;
    double total_ram_fee = 0.0;
    double total_touchscreen_fee = 0.0;
    double total_cost = 0.0;

    // calculations
    // calculate addition fees for speed
    if (speed > GHZ_MIN)
    {
        total_GHZ_Fees = (speed - GHZ_MIN) * ADDITION_GHZ_FEES;
    }

    // calculate additional fees for storage
    if (storage > STORAGE_MIN)
    {
        total_storage_fee = ADDITIONAL_STORAGE_COST;
    }

    // calculate additional fees for ram
    if (ram > MIN_RAM)
    {
        total_ram_fee = (ram - MIN_RAM) * ADDITIONAL_RAM_COST;
    }

    // calculate touch screen fee
    if (touchScreen == 'Y' || touchScreen == 'y')
    {
        total_touchscreen_fee = TOUCHSCREEN_COST;
    }

    // the total cost of computer calculation
    total_cost = BASECOST_COMPUTER + total_GHZ_Fees + total_storage_fee + total_ram_fee + total_touchscreen_fee;

    // total with the 75% markup
    double price = total_cost + MARKUP_PERCENT * total_cost;

    return price;
}

// Function to display the information
void display(double speed, double storage, double ram, char touchScreen, double price)
{
    cout << endl
         << "Computer Information:" << endl;
    cout << "Processor speed: " << speed << " GHz" << endl;
    cout << "Storage capacity: " << storage << " GB" << endl;
    cout << "RAM amount: " << ram << " GB" << endl;
    cout << "Touchscreen: " << (touchScreen == 'Y' || touchScreen == 'y' ? "Yes" : "No") << endl;
    cout << fixed << setprecision(2);
    cout << "Price: $" << price << endl
         << endl;
}

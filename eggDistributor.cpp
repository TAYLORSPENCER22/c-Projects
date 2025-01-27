//
//  TaylorSpencer_Lab5
//  Distribution of eggs
// June 29, 2024

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    // VARIABLES
    const int DOZEN = 12; // max eggs in each basket
    const int MIN = 0;    // min number of eggs in each basket

    int basketsTotal = 0;
    int brownEggs = 0;
    int whiteEggs = 0;

    int total_of_brown_eggs = 0;
    int total_of_white_eggs = 0;

    cout << " This application processes the distribution of eggs." << endl;

    cout << endl;

    // ASK HOW MANY BASKETS ARE AVAILABLE
    cout << " How many baskets are available in total: ";
    cin >> basketsTotal;
    while (basketsTotal < MIN)
    {
        cout << " Total baskets cannot be negative. Please enter a positive number: ";
        cin >> basketsTotal;
        cout << endl;
    }
    if (basketsTotal == 0)
    {
        cout << " You have no eggs to distribute. " << endl;
        cout << endl;
        return 0;
    }
    cout << endl;

    // CALCULATE THE TOTAL NUMBER OF BROWN EGGS
    for (int i = 1; i <= basketsTotal; i++)
    {
        cout << " Please enter the number of brown eggs in a basket #" << i << ":";
        cin >> brownEggs;
        while (brownEggs < MIN)
        {
            cout << " Number of brown eggs cannot be negative. Please enter the number of brown eggs in a basket #" << i << ": ";
            cin >> brownEggs;
        }
        total_of_brown_eggs += brownEggs;
    }
    cout << endl;

    // CALCULATE THE TOTAL NUMBER OF WHITE EGGS
    for (int i = 1; i <= basketsTotal; i++)
    {
        cout << " Please enter the number of white eggs in a basket #" << i << ":";
        cin >> whiteEggs;
        while (whiteEggs < MIN)
        {
            cout << " Number of white eggs cannot be negative. Please enter the number of white eggs in a basket #" << i << ": ";
            cin >> whiteEggs;
        }
        total_of_white_eggs += whiteEggs;
    }
    cout << endl;
    cout << " The total number of brown eggs: " << total_of_brown_eggs;
    cout << endl;
    cout << " The total number of white eggs: " << total_of_white_eggs;
    cout << endl;
    cout << endl;

    // CALCULATIONS
    int egg_total = total_of_brown_eggs + total_of_white_eggs;
    double percent_of_brown_eggs = (static_cast<double>(total_of_brown_eggs) / egg_total) * 100;
    double percent_of_white_eggs = (static_cast<double>(total_of_white_eggs) / egg_total) * 100;
    int brown_egg_packs = total_of_brown_eggs / DOZEN;
    int white_egg_packs = total_of_white_eggs / DOZEN;

    // PERCENTAGE OF EGGS
    cout << fixed << setprecision(2);
    cout << " The percentage of brown eggs: " << percent_of_brown_eggs << "%" << endl;
    cout << " The percentage of white eggs: " << percent_of_white_eggs << "%" << endl;

    cout << endl;

    // NUMBER OF BROWN EGG DOZEN PACKS
    cout << " Number of brown egg dozen packs:  " << brown_egg_packs << endl;

    // NUMBER OF WHITE EGG DOZEN PACKS
    cout << " Number of white egg dozen packs:  " << white_egg_packs << endl;
    cout << endl;
    return 0;
}

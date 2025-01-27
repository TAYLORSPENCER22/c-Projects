//

//  Taylor Spencer Lab 7 - Purchase order for Plastic Products Inc
//  Created by Taylor Spencer on 7/8/24.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void calculateTotal(double pounds[], double totalCost[], double price[], int size);
void getPoundsInput(double pounds[], double totalCost[], string plasticTypes[], double price[], int size);
void display(double pounds[], double totalCost[], string plasticTypes[], double price[], int size);

int main()
{
    const int SIZE = 6; // number of items

    double pounds[SIZE];
    double totalCost[SIZE];
    string plasticTypes[SIZE] = {
        "PET beverage bottles and jars", "Natural high-density polyethylene", "Color HDPE", "Grade A film", "Grade B film", "Grade C film"};
    double price[SIZE] = {.08, .34, .04, .08, .05, .02};
    double totalWeight = 0;
    double finalCost = 0;

    cout << "  This program creates a purchase order for Plastic Products Inc. " << endl
         << endl;
    cout << "  Enter weight for each item to create a purchase order." << endl;

    getPoundsInput(pounds, totalCost, plasticTypes, price, SIZE);

    // Calculate total weight and final cost
    for (int i = 0; i < SIZE; i++)
    {
        totalWeight += pounds[i];
        finalCost += totalCost[i];
    }

    // Display the results
    cout << fixed << setprecision(2);
    cout << endl
         << "                             PURCHASE ORDER:" << endl;
    cout << setw(40) << left << "Material";
    cout << setw(20) << left << "Weight(Pounds)";
    cout << setw(20) << left << "Cost/Pound";
    cout << setw(20) << left << "Cost" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(40) << left << plasticTypes[i];
        cout << setw(20) << left << pounds[i];
        cout << "$" << setw(20) << left << price[i];
        cout << "$" << setw(19) << left << totalCost[i] << endl;
    }

    // Display total weight and cost
    cout << endl;
    cout << setw(40) << left << "Total";
    cout << setw(20) << left << totalWeight;
    cout << setw(20) << left << "";
    cout << "$" << setw(19) << left << finalCost << endl;

    cout << endl
         << endl;

    return 0;
}

// Calculate total cost
void calculateTotal(double pounds[], double totalCost[], double price[], int size)
{
    for (int i = 0; i < size; i++)
    {
        totalCost[i] = pounds[i] * price[i];
    }
}

// Get pounds from input
void getPoundsInput(double pounds[], double totalCost[], string plasticTypes[], double price[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "  How many pounds of " << plasticTypes[i] << "? ";
        cin >> pounds[i];
        while (pounds[i] <= 0)
        {
            cout << "  Error: Value must be greater than 0! How many pounds of " << plasticTypes[i] << ": ";
            cin >> pounds[i];
        }
    }
    calculateTotal(pounds, totalCost, price, size);

    cout << endl
         << endl;
}

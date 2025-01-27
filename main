//
//Taylor Spencer Lab 8 - Password Validator
//July 11, 2014
//

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

bool isValidPassword(const char password[]);
void getPassword(char password[], const int maxSize);

int main() {
    const int SIZE = 50;
    char password1[SIZE]; // First password entry
    char password2[SIZE]; // Second password entry for confirmation

  
    cout << "This program creates a strong password." << endl << endl;

    // Get and validate the first password entry
    getPassword(password1, SIZE);

    bool match = false;
    while (!match) {
        cout << "Re-enter your password: ";
        cin.getline(password2, SIZE);

        // Check if the passwords match
        if (strcmp(password1, password2) == 0) {
            match = true;
            cout << "Password has been saved." << endl;
        } else {
            cout << "Passwords do not match. Try again." << endl;
        }
    }

    return 0;
}

// Function to check if the password is valid
bool isValidPassword(const char password[]) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    size_t length = strlen(password);
    if (length < 6) return false;

    for (size_t i = 0; i < length; i++) {
        if (isspace(password[i])) return false;
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
        if (ispunct(password[i])) hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Function to get the password from the user and validate it
void getPassword(char password[], const int maxSize) {
    bool valid = false;

    while (!valid) {
        cout << "Enter a password: ";
        cin.getline(password, maxSize);

        if (isValidPassword(password)) {
            valid = true;
        } else {
            cout << "Invalid password. Ensure it has:" << endl
                 << "  No spaces" << endl
                 << "  At least six characters" << endl
                 << "  At least one uppercase letter" << endl
                 << "  At least one lowercase letter" << endl
                 << "  At least one number" << endl
                 << "  At least one special character" << endl;
        }
    }
}

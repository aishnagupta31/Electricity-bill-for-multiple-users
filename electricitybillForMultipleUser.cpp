#include <iostream>
#include <string>
using namespace std;

class User {
    string name;
    int units;
    float total;
    
public:
    void setDetails(int units, string name) {
        this->units = units;
        this->name = name;
    }
    
    float calculateBill() {
        total = 50; // Fixed base charge
        
        if (units <= 100) {
            total += units * 0.60;
        } else if (units <= 300) {
            total += (100 * 0.60) + ((units - 100) * 0.80);
        } else {
            total += (100 * 0.60) + (200 * 0.80) + ((units - 300) * 0.90);
        }
        
        return total;
    }
    
    float applySurcharge() {
        if (total > 300) {
            total += total * 0.15;
        }
        return total;
    }
    
    void show() {
        cout << "Name: " << name << "\tUnits: " << units << "\tTotal: " << total << " rupees" << endl;
    }
    
    void calculateAndDisplay() {
        total = calculateBill();
        applySurcharge(); // Directly modifies total
        show();
    }
};

int main() {
    int n;
    cout << "Enter the number of users: ";
    cin >> n;
    int MAX_USERS = 100; // Adjust as needed
    User users[MAX_USERS]; // Array to hold up to MAX_USERS users
    for (int i = 0; i < n; ++i) {
        string name;
        int units;
        cout << "Enter details for user " << i + 1 << endl;
        cout << "Name: ";
        cin.ignore(); // Clear any leftover newline characters in the input buffer
        getline(cin, name); // To handle names with spaces
        cout << "Units: ";
        cin >> units;
        
        users[i].setDetails(units, name);
    }
    
    cout << "\nUser details and bills:\n";
    for (int i = 0; i < n; ++i) {
        users[i].calculateAndDisplay();
    }

    return 0;
}

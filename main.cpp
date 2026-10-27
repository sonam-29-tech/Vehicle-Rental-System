#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const int MIN_DAYS = 1;
const int MAX_DAYS = 30;

class Vehicle {
private:
    string vehicleId;
    string model;
    double ratePerDay;
    int rentalDays;

public:
    Vehicle(string id, string mdl, double rate) {
        vehicleId = id;
        model = mdl;
        ratePerDay = rate;
        rentalDays = 0;
    }

    virtual ~Vehicle() {}

    string getId() const {
        return vehicleId;
    }

    string getModel() const {
        return model;
    }

    double getRate() const {
        return ratePerDay;
    }

    int getRentalDays() const {
        return rentalDays;
    }

    void setRentalDays(int days) {
        rentalDays = days;
    }

    virtual double calculateRent() const {
        return ratePerDay * rentalDays;
    }

    virtual string getType() const {
        return "Vehicle";
    }

    virtual void display() const {
        cout << "\n---------- Rental Details ----------\n";
        cout << "Type            : " << getType() << endl;
        cout << "Vehicle ID      : " << vehicleId << endl;
        cout << "Model           : " << model << endl;
        cout << "Rental Duration : " << rentalDays << " day(s)" << endl;
        cout << fixed << setprecision(2);
        cout << "Rate per day    : Rs. " << ratePerDay << endl;
    }
};

class Car : public Vehicle {
public:
    Car(string id, string mdl, double rate)
        : Vehicle(id, mdl, rate) {}

    double calculateRent() const {
        double total = getRate() * getRentalDays();

        if (getRentalDays() >= 7)
            total = total - (total * 0.10);

        return total + 200;
    }

    string getType() const {
        return "Car";
    }

    void display() const {
        Vehicle::display();

        cout << "Insurance Fee   : Rs. 200.00" << endl;

        if (getRentalDays() >= 7)
            cout << "Discount        : 10%" << endl;
        else
            cout << "Discount        : None" << endl;

        cout << "Total Charges   : Rs. "
             << calculateRent() << endl;
        cout << "------------------------------------\n";
    }
};

class Bike : public Vehicle {
public:
    Bike(string id, string mdl, double rate)
        : Vehicle(id, mdl, rate) {}

    double calculateRent() const {
        double total = getRate() * getRentalDays();

        if (getRentalDays() >= 5)
            total = total - (total * 0.05);

        return total + 50;
    }

    string getType() const {
        return "Bike";
    }

    void display() const {
        Vehicle::display();

        cout << "Helmet Fee      : Rs. 50.00" << endl;

        if (getRentalDays() >= 5)
            cout << "Discount        : 5%" << endl;
        else
            cout << "Discount        : None" << endl;

        cout << "Total Charges   : Rs. "
             << calculateRent() << endl;
        cout << "------------------------------------\n";
    }
};

string readText(string prompt) {
    string text;

    while (true) {
        cout << prompt;
        getline(cin, text);

        if (text.length() > 0)
            return text;

        cout << "Input cannot be empty. Try again.\n";
    }
}

double readPositiveDouble(string prompt) {
    double value;

    while (true) {
        cout << prompt;

        if (cin >> value && value > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Enter a number greater than 0.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readInt(string prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Please enter a whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "====== Vehicle Rental System ======\n";

    while (true) {
        cout << "\n1. Rent a Car\n";
        cout << "2. Rent a Bike\n";
        cout << "3. Exit\n";

        int choice = readInt("Enter choice: ");

        if (choice == 3) {
            cout << "Thank you for using the system!\n";
            break;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Select 1, 2 or 3.\n";
            continue;
        }

        string id = readText("Enter Vehicle ID : ");
        string model = readText("Enter Model      : ");
        double rate = readPositiveDouble("Enter Rate/day (Rs.): ");

        Vehicle *vehicle;

        if (choice == 1)
            vehicle = new Car(id, model, rate);
        else
            vehicle = new Bike(id, model, rate);

        int days;

        while (true) {
            days = readInt("Enter rental days (1-30): ");

            if (days >= MIN_DAYS && days <= MAX_DAYS)
                break;

            cout << "Rental duration must be between 1 and 30 days.\n";
        }

        vehicle->setRentalDays(days);
        vehicle->display();

        delete vehicle;
    }

    return 0;
}

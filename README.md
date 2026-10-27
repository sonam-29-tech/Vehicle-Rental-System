# Vehicle Rental System (C++)

A simple console application that demonstrates **single inheritance** in C++ by modelling cars and bikes and calculating rental charges based on vehicle type.

## Features

- Base `Vehicle` class with common details: vehicle ID, model, rate per day and rental duration
- `Car` and `Bike` classes derived from `Vehicle` (single inheritance)
- Different rental charge logic for each vehicle type (function overriding)
- Displays vehicle details, rental duration, rate and total charges
- Input validation for rental duration and other inputs (no crashes on invalid input)

## OOP Concepts Used

| Concept | Where it is used |
|---|---|
| Classes and objects | `Vehicle`, `Car`, `Bike` |
| Constructors | Each class has a constructor; derived classes call the base constructor |
| Encapsulation | Data members are `private`, accessed through getters/setters |
| Single inheritance | `Car : public Vehicle`, `Bike : public Vehicle` |
| Function overriding | `calculateRent()`, `getType()` and `display()` are `virtual` and overridden |
| Polymorphism | A `Vehicle` pointer holds a `Car` or `Bike` object |

## Rental Charge Rules

| Vehicle | Formula |
|---|---|
| Car | `rate × days`, **10% discount** if days ≥ 7, plus **Rs. 200** insurance fee |
| Bike | `rate × days`, **5% discount** if days ≥ 5, plus **Rs. 50** helmet fee |

## Validation

- Rental duration must be between **1 and 30** days (throws `invalid_argument`, handled with `try/catch`)
- Rate must be a number greater than 0
- Non-numeric input is rejected and the user is asked again
- Empty ID/model is not allowed

## Project Structure

```
vehicle-rental-system/
├── main.cpp
└── README.md
```

## How to Compile and Run

Requires a compiler with C++14 support or later (g++, clang, MSVC).

```bash
g++ -std=c++14 main.cpp -o rental
./rental          # Windows: rental.exe
```

## Sample Output

```
====== Vehicle Rental System ======

1. Rent a Car
2. Rent a Bike
3. Exit
Enter choice: 1
Enter Vehicle ID : C101
Enter Model      : Honda City
Enter Rate/day (Rs.): 1500
Enter rental days (1-30): 0
Error: Rental duration must be between 1 and 30 days.
Enter rental days (1-30): 7

------------ Rental Details ------------
Type            : Car
Vehicle ID      : C101
Model           : Honda City
Rental Duration : 7 day(s)
Rate per day    : Rs. 1500.00
Insurance fee   : Rs. 200.00
Discount        : 10%
Total Charges   : Rs. 9650.00
----------------------------------------
```

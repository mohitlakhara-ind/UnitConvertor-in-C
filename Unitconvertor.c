#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 20

// Function prototypes
void printMenu();
void convertTemperature();
void convertLength();
void convertVolume();
void convertWeight();
void convertArea();
void convertSpeed();
void convertTime();
void convertEnergy();
void convertCurrency();
void showHistory();
void addHistory(const char* entry);
float getPositiveFloat(const char* prompt);
float getConversionRate(const char* currency);
void setPrecision();

// Global variables
char history[MAX_HISTORY][200];
int historyIndex = 0;
int precision = 2;

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice (1-11, or 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch(choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                convertLength();
                break;
            case 3:
                convertVolume();
                break;
            case 4:
                convertWeight();
                break;
            case 5:
                convertArea();
                break;
            case 6:
                convertSpeed();
                break;
            case 7:
                convertTime();
                break;
            case 8:
                convertEnergy();
                break;
            case 9:
                convertCurrency();
                break;
            case 10:
                setPrecision();
                break;
            case 11:
                showHistory();
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
}

// Print the menu
void printMenu() {
    printf("\nUnit Converter\n");
    printf("1. Temperature (Celsius, Fahrenheit, Kelvin)\n");
    printf("2. Length (Meters, Centimeters, Kilometers, Miles, Inches, Feet)\n");
    printf("3. Volume (Liters, Milliliters, Gallons, Cubic Meters, Cubic Feet)\n");
    printf("4. Weight (Kilograms, Grams, Pounds, Ounces)\n");
    printf("5. Area (Square Meters, Square Kilometers, Square Feet, Acres, Hectares)\n");
    printf("6. Speed (Kilometers/Hour, Miles/Hour, Meters/Second, Knots)\n");
    printf("7. Time (Seconds, Minutes, Hours, Days)\n");
    printf("8. Energy (Joules, Kilojoules, Calories, Kilowatt-hours)\n");
    printf("9. Currency (USD, INR, EUR, GBP, Custom)\n");
    printf("10. Set Conversion Precision\n");
    printf("11. Show History\n");
    printf("0. Exit\n");
}

// Convert Temperature between Celsius, Fahrenheit, and Kelvin
void convertTemperature() {
    int choice;
    float value;

    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter temperature in Celsius: ");
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 9/5) + 32);
            addHistory("Celsius to Fahrenheit");
            break;
        case 2:
            value = getPositiveFloat("Enter temperature in Fahrenheit: ");
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) * 5/9);
            addHistory("Fahrenheit to Celsius");
            break;
        case 3:
            value = getPositiveFloat("Enter temperature in Celsius: ");
            printf("%.2f Celsius = %.2f Kelvin\n", value, value + 273.15);
            addHistory("Celsius to Kelvin");
            break;
        case 4:
            value = getPositiveFloat("Enter temperature in Kelvin: ");
            printf("%.2f Kelvin = %.2f Celsius\n", value, value - 273.15);
            addHistory("Kelvin to Celsius");
            break;
        case 5:
            value = getPositiveFloat("Enter temperature in Fahrenheit: ");
            printf("%.2f Fahrenheit = %.2f Kelvin\n", value, (value + 459.67) * 5/9);
            addHistory("Fahrenheit to Kelvin");
            break;
        case 6:
            value = getPositiveFloat("Enter temperature in Kelvin: ");
            printf("%.2f Kelvin = %.2f Fahrenheit\n", value, (value * 9/5) - 459.67);
            addHistory("Kelvin to Fahrenheit");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Convert Length between various units
void convertLength() {
    int choice;
    float value;

    printf("1. Meters to Centimeters\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Inches to Centimeters\n");
    printf("5. Feet to Meters\n");
    printf("6. Centimeters to Inches\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter length in Meters: ");
            printf("%.2f Meters = %.2f Centimeters\n", value, value * 100);
            addHistory("Meters to Centimeters");
            break;
        case 2:
            value = getPositiveFloat("Enter length in Kilometers: ");
            printf("%.2f Kilometers = %.2f Meters\n", value, value * 1000);
            addHistory("Kilometers to Meters");
            break;
        case 3:
            value = getPositiveFloat("Enter length in Miles: ");
            printf("%.2f Miles = %.2f Kilometers\n", value, value * 1.60934);
            addHistory("Miles to Kilometers");
            break;
        case 4:
            value = getPositiveFloat("Enter length in Inches: ");
            printf("%.2f Inches = %.2f Centimeters\n", value, value * 2.54);
            addHistory("Inches to Centimeters");
            break;
        case 5:
            value = getPositiveFloat("Enter length in Feet: ");
            printf("%.2f Feet = %.2f Meters\n", value, value * 0.3048);
            addHistory("Feet to Meters");
            break;
        case 6:
            value = getPositiveFloat("Enter length in Centimeters: ");
            printf("%.2f Centimeters = %.2f Inches\n", value, value / 2.54);
            addHistory("Centimeters to Inches");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Convert Volume between various units
void convertVolume() {
    int choice;
    float value;

    printf("1. Liters to Milliliters\n");
    printf("2. Gallons to Liters\n");
    printf("3. Cubic Meters to Liters\n");
    printf("4. Cubic Feet to Liters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter volume in Liters: ");
            printf("%.2f Liters = %.2f Milliliters\n", value, value * 1000);
            addHistory("Liters to Milliliters");
            break;
        case 2:
            value = getPositiveFloat("Enter volume in Gallons: ");
            printf("%.2f Gallons = %.2f Liters\n", value, value * 3.78541);
            addHistory("Gallons to Liters");
            break;
        case 3:
            value = getPositiveFloat("Enter volume in Cubic Meters: ");
            printf("%.2f Cubic Meters = %.2f Liters\n", value, value * 1000);
            addHistory("Cubic Meters to Liters");
            break;
        case 4:
            value = getPositiveFloat("Enter volume in Cubic Feet: ");
            printf("%.2f Cubic Feet = %.2f Liters\n", value, value * 28.3168);
            addHistory("Cubic Feet to Liters");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Convert Weight between various units
void convertWeight() {
    int choice;
    float value;

    printf("1. Kilograms to Grams\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Grams to Ounces\n");
    printf("4. Pounds to Kilograms\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter weight in Kilograms: ");
            printf("%.2f Kilograms = %.2f Grams\n", value, value * 1000);
            addHistory("Kilograms to Grams");
            break;
        case 2:
            value = getPositiveFloat("Enter weight in Kilograms: ");
            printf("%.2f Kilograms = %.2f Pounds\n", value, value * 2.20462);
            addHistory("Kilograms to Pounds");
            break;
        case 3:
            value = getPositiveFloat("Enter weight in Grams: ");
            printf("%.2f Grams = %.2f Ounces\n", value, value * 0.035274);
            addHistory("Grams to Ounces");
            break;
        case 4:
            value = getPositiveFloat("Enter weight in Pounds: ");
            printf("%.2f Pounds = %.2f Kilograms\n", value, value * 0.453592);
            addHistory("Pounds to Kilograms");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Convert Area between various units
void convertArea() {
    int choice;
    float value;

    printf("1. Square Meters to Square Feet\n");
    printf("2. Square Kilometers to Square Miles\n");
    printf("3. Acres to Square Meters\n");
    printf("4. Hectares to Acres\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter area in Square Meters: ");
            printf("%.2f Square Meters = %.2f Square Feet\n", value, value * 10.7639);
            addHistory("Square Meters to Square Feet");
            break;
        case 2:
            value = getPositiveFloat("Enter area in Square Kilometers: ");
            printf("%.2f Square Kilometers = %.2f Square Miles\n", value, value * 0.386102);
            addHistory("Square Kilometers to Square Miles");
            break;
        case 3:
            value = getPositiveFloat("Enter area in Acres: ");
            printf("%.2f Acres = %.2f Square Meters\n", value, value * 4046.86);
            addHistory("Acres to Square Meters");
            break;
        case 4:
            value = getPositiveFloat("Enter area in Hectares: ");
            printf("%.2f Hectares = %.2f Acres\n", value, value * 2.47105);
            addHistory("Hectares to Acres");
            break;
        default:
            printf("Invalid choice.\n");
    }
}
// Convert Speed between various units
void convertSpeed() {
    int choice;
    float value;

    printf("1. Kilometers/Hour to Miles/Hour\n");
    printf("2. Miles/Hour to Kilometers/Hour\n");
    printf("3. Meters/Second to Kilometers/Hour\n");
    printf("4. Knots to Miles/Hour\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter speed in Kilometers/Hour: ");
            printf("%.2f Kilometers/Hour = %.2f Miles/Hour\n", value, value * 0.621371);
            addHistory("Kilometers/Hour to Miles/Hour");
            break;
        case 2:
            value = getPositiveFloat("Enter speed in Miles/Hour: ");
            printf("%.2f Miles/Hour = %.2f Kilometers/Hour\n", value, value * 1.60934);
            addHistory("Miles/Hour to Kilometers/Hour");
            break;
        case 3:
            value = getPositiveFloat("Enter speed in Meters/Second: ");
            printf("%.2f Meters/Second = %.2f Kilometers/Hour\n", value, value * 3.6);
            addHistory("Meters/Second to Kilometers/Hour");
            break;
        case 4:
            value = getPositiveFloat("Enter speed in Knots: ");
            printf("%.2f Knots = %.2f Miles/Hour\n", value, value * 1.15078);
            addHistory("Knots to Miles/Hour");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Convert Time between various units
void convertTime() {
    int choice;
    float value;

    printf("1. Seconds to Minutes\n");
    printf("2. Minutes to Hours\n");
    printf("3. Hours to Days\n");
    printf("4. Days to Hours\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter time in Seconds: ");
            printf("%.2f Seconds = %.2f Minutes\n", value, value / 60);
            addHistory("Seconds to Minutes");
            break;
        case 2:
            value = getPositiveFloat("Enter time in Minutes: ");
            printf("%.2f Minutes = %.2f Hours\n", value, value / 60);
            addHistory("Minutes to Hours");
            break;
        case 3:
            value = getPositiveFloat("Enter time in Hours: ");
            printf("%.2f Hours = %.2f Days\n", value, value / 24);
            addHistory("Hours to Days");
            break;
        case 4:
            value = getPositiveFloat("Enter time in Days: ");
            printf("%.2f Days = %.2f Hours\n", value, value * 24);
            addHistory("Days to Hours");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Convert Energy between various units
void convertEnergy() {
    int choice;
    float value;

    printf("1. Joules to Kilojoules\n");
    printf("2. Kilojoules to Calories\n");
    printf("3. Calories to Kilowatt-hours\n");
    printf("4. Kilowatt-hours to Joules\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            value = getPositiveFloat("Enter energy in Joules: ");
            printf("%.2f Joules = %.2f Kilojoules\n", value, value / 1000);
            addHistory("Joules to Kilojoules");
            break;
        case 2:
            value = getPositiveFloat("Enter energy in Kilojoules: ");
            printf("%.2f Kilojoules = %.2f Calories\n", value, value * 239.006);
            addHistory("Kilojoules to Calories");
            break;
        case 3:
            value = getPositiveFloat("Enter energy in Calories: ");
            printf("%.2f Calories = %.2f Kilowatt-hours\n", value, value * 1.16222e-6);
            addHistory("Calories to Kilowatt-hours");
            break;
        case 4:
            value = getPositiveFloat("Enter energy in Kilowatt-hours: ");
            printf("%.2f Kilowatt-hours = %.2f Joules\n", value, value * 3.6e6);
            addHistory("Kilowatt-hours to Joules");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Convert Currency between various units
void convertCurrency() {
    int choice;
    float value, rate;

    printf("1. USD to INR\n");
    printf("2. EUR to USD\n");
    printf("3. GBP to EUR\n");
    printf("4. Custom Currency Conversion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            rate = getConversionRate("Enter conversion rate for USD to INR: ");
            value = getPositiveFloat("Enter amount in USD: ");
            printf("%.2f USD = %.2f INR\n", value, value * rate);
            addHistory("USD to INR");
            break;
        case 2:
            rate = getConversionRate("Enter conversion rate for EUR to USD: ");
            value = getPositiveFloat("Enter amount in EUR: ");
            printf("%.2f EUR = %.2f USD\n", value, value * rate);
            addHistory("EUR to USD");
            break;
        case 3:
            rate = getConversionRate("Enter conversion rate for GBP to EUR: ");
            value = getPositiveFloat("Enter amount in GBP: ");
            printf("%.2f GBP = %.2f EUR\n", value, value * rate);
            addHistory("GBP to EUR");
            break;
        case 4:
            rate = getConversionRate("Enter conversion rate for Custom Currency to USD: ");
            value = getPositiveFloat("Enter amount in Custom Currency: ");
            printf("%.2f Custom Currency = %.2f USD\n", value, value * rate);
            addHistory("Custom Currency Conversion");
            break;
        default:
            printf("Invalid choice.\n");
    }
}


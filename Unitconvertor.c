#include <stdio.h>
#include <string.h>

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

float getPositiveFloat(const char* prompt);
float getConversionRate(const char* currency);

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice (1-9, or 0 to exit): ");
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
    printf("1. Temperature (Celsius to Fahrenheit)\n");
    printf("2. Length (Meters to Centimeters)\n");
    printf("3. Volume (Liters to Milliliters)\n");
    printf("4. Weight (Kilograms to Pounds)\n");
    printf("5. Area (Square Meters to Square Feet)\n");
    printf("6. Speed (Kilometers per Hour to Meters per Second)\n");
    printf("7. Time (Hours to Minutes)\n");
    printf("8. Energy (Joules to Calories)\n");
    printf("9. Currency (Dollar to Rupee, Euro, Yen)\n");
    printf("0. Exit\n");
}

// Convert Celsius to Fahrenheit
void convertTemperature() {
    float celsius = getPositiveFloat("Enter temperature in Celsius: ");
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
}

// Convert Meters to Centimeters
void convertLength() {
    float meters = getPositiveFloat("Enter length in Meters: ");
    float centimeters = meters * 100;
    printf("%.2f Meters = %.2f Centimeters\n", meters, centimeters);
}

// Convert Liters to Milliliters
void convertVolume() {
    float liters = getPositiveFloat("Enter volume in Liters: ");
    float milliliters = liters * 1000;
    printf("%.2f Liters = %.2f Milliliters\n", liters, milliliters);
}

// Convert Kilograms to Pounds
void convertWeight() {
    float kilograms = getPositiveFloat("Enter weight in Kilograms: ");
    float pounds = kilograms * 2.20462;
    printf("%.2f Kilograms = %.2f Pounds\n", kilograms, pounds);
}

// Convert Square Meters to Square Feet
void convertArea() {
    float squareMeters = getPositiveFloat("Enter area in Square Meters: ");
    float squareFeet = squareMeters * 10.7639;
    printf("%.2f Square Meters = %.2f Square Feet\n", squareMeters, squareFeet);
}

// Convert Kilometers per Hour to Meters per Second
void convertSpeed() {
    float kmph = getPositiveFloat("Enter speed in Kilometers per Hour: ");
    float mps = kmph * 0.277778;
    printf("%.2f Kilometers per Hour = %.2f Meters per Second\n", kmph, mps);
}

// Convert Hours to Minutes
void convertTime() {
    float hours = getPositiveFloat("Enter time in Hours: ");
    float minutes = hours * 60;
    printf("%.2f Hours = %.2f Minutes\n", hours, minutes);
}

// Convert Joules to Calories
void convertEnergy() {
    float joules = getPositiveFloat("Enter energy in Joules: ");
    float calories = joules * 0.239006;
    printf("%.2f Joules = %.2f Calories\n", joules, calories);
}

// Convert Dollars to another currency
void convertCurrency() {
    float dollars = getPositiveFloat("Enter amount in Dollars: ");
    char currency[10];
    
    printf("Enter currency to convert to (Rupee, Euro, Yen): ");
    scanf("%s", currency);

    float rate = getConversionRate(currency);
    if (rate > 0) {
        float converted = dollars * rate;
        printf("%.2f Dollars = %.2f %s\n", dollars, converted, currency);
    } else {
        printf("Invalid currency.\n");
    }
}

// Get a positive float value from the user
float getPositiveFloat(const char* prompt) {
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1 || value < 0) {
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n'); // Clear invalid input
    }
    return value;
}

// Get conversion rate for a given currency
float getConversionRate(const char* currency) {
    if (strcmp(currency, "Rupee") == 0) {
        return 83.00; // Example rate, Dollar to Rupee
    } else if (strcmp(currency, "Euro") == 0) {
        return 0.92; // Example rate, Dollar to Euro
    } else if (strcmp(currency, "Yen") == 0) {
        return 150.00; // Example rate, Dollar to Yen
    } else {
        return -1; // Invalid currency
    }
}


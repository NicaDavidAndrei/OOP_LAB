// T2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdexcept> // for exceptions
#include <sstream>   // for stringstream
using namespace std;

// Function to convert string to float
float stringToFloat(const string& str) {
    stringstream ss(str);
    float num;
    if (!(ss >> num)) {  // Try converting to float
        throw invalid_argument("Invalid input: Not a number");
    }
    return num;
}

// Function to calculate area of rectangle
float calculateAreaRect(float length, float width) {
    return length * width;
}

// Function pointer definition
typedef float (*AreaFunc)(float, float);

// Main function to compute the area, handling exceptions
float computeArea(const string& input1, const string& input2 = "") {
    try {
        // Convert inputs from strings to float
        float length = stringToFloat(input1);
        float width = length;  // Default for square

        if (!input2.empty()) {  // If second input is provided (rectangle)
            width = stringToFloat(input2);
        }

        // Use function pointer to calculate area
        AreaFunc areaFunc = &calculateAreaRect;
        return areaFunc(length, width);

    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return -1;  // Return -1 for invalid input
    }
}

int main() {
    string lengthInput, widthInput;

    cout << "Enter the length: ";
    cin >> lengthInput;

    // Get width input from the user (optional for square)
    cout << "Enter the width (press Enter for square): ";
    cin.ignore();  // Ignore any leftover newline from previous input
    getline(cin, widthInput);

    // Compute the area and display the result
    if (widthInput.empty()) {
        cout << "Square area: " << computeArea(lengthInput) << endl;
    }
    else {
        cout << "Rectangle area: " << computeArea(lengthInput, widthInput) << endl;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
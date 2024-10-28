// TemperatureConverter.cpp or OOPLab1.cpp

#include <iostream>
#include "OOPLab1.h"

using namespace std;


//Define USE_HEADER1 and set its value to 1
//if USE_HEADER1 IS 1, will display f() from header1.h
//if USE_HEADER1 IS 0, will display f() from header2.h

#define USE_HEADER1 1
#define DEBUG 1

//Include either header1.h or header2.h based on USE_HEADER1
#ifdef USE_HEADER1

#if USE_HEADER1 == 1
#include "header1.h"

#else
#include "header2.h"
#endif

#else
#include "header2.h"
#endif


// Debug function - Optional_1
#ifdef DEBUG
void debug_message()
{
    std::cout << "\n [DEBUG] : Option selected for temperature conversion!\n" << std::endl;
}

void debug_final()
{
    std::cout << "\n [DEBUG] : Program ended!" << std::endl;
}
#endif

//OS message - Optional_2
void os_message()
{
#ifdef _WIN32
    cout << "Hello, Windows!" << endl;
#elif _linux_
    cout << "Hello, Linux!" << endl;
#else
    cout << "Hello, Unknown Operating System!" << endl;
#endif
}


int main()
{
    double temperature;
    char option;

    // Call the function f() from the included header
    // This will call the function f() from either header1.h or header2.h
    f();

    cout << "\n\n";
    os_message();
    cout << "\n";

    cout << "\n\n";

    cout << "Do you want to convert from Celsius or Fahrenheit? \n\n Possible solutions are: \n Celsius - C or c \n Fahrenheit - F or f \n\n Your choice is : ";

    cin >> option;


#ifdef DEBUG
    debug_message();
#endif


    if (option == 'C' || option == 'c')
    {
        //Celsius to Fahrenheit
        cout << " Input temperature in Celsius: ";
        cin >> temperature;
        double fahrenheit = CelsiusToFahrenheit(temperature);
        cout << " Fahrenheit obtained temperature is " << fahrenheit << endl;
    }

    else

        if (option == 'F' || option == 'f')
        {
            //Fahrenheit to Celsius
            cout << " Input temperature in Fahrenheit: ";
            cin >> temperature;
            double celsius = FahrenheitToCelsius(temperature);
            cout << " Celsius obtained temperature is " << celsius << endl;
            cout << "\n";

        }

        else
            cout << "Invalid option selected! Choose something else!" << endl;

#ifdef DEBUG
    debug_final();
#endif

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
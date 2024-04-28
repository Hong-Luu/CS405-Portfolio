// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>

// Custom exception derived from std::exception
class MyCustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "My custom exception occurred!";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    throw std::runtime_error("Standard exception occured!"); // throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    
    // Wrap the call
    try {
        if (do_even_more_custom_application_logic())
        {
            do_even_more_custom_application_logic();
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    
    // catches std::exception, displays a message and the exception.what()
    catch (const std::exception& ex) {
        std::cout << "Caught std::exception: " << ex.what() << std::endl;
    }


    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    throw MyCustomException(); // throw custom exception


    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    if (den == 0) {
        // Throwing an exception to deal with divide by zero errors using a standard C++ defined exception
        throw std::invalid_argument("Division by zero error!");
    }

    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.
    try {
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "Caught exception in division: " << ex.what() << std::endl;
        throw; // rethrowing the exception to be caught in the main function
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // Wrap the whole main function
    try {
        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }
    catch (const MyCustomException& ex) {
        std::cout << "Caught custom exception in main: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Caught exception in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "Caught an uncaught exception in main!" << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
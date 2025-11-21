// Created by: Shem
// Created on: 11/21/2025
// This program generates a random number and asks the user to guess it.
// It uses a loop, handles invalid input safely with try-catch, and prints
// a cute cat when guessed correctly.
// Copyright 2025 Shem

#include <cstdlib>  // for rand_r
#include <ctime>    // for time()
#include <iostream>
#include <string>

int main() {
    // Initialize seed for rand_r
    unsigned int seed = (unsigned)time(NULL);

    // Generate a random number between 1 and 10 using rand_r
    int correct_number = rand_r(&seed) % 10 + 1;

    std::string userGuessAsString;
    int userGuessAsInt;

    while (true) {
        std::cout << "Enter your guess (1 - 10): ";
        std::cin >> userGuessAsString;

        try {
            // Convert the user's guess to an int
            userGuessAsInt = std::stoi(userGuessAsString);

            // Check if the guess is in range
            if (userGuessAsInt < 1 || userGuessAsInt > 10) {
                std::cout << "Please enter a number between 1 and 10.\n";
            } else if (userGuessAsInt == correct_number) {
                std::cout << "You guessed it! The number was "
                          << correct_number << "\n";
                std::cout << "Thank you for playing\n";
                std::cout << " /\\_/\\  \n";
                std::cout << "( ^_^ )\n";
                std::cout << " > ^ < \n";
                break;  // Exit the loop
            } else {
                std::cout << "Wrong guess, try again!\n";
            }
        } catch (std::invalid_argument) {
            // The user did not enter an integer
            std::cout << userGuessAsString << " is not an integer.\n";
        }
    }
}

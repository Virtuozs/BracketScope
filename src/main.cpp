#include <iostream>
#include <limits>
#include <sstream>
#include "parenthesesChecker.hpp"
#include <utilities.hpp>

void printMainMenu() {
    std::cout << "\n=== Parentheses Checker ===\n";
    std::cout << "1. Check String\n";
    std::cout << "2. Check File\n";
    std::cout << "3. View Checked Files\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

void printErrors(const ParenthesesChecker& checker, const std::string& input) {
    if (checker.isValid()) {
        std::cout << "\nResult: VALID\n";
        return;
    }

    const auto& errors = checker.getErrorInfo();
    std::cout << "\nResult: INVALID - Found " << errors.size() << " error(s):\n";
    
    std::cout << "\nInput:\n" << input << "\n\n";
    
    std::string markers(input.size(), ' ');
    for (const auto& error : errors) {
        if (error.position < markers.size()) {
            markers[error.position] = '^';
        }
    }
    std::cout << markers << "\n";
    
    for (const auto& error : errors) {
        std::cout << "- Position " << error.position << ": " << error.message << "\n";
    }
}

void checkString(ParenthesesChecker& checker) {
    utilities::clearScreen();
    std::string input;
    std::cout << "Enter string to check: ";
    std::getline(std::cin, input);
    
    checker.check(input);
    printErrors(checker, input);
    utilities::pressAnyKeyToContinue();
}

void checkFile(ParenthesesChecker& checker) {
    utilities::clearScreen();
    std::string filename;
    std::cout << "Enter filename to check: ";
    std::getline(std::cin, filename);
    
    try {
        checker.checkFromFile(filename);
        printErrors(checker, checker.getCheckedFiles().back());
    } catch (const std::runtime_error& e) {
        std::cout << "\nError: " << e.what() << "\n";
    }
    utilities::pressAnyKeyToContinue();
}

void viewCheckedFiles(const ParenthesesChecker& checker) {
    utilities::clearScreen();
    const auto& files = checker.getCheckedFiles();
    
    if (files.empty()) {
        std::cout << "No files have been checked yet.\n";
    } else {
        std::cout << "Previously checked files:\n";
        for (const auto& file : files) {
            std::cout << " - " << file << "\n";
        }
    }
    utilities::pressAnyKeyToContinue();
}

int main() {
    ParenthesesChecker checker;
    int choice;

    do {
        utilities::clearScreen();
        printMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                checkString(checker);
                break;
            case 2:
                checkFile(checker);
                break;
            case 3:
                viewCheckedFiles(checker);
                break;
            case 4:
                utilities::pressAnyKeyToContinue("Exiting...");
                break;
            default:
                utilities::pressAnyKeyToContinue("Invalid option...");
        }
    } while (choice != 4);

    return 0;
}
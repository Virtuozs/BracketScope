#include <utilities.hpp>
#include <iostream>

void utilities::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void utilities::pressAnyKeyToContinue(const std::string& customMessage){
    if(customMessage.empty()){
        std::cout << "Press any key to continue ...";
    }else{
        std::cout << customMessage;
    }

    std::cin.ignore();
}
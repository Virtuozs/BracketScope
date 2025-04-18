#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>

class utilities
{
    public:
        static void clearScreen();
        static void pressAnyKeyToContinue(const std::string& customMessage="");   
};

#endif
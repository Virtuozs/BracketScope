#include "parenthesesChecker.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

bool ParenthesesChecker::isOpeningBracket(char ch) const {
    return ch == '(' || ch == '{' || ch == '[';
}

bool ParenthesesChecker::isClosingBracket(char ch) const {
    return ch == ')' || ch == '}' || ch == ']';
}

char ParenthesesChecker::getMatchingOpening(char closing) const {
    switch (closing) {
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
        default: return '\0';
    }
}

std::string ParenthesesChecker::readFileContent(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    checkedFiles.push_back(filePath);
    return buffer.str();
}

void ParenthesesChecker::check(const std::string& expression) {
    clear();
    
    for (size_t i = 0; i < expression.size(); ++i) {
        char ch = expression[i];
        
        if (isOpeningBracket(ch)) {
            bracketStack.push_back({ch, i});
        } 
        else if (isClosingBracket(ch)) {
            if (bracketStack.empty()) {
                errors.push_back({i, "Unmatched closing bracket '" + std::string(1, ch) + "'"});
                continue;
            }
            
            auto top = bracketStack.back();
            char expectedOpening = getMatchingOpening(ch);
            
            if (top.bracket != expectedOpening) {
                errors.push_back({i, "Mismatched brackets '" + std::string(1, top.bracket) + 
                                    "' and '" + std::string(1, ch) + "'"});
            }
            
            bracketStack.pop_back();
        }
    }

    for (const auto& bp : bracketStack) {
        errors.push_back({bp.position, "Unmatched opening bracket '" + 
                          std::string(1, bp.bracket) + "'"});
    }
}

void ParenthesesChecker::checkFromFile(const std::string& filePath) {
    std::string content = readFileContent(filePath);
    check(content);
}

bool ParenthesesChecker::isValid() const {
    return errors.empty();
}

const std::vector<ParenthesesChecker::ErrorInfo>& ParenthesesChecker::getErrorInfo() const {
    return errors;
}

const std::vector<std::string>& ParenthesesChecker::getCheckedFiles() const {
    return checkedFiles;
}

void ParenthesesChecker::clear() {
    errors.clear();
    bracketStack.clear();
}
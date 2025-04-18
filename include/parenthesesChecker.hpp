#ifndef PARENTHESESCHECKER_HPP
#define PARENTHESESCHECKER_HPP

#include <stack>
#include <string>
#include <vector>
#include <utility>

class ParenthesesChecker {
public:
    struct ErrorInfo {
        size_t position;
        std::string message;
    };

    void check(const std::string& expression);
    void checkFromFile(const std::string& filePath);
    bool isValid() const;
    const std::vector<ErrorInfo>& getErrorInfo() const;
    const std::vector<std::string>& getCheckedFiles() const;
    void clear();

private:
    struct StackItem {
        char bracket;
        size_t position;
    };

    std::stack<StackItem> bracketStack;
    std::vector<ErrorInfo> errors;
    std::vector<std::string> checkedFiles;

    bool isOpeningBracket(char ch) const;
    bool isClosingBracket(char ch) const;
    char getMatchingOpening(char closing) const;
    std::string readFileContent(const std::string& filePath);
};

#endif
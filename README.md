## Parentheses Checker

A C++ application that validates balanced parentheses, brackets, and braces in both strings and files. Built using Object-Oriented Programming principles with a stack-based algorithm to better understand how the stack works.

## Features

### ✅ Multi-Bracket Support
Validates three types of brackets: (), {}, and []

### 📝 Dual Input Modes
- Direct string input
- File content checking

### 🔍 Comprehensive Error Detection
- Detects all mismatched brackets in a single pass
- Identifies unmatched opening/closing brackets

## Technical Details

### Algorithm: Stack-based validation

### Data Structures:
- std::stack for bracket tracking
- std::vector for error collection

### OOP Principles:
- Encapsulation of checking logic
- Separation of concerns
- Clear public interface

### 🛠️ Requirements
- C++17 or later
- g++ compiler
- Terminal/console environment
- make (for using the provided Makefile)

## 🧼 Future Improvements
- Shows exact error locations with caret (^) markers on file input
- Provides line numbers and column positions for file input

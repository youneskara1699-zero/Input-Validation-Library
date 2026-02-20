# Input & Validation Library - C++ Input Handling and Validation Suite

A robust, type-safe C++ library for handling user input with comprehensive validation capabilities. This library provides a clean, reusable interface for reading and validating various data types with built-in error handling and range checking.

## Features

### 📥 Input Handling
- Type-safe input reading for integers and floating-point numbers
- Automatic error recovery from invalid input
- Customizable error messages
- Stream buffer clearing to prevent input cascading

### ✅ Validation Utilities
- Range validation for numeric types (integers and doubles)
- Date validation with comprehensive checking
- Comparison operations for dates
- Leap year detection

### 🛡️ Error Prevention
- Input buffer clearing after each operation
- Protection against input stream failures
- Graceful handling of non-numeric input

## Class Structure

### `clsString` - Utility String Class
- Provides string splitting functionality for date parsing

### `clsDate` - Date Validation Class
- Date creation and manipulation
- Date validation logic
- Leap year calculations
- Date comparison operations

### `clsInputValidate` - Main Input/Validation Class
- Core input reading functionality
- Validation methods for numbers and dates
- Range checking utilities

## Installation

Simply include the header file in your C++ project:

```cpp
#include "InputValidationLibrary.cpp"

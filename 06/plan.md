# ! The code is compiled with the flag -std=c++98
# Map for C++ Module 06 - ex00: Scalar Converter

## Current State Analysis
- `ScalarConverter` class is partially implemented.
- `convert` method is static but relies on instantiating the class.
- Basic logic for `char` and `int` exists but is incomplete.
- `float` and `double` conversions are commented out.
- Special literals (`nan`, `inf`) are not handled.
- Class is currently instantiable (it shouldn't be according to typical C++ Module requirements for this exercise).

## Implementation Steps

### 1. Refactor `ScalarConverter` Architecture
- **Non-instantiable class**: Move constructor, copy constructor, assignment operator, and destructor to private.
- **Static methods**: Ensure all conversion and helper methods are `static`.
- **Header update**: Define types and helper functions for parsing.

### 2. Input Parsing Logic
Implement a robust way to identify the input type:
- **Special Literals**: Check for `nan`, `nanf`, `+inf`, `+inff`, `-inf`, `-inff` first.
- **Char**: Length 1 and not a digit.
- **Int**: Numeric string (can have leading +/-).
- **Float**: Numeric string with a decimal point and ending in 'f', or ending in 'f' (e.g., `42.0f`, `42f`).
- **Double**: Numeric string with a decimal point (e.g., `42.0`).

### 3. Conversion and Printing
For each identified type:
- Convert the string to the detected type using appropriate functions (`std::stoi`, `std::stof`, `std::stod`, or manual parsing for older C++ standards if required).
- From the source type, use `static_cast` to convert to the other three types.
- **Output formatting**:
    - **char**: Show character if displayable, "Non displayable" if not, or "impossible" if out of range or NaN.
    - **int**: Show value or "impossible" if out of range or NaN.
    - **float**: Show value with at least one decimal point (e.g., `42.0f`).
    - **double**: Show value with at least one decimal point (e.g., `42.0`).

### 4. Edge Case Handling
- **NaN/Inf**: Handle these specifically for `char` and `int` (always "impossible").
- **Overflow**: Check if the value fits in `int` or `char` before casting.

### 5. Verification
- Run with provided examples: `0`, `nan`, `42.0f`.
- Run with edge cases: `*`, `255`, `2147483647`, `2147483648`, `inf`.

## Next Action
- Modify `ScalarConverter.hpp` to make the class non-instantiable and methods static.
- Implement the parsing and conversion logic in `ScalarConverter.cpp`.

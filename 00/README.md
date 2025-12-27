# C++ Module 00 - Comprehensive Guide

## Overview
This module introduces you to **C++ basics**: namespaces, classes, member functions, stdio streams, initialization lists, static members, const, and fundamental OOP concepts. It's your first step into C++ from C.

---

## 📚 Core Concepts You Must Understand

### 1. **Namespaces**

Namespaces prevent name collisions by grouping identifiers under a unique name.

```cpp
#include <iostream>

namespace MyNamespace {
    int value = 42;
    void print() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}

int main() {
    std::cout << MyNamespace::value << std::endl;  // Access with ::
    MyNamespace::print();
    
    using namespace MyNamespace;  // Now can use without prefix
    print();  // Works now
    
    return 0;
}
```

**Key Points:**
- `std::` is the standard library namespace
- Use `::` (scope resolution operator) to access namespace members
- Avoid `using namespace std;` in headers (pollutes global scope)
- Good practice: Use explicit `std::` prefix

---

### 2. **Classes and Objects**

Classes are user-defined types that encapsulate data and functions.

```cpp
class Person {
private:
    std::string name;    // Private: only accessible inside class
    int age;

public:
    // Constructor
    Person(std::string n, int a) : name(n), age(a) {
    }
    
    // Member function (method)
    void introduce() {
        std::cout << "I'm " << name << ", " << age << " years old" << std::endl;
    }
    
    // Getter
    std::string getName() const {
        return name;
    }
    
    // Setter
    void setAge(int a) {
        age = a;
    }
};

int main() {
    Person person("Alice", 25);  // Create object
    person.introduce();           // Call method
    return 0;
}
```

**Access Specifiers:**
- `private`: Only accessible within the class (default for class)
- `public`: Accessible from anywhere
- `protected`: Accessible in class and derived classes

---

### 3. **Member Functions vs Regular Functions**

```cpp
class Calculator {
private:
    int result;

public:
    Calculator() : result(0) {}
    
    // Member function - operates on object data
    void add(int value) {
        result += value;  // Has access to 'result'
    }
    
    int getResult() const {
        return result;
    }
};

// Regular function - needs all data passed as parameters
int addNumbers(int a, int b) {
    return a + b;
}
```

**Key Difference:**
- Member functions have implicit access to object's data members
- Regular functions are standalone

---

### 4. **Constructors and Destructors**

```cpp
class Resource {
private:
    std::string name;

public:
    // Constructor - called when object is created
    Resource(std::string n) : name(n) {
        std::cout << "Resource " << name << " created" << std::endl;
    }
    
    // Destructor - called when object is destroyed
    ~Resource() {
        std::cout << "Resource " << name << " destroyed" << std::endl;
    }
};

int main() {
    Resource r1("A");
    {
        Resource r2("B");
    }  // r2 destroyed here
    
    return 0;
}  // r1 destroyed here
```

**Constructor Types:**
- **Default constructor**: No parameters
- **Parameterized constructor**: Takes arguments
- **Copy constructor**: Creates copy of another object

---

### 5. **Initialization Lists**

Preferred way to initialize member variables in constructors.

```cpp
class Point {
private:
    int x;
    int y;

public:
    // Bad: Assignment in constructor body
    Point(int xVal, int yVal) {
        x = xVal;  // Assignment, not initialization
        y = yVal;
    }
    
    // Good: Initialization list
    Point(int xVal, int yVal) : x(xVal), y(yVal) {
        // Members already initialized before body executes
    }
};
```

**Why Use Initialization Lists?**
- More efficient (direct initialization vs assignment)
- Required for const members
- Required for reference members
- Required for members without default constructors

---

### 6. **Const Keyword**

`const` makes values immutable.

```cpp
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) : balance(b) {}
    
    // Const member function - doesn't modify object state
    double getBalance() const {
        return balance;  // Can only read, not modify
    }
    
    // Non-const member function - can modify state
    void deposit(double amount) {
        balance += amount;
    }
};

int main() {
    const BankAccount account(1000);  // Const object
    
    std::cout << account.getBalance();  // OK - const function
    // account.deposit(100);  // ERROR - can't call non-const function on const object
    
    return 0;
}
```

**Const Usage:**
- `const int x = 5;` - const variable
- `int* const ptr;` - const pointer (can't change where it points)
- `const int* ptr;` - pointer to const (can't change value through pointer)
- `void func() const;` - const member function (can't modify object)

---

### 7. **Static Members**

Static members belong to the class, not individual objects.

```cpp
class Counter {
private:
    static int count;  // Shared by all objects
    int id;

public:
    Counter() {
        id = ++count;  // Each object gets unique ID
    }
    
    static int getCount() {  // Static member function
        return count;
        // Can't access non-static members (no 'this' pointer)
    }
    
    int getId() const {
        return id;
    }
};

// Must define static member outside class
int Counter::count = 0;

int main() {
    Counter c1, c2, c3;
    std::cout << "Total objects: " << Counter::getCount() << std::endl;  // 3
    std::cout << "c2 ID: " << c2.getId() << std::endl;  // 2
    return 0;
}
```

**Static vs Non-Static:**
- **Static**: Shared by all instances, accessed via class name
- **Non-Static**: Unique to each instance, accessed via object

---

### 8. **iostream (Input/Output Streams)**

C++ provides type-safe I/O through streams.

```cpp
#include <iostream>
#include <iomanip>  // For formatting
#include <string>

int main() {
    // Output
    std::cout << "Hello World" << std::endl;  // endl flushes buffer
    
    // Input
    std::string name;
    int age;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);  // Read line with spaces
    std::cout << "Enter age: ";
    std::cin >> age;  // Read single value
    
    // Formatting
    double pi = 3.14159265359;
    std::cout << std::fixed << std::setprecision(2);  // 2 decimal places
    std::cout << pi << std::endl;  // 3.14
    
    std::cout << std::setw(10) << std::right << "Right";  // Right-align in 10 chars
    std::cout << std::setw(10) << std::left << "Left";    // Left-align
    
    return 0;
}
```

**Common Manipulators:**
- `std::endl` - newline + flush
- `std::setw(n)` - set field width
- `std::left/right` - alignment
- `std::setprecision(n)` - decimal precision
- `std::fixed` - fixed-point notation

---

### 9. **String Class**

C++ `std::string` is safer and easier than C-style strings.

```cpp
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2 = " World";
    
    // Concatenation
    std::string str3 = str1 + str2;  // "Hello World"
    
    // Length
    std::cout << str3.length() << std::endl;  // 11
    
    // Access characters
    std::cout << str3[0] << std::endl;  // 'H'
    
    // Substring
    std::string sub = str3.substr(0, 5);  // "Hello"
    
    // Find
    size_t pos = str3.find("World");  // Returns position or std::string::npos
    
    // Compare
    if (str1 == "Hello") {
        std::cout << "Equal!" << std::endl;
    }
    
    // Empty check
    if (str1.empty()) {
        std::cout << "String is empty" << std::endl;
    }
    
    return 0;
}
```

---

### 10. **Header Files (.hpp) and Implementation (.cpp)**

**Header File (Person.hpp):**
```cpp
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a);  // Declaration only
    void introduce() const;
    std::string getName() const;
};

#endif
```

**Implementation File (Person.cpp):**
```cpp
#include "Person.hpp"
#include <iostream>

// Define member functions outside class
Person::Person(std::string n, int a) : name(n), age(a) {
}

void Person::introduce() const {
    std::cout << "I'm " << name << ", " << age << " years old" << std::endl;
}

std::string Person::getName() const {
    return name;
}
```

**Why Separate?**
- **Header**: Interface (declarations) - what the class can do
- **Implementation**: Definition - how it does it
- Allows compilation of only changed files
- Include guards (`#ifndef`) prevent multiple inclusion

---

## 🎯 Exercise Breakdown

### **Ex00: Megaphone**
**Concepts**: Command-line arguments, string manipulation, character conversion

**What to learn:**
- `argc` and `argv` handling
- `toupper()` for character conversion
- String iteration
- Basic I/O with `std::cout`

**Key point**: Simple warm-up to get comfortable with C++ syntax vs C.

---

### **Ex01: My Awesome PhoneBook**
**Concepts**: Classes, arrays, member functions, formatting, input handling

**What to learn:**
- Class design (PhoneBook and Contact)
- Fixed-size arrays (no dynamic allocation)
- Circular buffer concept (replacing oldest entry)
- Input validation (no empty fields)
- Output formatting with `std::setw()`, `std::left/right`
- String truncation
- Interactive command loop

**Key challenges:**
- Formatting table with pipes and aligned columns
- Handling input with spaces (`std::getline`)
- Index validation for SEARCH command

---

### **Ex02: The Job Of Your Dreams**
**Concepts**: Static members, timestamps, log analysis, reverse engineering

**What to learn:**
- Static member variables (shared across all instances)
- Static member functions
- Time formatting
- Reading existing code to understand requirements
- Matching exact output format

**Key challenges:**
- Understanding the log file format
- Implementing static member initialization
- Timestamp generation (optional: can be simplified)
- Matching destructor output exactly

---

## 🔧 Important C++ Basics

### C vs C++

| Feature | C | C++ |
|---------|---|-----|
| I/O | `printf`, `scanf` | `std::cout`, `std::cin` |
| Strings | `char*` | `std::string` |
| Memory | `malloc/free` | `new/delete` |
| Functions | Only functions | Functions + methods |
| Namespaces | No | Yes |
| Classes | No (only structs) | Yes |

---

### Common Mistakes to Avoid

❌ **Using `using namespace std;` everywhere**
```cpp
using namespace std;  // Pollutes global namespace
```

✅ **Use explicit `std::`**
```cpp
std::cout << "Better practice" << std::endl;
```

---

❌ **Forgetting const on read-only methods**
```cpp
std::string getName() {  // Should be const
    return name;
}
```

✅ **Mark read-only methods as const**
```cpp
std::string getName() const {
    return name;
}
```

---

❌ **Not using initialization lists**
```cpp
Person(std::string n) {
    name = n;  // Assignment, not initialization
}
```

✅ **Use initialization lists**
```cpp
Person(std::string n) : name(n) {
    // Better performance
}
```

---

## 📖 Key Takeaways

1. **OOP Basics**: Classes encapsulate data (private) and behavior (public methods)
2. **Const Correctness**: Use `const` for read-only operations
3. **Initialization Lists**: Preferred for initializing members
4. **Static Members**: Shared across all instances of a class
5. **iostream**: Type-safe I/O, better than C's printf/scanf
6. **std::string**: Much safer and easier than C-style strings
7. **Header Guards**: Prevent multiple inclusion issues
8. **Namespaces**: Organize code and prevent naming conflicts

---

## 🧪 Testing Principles

### Ex00
```bash
./megaphone "test TEST" "123"
./megaphone
./megaphone "multiple arguments"
```

### Ex01
- Test ADD with valid and empty fields
- Test SEARCH with empty phonebook
- Test SEARCH with out-of-range indices
- Test adding 9th contact (replaces oldest)
- Test formatting with short and long strings

### Ex02
- Compare output with provided log file
- Check static member initialization
- Verify constructor/destructor call order

---

## ✅ Evaluation Checklist

- [ ] All programs compile with `-Wall -Wextra -Werror -std=c++98`
- [ ] No forbidden functions used
- [ ] Proper class design (private data, public interface)
- [ ] Const correctness applied
- [ ] Header guards in all .hpp files
- [ ] Makefiles work correctly
- [ ] Input validation implemented
- [ ] Output formatting matches requirements
- [ ] Can explain class design decisions

---

Good luck with Module 00! This is your foundation for all C++ modules. 🚀

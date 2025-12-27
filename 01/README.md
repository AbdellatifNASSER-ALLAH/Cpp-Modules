# C++ Module 01 - Comprehensive Guide

## Overview
This module covers **memory allocation, pointers, references, and switch statements** in C++. These are fundamental concepts that distinguish C++ from C and higher-level languages.

---

## 📚 Core Concepts You Must Understand

### 1. **Stack vs Heap Memory Allocation**

#### Stack Allocation
- **Automatic memory management** - freed when going out of scope
- **Fast allocation/deallocation**
- **Limited size** (typically a few MB)
- **Local scope lifetime**

```cpp
void function() {
    Zombie stackZombie("Stack");  // Allocated on stack
    stackZombie.announce();       // Valid here
}  // stackZombie is automatically destroyed here
```

#### Heap Allocation
- **Manual memory management** - must use `delete` or `delete[]`
- **Slower allocation/deallocation**
- **Large size** (limited by system RAM)
- **Can persist beyond function scope**

```cpp
Zombie* heapZombie = new Zombie("Heap");  // Allocated on heap
heapZombie->announce();                    // Valid anywhere
delete heapZombie;                         // Must manually delete
```

**When to use what?**
- **Stack**: Small objects with known lifetime within a function
- **Heap**: Objects that need to outlive the function, large objects, or dynamic arrays

---

### 2. **Pointers vs References**

#### Pointers
- Can be `NULL` or reassigned
- Uses `*` for declaration and `->` for member access
- Can do pointer arithmetic
- Stores memory address

```cpp
Weapon* weaponPtr = &weapon;  // Can be NULL
weaponPtr->getType();         // Access with ->
weaponPtr = &anotherWeapon;   // Can reassign
```

#### References
- Must be initialized, cannot be NULL
- Uses `&` for declaration and `.` for member access
- Cannot be reassigned
- Acts as an alias to the original object

```cpp
Weapon& weaponRef = weapon;   // Must initialize, cannot be NULL
weaponRef.getType();          // Access with .
// weaponRef = anotherWeapon; // This modifies weapon's value, not the reference
```

**When to use what?**
- **Pointer**: When NULL is a valid state, or when you need to reassign
- **Reference**: When you always have a valid object and don't need reassignment

---

### 3. **The `new` and `delete` Keywords**

#### Single Object
```cpp
Zombie* z = new Zombie("Bob");  // Allocate one object
delete z;                        // Deallocate one object
```

#### Array of Objects
```cpp
Zombie* horde = new Zombie[10];  // Allocate array
delete[] horde;                   // Must use delete[] for arrays!
```

⚠️ **Critical**: Using `delete` instead of `delete[]` on arrays causes **undefined behavior**!

---

### 4. **Member Function Pointers**

Regular function pointers don't work for class member functions. C++ provides special syntax:

```cpp
class Harl {
    void debug();
    void info();
    
    void complain(std::string level) {
        // Define array of member function pointers
        void (Harl::*functions[])() = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
        };
        
        // Call through pointer
        (this->*functions[index])();
    }
};
```

**Syntax breakdown:**
- `void (Harl::*)()` - pointer to member function returning void, taking no parameters
- `&Harl::debug` - address of member function
- `(this->*ptr)()` - call member function through pointer

---

### 5. **Switch Statements**

More efficient than if-else chains for multiple discrete values:

```cpp
switch (level) {
    case DEBUG:
        // Fall through to execute all cases below
    case INFO:
        info();
        // Fall through
    case WARNING:
        warning();
        // Fall through
    case ERROR:
        error();
        break;
    default:
        std::cout << "Unknown level\n";
}
```

**Key points:**
- Cases fall through unless you use `break`
- `default` handles unmatched cases
- Only works with integral types (int, char, enum)

---

### 6. **File I/O in C++**

C++ provides `std::ifstream` and `std::ofstream` for file operations:

```cpp
#include <fstream>
#include <string>

std::ifstream inFile("input.txt");
std::ofstream outFile("output.txt");

std::string line;
while (std::getline(inFile, line)) {
    // Process line
    outFile << line << std::endl;
}

inFile.close();
outFile.close();
```

**String manipulation:**
```cpp
std::string::find(s1)        // Find position of s1
std::string::substr(pos, len) // Extract substring
std::string::append(str)      // Append string
str1 + str2                   // Concatenate
```

---

## 🎯 Exercise Breakdown

### **Ex00: BraiiiiiiinnnzzzZ**
**Concepts**: Stack vs Heap, constructors/destructors

- Learn when to allocate on stack vs heap
- `newZombie()`: Returns heap-allocated zombie (persists)
- `randomChump()`: Stack-allocated zombie (destroyed at function end)

### **Ex01: Moar brainz!**
**Concepts**: Dynamic arrays, `new[]` and `delete[]`

- Allocate multiple objects in single allocation
- Must use `delete[]` to properly deallocate array

### **Ex02: HI THIS IS BRAIN**
**Concepts**: Pointers vs references

- Understand that references are just safer pointer syntax
- See that all three access the same memory address

### **Ex03: Unnecessary violence**
**Concepts**: When to use pointers vs references

- `HumanA`: Always has weapon → use reference
- `HumanB`: May not have weapon → use pointer
- Demonstrates the design choice

### **Ex04: Sed is for losers**
**Concepts**: File I/O, string manipulation

- Read from file, write to new file
- Find and replace strings without using `std::string::replace()`
- Handle edge cases (empty file, s1 not found, etc.)

### **Ex05: Harl 2.0**
**Concepts**: Pointers to member functions

- Avoid long if-else chains
- Use array of function pointers for clean code
- Understand member function pointer syntax

### **Ex06: Harl filter**
**Concepts**: Switch statements with fall-through

- Filter log levels
- Use switch case fall-through feature intentionally
- Understand when switch is better than if-else

---

## 🔧 Compilation

Each exercise has a Makefile:
```bash
make        # Compile
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild from scratch
```

**Compiler flags used:**
- `-Wall -Wextra -Werror`: All warnings as errors
- `-std=c++98`: Use C++98 standard
- `-o`: Output executable name

---

## 🧪 Testing

### Memory Leak Detection
Always test with valgrind:
```bash
valgrind --leak-check=full ./executable
```

Should show:
```
All heap blocks were freed -- no leaks are possible
```

### Common Mistakes
1. ❌ Using `delete` on `new[]` allocated memory
2. ❌ Forgetting to delete heap-allocated objects
3. ❌ Dereferencing NULL pointers
4. ❌ Using references when pointer (nullable) is needed
5. ❌ Returning reference to local variable

---

## 📖 Key Takeaways

1. **Stack vs Heap**: Choose based on lifetime and size requirements
2. **References vs Pointers**: Use references when possible, pointers when needed
3. **Memory Management**: Always `delete` what you `new`, use `delete[]` for arrays
4. **RAII Principle**: Resource Acquisition Is Initialization - clean up in destructors
5. **Member Function Pointers**: Clean alternative to if-else chains
6. **Switch Statements**: Efficient for discrete values with intentional fall-through

---

## 🎓 Study Resources

- **Stack vs Heap**: Understanding memory layout and performance implications
- **Pointer vs Reference**: Both are addresses, references are safer
- **RAII**: Destructor-based cleanup is idiomatic C++
- **Member Functions**: Understanding the implicit `this` pointer
- **File Streams**: C++ iostream library for type-safe I/O

---

## ✅ Evaluation Checklist

- [ ] All programs compile with `-Wall -Wextra -Werror -std=c++98`
- [ ] No memory leaks (check with valgrind)
- [ ] Proper use of stack vs heap allocation
- [ ] Correct use of pointers vs references
- [ ] Destructors print messages for debugging
- [ ] Orthodox Canonical Form where applicable
- [ ] Makefiles include all required rules
- [ ] Code follows 42 norm

---

Good luck with your module! Remember: understanding **when** to use each concept is just as important as knowing **how** to use it. 🚀

# C++ Module 00 - Complete Navigation Guide

## 📋 Table of Contents

### 📖 Documentation Files
1. **[README.md](README.md)** - Main comprehensive guide
   - Core C++ concepts (Classes, Namespaces, iostream)
   - Detailed explanations with code examples
   - Constructor/Destructor, Static members, Const
   - Initialization lists and best practices
   - C vs C++ comparison

2. **[QUICKSTART.md](QUICKSTART.md)** - Quick reference
   - Fast overview of all exercises
   - Common mistakes and how to avoid them
   - Pro tips for writing clean C++ code
   - Time estimates for each exercise
   - Evaluation preparation tips

3. **[TESTING.md](TESTING.md)** - Testing guide
   - Detailed test cases for each exercise
   - Edge cases and validation
   - Debugging techniques
   - Common issues and solutions
   - Memory testing with valgrind

4. **[INDEX.md](INDEX.md)** - This file - navigation hub
   - Project overview and structure
   - Exercise summaries
   - Study workflow
   - Pre-submission checklist

---

## 🎯 Exercises Overview

### **Exercise 00: Megaphone** - C++ Basics Warm-up
**Directory**: `ex00/`  
**Files**: `megaphone.cpp`, `Makefile`  
**Time**: ~40 minutes  
**Difficulty**: ⭐☆☆☆☆

**Concepts Covered:**
- Command-line arguments (`argc`, `argv`)
- Character conversion (`toupper()`)
- C++ I/O streams (`std::cout`)
- String manipulation in C++

**What It Does:**
Converts all command-line arguments to uppercase and prints them.
If no arguments, prints a feedback noise message.

**Key Learning:**
- Basic C++ syntax vs C
- How to use `std::cout` instead of `printf`
- Command-line argument handling

**Example:**
```bash
./megaphone "hello world"
# Output: HELLO WORLD

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

---

### **Exercise 01: My Awesome PhoneBook** - OOP Introduction
**Directory**: `ex01/`  
**Files**: `PhoneBook.{hpp,cpp}`, `Contact.{hpp,cpp}`, `main.cpp`, `Makefile`  
**Time**: ~4 hours  
**Difficulty**: ⭐⭐⭐⭐☆

**Concepts Covered:**
- Class design and implementation
- Private vs public members
- Member functions (methods)
- Constructor and destructor
- Const member functions
- Fixed-size arrays
- Input validation
- Output formatting with `std::setw()`, `std::left/right`
- Interactive command loop

**What It Does:**
Interactive phonebook application that stores up to 8 contacts.
Supports ADD (add contact), SEARCH (display and select), and EXIT commands.

**Key Learning:**
- How to design classes in C++
- Encapsulation (hiding data, exposing interface)
- Input handling with `std::getline()`
- Output formatting for tables
- Circular buffer concept (replacing oldest)

**Commands:**
- `ADD`: Add new contact with fields (first name, last name, nickname, phone, secret)
- `SEARCH`: Display contacts as formatted table, then show detail by index
- `EXIT`: Quit and lose all data

**Table Format:**
```
     Index|First Name| Last Name|  Nickname
         0|      John|     Smith|    Johnny
         1| Very Long.| Very Long.|      Nick
```
(10 characters per column, truncated with '.' if longer)

---

### **Exercise 02: The Job Of Your Dreams** - Static Members
**Directory**: `ex02/`  
**Files**: `Account.cpp`, `Account.hpp`, `tests.cpp`, `Makefile`, `19920104_091532.log`  
**Time**: ~2.5 hours  
**Difficulty**: ⭐⭐⭐☆☆  
**Status**: Optional (not required to pass module)

**Concepts Covered:**
- Static member variables (shared across all instances)
- Static member functions
- Log file analysis
- Reverse engineering code from tests
- Time formatting
- Reading existing code to understand requirements

**What It Does:**
Implements the missing `Account.cpp` file for a banking system.
The header (`Account.hpp`) and test file (`tests.cpp`) are provided.
Must match the output in the provided log file.

**Key Learning:**
- Understanding static members (class-level data)
- Why static functions can only access static data
- Analyzing logs to understand requirements
- Matching exact output format

**Static Data Tracked:**
- Total number of accounts
- Total amount across all accounts
- Total deposits made
- Total withdrawals made

---

## 🚀 Getting Started

### 1. First Time Setup
```bash
cd /home/abdellatif/Files/Cpp-Modules/00
ls -la  # See all files and directories
```

### 2. Read Documentation Order
1. Start with **INDEX.md** (this file) for overview
2. Read **README.md** for deep concept understanding
3. Use **QUICKSTART.md** as quick reference while coding
4. Check **TESTING.md** before testing your code

### 3. Compile Everything
```bash
# Compile all exercises
for i in 0 1 2; do
    echo "Compiling ex0$i..."
    (cd ex0$i && make)
done
```

### 4. Test Your Work
```bash
# Ex00 - simple test
cd ex00
./megaphone "test"
cd ..

# Ex01 - interactive test
cd ex01
./phonebook
# Try ADD, SEARCH, EXIT commands
cd ..

# Ex02 - compare output
cd ex02
./account > my_output.log
diff my_output.log 19920104_091532.log
cd ..
```

---

## 📚 Study Workflow

### For Understanding (First Time)
1. Read subject PDF to understand requirements
2. Read **README.md** section for that exercise
3. Study provided code (if any)
4. Implement solution step by step
5. Test frequently with **TESTING.md** scenarios
6. Compile and run to verify behavior

### For Review (Before Evaluation)
1. Review **QUICKSTART.md** for key concepts
2. Test all exercises with edge cases
3. Practice explaining your code out loud
4. Review **TESTING.md** common issues
5. Be ready to modify code on the spot

### For Exam Preparation
1. Understand WHY, not just HOW
2. Practice writing classes from scratch
3. Memorize key syntax patterns
4. Know when to use const, static, private/public
5. Practice with pen and paper (no IDE)

---

## 🎓 Evaluation Preparation

### Questions You Must Be Able To Answer

**General C++ Concepts:**
- What is a class? What is an object?
- Difference between private and public?
- What is a constructor? A destructor?
- What does const mean on a member function?
- What are static members?
- Why use initialization lists?

**Ex00 Specific:**
- How do argc and argv work?
- What does toupper() do?
- Why prefer std::cout over printf?

**Ex01 Specific:**
- Why are Contact data members private?
- How does circular buffer work (replacing oldest)?
- How do you validate empty input?
- Explain table formatting logic (setw, truncation)
- Why mark getters as const?

**Ex02 Specific:**
- What are static members and why use them?
- Why can't static functions access non-static data?
- How did you reverse-engineer Account.cpp?
- Explain the log file format

### Be Ready To Modify Code

Common modification requests:
- **Ex01**: Add new field to Contact (e.g., email)
- **Ex01**: Change column width (e.g., from 10 to 15)
- **Ex01**: Add DELETE command
- **Ex02**: Add account transfer function
- **Ex02**: Modify output format

Practice making these changes quickly!

---

## 💡 Key Concepts Quick Reference

### Class Structure
```cpp
class MyClass {
private:                    // Only accessible inside class
    int privateData;
    
public:                     // Accessible from anywhere
    MyClass();              // Constructor
    ~MyClass();             // Destructor
    
    void setter(int x);     // Modifies data
    int getter() const;     // Reads data (const!)
    
    static int getCount();  // Static function
private:
    static int count;       // Static member
};
```

### Initialization List
```cpp
MyClass::MyClass(int x, int y) : memberX(x), memberY(y) {
    // Members already initialized before body
}
```

### Const Correctness
```cpp
int getValue() const {      // Won't modify object
    return value;
}

void setValue(int v) {      // Will modify object
    value = v;
}
```

### Static Members
```cpp
// In .hpp
class Counter {
    static int total;
public:
    static int getTotal();
};

// In .cpp
int Counter::total = 0;     // Must define outside

int Counter::getTotal() {
    return total;           // Can only access static data
}
```

### Input/Output
```cpp
// Output
std::cout << "Text" << std::endl;

// Input single word
std::cin >> word;

// Input line with spaces
std::getline(std::cin, line);

// Formatting
std::cout << std::setw(10) << std::right << text;
```

---

## ⚠️ Common Pitfalls

### Compilation Errors
❌ Forgetting header guards
❌ Circular includes
❌ Using `using namespace std;` in headers
❌ Not initializing static members outside class

### Logic Errors
❌ Not validating empty input
❌ Off-by-one errors in array indexing
❌ Forgetting to mark read-only methods as const
❌ Using assignment instead of initialization list

### Formatting Errors
❌ Wrong truncation (9 chars instead of 9 + dot)
❌ Not using setw() for each column
❌ Missing alignment (left/right)

---

## 📊 Time Investment

| Activity | Time |
|----------|------|
| Reading Documentation | 1-2 hours |
| Ex00 Implementation | 30 min |
| Ex01 Implementation | 3-4 hours |
| Ex02 Implementation | 2-3 hours |
| Testing & Debugging | 1-2 hours |
| Review for Evaluation | 1 hour |
| **Total** | **8-13 hours** |

**Pro Tip**: Don't rush. Understanding is more valuable than speed.

---

## 🔗 Quick Links

### Documentation
- **Main Concepts**: [README.md](README.md)
- **Quick Reference**: [QUICKSTART.md](QUICKSTART.md)
- **Testing Guide**: [TESTING.md](TESTING.md)

### External Resources
- **String Reference**: http://www.cplusplus.com/reference/string/string/
- **iomanip Reference**: http://www.cplusplus.com/reference/iomanip/
- **iostream Reference**: http://www.cplusplus.com/reference/iostream/

---

## ✅ Pre-Submission Checklist

### Code Quality
- [ ] All exercises compile with `-Wall -Wextra -Werror -std=c++98`
- [ ] No compilation warnings
- [ ] Header guards in all .hpp files
- [ ] Proper const correctness
- [ ] Initialization lists used
- [ ] No forbidden functions

### Functionality
- [ ] Ex00: All test cases work
- [ ] Ex01: Input validation complete
- [ ] Ex01: Table formatting perfect
- [ ] Ex01: 9th contact replaces oldest
- [ ] Ex02: Output matches log (optional)

### Makefiles
- [ ] All Makefiles have: all, clean, fclean, re
- [ ] Proper recompilation (only changed files)
- [ ] Correct executable names

### Understanding
- [ ] Can explain every design decision
- [ ] Know when to use private vs public
- [ ] Understand const, static, initialization lists
- [ ] Ready for live code modifications

### Testing
- [ ] Tested with valid inputs
- [ ] Tested with edge cases
- [ ] Tested with invalid inputs
- [ ] No memory leaks (valgrind clean)

---

## 📞 Getting Help

### If You're Stuck:

1. **Read error messages carefully** - compiler tells you what's wrong
2. **Check README.md** - concept explained with examples
3. **Review TESTING.md** - see if it's a common issue
4. **Ask peers** - peer learning is valuable!
5. **Debug systematically** - add print statements, use gdb

### Debugging Process:

1. Read the error message completely
2. Identify the file and line number
3. Understand what the compiler/program expects
4. Check similar examples in README.md
5. Fix one error at a time
6. Recompile and test

---

## 🎯 Success Criteria

You've mastered Module 00 when you can:

✅ Explain what classes and objects are  
✅ Design a class with proper encapsulation  
✅ Use const correctly on methods  
✅ Implement and use static members  
✅ Handle input/output with iostreams  
✅ Format output properly  
✅ Write Makefiles for C++ projects  
✅ Debug compilation errors  
✅ Modify existing code confidently  

---

**Created**: December 2024  
**Standard**: C++98  
**Purpose**: 42 School C++ Module 00

Welcome to C++! This is where your OOP journey begins. Take your time, understand deeply, and enjoy the learning process. 🚀🎓

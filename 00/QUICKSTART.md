# C++ Module 00 - Quick Start

## 📁 Project Structure

```
00/
├── README.md           # Comprehensive concept guide
├── TESTING.md          # Testing and debugging guide
├── QUICKSTART.md       # This file - quick reference
├── INDEX.md            # Navigation hub
├── ex00/              # Simple string manipulation (Megaphone)
├── ex01/              # OOP basics (PhoneBook)
└── ex02/              # Static members (Account)
```

## 🚀 Quick Start

### Compile and Run Everything
```bash
# From the 00/ directory

# Ex00
cd ex00 && make && ./megaphone "hello world" && cd ..

# Ex01
cd ex01 && make && ./phonebook && cd ..

# Ex02
cd ex02 && make && ./account && cd ..
```

### Clean Everything
```bash
for i in 0 1 2; do (cd ex0$i && make fclean); done
```

## 📚 What You'll Learn

### Ex00: Megaphone
**Time**: 30 minutes  
**Difficulty**: ⭐☆☆☆☆

Learn:
- Command-line arguments (`argc`, `argv`)
- Character conversion (`toupper()`)
- Basic C++ I/O (`std::cout`)
- String handling

```bash
./megaphone "shhhhh... I think the students are asleep..."
# Output: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

---

### Ex01: My Awesome PhoneBook
**Time**: 3-4 hours  
**Difficulty**: ⭐⭐⭐⭐☆

Learn:
- **Class design** (PhoneBook, Contact)
- **Private vs public** members
- **Member functions**
- **Fixed arrays** (no dynamic allocation)
- **Input handling** with `std::getline()`
- **Output formatting** with `std::setw()`, `std::left/right`
- **Circular buffer** (replacing oldest entry)

**Commands:**
- `ADD` - Add new contact (max 8, oldest replaced)
- `SEARCH` - Display contacts in table, then show detail by index
- `EXIT` - Quit program

**Key Challenge**: Format output as table with 10-char columns:
```
     Index|First Name| Last Name|  Nickname
         0|      John|     Smith|    Johnny
         1|     Alice|   Johnson|       Ali
```

If text > 10 chars, truncate and add dot:
```
         0|  Very Lon.|  LastName|      Nick
```

---

### Ex02: The Job Of Your Dreams
**Time**: 2-3 hours  
**Difficulty**: ⭐⭐⭐☆☆  
**Note**: Optional (not required to pass module)

Learn:
- **Static members** (shared across instances)
- **Static member functions**
- **Log file analysis**
- **Reverse engineering**
- Time formatting

**Goal**: Recreate `Account.cpp` by:
1. Reading `Account.hpp` (header provided)
2. Analyzing `tests.cpp` (test file provided)
3. Matching output in `19920104_091532.log` (log provided)

**Key Concepts:**
- Static variables track totals across all accounts
- Static functions access only static data
- Timestamps format: `[19920104_091532]`

---

## 🎯 Key Concepts Summary

### 1. Classes and Objects
```cpp
class Contact {
private:
    std::string firstName;  // Private data

public:
    Contact();              // Constructor
    void setFirstName(std::string name);  // Setter
    std::string getFirstName() const;     // Getter (const!)
};
```

**Remember:**
- Private: internal data
- Public: interface to outside
- Const methods: don't modify object

---

### 2. Initialization Lists
```cpp
// Bad
Contact::Contact(std::string name) {
    firstName = name;  // Assignment
}

// Good
Contact::Contact(std::string name) : firstName(name) {
    // Direct initialization
}
```

---

### 3. Const Correctness
```cpp
class Person {
public:
    std::string getName() const {  // Won't modify object
        return name;
    }
    
    void setName(std::string n) {  // Will modify object
        name = n;
    }
};
```

---

### 4. Static Members
```cpp
class Counter {
private:
    static int totalCount;  // Shared by all objects
    int instanceId;         // Unique per object

public:
    static int getTotalCount() {  // Can call without object
        return totalCount;
    }
};

// Must define outside class
int Counter::totalCount = 0;

// Usage
Counter::getTotalCount();  // No object needed!
```

---

### 5. Input/Output
```cpp
#include <iostream>
#include <iomanip>
#include <string>

// Output
std::cout << "Hello" << std::endl;

// Input (single word)
std::string word;
std::cin >> word;

// Input (full line with spaces)
std::string line;
std::getline(std::cin, line);

// Formatting
std::cout << std::setw(10) << std::right << "Text";  // Right-align in 10 chars
std::cout << std::setw(10) << std::left << "Text";   // Left-align
```

---

## ⚠️ Common Mistakes

### Mistake 1: Forgetting to clear input buffer
```cpp
int num;
std::string line;

std::cin >> num;           // Reads number, leaves '\n' in buffer
std::getline(std::cin, line);  // Gets empty line!

// Fix:
std::cin >> num;
std::cin.ignore();         // Clear the '\n'
std::getline(std::cin, line);
```

### Mistake 2: Not checking empty input
```cpp
// Bad
std::string name;
std::getline(std::cin, name);
// What if user just pressed Enter?

// Good
std::string name;
std::getline(std::cin, name);
if (name.empty()) {
    std::cout << "Error: field cannot be empty" << std::endl;
}
```

### Mistake 3: Wrong truncation
```cpp
// Bad: Loses last character
if (str.length() > 10) {
    str = str.substr(0, 9);  // Only 9 chars!
}

// Good: 9 chars + dot = 10
if (str.length() > 10) {
    str = str.substr(0, 9) + ".";  // Exactly 10 chars
}
```

### Mistake 4: Forgetting const
```cpp
// Bad: Can't call on const objects
std::string getName() {
    return name;
}

// Good: Works on const and non-const
std::string getName() const {
    return name;
}
```

---

## 🧪 Testing Commands

### Ex00
```bash
./megaphone
./megaphone "hello" "world"
./megaphone "Test 123"
./megaphone "lowercase" "UPPERCASE" "MiXeD"
```

### Ex01
Test each command thoroughly:

**ADD Command:**
- Add contact with all fields
- Try adding contact with empty field (should reject)
- Add 8 contacts, then add 9th (should replace first)

**SEARCH Command:**
- Search in empty phonebook
- Search with valid index
- Search with invalid index (negative, too large, non-numeric)
- Check table formatting with short and long names

**Input Test:**
```
ADD
John
Smith
Johnny
555-1234
Secret here
SEARCH
0
EXIT
```

### Ex02
```bash
./account > output.log
diff output.log 19920104_091532.log
# Only timestamps should differ
```

---

## 💡 Pro Tips

### Tip 1: Use std:: explicitly
```cpp
// Don't do this in headers or global scope
using namespace std;

// Do this
std::cout << "Better" << std::endl;
```

### Tip 2: Header guards
Always use in .hpp files:
```cpp
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class MyClass {
    // ...
};

#endif
```

### Tip 3: Const correctness
Mark all read-only methods as `const`:
```cpp
int getValue() const { return value; }
std::string getName() const { return name; }
```

### Tip 4: Initialization lists
Always prefer initialization lists:
```cpp
// Preferred
MyClass(int x, int y) : memberX(x), memberY(y) {
}
```

---

## 🎓 During Evaluation

### Be Ready to Explain:

**Ex00:**
- How argc and argv work
- Why toupper() only takes one character
- Difference between std::cout and printf

**Ex01:**
- Why Contact members are private
- Why getters are const
- How circular buffer works (replacing oldest)
- How you handle empty input
- How truncation works

**Ex02:**
- What static members are
- Why static functions can't access non-static members
- How you matched the log output

### Be Ready to Modify:

- Add a new field to Contact
- Change table column width
- Add input validation
- Modify search behavior

---

## 📊 Time Estimates

| Exercise | Coding | Understanding | Testing | Total |
|----------|--------|---------------|---------|-------|
| Ex00     | 20 min | 10 min        | 10 min  | 40 min|
| Ex01     | 2 hrs  | 1 hr          | 1 hr    | 4 hrs |
| Ex02     | 1.5 hr | 45 min        | 15 min  | 2.5 hr|
| **Total**| **~4hr**| **~2hr**     | **~1.5hr**| **~7hr**|

---

## 🔗 Useful References

- **String**: http://www.cplusplus.com/reference/string/string/
- **iomanip**: http://www.cplusplus.com/reference/iomanip/
- **iostream**: http://www.cplusplus.com/reference/iostream/

---

## ✅ Pre-Submission Checklist

- [ ] All exercises compile with `-Wall -Wextra -Werror -std=c++98`
- [ ] No compilation warnings
- [ ] All Makefiles have required rules
- [ ] Ex00: Handles all test cases
- [ ] Ex01: Input validation works
- [ ] Ex01: Table formatting correct
- [ ] Ex01: Handles 9th contact properly
- [ ] Ex02: Output matches log (except timestamps)
- [ ] Can explain all design decisions
- [ ] Ready for live modifications

---

**This is your C++ journey's beginning!** Master these fundamentals—they're essential for all future modules. 🚀

# Issues to Fix

This document lists specific issues found during code review that should be addressed.

## High Priority Issues

### 1. PhoneBook Count Reset Logic Bug

**File**: `00/ex01/PhoneBook.cpp`
**Line**: 49
**Current Code**:
```cpp
(count < 8) ? count++ : count = 1;
```

**Problem**: When the phonebook is full (8 contacts), the count resets to 1 instead of 0, causing the first contact (index 0) to never be overwritten in subsequent additions.

**Fix**:
```cpp
count = (count + 1) % 8;
```
or
```cpp
(count < 8) ? count++ : count = 0;
```

**Impact**: Medium - Affects circular buffer behavior after 8 contacts are added.

---

## Medium Priority Issues

### 2. Spelling Errors in PhoneBook Welcome Message

**File**: `00/ex01/main.cpp`
**Line**: 11
**Current Code**:
```cpp
std::cout << "Welcome the the Foking awsome Phone Book form 80's" << std::endl;
```

**Problems**:
- "the the" should be "to the"
- "Foking awsome" should be "Amazing" or "Awesome"
- "form" should be "from"
- "80's" should be "the 80's"

**Fix**:
```cpp
std::cout << "Welcome to the Amazing Phone Book from the 80's" << std::endl;
```

**Impact**: Low - Cosmetic issue affecting professionalism.

---

## Low Priority Issues

### 3. Ineffective Expression in PhoneBook

**File**: `00/ex01/PhoneBook.cpp`
**Line**: 50
**Current Code**:
```cpp
(max < 8) ? max++ : 0;
```

**Problem**: The `: 0` part has no effect. The expression evaluates to 0 but doesn't assign it anywhere.

**Fix**:
```cpp
if (max < 8)
    max++;
```

**Impact**: Low - Code smell, doesn't affect functionality but reduces clarity.

---

### 4. Contact Constructor Not Using Initialization Lists

**File**: `00/ex01/Contact.cpp`
**Lines**: 5-10
**Current Code**:
```cpp
Contact::Contact() {
    first_name = "";
    last_name = "";
    nick_name = "";
    phone_number = "";
    darkest_secret = "";
}
```

**Problem**: Uses assignment instead of initialization. While this works for std::string (which has a default constructor), it's less efficient.

**Fix** (Optional - strings already default to empty):
```cpp
Contact::Contact() : first_name(""), last_name(""), nick_name(""), 
                     phone_number(""), darkest_secret("") {
}
```

Or even simpler (rely on default string constructor):
```cpp
Contact::Contact() {
    // Member strings are already default-initialized to empty
}
```

**Impact**: Very Low - Performance negligible for strings, but good practice.

---

### 5. Missing Documentation for Memory Ownership

**File**: `01/ex01/zombieHorde.cpp`
**Current**: No comments about memory management

**Recommendation**: Add a comment explaining that the caller is responsible for deleting the returned array.

**Fix**:
```cpp
// Creates and returns a horde of N zombies with the given name
// Caller is responsible for deleting the returned array with delete[]
Zombie* zombieHorde(int N, std::string name) {
    // ... existing code ...
}
```

**Impact**: Low - Documentation issue, doesn't affect functionality.

---

## Summary

- **Critical**: 0 issues
- **High Priority**: 1 issue (count reset bug)
- **Medium Priority**: 1 issue (spelling errors)
- **Low Priority**: 3 issues (code style/documentation)

**Total Issues**: 5 (4 code-related, 1 documentation)

All other code reviewed is of good quality and follows best practices.

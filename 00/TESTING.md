# Testing Guide for C++ Module 00

## Quick Test All Exercises

Run this to test all exercises:

```bash
#!/bin/bash

echo "========================================="
echo "Testing ex00 - Megaphone"
echo "========================================="
cd ex00
make
./megaphone "hello world"
./megaphone
cd ..

echo ""
echo "========================================="
echo "Testing ex01 - PhoneBook"
echo "========================================="
cd ex01
make
# Interactive - test manually
cd ..

echo ""
echo "========================================="
echo "Testing ex02 - Account"
echo "========================================="
cd ex02
make
./account
cd ..
```

---

## Individual Exercise Tests

### Ex00 - Megaphone

#### Basic Tests
```bash
cd ex00
make

# Test 1: Multiple arguments
./megaphone "shhhhh... I think the students are asleep..."
# Expected: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

# Test 2: Multiple separate arguments
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
# Expected: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

# Test 3: No arguments
./megaphone
# Expected: * LOUD AND UNBEARABLE FEEDBACK NOISE *

# Test 4: Mixed case
./megaphone "Hello World" "TEST" "test"
# Expected: HELLO WORLD TEST TEST

# Test 5: Special characters
./megaphone "test@123" "!@#$%"
# Expected: TEST@123 !@#$%

# Test 6: Numbers
./megaphone "123" "abc" "456"
# Expected: 123 ABC 456
```

#### Edge Cases
```bash
# Empty string argument
./megaphone ""
# Expected: * LOUD AND UNBEARABLE FEEDBACK NOISE *

# Single character
./megaphone "a"
# Expected: A

# Very long string
./megaphone "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
# Expected: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
```

---

### Ex01 - My Awesome PhoneBook

#### Test 1: Basic ADD and SEARCH
```
Input:
ADD
John
Doe
JD
555-1234
Secret1
SEARCH
0
EXIT

Expected:
- Contact added successfully
- Table displays correctly with index 0
- When index 0 selected, shows all John Doe details
```

#### Test 2: Empty Field Validation
```
Input:
ADD
John

(empty last name)

Expected:
- Should reject and ask again for last name
- Cannot proceed with empty field
```

#### Test 3: Table Formatting
```
Input:
ADD
John
Smith
Johnny
555-1234
Secret
ADD
VeryLongFirstName
VeryLongLastName
VeryLongNickname
555-5678
AnotherSecret
SEARCH

Expected Table:
     Index|First Name| Last Name|  Nickname
         0|      John|     Smith|    Johnny
         1| Very Long.| Very Long.| Very Long.

(Truncated with dot when > 10 chars)
```

#### Test 4: Circular Buffer (8 contacts max)
```
Input:
ADD (contact 1)
ADD (contact 2)
ADD (contact 3)
ADD (contact 4)
ADD (contact 5)
ADD (contact 6)
ADD (contact 7)
ADD (contact 8)
ADD (contact 9 - should replace contact 1)
SEARCH

Expected:
- Only 8 contacts shown
- Contact 9 replaced contact 1
- Indices 0-7 shown
```

#### Test 5: SEARCH Edge Cases
```
Input:
SEARCH
(in empty phonebook)

Expected:
- Should handle gracefully (show empty or appropriate message)

Input:
SEARCH
99
(index out of range)

Expected:
- Error message about invalid index

Input:
SEARCH
abc
(non-numeric input)

Expected:
- Error message about invalid input
```

#### Test 6: Input with Spaces
```
Input:
ADD
John Paul
Smith Jones
JP
555-1234
My secret has spaces

Expected:
- All fields should accept and store spaces correctly
- Display should work properly
```

#### Test 7: EXIT Command
```
Input:
EXIT

Expected:
- Program exits cleanly
- All contacts lost (not saved)
```

#### Automated Test Script
```bash
cd ex01
make

# Create test input file
cat > test_input.txt << 'EOF'
ADD
Alice
Smith
Ali
111-1111
Secret1
ADD
Bob
Jones
Bobby
222-2222
Secret2
SEARCH
0
SEARCH
1
SEARCH
99
EXIT
EOF

# Run with input file
./phonebook < test_input.txt
```

---

### Ex02 - The Job Of Your Dreams

#### Test 1: Basic Execution
```bash
cd ex02
make
./account > output.log

# Compare with expected (ignore timestamps)
# Should see same pattern of:
# - Accounts created
# - Deposits made
# - Withdrawals attempted
# - Account status displays
# - Accounts destroyed
```

#### Test 2: Output Format Check
```bash
# Check account creation format
grep "index:" output.log | head -1
# Expected pattern: [timestamp] index:X;amount:Y;created

# Check deposit format
grep "deposit:" output.log | head -1
# Expected pattern: [timestamp] index:X;p_amount:Y;deposit:Z;amount:W;nb_deposits:N

# Check withdrawal format
grep "withdrawal:" output.log | head -1
# Expected pattern: [timestamp] index:X;p_amount:Y;withdrawal:Z;amount:W;nb_withdrawals:N
```

#### Test 3: Static Members
Your implementation should track:
- Total number of accounts
- Total amount across all accounts
- Total deposits made
- Total withdrawals made

```bash
# Check if totals are displayed correctly
grep "accounts:" output.log
# Should show running totals
```

#### Test 4: Destructor Order
```bash
# Check destructor output
grep "closed" output.log
# Destructors may be in reverse order of construction
# This is OK (depends on compiler/OS)
```

#### Detailed Comparison
```bash
# Generate your output
./account > my_output.log

# Strip timestamps for comparison
sed 's/\[[0-9_]*\]//g' 19920104_091532.log > expected_no_time.log
sed 's/\[[0-9_]*\]//g' my_output.log > my_output_no_time.log

# Compare
diff expected_no_time.log my_output_no_time.log
# Should be identical
```

---

## Common Issues and Solutions

### Issue 1: Ex00 - Not Converting to Uppercase
**Symptom**: Output is same as input
**Solution**: Use `toupper()` on each character:
```cpp
char c = std::toupper(str[i]);
```

### Issue 2: Ex01 - Table Columns Not Aligned
**Symptom**: Pipes don't line up
**Solution**: Use `std::setw(10)` for each column:
```cpp
std::cout << std::setw(10) << std::right << text << "|";
```

### Issue 3: Ex01 - Truncation Wrong
**Symptom**: Text is 11 chars or wrong truncation
**Solution**: Take 9 chars + dot:
```cpp
if (str.length() > 10)
    str = str.substr(0, 9) + ".";
```

### Issue 4: Ex01 - Empty Input Not Rejected
**Symptom**: Accepts empty fields
**Solution**: Check and loop until valid:
```cpp
while (input.empty()) {
    std::cout << "Field cannot be empty. Try again: ";
    std::getline(std::cin, input);
}
```

### Issue 5: Ex01 - Getline Skipped After Cin
**Symptom**: Input prompt skipped
**Solution**: Clear buffer after `std::cin >>`:
```cpp
std::cin >> index;
std::cin.ignore();  // Clear the newline
```

### Issue 6: Ex02 - Static Members Not Updating
**Symptom**: Totals are always 0
**Solution**: 
- Initialize static members outside class
- Update in constructors/methods
```cpp
// In .cpp file
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
```

### Issue 7: Compilation Warnings
**Symptom**: Warnings with -Werror
**Solution**: Common fixes:
```cpp
// Unused parameter
void func(int /* unused */) { }

// Comparison signed/unsigned
size_t i; // Use size_t for string indices

// Initialization order
// Put members in initialization list in same order as declared
```

---

## Memory Testing

No dynamic allocation in Module 00, but still check:

```bash
# Ex00
valgrind --leak-check=full ./megaphone "test"

# Ex01
valgrind --leak-check=full ./phonebook < test_input.txt

# Ex02
valgrind --leak-check=full ./account
```

All should show:
```
All heap blocks were freed -- no leaks are possible
```

---

## Evaluation Preparation

### Questions You Should Answer:

**Ex00:**
1. What is argc and argv?
2. How does toupper() work?
3. Why use std::cout instead of printf?

**Ex01:**
4. Why are Contact members private?
5. What is the difference between private and public?
6. Why mark getters as const?
7. How does your circular buffer work?
8. How do you validate input?
9. Explain the table formatting logic

**Ex02:**
10. What are static members?
11. Why can't static functions access non-static members?
12. How did you determine what Account.cpp should contain?
13. What is the purpose of timestamps in output?

### Live Modifications to Practice:

**Ex01 Modifications:**
- Add an "email" field to Contact
- Change table width to 15 characters
- Add a DELETE command to remove a contact
- Add error counter for failed searches

**Ex02 Modifications:**
- Add a transfer function between accounts
- Add interest calculation
- Modify display format

---

## Debugging Tips

### Debug Output
Add debug prints:
```cpp
std::cout << "[DEBUG] Variable value: " << var << std::endl;
```

### GDB (GNU Debugger)
```bash
# Compile with debug symbols
g++ -g -o program file.cpp

# Run in debugger
gdb ./program

# GDB commands
(gdb) break main
(gdb) run
(gdb) next
(gdb) print variable_name
(gdb) continue
```

### Check Compilation Flags
```bash
# Your Makefile should have:
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

---

## Final Checklist

Before submission:

- [ ] Ex00: All test cases pass
- [ ] Ex01: ADD validates empty fields
- [ ] Ex01: SEARCH handles invalid indices
- [ ] Ex01: Table formatting correct (10 chars + truncation)
- [ ] Ex01: 9th contact replaces oldest
- [ ] Ex02: Output matches log (except timestamps)
- [ ] All compile without warnings
- [ ] All Makefiles work (all, clean, fclean, re)
- [ ] No memory leaks (valgrind clean)
- [ ] Header guards in all .hpp files
- [ ] Can explain every design decision

---

Good luck! Remember: understanding is more important than just passing. 🎓

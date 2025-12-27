# Testing Guide for C++ Module 01

## Quick Test All Exercises

Run this script to test all exercises:

```bash
#!/bin/bash

for i in 0 1 2 3 4 5 6; do
    echo "========================================="
    echo "Testing ex0$i"
    echo "========================================="
    cd ex0$i
    make re
    cd ..
    echo
done
```

## Individual Exercise Tests

### Ex00 - BraiiiiiiinnnzzzZ
```bash
cd ex00
make
./zombie
```
**Expected**: HeapZombie announces, StackZombie announces and is destroyed immediately, then HeapZombie is manually destroyed.

**Memory leak check**:
```bash
valgrind --leak-check=full ./zombie
```

---

### Ex01 - Moar brainz!
```bash
cd ex01
make
./zombie
```
**Expected**: 5 zombies created, all announce, all destroyed properly with delete[].

**Memory leak check**:
```bash
valgrind --leak-check=full ./zombie
```

---

### Ex02 - HI THIS IS BRAIN
```bash
cd ex02
make
./brain
```
**Expected**: All three (string, pointer, reference) show the SAME memory address and SAME value.

---

### Ex03 - Unnecessary violence
```bash
cd ex03
make
./violence
```
**Expected**:
```
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club
```

**Memory leak check**:
```bash
valgrind --leak-check=full ./violence
```

---

### Ex04 - Sed is for losers
```bash
cd ex04
make

# Test 1: Normal replacement
echo "Hello world. world is beautiful." > test.txt
./sed test.txt world universe
cat test.txt.replace
# Expected: "Hello universe. universe is beautiful."

# Test 2: Empty string s1
./sed test.txt "" replacement
# Should handle gracefully

# Test 3: String not found
./sed test.txt "notfound" "replacement"
cat test.txt.replace
# Should output original content

# Test 4: File doesn't exist
./sed nonexistent.txt old new
# Should print error message

# Clean up
rm -f test.txt test.txt.replace
```

---

### Ex05 - Harl 2.0
```bash
cd ex05
make
./harl
```
**Expected**: All levels tested (DEBUG, INFO, WARNING, ERROR, INVALID).

**Key concept**: Uses member function pointers instead of if-else chain.

---

### Ex06 - Harl filter
```bash
cd ex06
make

# Test different filter levels
./harlFilter DEBUG
# Shows DEBUG, INFO, WARNING, ERROR

./harlFilter INFO
# Shows INFO, WARNING, ERROR

./harlFilter WARNING
# Shows WARNING, ERROR

./harlFilter ERROR
# Shows only ERROR

./harlFilter "random"
# Shows: [ Probably complaining about insignificant problems ]
```

**Key concept**: Uses switch statement with intentional fall-through.

---

## Memory Leak Testing

Install valgrind if not available:
```bash
sudo apt-get install valgrind
```

Test each exercise:
```bash
cd ex00 && valgrind --leak-check=full --show-leak-kinds=all ./zombie
cd ex01 && valgrind --leak-check=full --show-leak-kinds=all ./zombie
cd ex03 && valgrind --leak-check=full --show-leak-kinds=all ./violence
```

**Perfect output should show**:
```
All heap blocks were freed -- no leaks are possible
```

---

## Common Issues and Solutions

### Issue 1: Segmentation Fault
- **Cause**: Dereferencing NULL pointer or accessing deleted memory
- **Solution**: Check pointer initialization and delete operations

### Issue 2: Memory Leaks
- **Cause**: Missing delete or using delete instead of delete[]
- **Solution**: Every `new` needs a `delete`, every `new[]` needs a `delete[]`

### Issue 3: Compilation Errors
- **Cause**: Wrong C++ standard or missing flags
- **Solution**: Ensure Makefile uses `-std=c++98 -Wall -Wextra -Werror`

### Issue 4: Wrong Fall-through in Switch
- **Cause**: Compiler treating fall-through as error
- **Solution**: Add comment `// fall through` before next case

---

## Evaluation Preparation

Before defense, verify:
- [ ] All programs compile without warnings
- [ ] No memory leaks (valgrind shows clean)
- [ ] All destructors print debug messages
- [ ] Makefiles have all rules (all, clean, fclean, re)
- [ ] Understand when to use stack vs heap
- [ ] Understand when to use pointer vs reference
- [ ] Can explain member function pointers
- [ ] Can explain switch fall-through behavior

---

## Quick Reference Commands

**Compile all**:
```bash
for dir in ex0{0..6}; do (cd $dir && make); done
```

**Clean all**:
```bash
for dir in ex0{0..6}; do (cd $dir && make fclean); done
```

**Test memory leaks in all**:
```bash
valgrind --leak-check=full ex00/zombie
valgrind --leak-check=full ex01/zombie
valgrind --leak-check=full ex02/brain
valgrind --leak-check=full ex03/violence
```

---

Good luck! 🚀

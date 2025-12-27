# C++ Module 01 - Complete Package

## 📋 Table of Contents

### 📖 Documentation Files
1. **[README.md](README.md)** - Main documentation
   - Core C++ concepts (Stack/Heap, Pointers/References, etc.)
   - Detailed explanations with code examples
   - When to use each concept
   - Study resources and key takeaways

2. **[QUICKSTART.md](QUICKSTART.md)** - Quick reference
   - Fast overview of all exercises
   - Quick commands to compile and test
   - Common mistakes and how to avoid them
   - Evaluation preparation checklist

3. **[TESTING.md](TESTING.md)** - Testing guide
   - Detailed test cases for each exercise
   - Memory leak detection with valgrind
   - Troubleshooting common issues
   - Test automation scripts

---

## 🎯 Exercises Overview

### **Exercise 00: BraiiiiiiinnnzzzZ** - Stack vs Heap
**Directory**: `ex00/`  
**Files**: `Zombie.{hpp,cpp}`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`, `Makefile`  
**Concepts**: 
- Stack allocation (automatic cleanup)
- Heap allocation (manual cleanup with delete)
- When to use each allocation type
- Constructor/Destructor debugging

**Key Learning**: Understand lifetime management and choosing appropriate allocation.

---

### **Exercise 01: Moar brainz!** - Dynamic Arrays
**Directory**: `ex01/`  
**Files**: `Zombie.{hpp,cpp}`, `zombieHorde.cpp`, `main.cpp`, `Makefile`  
**Concepts**:
- Array allocation with `new[]`
- Array deallocation with `delete[]`
- Single allocation for multiple objects
- Object initialization in arrays

**Key Learning**: Critical difference between `delete` and `delete[]`.

---

### **Exercise 02: HI THIS IS BRAIN** - Pointers vs References
**Directory**: `ex02/`  
**Files**: `main.cpp`, `Makefile`  
**Concepts**:
- Pointer syntax and usage
- Reference syntax and usage
- Memory address comparison
- Both access same underlying memory

**Key Learning**: References are safer pointer syntax, both reference the same address.

---

### **Exercise 03: Unnecessary violence** - Design Choice
**Directory**: `ex03/`  
**Files**: `Weapon.{hpp,cpp}`, `HumanA.{hpp,cpp}`, `HumanB.{hpp,cpp}`, `main.cpp`, `Makefile`  
**Concepts**:
- When to use references (always valid object)
- When to use pointers (nullable object)
- Design decision based on requirements
- Const references for getters

**Key Learning**: Choose pointer vs reference based on whether NULL is a valid state.

---

### **Exercise 04: Sed is for losers** - File I/O
**Directory**: `ex04/`  
**Files**: `main.cpp`, `Makefile`  
**Concepts**:
- `std::ifstream` for reading files
- `std::ofstream` for writing files
- String manipulation (`find`, `substr`, `append`)
- Implementing find-replace without `std::string::replace()`

**Key Learning**: C++ file streams and manual string algorithms.

---

### **Exercise 05: Harl 2.0** - Member Function Pointers
**Directory**: `ex05/`  
**Files**: `Harl.{hpp,cpp}`, `main.cpp`, `Makefile`  
**Concepts**:
- Pointer to member function syntax
- Array of member function pointers
- Calling member functions through pointers
- Avoiding long if-else chains

**Key Learning**: Elegant dispatch mechanism using function pointers.

---

### **Exercise 06: Harl filter** - Switch Statements
**Directory**: `ex06/`  
**Files**: `Harl.{hpp,cpp}`, `main.cpp`, `Makefile`  
**Concepts**:
- Switch statement syntax
- Intentional fall-through behavior
- Filtering with levels
- When switch is better than if-else

**Key Learning**: Leveraging fall-through for cascading behavior.

---

## 🚀 Getting Started

### 1. First Time Setup
```bash
cd /path/to/Cpp-Modules/01
ls -la  # See all files and directories
```

### 2. Read Documentation
- Start with **README.md** for concept understanding
- Use **QUICKSTART.md** for quick reference
- Check **TESTING.md** before testing

### 3. Compile Everything
```bash
for i in 0 1 2 3 4 5 6; do
    echo "Compiling ex0$i..."
    (cd ex0$i && make)
done
```

### 4. Test Memory Leaks
```bash
# Exercises with dynamic allocation
valgrind --leak-check=full ex00/zombie
valgrind --leak-check=full ex01/zombie
valgrind --leak-check=full ex03/violence
```

---

## 📚 Study Workflow

### For Understanding
1. Read the subject PDF
2. Read README.md section for that exercise
3. Study the code implementation
4. Compile and run
5. Experiment with modifications

### For Exam Preparation
1. Review QUICKSTART.md
2. Practice explaining each concept
3. Memorize key differences (stack/heap, pointer/reference)
4. Run through TESTING.md scenarios
5. Be ready to modify code during evaluation

---

## 🎓 Evaluation Tips

### Be Ready to Explain
- **Ex00**: Why newZombie uses heap but randomChump uses stack
- **Ex01**: Why `delete[]` is mandatory for arrays
- **Ex02**: Why all three addresses are identical
- **Ex03**: Design rationale for HumanA vs HumanB
- **Ex04**: Your string replacement algorithm
- **Ex05**: What member function pointers are
- **Ex06**: How switch fall-through works

### Be Ready to Modify
- Add new methods to classes
- Change allocation strategies
- Add error handling
- Modify behavior slightly

### Common Questions
- "What happens if you use delete instead of delete[]?"
- "Can a reference be NULL?"
- "When would you prefer a pointer over a reference?"
- "What is RAII?"
- "How does switch fall-through work?"

---

## ⚠️ Important Notes

### Compilation
- **Must compile with**: `-Wall -Wextra -Werror -std=c++98`
- **No warnings allowed**: Fix all warnings before submission

### Memory Management
- **Every `new` needs `delete`**
- **Every `new[]` needs `delete[]`**
- **Test with valgrind** to ensure no leaks

### Code Style
- Follow 42 norm
- Use meaningful variable names
- Add comments only where needed
- Keep functions small and focused

---

## 📊 Time Estimates

| Exercise | Implementation | Understanding | Total |
|----------|---------------|---------------|-------|
| Ex00     | 30 min        | 30 min        | 1 hr  |
| Ex01     | 30 min        | 20 min        | 50 min|
| Ex02     | 15 min        | 15 min        | 30 min|
| Ex03     | 45 min        | 30 min        | 1.25 hr|
| Ex04     | 1 hr          | 30 min        | 1.5 hr|
| Ex05     | 45 min        | 45 min        | 1.5 hr|
| Ex06     | 30 min        | 30 min        | 1 hr  |
| **Total**| **4.5 hrs**   | **3.5 hrs**   | **8 hrs**|

---

## ✅ Pre-Submission Checklist

- [ ] All exercises compile without warnings
- [ ] No memory leaks (valgrind clean)
- [ ] All Makefiles work (all, clean, fclean, re)
- [ ] Code follows 42 norm
- [ ] Destructors print debug messages
- [ ] Can explain every design decision
- [ ] Tested edge cases
- [ ] Ready for live code modifications

---

## 🔗 Quick Links

- **Main Concepts**: [README.md](README.md)
- **Quick Reference**: [QUICKSTART.md](QUICKSTART.md)
- **Testing Guide**: [TESTING.md](TESTING.md)

---

## 📞 Support

If you encounter issues:
1. Check error messages carefully
2. Review relevant section in README.md
3. Check TESTING.md for similar issues
4. Use valgrind to detect memory problems
5. Read compiler warnings/errors completely

---

**Created**: December 2024  
**Standard**: C++98  
**Purpose**: 42 School C++ Module 01

Good luck! You've got this! 🚀

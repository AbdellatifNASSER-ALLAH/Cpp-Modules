# C++ Module 01 - Quick Start

## 📁 Project Structure

```
01/
├── README.md           # Comprehensive concept guide
├── TESTING.md          # Testing and debugging guide
├── ex00/              # Stack vs Heap (Zombie)
├── ex01/              # Dynamic arrays (Zombie Horde)
├── ex02/              # Pointers vs References (Brain)
├── ex03/              # When to use pointer/reference (Weapons)
├── ex04/              # File I/O and string manipulation (Sed)
├── ex05/              # Member function pointers (Harl)
└── ex06/              # Switch statements (Harl Filter)
```

## 🚀 Quick Start

### Compile and Run Everything
```bash
# From the 01/ directory
for i in 0 1 2 3 5; do
    echo "=== Exercise 0$i ==="
    cd ex0$i && make && ./$(ls | grep -v '\.' | head -1)
    cd ..
done

# Ex04 needs arguments
cd ex04 && echo "test text" > test.txt && ./sed test.txt text replaced && cat test.txt.replace && cd ..

# Ex06 needs argument
cd ex06 && ./harlFilter WARNING && cd ..
```

### Check Memory Leaks
```bash
# For exercises with dynamic allocation (00, 01, 03)
valgrind --leak-check=full ex00/zombie
valgrind --leak-check=full ex01/zombie
valgrind --leak-check=full ex03/violence
```

## 📚 What You'll Learn

### Ex00: Stack vs Heap
- **Stack**: Fast, automatic cleanup, limited lifetime
- **Heap**: Manual cleanup, persists beyond function, flexible lifetime
- **When to use each**: Local/temporary objects vs objects that outlive function

### Ex01: Dynamic Arrays
- Allocating multiple objects: `new Type[n]`
- **Critical**: Use `delete[]` not `delete` for arrays
- Array initialization in a single allocation

### Ex02: Pointers vs References
- Both access same memory address
- References are safer syntax for pointers
- References can't be NULL, can't be reassigned

### Ex03: Design Choice - Pointer or Reference?
- **Reference**: When object always exists (`HumanA` always has weapon)
- **Pointer**: When object may not exist (`HumanB` may not have weapon)
- Think about "nullable" vs "always valid"

### Ex04: File I/O
- Using `std::ifstream` and `std::ofstream`
- String manipulation: `find()`, `substr()`, `append()`
- Manual find-replace implementation

### Ex05: Member Function Pointers
- Avoid if-else chains with function pointer arrays
- Syntax: `void (Class::*ptr)()`
- Call: `(this->*ptr)()`
- Cleaner, more maintainable code

### Ex06: Switch Statements
- Fall-through behavior (intentional)
- More efficient than if-else for discrete values
- Use `// fall through` comment to mark intentional fall-through

## 🎯 Key Takeaways

1. **Memory Management**: Always `delete` what you `new`, use `delete[]` for arrays
2. **RAII**: Use destructors for cleanup (Resource Acquisition Is Initialization)
3. **Design Decisions**: Choose pointer vs reference based on nullability requirements
4. **Code Quality**: Use member function pointers to avoid repetitive conditionals
5. **C++ Features**: Leverage language features (references, switch) for cleaner code

## ⚠️ Common Mistakes to Avoid

❌ Using `delete` on `new[]` allocated memory  
✅ Use `delete[]` for arrays

❌ Forgetting to delete heap allocations  
✅ Every `new` must have a corresponding `delete`

❌ Using pointer when reference is better  
✅ Use reference when object always exists

❌ Using reference when pointer is needed  
✅ Use pointer when object may be NULL

❌ Long if-else chains for dispatch  
✅ Use member function pointers or switch

## 🧪 Testing Checklist

Before submission:
- [ ] All exercises compile with `-Wall -Wextra -Werror -std=c++98`
- [ ] No memory leaks (run valgrind on ex00, ex01, ex03)
- [ ] All destructors print debug messages
- [ ] Makefiles work correctly (all, clean, fclean, re)
- [ ] Understand WHY each design choice was made
- [ ] Can explain concepts to evaluator

## 📖 Study Order

1. **Start with README.md** - Understand all concepts
2. **Read the code** - See how concepts are implemented
3. **Compile and run** - See the behavior
4. **Use valgrind** - Verify no memory leaks
5. **Read TESTING.md** - Understand edge cases
6. **Modify code** - Experiment to deepen understanding

## 🎓 During Evaluation

Be prepared to explain:
- **Ex00**: Why newZombie returns pointer (heap) but randomChump uses stack
- **Ex01**: Why delete[] is required instead of delete
- **Ex02**: Why all three addresses are identical
- **Ex03**: Why HumanA uses reference but HumanB uses pointer
- **Ex04**: How your string replacement algorithm works
- **Ex05**: What member function pointers are and why they're useful
- **Ex06**: How switch fall-through works and why it's used here

## 💡 Pro Tips

- **Understand, don't memorize**: Know WHY, not just HOW
- **Draw memory diagrams**: Visualize stack vs heap
- **Practice explaining**: Teaching is the best way to learn
- **Ask "why"**: Why this design choice? What are alternatives?
- **Read compiler errors carefully**: They tell you what's wrong

---

**Time estimate**: 
- Implementation: 3-5 hours
- Understanding: 2-3 hours  
- Testing: 1 hour
- **Total**: ~6-9 hours

Good luck! Remember: C++ is about understanding tradeoffs and making informed decisions. 🚀

# Exercise 01: Serena, my love!

## Overview
This exercise introduces the concept of **Inheritance** in C++. We create a new class `ScavTrap` that derives from the `ClapTrap` class created in Exercise 00. This demonstrates how derived classes can reuse and extend the functionality of base classes.

## Purpose
- To understand **single inheritance** syntax (`class Derived : public Base`).
- To learn about the `protected` access specifier.
- To observe the order of **constructor and destructor calls** in inheritance (Chaining).
- To override member functions (`attack`).
- To add specific functionality to a derived class.

## Implementation Details

### Modifications to `ClapTrap`
To allow `ScavTrap` to access and modify `ClapTrap`'s attributes directly:
- The attributes (`name`, `hitPoints`, etc.) in `ClapTrap.hpp` were changed from `private` to **`protected`**.
- The `ClapTrap` destructor was made **`virtual`**. This is crucial to ensure that when a derived object is deleted through a base class pointer, the derived destructor is called first, preventing memory leaks (though strictly necessary mostly for polymorphism, it's good practice here).

### The `ScavTrap` Class
defined in `ScavTrap.hpp` and implemented in `ScavTrap.cpp`.

#### Attributes (Inherited)
`ScavTrap` initializes the inherited attributes with different values in its constructor:
- `hitPoints`: **100**
- `energyPoints`: **50**
- `attackDamage`: **20**

#### Special Member Functions
- **Constructors:** `ScavTrap` constructors explicitly call the corresponding `ClapTrap` constructors.
    - *Output:* When a `ScavTrap` is created, you will see the `ClapTrap` constructor message followed by the `ScavTrap` constructor message.
- **Destructor:**
    - *Output:* When destroyed, the `ScavTrap` destructor message appears first, followed by the `ClapTrap` destructor message (Reverse order of construction).

#### New & Overridden Functions
- `void attack(const std::string& target)`: This function is **overridden** (re-implemented) in `ScavTrap` to print a different message indicating that a *ScavTrap* is attacking.
- `void guardGate()`: A new special member function specific to `ScavTrap`. It simply prints a message stating that the ScavTrap is in "Gate keeper mode".

## How it Works
The `main.cpp` tests the inheritance.
1.  **Instantiation:** Creating a `ScavTrap` initializes the base `ClapTrap` part first.
2.  **Polymorphism (Behavior):** Calling `attack` uses `ScavTrap`'s version. Calling `takeDamage` (not overridden) uses `ClapTrap`'s version.
3.  **Special Ability:** `guardGate` can be called on `ScavTrap` objects but not on plain `ClapTrap` objects.
4.  **Destruction:** The automatic destruction order confirms the parent-child relationship.

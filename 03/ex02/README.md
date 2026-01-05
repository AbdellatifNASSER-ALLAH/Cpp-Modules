# Exercise 02: Repetitive work

## Overview
In this exercise, we continue exploring inheritance by creating another derived class, `FragTrap`, which also inherits from `ClapTrap`. This reinforces the concept that multiple distinct classes can share a common base implementation while having their own unique traits.

## Purpose
- To practice creating derived classes.
- To manage different initializations for different derived classes.
- To implement another unique special member function.
- To demonstrate that sibling classes (`ScavTrap` and `FragTrap`) are independent of each other but share the same parent (`ClapTrap`).

## Implementation Details

### The `FragTrap` Class
Defined in `FragTrap.hpp` and implemented in `FragTrap.cpp`.

#### Attributes (Inherited)
`FragTrap` initializes the inherited attributes with values different from both `ClapTrap` and `ScavTrap`:
- `hitPoints`: **100** (Same as ScavTrap)
- `energyPoints`: **100** (Higher than ScavTrap)
- `attackDamage`: **30** (Highest among the three)

#### Special Member Functions
- **Constructors:** Similar to `ScavTrap`, `FragTrap` constructors chain to `ClapTrap` constructors.
- **Destructor:** Prints a specific `FragTrap` destruction message.

#### Unique Functionality
- `void highFivesGuys(void)`: This is the special ability of `FragTrap`. It prints a positive high-five request to the standard output. Unlike `ScavTrap`'s `guardGate`, this function is unique to `FragTrap`.

## How it Works
The `main.cpp` demonstrates the creation and usage of a `FragTrap`.
1.  **Construction:** We see `ClapTrap` constructed, then `FragTrap` constructed.
2.  **Usage:** `FragTrap` uses its own high attack damage and high energy pool. It can perform the `highFivesGuys` action.
3.  **Independence:** A `FragTrap` is *not* a `ScavTrap`. It does not have `guardGate`, and `ScavTrap` does not have `highFivesGuys`. They are siblings in the class hierarchy.

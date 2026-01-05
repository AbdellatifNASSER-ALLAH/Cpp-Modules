# Exercise 00: Aaaaand... OPEN!

## Overview
This exercise introduces the basic concepts of **Object-Oriented Programming (OOP)** in C++. The goal is to create a simple class named `ClapTrap` that simulates a robot with specific attributes and behaviors. This serves as the foundation for the subsequent inheritance exercises.

## Purpose
- To understand how to define a **class** in C++.
- To implement the **Orthodox Canonical Form** (Default Constructor, Copy Constructor, Copy Assignment Operator, Destructor).
- To manage **private** access specifiers for encapsulation.
- To implement member functions that manipulate the class's internal state.

## Implementation Details

### The `ClapTrap` Class
The class is defined in `ClapTrap.hpp` and implemented in `ClapTrap.cpp`.

#### Attributes (Private)
The class has the following private attributes to store the robot's status:
- `name` (std::string): The name of the robot.
- `hitPoints` (unsigned int): Represents health (initialized to **10**).
- `energyPoints` (unsigned int): Resource required to perform actions (initialized to **10**).
- `attackDamage` (unsigned int): The damage dealt when attacking (initialized to **0**).

#### Orthodox Canonical Form
To ensure the class behaves correctly during creation, copying, and destruction, the following are implemented:
1.  **Default Constructor:** Initializes a `ClapTrap` with default values.
2.  **Parameterized Constructor:** Initializes a `ClapTrap` with a specific name.
3.  **Copy Constructor:** Creates a new object as a copy of an existing one.
4.  **Copy Assignment Operator:** Assigns the values of one object to another existing object.
5.  **Destructor:** Handles any cleanup (mainly printing a message in this simple case).

#### Member Functions
- `void attack(const std::string& target)`:
    - Costs **1 energy point**.
    - Prints a message indicating the attack and damage dealt.
    - Fails if there are no hit points or energy points left.
- `void takeDamage(unsigned int amount)`:
    - Reduces `hitPoints` by the `amount`.
    - Cannot go below 0.
- `void beRepaired(unsigned int amount)`:
    - Costs **1 energy point**.
    - Restores `hitPoints` by the `amount`.
    - Fails if there are no hit points or energy points left.

## How it Works
The `main.cpp` file demonstrates the functionality. When a `ClapTrap` is created, it starts with 10 HP and 10 Energy. 
- Calling `attack()` or `beRepaired()` consumes energy.
- If `energyPoints` drops to 0, the robot can no longer act.
- If `hitPoints` drops to 0 (via `takeDamage`), the robot is "dead" and cannot act.
- All actions print descriptive messages to the standard output to trace the program's execution.

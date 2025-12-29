# tests.cpp - Account Class Testing

## Overview
This file contains the main test program for the `Account` class implementation. It simulates a banking system scenario with multiple accounts, deposits, and withdrawals.

## Data Structures and Type Definitions

### Type Aliases (typedef)
The program defines several type aliases for cleaner, more readable code:

#### `accounts_t`
```cpp
typedef std::vector<Account::t> accounts_t;
```
- **Purpose**: Container to hold multiple Account objects
- **std::vector**: Dynamic array that can grow/shrink in size
- **Account::t**: The Account class type (typedef for Account)
- **Usage**: Stores all 8 bank accounts created in the test

#### `ints_t`
```cpp
typedef std::vector<int> ints_t;
```
- **Purpose**: Container to hold integer values
- **Usage**: Stores arrays of deposit and withdrawal amounts
- **Advantage**: Provides dynamic sizing and STL compatibility

#### `acc_int_t`
```cpp
typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
```
- **Purpose**: Pairs two iterators together for synchronized iteration
- **std::pair**: Template class that holds two values as a single unit
- **Iterator**: Object that points to elements in a container (like a pointer)
- **Usage**: Allows simultaneous iteration through accounts and transaction amounts
- **Access**: `.first` for account iterator, `.second` for amount iterator

### How Vectors Work in This Program

#### Vector Initialization
```cpp
int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
accounts_t accounts( amounts, amounts + amounts_size );
```
- Creates a vector by copying elements from a C-style array
- `amounts` is the start pointer, `amounts + amounts_size` is the end pointer
- The vector constructor copies all elements between these pointers

#### Iterators
```cpp
accounts_t::iterator acc_begin = accounts.begin();
accounts_t::iterator acc_end   = accounts.end();
```
- **Iterator**: Acts like a pointer to traverse container elements
- **begin()**: Returns iterator to the first element
- **end()**: Returns iterator to one past the last element (sentinel value)
- **Usage**: Defines range for algorithms and loops

#### std::for_each
```cpp
std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
```
- **Purpose**: Applies a function to each element in a range
- **Parameters**: start iterator, end iterator, function to apply
- **std::mem_fun_ref**: Adapter that converts member function to a callable function object
- **Effect**: Calls `displayStatus()` on every Account in the vector

#### Synchronized Iteration
```cpp
for ( acc_int_t it( acc_begin, dep_begin );
      it.first != acc_end && it.second != dep_end;
      ++(it.first), ++(it.second) )
```
- **Purpose**: Iterate through two containers simultaneously
- **it.first**: Iterator pointing to current Account
- **it.second**: Iterator pointing to current deposit/withdrawal amount
- ***(it.first)**: Dereferences iterator to access the Account object
- ***(it.second)**: Dereferences iterator to access the integer value
- Both iterators increment in lockstep to keep accounts and amounts synchronized

## Main Function Workflow

### 1. **Initialization Phase**
The program creates 8 bank accounts with initial balances:
```
{ 42, 54, 957, 432, 1234, 0, 754, 16576 }
```

### 2. **Initial State Display**
- Calls `Account::displayAccountsInfos()` to show overall account statistics
- Displays individual account status for each account using `displayStatus()`

### 3. **Deposit Phase**
Processes deposits for each account with these amounts:
```
{ 5, 765, 564, 2, 87, 23, 9, 20 }
```
- Iterates through accounts and deposits simultaneously
- Calls `makeDeposit()` for each account-deposit pair
- Displays updated account information and status

### 4. **Withdrawal Phase**
Attempts withdrawals from each account with these amounts:
```
{ 321, 34, 657, 4, 76, 275, 657, 7654 }
```
- Iterates through accounts and withdrawals simultaneously
- Calls `makeWithdrawal()` for each account-withdrawal pair
- Displays final account information and status

### 5. **Final State Display**
Shows the final state of all accounts after deposits and withdrawals

## Key Features Tested
- Account creation with various initial amounts
- Static member functions (`displayAccountsInfos()`)
- Instance member functions (`displayStatus()`, `makeDeposit()`, `makeWithdrawal()`)
- Proper handling of valid/invalid transactions
- Account tracking and statistics across multiple accounts

## Technical Notes
- Uses STL containers (`std::vector`) and algorithms (`std::for_each`)
- Employs iterator pairs to synchronize operations on accounts and transaction amounts
- Tests both successful operations and edge cases (e.g., withdrawal from insufficient funds)

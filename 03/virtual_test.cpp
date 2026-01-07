#include <iostream>

// === CASE 1: NO VIRTUAL DESTRUCTOR (What ex00 looks like) ===
class BadBase {
public:
    BadBase() { std::cout << "BadBase Created" << std::endl; }
    ~BadBase() { std::cout << "BadBase Destroyed" << std::endl; } // NOT VIRTUAL
};

class BadDerived : public BadBase {
public:
    BadDerived() { std::cout << "BadDerived Created" << std::endl; }
    ~BadDerived() { std::cout << "BadDerived Destroyed (THIS WILL BE SKIPPED)" << std::endl; }
};

// === CASE 2: VIRTUAL DESTRUCTOR (What ex01/ex02 should look like) ===
class GoodBase {
public:
    GoodBase() { std::cout << "GoodBase Created" << std::endl; }
    virtual ~GoodBase() { std::cout << "GoodBase Destroyed" << std::endl; } // VIRTUAL
};

class GoodDerived : public GoodBase {
public:
    GoodDerived() { std::cout << "GoodDerived Created" << std::endl; }
    ~GoodDerived() { std::cout << "GoodDerived Destroyed (Correctly called)" << std::endl; }
};

int main() {
    std::cout << "--- TESTING NON-VIRTUAL (BAD) ---" << std::endl;
    std::cout << "Creating BadDerived on Heap but deleting via BadBase*..." << std::endl;
    BadBase* badPtr = new BadDerived();
    delete badPtr; // Undefined behavior, usually skips derived destructor

    std::cout << "\n--- TESTING VIRTUAL (GOOD) ---" << std::endl;
    std::cout << "Creating GoodDerived on Heap and deleting via GoodBase*..." << std::endl;
    GoodBase* goodPtr = new GoodDerived();
    delete goodPtr; // Correctly calls Derived then Base

    return 0;
}

#include <iostream>
#include <vector>
#include <list>
#include <iomanip> // For std::setw
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()
#include "MutantStack.hpp"

int main()
{
    // 1. Seed the pseudo-random number generator
    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "========================================================\n";
    std::cout << " TEST 1: MutantStack<vector> vs std::vector\n";
    std::cout << "========================================================\n";
    {
        // 🚨 Explicitly overriding the underlying container
        MutantStack<int, std::vector<int> > mstack;
        std::vector<int>                    compVector;

        for (int i = 0; i < 10000; ++i)
        {
            int randomVal = rand() % 100000;
            mstack.push(randomVal);
            compVector.push_back(randomVal);
        }

        // Action: Pop 50 elements
        for (int i = 0; i < 50; ++i)
        {
            mstack.pop();
            compVector.pop_back();
        }

        // Action: Push 3 specific elements
        mstack.push(42); compVector.push_back(42);
        mstack.push(84); compVector.push_back(84);
        mstack.push(21); compVector.push_back(21);

        std::cout << std::setw(15) << "MutantStack" << " | " << "std::vector\n";
        std::cout << "------------------------------------\n";

        MutantStack<int, std::vector<int> >::iterator it_m = mstack.begin();
        std::vector<int>::iterator                    it_v = compVector.begin();

        size_t totalSize = compVector.size();
        size_t index = 0;
        bool isIdentical = true;

        while (it_m != mstack.end() && it_v != compVector.end())
        {
            if (*it_m != *it_v)
                isIdentical = false;

            if (index >= totalSize - 10) // Print only the last 10
                std::cout << std::setw(15) << *it_m << " | " << *it_v << '\n';

            ++it_m;
            ++it_v;
            ++index;
        }

        if (isIdentical && mstack.size() == compVector.size())
            std::cout << "\n[SUCCESS] Vector block outputs are identical.\n";
        else
            std::cout << "\n[ERROR] Vector block outputs diverge!\n";
    }

    std::cout << "\n========================================================\n";
    std::cout << " TEST 2: MutantStack<default> vs std::list\n";
    std::cout << "========================================================\n";
    {
        // 🚨 Using default underlying container (std::deque)
        MutantStack<int>    mstack;
        std::list<int>      compList;

        for (int i = 0; i < 10000; ++i)
        {
            int randomVal = rand() % 100000;
            mstack.push(randomVal);
            compList.push_back(randomVal);
        }

        // Action: Pop 50 elements
        for (int i = 0; i < 50; ++i)
        {
            mstack.pop();
            compList.pop_back();
        }

        // Action: Push 3 specific elements
        mstack.push(42); compList.push_back(42);
        mstack.push(84); compList.push_back(84);
        mstack.push(21); compList.push_back(21);

        std::cout << std::setw(15) << "MutantStack" << " | " << "std::list\n";
        std::cout << "------------------------------------\n";

        MutantStack<int>::iterator it_m = mstack.begin();
        std::list<int>::iterator   it_l = compList.begin();

        size_t totalSize = compList.size();
        size_t index = 0;
        bool isIdentical = true;

        while (it_m != mstack.end() && it_l != compList.end())
        {
            if (*it_m != *it_l)
                isIdentical = false;

            if (index >= totalSize - 10) // Print only the last 10
                std::cout << std::setw(15) << *it_m << " | " << *it_l << '\n';

            ++it_m;
            ++it_l;
            ++index;
        }

        if (isIdentical && mstack.size() == compList.size())
            std::cout << "\n[SUCCESS] List block outputs are identical.\n";
        else
            std::cout << "\n[ERROR] List block outputs diverge!\n";
    }

    return 0;
}

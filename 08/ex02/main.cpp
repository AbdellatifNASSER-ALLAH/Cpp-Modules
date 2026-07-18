#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "--- Testing MutantStack ---" << '\n';
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << '\n';

        mstack.pop();

        std::cout << mstack.size() << '\n';

        mstack.push(3);
        mstack.push(5);
        mstack.push(733);
        //[...]
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << '\n';
            ++it;
        }
        std::stack<int> s(mstack); // Validates Canonical Form and inheritance
    }

    std::cout << "\n--- Testing std::list (Comparison) ---" << '\n';
    {
        std::list<int> list;

        list.push_back(5);
        list.push_back(17);

        std::cout << list.back() << '\n';

        list.pop_back();

        std::cout << list.size() << '\n';

        list.push_back(3);
        list.push_back(5);
        list.push_back(733);
        //[...]
        list.push_back(0);

        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << '\n';
            ++it;
        }
    }

    return 0;
}

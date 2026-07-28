#include <iostream>
#include <vector>
#include <algorithm>   // for std::swap, std::lower_bound

// ============================================================
//  Helper: generate the next Jacobsthal number
//  Sequence used: 1, 3, 5, 11, 21, 43, 85, ...
//  Formula: J(k) = (2^(k+1) + (-1)^k) / 3
// ============================================================
static int jacobsthal(int k)
{
    if (k == 0) return 0;
    if (k == 1) return 1;
    // We use the recurrence for simplicity and C++98 compatibility
    // J(n) = J(n-1) + 2*J(n-2)
    int a = 0;   // J(0)
    int b = 1;   // J(1)
    for (int i = 2; i <= k; ++i) {
        int next = b + 2 * a;
        a = b;
        b = next;
    }
    return b;
}

// ============================================================
//  Binary insertion of one element into an already sorted vector.
//  Returns the position where the element was inserted.
// ============================================================
static void binaryInsert(std::vector<int>& mainChain, int value)
{
    // std::lower_bound finds the first position where value can be inserted
    // while keeping the vector sorted (uses binary search internally)
    std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(),
                                                      mainChain.end(),
                                                      value);
    mainChain.insert(pos, value);
}

// ============================================================
//  THE CORE ALGORITHM  –  Ford-Johnson Merge-Insertion Sort
// ============================================================
void fordJohnsonSort(std::vector<int>& arr)
{
    int n = static_cast<int>(arr.size());

    // --------------------------------------------------------
    // Base cases: nothing to sort or only one element
    // --------------------------------------------------------
    if (n <= 1)
        return;

    // --------------------------------------------------------
    // STEP 1: Pair the elements and separate winners / losers
    // --------------------------------------------------------
    std::vector<int> winners;   // larger elements of each pair
    std::vector<int> losers;    // smaller elements of each pair
    int unpaired = -1;          // the leftover element when n is odd

    // Walk through the array two elements at a time
    for (int i = 0; i + 1 < n; i += 2) {
        int a = arr[i];
        int b = arr[i + 1];

        if (a > b) {
            winners.push_back(a);
            losers.push_back(b);
        } else {
            winners.push_back(b);
            losers.push_back(a);
        }
    }

    // If the number of elements is odd, the last one has no partner
    if (n % 2 == 1)
        unpaired = arr[n - 1];

    // --------------------------------------------------------
    // STEP 2: Recursively sort ONLY the winners
    //         (this is the recursive call of the algorithm)
    // --------------------------------------------------------
    fordJohnsonSort(winners);   // winners becomes the sorted "main chain"

    // At this point "winners" is fully sorted.
    // We will now build the final sorted sequence into "mainChain".
    std::vector<int> mainChain = winners;

    // --------------------------------------------------------
    // STEP 3: Insert the losers using the Jacobsthal order
    // --------------------------------------------------------

    // 3.1  The first loser can be inserted at the very beginning
    //      with ZERO comparisons (it is smaller than its partner,
    //      and its partner is the smallest element of the main chain).
    if (!losers.empty()) {
        mainChain.insert(mainChain.begin(), losers[0]);
    }

    // 3.2  Insert the remaining losers following the Jacobsthal sequence
    //      The classic order is:
    //      b3, b2, b5, b4, b11, b10, …, b6, …
    int loserCount = static_cast<int>(losers.size());
    int inserted = 1;   // we already inserted losers[0]

    int k = 2;          // start looking for Jacobsthal numbers from J(2)=3
    while (inserted < loserCount) {
        int j = jacobsthal(k);          // next Jacobsthal number

        // We insert from index (j-1) down to the previous boundary
        // (but never beyond the number of losers we still have)
        int end   = std::min(j, loserCount);
        int start = inserted;           // the first index we have not yet inserted

        // Insert in reverse order: end-1, end-2, …, start
        for (int i = end - 1; i >= start; --i) {
            binaryInsert(mainChain, losers[i]);
        }

        inserted = end;
        ++k;
    }

    // --------------------------------------------------------
    // 3.3  Finally insert the unpaired element (if any)
    // --------------------------------------------------------
    if (unpaired != -1)
        binaryInsert(mainChain, unpaired);

    // --------------------------------------------------------
    // Copy the fully sorted result back into the original array
    // --------------------------------------------------------
    arr = mainChain;
}

// ============================================================
//  Small test program
// ============================================================
int main()
{
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(2);
    numbers.push_back(9);
    numbers.push_back(1);
    numbers.push_back(7);
    numbers.push_back(3);
    numbers.push_back(8);
    numbers.push_back(4);
    numbers.push_back(6);

    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    fordJohnsonSort(numbers);

    std::cout << "After:  ";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    return 0;
}

#include "PmergeMe.hpp"
#include <iomanip>

// FIX: Helper function to print truncated containers as per subject requirements
template <typename T>
void printTruncated(const std::string &label, const T &container) {
    std::cout << label;
    typename T::const_iterator it = container.begin();
    for (int i = 0; i < 5 && it != container.end(); ++i, ++it) {
        std::cout << *it << " ";
    }
    if (container.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

int main(int ac, char **av) {
    // FIX: Wrapped entire logic in try-catch block for compliance with error handling requirements
    try {
        if (ac < 2) {
            throw std::invalid_argument("Error: No input numbers provided.");
        }

        PmergeMe::Vector v;
        PmergeMe::Deque d;

        // FIX: Timing Vector: includes both data management (prepare) and sorting
        std::clock_t v_start = std::clock();
        PmergeMe::prepare(v, ac, av);
        // FIX: Added 'Before:' printing in main before sorting starts
        printTruncated("Before: ", v);
        PmergeMe::sort(v);
        std::clock_t v_end = std::clock();

        // FIX: Timing Deque: includes both data management (prepare) and sorting
        std::clock_t d_start = std::clock();
        PmergeMe::prepare(d, ac, av);
        PmergeMe::sort(d);
        std::clock_t d_end = std::clock();

        // FIX: Added 'After:' printing in main after sorting finishes
        printTruncated("After:  ", v);

        // FIX: Displaying elapsed time for Vector in microseconds
        double v_time = static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << v.size() 
                  << " elements with std::vector : " << std::fixed << std::setprecision(5) << v_time << " us" << std::endl;

        // FIX: Displaying elapsed time for Deque in microseconds
        double d_time = static_cast<double>(d_end - d_start) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << d.size() 
                  << " elements with std::deque  : " << std::fixed << std::setprecision(5) << d_time << " us" << std::endl;

    } catch (const std::exception &e) {
        // FIX: Catching exceptions and printing strictly to std::cerr
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

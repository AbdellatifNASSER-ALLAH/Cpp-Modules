#include "PmergeMe.hpp"
#include <iomanip>

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
    try {

        PmergeMe::Vector v;
        PmergeMe::Deque d;

        std::clock_t v_start = std::clock();
        PmergeMe::prepare(v, ac, av);
        printTruncated("Before: ", v);
        PmergeMe::sort(v);
        std::clock_t v_end = std::clock();

        std::clock_t d_start = std::clock();
        PmergeMe::prepare(d, ac, av);
        PmergeMe::sort(d);
        std::clock_t d_end = std::clock();

        printTruncated("After:  ", v);

        double v_time = static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << v.size() 
                  << " elements with std::vector : " << std::fixed << std::setprecision(5) << v_time << " us" << std::endl;

        double d_time = static_cast<double>(d_end - d_start) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << d.size() 
                  << " elements with std::deque  : " << std::fixed << std::setprecision(5) << d_time << " us" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

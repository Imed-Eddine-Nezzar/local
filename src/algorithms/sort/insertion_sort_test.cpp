#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>            // std::is_sorted
#include <ios>                  // std::boolalpha
#include "../../util.hpp"
#include "insertion_sort.cpp"
#include "selection_sort.cpp"
#include "bubble_sort.cpp"
#include "heap_sort.cpp"


int main(void) {
    using namespace local;

    // insertion sort
    int arr[10];
    std::vector<int> vec(10);
    std::list<int> lst(10);

    std::cout << std::boolalpha;

    std::cout << "insertion sort:\n";
    util::fill_random(std::begin(arr), std::end(arr), 0, 100);
    util::fill_random(vec.begin(), vec.end(), 0, 100);
    util::fill_random(lst.begin(), lst.end(), 0, 100);

    algorithms::sort::insertion_sort(std::begin(arr), std::end(arr));
    algorithms::sort::insertion_sort(vec.begin(), vec.end());
    algorithms::sort::insertion_sort(lst.begin(), lst.end());

    std::cout << "array sorted: " << std::is_sorted(std::begin(arr), std::end(arr)) << "\n";
    std::cout << "vector sorted: " << std::is_sorted(vec.begin(), vec.end()) << "\n";
    std::cout << "list sorted: " << std::is_sorted(lst.begin(), lst.end()) << "\n";

    std::cout << "\n";

    std::cout << "selection sort:\n";
    util::fill_random(std::begin(arr), std::end(arr), 0, 100);
    util::fill_random(vec.begin(), vec.end(), 0, 100);
    util::fill_random(lst.begin(), lst.end(), 0, 100);

    algorithms::sort::selection_sort(std::begin(arr), std::end(arr));
    algorithms::sort::selection_sort(vec.begin(), vec.end());
    algorithms::sort::selection_sort(lst.begin(), lst.end());

    std::cout << "array sorted: " << std::is_sorted(std::begin(arr), std::end(arr)) << "\n";
    std::cout << "vector sorted: " << std::is_sorted(vec.begin(), vec.end()) << "\n";
    std::cout << "list sorted: " << std::is_sorted(lst.begin(), lst.end()) << "\n";


    std::cout << "\n";

    std::cout << "bubble_sort sort:\n";
    util::fill_random(std::begin(arr), std::end(arr), 0, 100);
    util::fill_random(vec.begin(), vec.end(), 0, 100);
    util::fill_random(lst.begin(), lst.end(), 0, 100);

    algorithms::sort::bubble_sort(std::begin(arr), std::end(arr));
    algorithms::sort::bubble_sort(vec.begin(), vec.end());
    algorithms::sort::bubble_sort(lst.begin(), lst.end());

    std::cout << "array sorted: " << std::is_sorted(std::begin(arr), std::end(arr)) << "\n";
    std::cout << "vector sorted: " << std::is_sorted(vec.begin(), vec.end()) << "\n";
    std::cout << "list sorted: " << std::is_sorted(lst.begin(), lst.end()) << "\n";

    std::cout << "\n";

    std::cout << "heap sort:\n";
    util::fill_random(vec.begin(), vec.end(), 0, 100);

    util::output(vec);

    algorithms::sort::build_heap(vec.begin(), vec.end());

    util::output(vec);
    std::make_heap(vec.begin(), vec.end());
    util::output(vec);
    std::cout << std::is_heap(vec.begin(), vec.end()) << "\n";


    return 0;
}
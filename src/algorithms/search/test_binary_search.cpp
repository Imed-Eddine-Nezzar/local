#include <iostream>
#include <vector>
#include <numeric>
#include "../../util.hpp"
#include "binary_search.cpp"

int main(int argc, char const *argv[]) {
    using namespace local;
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 10);
    util::output(v);
    std::cout << std::boolalpha
                << algorithms::search::binary_search(v.begin(), v.end(), 10) << "\n";
    return 0;
}
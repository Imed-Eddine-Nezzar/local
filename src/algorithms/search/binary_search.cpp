#ifndef __ALGORITHMS_SEARCH_BINARY_SEARCH_HPP__
#define __ALGORITHMS_SEARCH_BINARY_SEARCH_HPP__

#include <iterator>
#include <functional>


namespace local {
  namespace algorithms {
    namespace search {

      template <
        typename RandomAccessIt,
        typename IteratorTag = typename std::iterator_traits<RandomAccessIt>::iterator_category
      >
      bool binary_search(
        RandomAccessIt first,
        RandomAccessIt last,
        const typename std::iterator_traits<RandomAccessIt>::value_type& val,
        std::random_access_iterator_tag = IteratorTag()
        ) {
        RandomAccessIt mid;
        while (first < last) {
          mid = first + (last - first) / 2;
          if (val == *mid)
            return true;
          else if (val < *mid)
            last = mid - 1;
          else
            first = mid + 1;
        }
        return false;
      }

    } // namespace search
  } // namespace algorithms
} // local

#endif // __ALGORITHMS_SEARCH_BINARY_SEARCH_HPP__
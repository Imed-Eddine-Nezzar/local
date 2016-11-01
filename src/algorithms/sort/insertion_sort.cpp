#ifndef __ALGORITHMS_SORT_INSERTION_SORT_HPP__
#define __ALGORITHMS_SORT_INSERTION_SORT_HPP__

#include <iterator>         // std::bidirectional_iterator_tag, std::prev,  std::iterator_traits
                            // std::bidirectional_itertor_tag
#include <functional>       // std::less

namespace local {
    namespace algorithms {
        namespace sort {
            
            template <typename BidirectionalIter, typename Compare>
            void insertion_sort(BidirectionalIter first, BidirectionalIter last, Compare comp, std::bidirectional_iterator_tag) {
                if (std::distance(first, last) > 1) {
                    BidirectionalIter current;
                    for (auto it = std::next(first); it != last; ++it) {
                        for (current = it; current != first and comp(*current, *std::prev(current)); --current) {
                            std::iter_swap(current, std::prev(current));
                        }
                    }
                }
            }


            template <typename BidirectionalIter, typename Compare = std::less<typename std::iterator_traits<BidirectionalIter>::value_type>>
            inline void insertion_sort(BidirectionalIter first, BidirectionalIter last, Compare comp = Compare()) {
                insertion_sort(first, last, comp, typename std::iterator_traits<BidirectionalIter>::iterator_category());
            }

        } // namespace sort
    } // namespace algorithms
} // namespace local

#endif // __ALGORITHMS_SORT_INSERTION_SORT_HPP__

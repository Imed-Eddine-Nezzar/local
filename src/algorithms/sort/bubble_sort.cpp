#ifndef __ALGORITHMS_SORT_BUBBLE_SORT_HPP__
#define __ALGORITHMS_SORT_BUBBLE_SORT_HPP__

#include <iterator>             // std::iterator_traits, std::iter_swap, std::prev, std::next
                                // std::bidirectional_iterator_tag
#include <functional>           // std::less

// TODO: implement a forward_itertor compatible version

namespace local { 
    namespace algorithms {
        namespace sort {

            template <typename BidirectionalIter, class Compare>
            void bubble_sort(BidirectionalIter first, BidirectionalIter last, Compare comp, std::bidirectional_iterator_tag) {
                bool made_swap;
                do {
                    made_swap = false;
                    for (auto current = std::next(first); current != last; ++current) {
                        if (comp(*current, *std::prev(current))) {
                            std::iter_swap(current, std::prev(current));
                            made_swap = true;
                        }
                    }
                    --last;
                } while (made_swap);
            }


            template <typename BidirectionalIter, class Compare = std::less<typename std::iterator_traits<BidirectionalIter>::value_type>>
            inline void bubble_sort(BidirectionalIter first, BidirectionalIter last,
                             Compare comp = std::less<typename std::iterator_traits<BidirectionalIter>::value_type>()) {
                bubble_sort(first, last, comp, typename std::iterator_traits<BidirectionalIter>::iterator_category());
            }

        } // namespace sort
    } // namespace algorithms
} // namespace local

#endif // __ALGORITHMS_SORT_BUBBLE_SORT_HPP__



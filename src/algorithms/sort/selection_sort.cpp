#ifndef __ALGORITHMS_SORT_SELECTION_SORT_HPP__
#define __ALGORITHMS_SORT_SELECTION_SORT_HPP__

#include <iterator>          // std::iterator_traits, std::forward_iterator_tag, std::iter_swap
#include <functional>        // std::less
#include "../misc.hpp"       // local::algorithms::pick_element

namespace local {

    namespace algorithms {

        namespace sort {

            template <
                typename ForwardIt,
                typename Compare = std::less<typename std::iterator_traits<ForwardIt>::value_type>,
                typename IterTag = typename std::iterator_traits<ForwardIt>::iterator_category
            >
            void selection_sort(ForwardIt first, ForwardIt last,
                                Compare comp = {},
                                std::forward_iterator_tag = IterTag())
            {
                if (std::distance(first, last) > 1) {
                    ForwardIt elem;
                    for (auto current = first; current != last; ++current) {
                        elem = local::algorithms::pick_element(current, last, comp);
                        std::iter_swap(elem, current);
                    }
                }
            }

        } // namespace sort
    } // namespace algorithms
} // namespace local

#endif // __ALGORITHMS_SORT_SELECTION_SORT_HPP__

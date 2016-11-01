#ifndef __ALGORITHMS_MISC_HPP__
#define __ALGORITHMS_MISC_HPP__

namespace local {
    namespace algorithms {

        template <
            typename ForwardIt,
            typename Compare,
            typename IterTag = typename std::iterator_traits<ForwardIt>::iterator_category
        >
        ForwardIt pick_element(ForwardIt first, ForwardIt last, Compare comp, std::forward_iterator_tag = IterTag()) {
            ForwardIt elem{first};
            for (auto it = ++first; it != last; ++it) {
            if (comp(*it, *elem))
                elem = it;
            }
            return elem;
        }


        template <
            typename ForwardIt,
            typename IterTag = typename std::iterator_traits<ForwardIt>::iterator_category
        >
        inline ForwardIt max_element(ForwardIt first, ForwardIt last, std::forward_iterator_tag = IterTag()) {
            return local::algorithms::pick_element(first, last, std::greater<typename std::iterator_traits<ForwardIt>::value_type>());
        }


        template <
            typename ForwardIt,
            typename IterTag = typename std::iterator_traits<ForwardIt>::iterator_category
        >
        inline ForwardIt min_element(ForwardIt first, ForwardIt last, std::forward_iterator_tag = IterTag()) {
            return local::algorithms::pick_element(first, last, std::less<typename std::iterator_traits<ForwardIt>::value_type>());
        }

        namespace sort {
            template <
                typename ForwardIt,
                typename Compare = std::less<typename std::iterator_traits<ForwardIt>::value_type>,
                typename IterTag = typename std::iterator_traits<ForwardIt>::iterator_category
            >
            bool is_sorted(ForwardIt first, ForwardIt last, Compare comp = {}, std::forward_iterator_tag = IterTag()) {
                for (auto it = first; it != last; ++it)
                    if (comp(*std::next(it), *it))
                        return false;
                return true;
            }

        } // namespace sort

    } // namespace algorithms
} // namespace local

#endif // __ALGORITHMS_MISC_HPP__

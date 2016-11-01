#ifndef __LOCAL_UTIL_HPP__
#define __LOCAL_UTIL_HPP__

#include <iostream>             // std::cout, std::ostream
#include <random>               // std::random_device
#include <algorithm>            // std::copy, std::generate
#include <iterator>             // std::ostream_iterator, std::input_iterator_tag, std::output_iterator_tag
                                // std::iterator_traits

// TODO: implement random string generator

namespace local {
    namespace util {

        template <
          class InputIt,
          class IterTag = typename std::iterator_traits<InputIt>::iterator_category
        >
        inline void output(
            InputIt first, InputIt last,
            std::ostream& os = std::cout,
            const char* sep = " ",
            const char* end = "\n",
            std::input_iterator_tag = IterTag())
        {
            typedef typename std::iterator_traits<InputIt>::value_type value_type;
            std::copy(first, last, std::ostream_iterator<value_type>(os, sep));
            os << "\n";
        }

        template <class InputIt>
        inline void output(InputIt first, InputIt last, std::ostream& os = std::cout, const char* sep = " ") {
            output(first, last, os, sep, typename std::iterator_traits<InputIt>::iterator_category());
        }

        template <class Container>
        inline void output(const Container& c, std::ostream& os = std::cout, const char* sep = " ") {
            output(c.begin(), c.end(), os, sep);
        }


        template <class OutputIt, typename T>
        inline void fill_n_random(OutputIt first, T start, T end, long n, std::output_iterator_tag) {
            if (n > 0) {
                std::random_device rand;
                std::generate_n(first, n, [&]() {
                    return (rand() % (end - start)) + start;
                });
            }
        }

        template <class OutputIt, typename T>
        inline void fill_n_random(OutputIt first, T start, T end, long n) {
            fill_n_random(first, start, end, n, typename std::iterator_traits<OutputIt>::iterator_category());
        }

        template <class ForwardIt, typename T>
        inline void fill_random(ForwardIt first, ForwardIt last, T start, T end, typename std::forward_iterator_tag) {
            std::random_device rand;
            std::generate(first, last, [&]() {
                return (rand() % (end - start)) + start;
            });
        }

        template <class ForwardIt, typename T>
        inline void fill_random(ForwardIt first, ForwardIt last, T start, T end) {
            fill_random(first, last, start, end,
                        typename std::iterator_traits<ForwardIt>::iterator_category());
        }

    } // namespace util
} // namespace local

#endif // __LOCAL_UTIL_HPP__

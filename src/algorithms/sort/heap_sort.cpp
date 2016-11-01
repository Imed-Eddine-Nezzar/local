#ifndef __ALGORITHMS_SORT_HEAP_SORT_HPP__
#define __ALGORITHMS_SORT_HEAP_SORT_HPP__

#include <algorithm>
#include <functional>
#include <iterator>

namespace local {
  namespace algorithms {
    namespace sort {

      template <
        typename RandomAccessIt,
        class Compare = std::less<typename std::iterator_traits<RandomAccessIt>::value_type>,
        typename IteratorTag = typename std::iterator_traits<RandomAccessIt>::iterator_category
      >
      void siftdown(
        RandomAccessIt first,
        RandomAccessIt i,
        RandomAccessIt last,
        Compare comp                    = Compare(),
        std::random_access_iterator_tag = IteratorTag()
      ) {
        auto c = i + (first - i + 1);

        auto pos = (c > last)       ? i
                 : (comp(*c, *i))   ? (comp(*(c + 1), *c)) ? c + 1 : c
                 :                    i;

          if (pos != i) {
            std::iter_swap(pos, i);
            siftdown(first, pos, last, comp);
          }
      }


      template <
        typename RandomAccessIt,
        class Compare = std::less<typename std::iterator_traits<RandomAccessIt>::value_type>,
        typename IteratorTag = typename std::iterator_traits<RandomAccessIt>::iterator_category
      >
      void build_heap(RandomAccessIt first,
                      RandomAccessIt last,
                      Compare comp                             = Compare(),
                      std::random_access_iterator_tag iter_tag = IteratorTag()) {

        for (auto it = first + (last - first) / 2; it != first - 1; --it) {
          siftdown(first, it, last, comp, iter_tag);
        }
      }
            /*
            template <typename T>
            void siftdown(T* arr, size_t i, size_t size) {
                size_t max = i;

                size_t l = i * 2 + 1;
                if (l < size and arr[l] > arr[max])
                    max = l;

                size_t r = i * 2 + 2;
                if (r < size and arr[r] > arr[max])
                    max = r;

                if (max != i) {
                    std::swap(arr[i], arr[max]);
                    siftdown(arr, max, size);
                }
            }

            template <typename T>
            void build_heap(T* arr, size_t size) {
                for (int i = size / 2; i >= 0; --i)
                    siftdown(arr, i, size);
            }

            template <typename T>
            void heap_sort(T* arr, size_t size) {
                build_heap(arr, size);

                while (size > 0) {
                    std::swap(arr[0], arr[size - 1]);
                    size -= 1;
                    siftdown(arr, 0, size);
                }
            }
            */
        } // namespace sort
    } // namespace algorithms
} // namespace local

#endif // __ALGORITHMS_SORT_HEAP_SORT_HPP__


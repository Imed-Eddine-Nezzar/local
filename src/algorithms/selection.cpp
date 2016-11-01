#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <functional>


template <
  typename InputIt,
  typename T,
  typename IterTag = typename std::iterator_traits<InputIt>::iterator_category
>
inline void fill_random(
    InputIt first,
    InputIt last,
    T start, T end,
    std::input_iterator_tag = IterTag())
{
  std::random_device rand;
  std::generate(first, last, [&]() {
      return (rand() % (end - start)) + start;
  });
}


template <
    typename ForwardIt,
    typename Compare,
    typename IterTag = typename std::iterator_traits<ForwardIt>::iterator_category
>
ForwardIt pick_element(
    ForwardIt first, ForwardIt last,
    Compare comp,
    std::forward_iterator_tag = IterTag()) 
{
    ForwardIt elem{first};
    for (auto it = ++first; it != last; ++it)
      if (comp(*it, *elem))
          elem = it;
    return elem;
}


template <
  typename ForwardIt,
  typename Compare = std::less<typename std::iterator_traits<ForwardIt>::value_type>,
  typename IterTag = typename std::iterator_traits<ForwardIt>::iterator_category
>
void selection_sort(
    ForwardIt first, ForwardIt last,
    Compare comp = {},
    std::forward_iterator_tag = IterTag())
{
  if (std::distance(first, last) > 1) {
    ForwardIt elem;
    for (auto current = first; current != last; ++current) {
        elem = pick_element(current, last, comp);
        std::iter_swap(elem, current);
    }
  }
}


template <
  typename Container,
  typename T,
  typename Compare
>
bool sort_test(T start, T end, int size, Compare comp) {
  Container cnt{size};
  fill_random(cnt.begin(), cnt.end(), 0, 10000);
  selection_sort(cnt.begin(), cnt.end(), comp);
  return std::is_sorted(cnt.begin(), cnt.end(), comp);
}


int main() {
  std::pair<int, int> ranges[] = {{-1000000, 0}, {0, 1000000}, {-1000000, 1000000}};
  std::cout << std::boolalpha;

  std::cout << "\nVector: \n";
  for (auto& range : ranges) {
    std::cout << "Passed: "
              << sort_test<std::vector<int>, int, std::less<int>>(range.first, range.second, 1000000, std::less<int>())
              << "\n";
  }

  std::cout << "\nList: \n";
  for (auto& range : ranges) {
    std::cout << "Passed: "
              << sort_test<std::list<int>, int, std::greater<int>>(range.first, range.second, 1000000, std::greater<int>())
              << "\n";
  }

  std::cout << "\nDeque: \n";
  for (auto& range : ranges) {
    std::cout << "Passed: "
              << sort_test<std::deque<int>, int, std::less<int>>(range.first, range.second, 1000000, std::less<int>())
              << "\n";
  }
}

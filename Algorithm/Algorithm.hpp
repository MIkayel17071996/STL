#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <utility>
#include <random>
#include "/home/mikayel/Desktop/STL/Iterators/InputIterator.hpp"
#include "/home/mikayel/Desktop/STL/Iterators/OutputIterator.hpp"
#include "/home/mikayel/Desktop/STL/Iterators/ForwardIterator.hpp"
#include "/home/mikayel/Desktop/STL/Iterators/BidirectionalIterator.hpp"
#include "/home/mikayel/Desktop/STL/Iterators/RandomAccessIterator.hpp"

namespace alg
{
    template <class InputIt, class UnaryFunc>
    constexpr UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f);

    template <class InputIt, class Size, class UnaryFunc>
    constexpr InputIt for_each_n(InputIt first, Size n, UnaryFunc f);

    template <class InputIt, class UnaryPred>
    bool all_of(InputIt first, InputIt last, UnaryPred p);

    template <class InputIt, class UnaryPred>
    bool any_of(InputIt first, InputIt last, UnaryPred p);

    template <class InputIt, class UnaryPred>
    bool none_of(InputIt first, InputIt last, UnaryPred p);

    template <class InputIt, class T>
    InputIt find(InputIt first, InputIt last, const T &value);

    template <class InputIt, class UnaryPred>
    InputIt find_if(InputIt first, InputIt last, UnaryPred p);

    template <class InputIt, class UnaryPred>
    InputIt find_if_not(InputIt first, InputIt last, UnaryPred q);

    template <class ForwardIt1, class ForwardIt2>
    ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                        ForwardIt2 s_first, ForwardIt2 s_last);

    template <class ForwardIt1, class ForwardIt2, class BinaryPred>
    ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                        ForwardIt2 s_first, ForwardIt2 s_last,
                        BinaryPred p);

    template <class InputIt, class ForwardIt>
    InputIt find_first_of(InputIt first, InputIt last,
                          ForwardIt s_first, ForwardIt s_last);

    template <class InputIt, class ForwardIt, class BinaryPred>
    InputIt find_first_of(InputIt first, InputIt last,
                          ForwardIt s_first, ForwardIt s_last,
                          BinaryPred p);

    template <class ForwardIt>
    ForwardIt adjacent_find(ForwardIt first, ForwardIt last);

    template <class ForwardIt, class BinaryPred>
    ForwardIt adjacent_find(ForwardIt first, ForwardIt last,
                            BinaryPred p);

    template <class InputIt, class T>
    size_t count(InputIt first, InputIt last, const T &value);

    template <class InputIt, class UnaryPred>
    size_t count_if(InputIt first, InputIt last, UnaryPred p);

    template <class InputIt1, class InputIt2>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2);

    template <class InputIt1, class InputIt2, class BinaryPred>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2, BinaryPred p);

    template <class InputIt1, class InputIt2>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2, InputIt2 last2);

    template <class InputIt1, class InputIt2, class BinaryPred>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2, InputIt2 last2, BinaryPred p);

    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2);

    template <class InputIt1, class InputIt2, class BinaryPred>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, BinaryPred p);

    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2);

    template <class InputIt1, class InputIt2, class BinaryPred>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2, BinaryPred p);

    template <class ForwardIt1, class ForwardIt2>
    ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
                      ForwardIt2 s_first, ForwardIt2 s_last);

    template <class ForwardIt1, class ForwardIt2, class BinaryPred>
    ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
                      ForwardIt2 s_first, ForwardIt2 s_last,
                      BinaryPred p);

    template <class InputIt, class OutputIt>
    OutputIt copy(InputIt first, InputIt last,
                  OutputIt dest_first);

    template <class InputIt, class OutputIt, class UnaryPred>
    OutputIt copy_if(InputIt first, InputIt last,
                     OutputIt d_first, UnaryPred pred);

    template <class InputIt, class Size, class OutputIt>
    OutputIt copy_n(InputIt first, Size count, OutputIt result);

    template <class BidirIt1, class BidirIt2>
    BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last);

    template <class InputIt, class OutputIt>
    OutputIt move(InputIt first, InputIt last,
                  OutputIt d_first);

    template <class BidirIt1, class BidirIt2>
    BidirIt2 move_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last);

    template <class InputIt, class OutputIt, class UnaryOp>
    OutputIt transform(InputIt first1, InputIt last1,
                       OutputIt d_first, UnaryOp unary_op);

    template <class InputIt1, class InputIt2,
              class OutputIt, class BinaryOp>
    OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                       OutputIt d_first, BinaryOp binary_op);

    template <class ForwardIt, class T>
    void replace(ForwardIt first, ForwardIt last,
                 const T &old_value, const T &new_value);

    template <class ForwardIt, class UnaryPred, class T>
    void replace_if(ForwardIt first, ForwardIt last,
                    UnaryPred p, const T &new_value);

    template <class InputIt, class OutputIt, class T>
    OutputIt replace_copy(InputIt first, InputIt last, OutputIt d_first,
                          const T &old_value, const T &new_value);

    template <class InputIt, class OutputIt, class UnaryPred, class T>
    OutputIt replace_copy_if(InputIt first, InputIt last, OutputIt d_first,
                             UnaryPred p, const T &new_value);

    template <class ForwardIt, class T>
    void fill(ForwardIt first, ForwardIt last, const T &value);

    template <class OutputIt, class Size, class T>
    OutputIt fill_n(OutputIt first, Size count, const T &value);

    template <class ForwardIt, class Generator>
    void generate(ForwardIt first, ForwardIt last, Generator g);

    template <class OutputIt, class Size, class Generator>
    OutputIt generate_n(OutputIt first, Size count, Generator g);

    template <class ForwardIt, class T>
    ForwardIt remove(ForwardIt first, ForwardIt last, const T &value);

    template <class ForwardIt, class UnaryPred>
    ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPred p);

    template <class InputIt, class OutputIt, class T>
    OutputIt remove_copy(InputIt first, InputIt last,
                         OutputIt d_first, const T &value);

    template <class InputIt, class OutputIt, class UnaryPred>
    OutputIt remove_copy_if(InputIt first, InputIt last,
                            OutputIt d_first, UnaryPred p);

    template <class ForwardIt>
    ForwardIt unique(ForwardIt first, ForwardIt last);

    template <class ForwardIt, class BinaryPred>
    ForwardIt unique(ForwardIt first, ForwardIt last, BinaryPred p);

    template <class InputIt, class OutputIt>
    OutputIt unique_copy(InputIt first, InputIt last, OutputIt d_first);

    template <class InputIt, class OutputIt, class BinaryPred>
    OutputIt unique_copy(InputIt first, InputIt last,
                         OutputIt d_first, BinaryPred p);

    ///////////////////////////////////////////////////////////////////////

    template <class T>
    void swap(T &a, T &b);

    template <class ForwardIt1, class ForwardIt2>
    void iter_swap(ForwardIt1 a, ForwardIt2 b);

    template <class ForwardIt1, class ForwardIt2>
    ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1,
                           ForwardIt2 first2);
    ///////////////////////////////////////////////////////////////////////

    template <class BidirIt>
    void reverse(BidirIt first, BidirIt last);

    template <class BidirIt, class OutputIt>
    OutputIt reverse_copy(BidirIt first, BidirIt last,
                          OutputIt d_first);

    template <class ForwardIt>
    ForwardIt rotate(ForwardIt first, ForwardIt middle, ForwardIt last);

    template <class ForwardIt, class OutputIt>
    OutputIt rotate_copy(ForwardIt first, ForwardIt n_first,
                         ForwardIt last, OutputIt d_first);

    template <class ForwardIt, class UnaryPred>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPred p);

    template <class ForwardIt, class BinaryPred>
    ForwardIt qs_partition(ForwardIt first, ForwardIt last, BinaryPred p);

    template <class InputIt, class OutputIt1,
              class OutputIt2, class UnaryPred>
    std::pair<OutputIt1, OutputIt2>
    partition_copy(InputIt first, InputIt last,
                   OutputIt1 d_first_true, OutputIt2 d_first_false,
                   UnaryPred p);

    template <class InputIt, class UnaryPred>
    bool is_partitioned(InputIt first, InputIt last, UnaryPred p);

    template <class RandomIt, class Compare = std::less<>>
    void insertion_sort(RandomIt first, RandomIt last, Compare comp = Compare{});

    template <class RandomIt, class Compare = std::less<>>
    void comb_sort(RandomIt first, RandomIt last, Compare comp = Compare{});

    template <class RandomIt, class Compare = std::less<>>
    void quick_sort(RandomIt first, RandomIt last, Compare comp = Compare{});

    template <class RandomIt, class Compare>
    void merge_sort(RandomIt first, RandomIt last, Compare comp = std::less<>{});

    template <class RandomIt, class Compare>
    void merge(RandomIt first, RandomIt middle, RandomIt last, Compare comp = std::less<>{});

    template <class RandomIt, class Compare = std::less<>>
    void sort(RandomIt first, RandomIt last, Compare comp = Compare{});

    template <class RandomIt, class Compare = std::less<>>
    void stable_sort(RandomIt first, RandomIt last, Compare comp = Compare{});

    template <class ForwardIt, class Compare = std::less<>>
    bool is_sorted(ForwardIt first, ForwardIt last, Compare comp = Compare{});

    template <typename RandomIt, typename Compare = std::less<>>
    void nth_element(RandomIt first, RandomIt nth, RandomIt last, Compare comp = Compare{});

    template <class ForwardIt, class T, class Compare = std::less<>>
    ForwardIt lower_bound(ForwardIt first, ForwardIt last,
                          const T &value, Compare comp = Compare{});

    template <class ForwardIt, class T, class Compare = std::greater<>>
    ForwardIt upper_bound(ForwardIt first, ForwardIt last,
                          const T &value, Compare comp = Compare{});

    template <class ForwardIt, class T, class Compare>
    std::pair<ForwardIt, ForwardIt>
    equal_range(ForwardIt first, ForwardIt last,
                const T &value, Compare comp);

    template <class ForwardIt, class T>
    bool binary_search(ForwardIt first, ForwardIt last, const T &value);

    template <class InputIt1, class InputIt2, class Compare = std::less<>>
    bool includes(InputIt1 first1, InputIt1 last1,
                  InputIt2 first2, InputIt2 last2, Compare comp = Compare{});

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare = std::less<>>
    OutputIt set_union(InputIt1 first1, InputIt1 last1,
                       InputIt2 first2, InputIt2 last2,
                       OutputIt d_first, Compare comp = Compare{});

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare = std::less<>>
    OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2,
                              OutputIt d_first, Compare comp = Compare{});

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare = std::less<>>
    OutputIt set_difference(InputIt1 first1, InputIt1 last1,
                            InputIt2 first2, InputIt2 last2,
                            OutputIt d_first, Compare comp = Compare{});

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare = std::less<>>
    OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
                                      InputIt2 first2, InputIt2 last2,
                                      OutputIt d_first, Compare comp = Compare{});

}

#include "Algorithm.tpp"

#endif // ALGORITHM_HPP

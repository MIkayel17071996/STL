#ifndef ALGORITHM_TPP
#define ALGORITHM_TPP

#include <type_traits>
#include <vector>

namespace alg
{
    template <class InputIt, class UnaryFunc>
    constexpr UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
    {
        for (; first != last; ++first)
        {
            f(*const_cast<typename std::remove_pointer<typename InputIt::pointer>::type *>(first.operator->()));
        }
        return f;
    }

    template <class InputIt, class Size, class UnaryFunc>
    constexpr InputIt for_each_n(InputIt first, Size n, UnaryFunc f)
    {
        for (size_t i = 0; i < n; ++first, ++i)
        {
            f(*const_cast<typename std::remove_pointer<typename InputIt::pointer>::type *>(first.operator->()));
        }
        return first;
    }

    template <class InputIt, class UnaryPred>
    bool all_of(InputIt first, InputIt last, UnaryPred p)
    {
        for (; first != last; ++first)
        {
            if (!p(*first))
            {
                return false;
            }
        }
        return true;
    }

    template <class InputIt, class UnaryPred>
    bool any_of(InputIt first, InputIt last, UnaryPred p)
    {
        for (; first != last; ++first)
        {
            if (p(*first))
            {
                return true;
            }
        }
        return false;
    }

    template <class InputIt, class UnaryPred>
    bool none_of(InputIt first, InputIt last, UnaryPred p)
    {
        for (; first != last; ++first)
        {
            if (p(*first))
            {
                return false;
            }
        }
        return true;
    }

    template <class InputIt, class T>
    InputIt find(InputIt first, InputIt last, const T &value)
    {
        for (; first != last; ++first)
        {
            if (*first == value)
            {
                return first;
            }
        }
        return last;
    }

    template <class InputIt, class UnaryPred>
    InputIt find_if(InputIt first, InputIt last, UnaryPred p)
    {
        for (; first != last; ++first)
        {
            if (p(*first))
            {
                return first;
            }
        }
        return last;
    }

    template <class InputIt, class UnaryPred>
    InputIt find_if_not(InputIt first, InputIt last, UnaryPred q)
    {
        for (; first != last; ++first)
        {
            if (!q(*first))
            {
                return first;
            }
        }
        return last;
    }

    template <class ForwardIt1, class ForwardIt2>
    ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                        ForwardIt2 s_first, ForwardIt2 s_last)
    {
        if (s_first == s_last)
        {
            return last;
        }

        ForwardIt1 result = last;

        for (ForwardIt1 it = first; it != last; ++it)
        {
            ForwardIt1 main_it = it;
            ForwardIt2 sub_it = s_first;

            while (main_it != last && sub_it != s_last && *main_it == *sub_it)
            {
                ++main_it;
                ++sub_it;
            }

            if (sub_it == s_last)
            {
                result = it;
            }
        }

        return result;
    }

    template <class ForwardIt1, class ForwardIt2, class BinaryPred>
    ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                        ForwardIt2 s_first, ForwardIt2 s_last,
                        BinaryPred p)
    {
        if (s_first == s_last)
        {
            return last;
        }

        ForwardIt1 result = last;

        for (ForwardIt1 it = first; it != last; ++it)
        {
            ForwardIt1 main_it = it;
            ForwardIt2 sub_it = s_first;

            while (main_it != last && sub_it != s_last && p(*main_it, *sub_it))
            {
                ++main_it;
                ++sub_it;
            }

            if (sub_it == s_last)
            {
                result = it;
            }
        }

        return result;
    }

    template <class InputIt, class ForwardIt>
    InputIt find_first_of(InputIt first, InputIt last,
                          ForwardIt s_first, ForwardIt s_last)
    {
        for (; first != last; ++first)
        {
            for (ForwardIt it = s_first; it != s_last; ++it)
            {
                if (*first == *it)
                {
                    return first;
                }
            }
        }
        return last;
    }

    template <class InputIt, class ForwardIt, class BinaryPred>
    InputIt find_first_of(InputIt first, InputIt last,
                          ForwardIt s_first, ForwardIt s_last,
                          BinaryPred p)
    {
        for (; first != last; ++first)
        {
            for (ForwardIt it = s_first; it != s_last; ++it)
            {
                if (p(*first, *it))
                {
                    return first;
                }
            }
        }
        return last;
    }

    template <class ForwardIt>
    ForwardIt adjacent_find(ForwardIt first, ForwardIt last)
    {
        if (first == last)
        {
            return last;
        }

        auto it = ForwardIt(first);
        ++it;

        while (it != last)
        {
            if (*it == *first)
            {
                return first;
            }
            ++it;
            ++first;
        }
        return last;
    }

    template <class ForwardIt, class BinaryPred>
    ForwardIt adjacent_find(ForwardIt first, ForwardIt last,
                            BinaryPred p)
    {
        if (first == last)
        {
            return last;
        }

        auto it = ForwardIt(first);
        ++it;

        while (it != last)
        {
            if (p(*it, *first))
            {
                return first;
            }
            ++it;
            ++first;
        }
        return last;
    }

    template <class InputIt, class T>
    size_t count(InputIt first, InputIt last, const T &value)
    {
        size_t count{0};

        while (first != last)
        {
            if (*first == value)
            {
                ++count;
            }

            ++first;
        }
        return count;
    }

    template <class InputIt, class UnaryPred>
    size_t count_if(InputIt first, InputIt last, UnaryPred p)
    {
        size_t count{0};

        while (first != last)
        {
            if (p(*first))
            {
                ++count;
            }

            ++first;
        }
        return count;
    }

    template <class InputIt1, class InputIt2>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2)
    {
        while (first1 != last1 && *first1 == *first2)
        {
            ++first1, ++first2;
        }

        return std::make_pair(first1, first2);
    }

    template <class InputIt1, class InputIt2, class BinaryPred>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2, BinaryPred p)
    {
        while (first1 != last1 && p(*first1, *first2))
        {
            ++first1, ++first2;
        }
        return std::make_pair(first1, first2);
    }

    template <class InputIt1, class InputIt2>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2, InputIt2 last2)
    {
        while (first1 != last1 && first2 != last2 && *first1 == *first2)
        {
            ++first1, ++first2;
        }

        return std::make_pair(first1, first2);
    }

    template <class InputIt1, class InputIt2, class BinaryPred>
    std::pair<InputIt1, InputIt2>
    mismatch(InputIt1 first1, InputIt1 last1,
             InputIt2 first2, InputIt2 last2, BinaryPred p)
    {
        while (first1 != last1 && first2 != last2 && p(*first1, *first2))
            ++first1, ++first2;

        return std::make_pair(first1, first2);
    }

    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2)
    {
        while (first1 != last1)
        {
            if (*first1 != *first2)
            {
                return false;
            }

            ++first1;
            ++first2;
        }

        return true;
    }

    template <class InputIt1, class InputIt2, class BinaryPred>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, BinaryPred p)
    {
        while (first1 != last1)
        {
            if (p(*first1, *first2))
            {
                return false;
            }

            ++first1;
            ++first2;
        }

        return true;
    }

    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2)
    {
        while (first1 != last1 && first2 != last2)
        {
            if (*first1 != *first2)
            {
                return false;
            }

            ++first1;
            ++first2;
        }

        return true;
    }

    template <class InputIt1, class InputIt2, class BinaryPred>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2, BinaryPred p)
    {
        while (first1 != last1 && first2 != last2)
        {
            if (p(*first1, *first2))
            {
                return false;
            }

            ++first1;
            ++first2;
        }

        return true;
    }

    template <class ForwardIt1, class ForwardIt2>
    ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
                      ForwardIt2 s_first, ForwardIt2 s_last)
    {
        if (s_first == s_last)
        {
            return first;
        }

        while (first != last)
        {
            ForwardIt1 it1 = first;
            ForwardIt2 it2 = s_first;

            while (it1 != last && it2 != s_last && *it1 == *it2)
            {
                ++it1;
                ++it2;
            }

            if (it2 == s_last)
            {
                return first;
            }

            ++first;
        }

        return last;
    }

    template <class ForwardIt1, class ForwardIt2, class BinaryPred>
    ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
                      ForwardIt2 s_first, ForwardIt2 s_last,
                      BinaryPred p)
    {
        if (s_first == s_last)
        {
            return first;
        }

        while (first != last)
        {
            ForwardIt1 it1 = first;
            ForwardIt2 it2 = s_first;

            while (it1 != last && it2 != s_last && p(*it1, *it2))
            {
                ++it1;
                ++it2;
            }

            if (it2 == s_last)
            {
                return first;
            }

            ++first;
        }

        return last;
    }

    template <class InputIt, class OutputIt>
    OutputIt copy(InputIt first, InputIt last,
                  OutputIt dest_first)
    {
        while (first != last)
        {
            *dest_first = *first;
            ++dest_first;
            ++first;
        }
        return dest_first;
    }

    template <class InputIt, class OutputIt, class UnaryPred>
    OutputIt copy_if(InputIt first, InputIt last,
                     OutputIt dest_first, UnaryPred pred)
    {
        while (first != last)
        {
            if (pred(*first))
            {
                *dest_first = *first;
                ++dest_first;
            }
            ++first;
        }
        return dest_first;
    }

    template <class InputIt, class Size, class OutputIt>
    OutputIt copy_n(InputIt first, Size count, OutputIt result)
    {
        for (size_t i{0}; i < count; ++i)
        {
            *result = *first;
            ++first;
            ++result;
        }
        return result;
    }

    template <class BidirIt1, class BidirIt2>
    BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
    {
        while (first != last)
        {
            *(--d_last) = *(--last);
        }

        return d_last;
    }

    template <class InputIt, class OutputIt>
    OutputIt move(InputIt first, InputIt last,
                  OutputIt d_first)
    {
        for (; first != last; ++d_first, ++first)
        {
            *d_first = std::move(*first);
        }

        return d_first;
    }

    template <class BidirIt1, class BidirIt2>
    BidirIt2 move_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
    {
        while (first != last)
            *(--d_last) = std::move(*(--last));

        return d_last;
    }

    template <class InputIt, class OutputIt, class UnaryOp>
    OutputIt transform(InputIt first1, InputIt last1,
                       OutputIt d_first, UnaryOp unary_op)
    {
        while (first1 != last1)
        {
            *d_first = unary_op(*first1);
            ++first1;
            ++d_first;
        }

        return d_first;
    }

    template <class InputIt1, class InputIt2,
              class OutputIt, class BinaryOp>
    OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                       OutputIt d_first, BinaryOp binary_op)
    {
        while (first1 != last1)
        {
            *d_first = binary_op(*first1, *first2);
            ++first1;
            ++first2;
            ++d_first;
        }

        return d_first;
    }

    template <class ForwardIt, class T>
    void replace(ForwardIt first, ForwardIt last,
                 const T &old_value, const T &new_value)
    {
        while (first != last)
        {
            if (*first == old_value)
            {
                *first = new_value;
            }

            ++first;
        }
    }

    template <class ForwardIt, class UnaryPred, class T>
    void replace_if(ForwardIt first, ForwardIt last,
                    UnaryPred p, const T &new_value)
    {
        while (first != last)
        {
            if (p(*first))
            {
                *first = new_value;
            }

            ++first;
        }
    }

    template <class InputIt, class OutputIt, class T>
    OutputIt replace_copy(InputIt first, InputIt last, OutputIt d_first,
                          const T &old_value, const T &new_value)
    {
        while (first != last)
        {
            if (*first == old_value)
            {
                *d_first = new_value;
            }
            else
            {
                *d_first = *first;
            }
            ++d_first;
            ++first;
        }
        return d_first;
    }

    template <class InputIt, class OutputIt, class UnaryPred, class T>
    OutputIt replace_copy_if(InputIt first, InputIt last, OutputIt d_first,
                             UnaryPred p, const T &new_value)
    {
        while (first != last)
        {
            if (p(*first))
            {
                *d_first = new_value;
            }
            else
            {
                *d_first = *first;
            }
            ++d_first;
            ++first;
        }
        return d_first;
    }

    template <class ForwardIt, class T>
    void fill(ForwardIt first, ForwardIt last, const T &value)
    {
        while (first != last)
        {
            *first = value;
            ++first;
        }
    }

    template <class OutputIt, class Size, class T>
    OutputIt fill_n(OutputIt first, Size count, const T &value)
    {
        for (size_t i{0}; i < count; ++i)
        {
            *first = value;
            ++first;
        }
        return first;
    }

    template <class ForwardIt, class Generator>
    void generate(ForwardIt first, ForwardIt last, Generator g)
    {
        while (first != last)
        {
            *first = g();
            ++first;
        }
    }

    template <class OutputIt, class Size, class Generator>
    OutputIt generate_n(OutputIt first, Size count, Generator g)
    {
        for (size_t i{0}; i < count; ++i)
        {
            *first = g();
            ++first;
        }
        return first;
    }

    template <class ForwardIt, class T>
    ForwardIt remove(ForwardIt first, ForwardIt last, const T &value)
    {
        while (first != last && *first == value)
        {
            ++first;
        }

        ForwardIt it = first;

        for (; it != last; ++it)
        {
            if (*it != value)
            {
                *first = *it;
                ++first;
            }
        }

        return first;
    }

    template <class ForwardIt, class UnaryPred>
    ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPred p)
    {
        while (first != last && p(*first))
        {
            ++first;
        }

        ForwardIt it = first;

        for (; it != last; ++it)
        {
            if (!p(*it))
            {
                *first = *it;
                ++first;
            }
        }

        return first;
    }

    template <class InputIt, class OutputIt, class T>
    OutputIt remove_copy(InputIt first, InputIt last, OutputIt d_first, const T &value)
    {
        for (; first != last; ++first)
        {
            if (*first != value)
            {
                *d_first = *first;
                ++d_first;
            }
        }
        return d_first;
    }

    template <class InputIt, class OutputIt, class UnaryPred>
    OutputIt remove_copy_if(InputIt first, InputIt last, OutputIt d_first, UnaryPred p)
    {
        for (; first != last; ++first)
        {
            if (!p(*first))
            {
                *d_first = *first;
                ++d_first;
            }
        }
        return d_first;
    }

    template <class ForwardIt>
    ForwardIt unique(ForwardIt first, ForwardIt last)
    {
        if (first == last)
        {
            return last;
        }

        ForwardIt result = first;
        ++first;

        while (first != last)
        {
            if (!(*result == *first))
            {
                ++result;
                *result = *first;
            }
            ++first;
        }

        return ++result;
    }

    template <class ForwardIt, class BinaryPred>
    ForwardIt unique(ForwardIt first, ForwardIt last, BinaryPred p)
    {
        if (first == last)
        {
            return last;
        }

        ForwardIt result = first;
        ++first;

        while (first != last)
        {
            if (!p(*result, *first))
            {
                ++result;
                *result = *first;
            }
            ++first;
        }

        return ++result;
    }

    template <class InputIt, class OutputIt>
    OutputIt unique_copy(InputIt first, InputIt last, OutputIt d_first)
    {
        if (first == last)
        {
            return d_first;
        }

        auto result = InputIt(first);
        ++first;

        while (first != last)
        {
            if (!(*result == *first))
            {
                ++result;
                *d_first = *first;
            }
            ++first;
        }

        return ++d_first;
    }

    template <class InputIt, class OutputIt, class BinaryPred>
    OutputIt unique_copy(InputIt first, InputIt last,
                         OutputIt d_first, BinaryPred p)
    {
        if (first == last)
        {
            return d_first;
        }

        auto result = InputIt(first);
        ++first;

        while (first != last)
        {
            if (!p(*result, *first))
            {
                ++result;
                *d_first = *first;
            }
            ++first;
        }

        return ++d_first;
        ;
    }

    ///////////////////////////////////////////////////////////////////////

    template <class T>
    void swap(T &a, T &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }
    template <class ForwardIt1, class ForwardIt2>
    void iter_swap(ForwardIt1 a, ForwardIt2 b)
    {
        using alg::swap;
        alg::swap(*a, *b);
    }

    template <class ForwardIt1, class ForwardIt2>
    ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1,
                           ForwardIt2 first2)
    {
        using alg::iter_swap;

        while (first1 != last1)
        {
            iter_swap(first1, first2);
            ++first1;
            ++first2;
        }
    }
    ///////////////////////////////////////////////////////////////////////

    template <class BidirIt>
    void reverse(BidirIt first, BidirIt last)
    {
        using alg::iter_swap;
        if (first == last)
        {
            return;
        }

        --last;

        while (first < last)
        {
            alg::iter_swap(first, last);
            ++first;
            --last;
        }
    }

    template <class BidirIt, class OutputIt>
    OutputIt reverse_copy(BidirIt first, BidirIt last, OutputIt d_first)
    {
        if (first == last)
            return d_first;

        --last;

        while (true)
        {
            *d_first = *last;
            ++d_first;

            if (last == first)
                break;

            --last;
        }

        return d_first;
    }

    template <class ForwardIt>
    ForwardIt rotate(ForwardIt first, ForwardIt middle, ForwardIt last)
    {
        using alg::reverse;

        if (first == middle)
        {
            return last;
        }

        if (middle == last)
        {
            return first;
        }

        if (middle > last)
        {
            auto distance = std::distance(first, last);
            middle = first + ((middle - first) % distance);
        }

        alg::reverse(first, middle);
        alg::reverse(middle, last);
        alg::reverse(first, last);

        return first;
    }

    template <class ForwardIt, class OutputIt>
    OutputIt rotate_copy(ForwardIt first, ForwardIt n_first,
                         ForwardIt last, OutputIt d_first)
    {
        using alg::copy;

        if (first == last)
        {
            return d_first;
        }

        if (n_first == first || n_first == last)
        {
            return alg::copy(first, last, d_first);
        }

        if (n_first > last)
        {
            auto distance = std::distance(first, last);
            n_first = first + ((n_first - first) % distance);
        }

        d_first = alg::copy(n_first, last, d_first);
        return alg::copy(first, n_first, d_first);
    }
    /////////////////////////////////////////////////////////////////////////////////
    template <class ForwardIt, class UnaryPred>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPred p)
    {
        first = alg::find_if_not(first, last, p);
        if (first == last)
            return first;

        for (auto i = std::next(first); i != last; ++i)
            if (p(*i))
            {
                alg::iter_swap(i, first);
                ++first;
            }

        return first;
    }

    template <class ForwardIt, class BinaryPred>
    ForwardIt qs_partition(ForwardIt first, ForwardIt last, BinaryPred p)
    {
        auto randomIndex = std::rand() % std::distance(first, last);
        alg::iter_swap(first + randomIndex, last - 1);

        auto pivot = *(last - 1);
        auto i = first;

        for (auto j = first; j < last - 1; ++j)
        {
            if (p(*j, pivot))
            {
                alg::iter_swap(i, j);
                ++i;
            }
        }

        alg::iter_swap(i, last - 1);
        return i;
    }

    template <class InputIt, class OutputIt1,
              class OutputIt2, class UnaryPred>
    std::pair<OutputIt1, OutputIt2>
    partition_copy(InputIt first, InputIt last,
                   OutputIt1 d_first_true, OutputIt2 d_first_false,
                   UnaryPred p)
    {
        for (; first != last; ++first)
        {
            if (p(*first))
            {
                *d_first_true = *first;
                ++d_first_true;
            }
            else
            {
                *d_first_false = *first;
                ++d_first_false;
            }
        }

        return std::pair<OutputIt1, OutputIt2>(d_first_true, d_first_false);
    }

    template <class InputIt, class UnaryPred>
    bool is_partitioned(InputIt first, InputIt last, UnaryPred p)
    {
        if (first == last)
        {
            return false;
        }

        while (first != last)
        {
            if (!p(*first))
            {
                break;
            }
            ++first;
        }

        while (first != last)
        {
            if (p(*first))
            {
                return false;
            }
            ++first;
        }

        return true;
    }

    ////////////////////////////////////////////////////////////////////////////////
    template <class RandomIt, class Compare>
    void insertion_sort(RandomIt first, RandomIt last, Compare comp)
    {
        if (first == last)
            return;

        for (auto it = first + 1; it != last; ++it)
        {
            auto key = *it;
            auto j = it - 1;

            while (j >= first && comp(key, *j))
            {
                *(j + 1) = *j;
                --j;
            }
            *(j + 1) = key;
        }
    }

    template <class RandomIt, class Compare>
    void comb_sort(RandomIt first, RandomIt last, Compare comp)
    {
        auto size = std::distance(first, last);
        auto gap = size;
        bool swapped = true;
        const float shrink_factor = 1.3;

        while (gap > 1 || swapped)
        {
            gap = static_cast<int>(std::floor(gap / shrink_factor));
            if (gap < 1)
            {
                gap = 1;
            }

            swapped = false;

            for (auto i = first; i + gap < last; ++i)
            {
                if (comp(*(i + gap), *i))
                {
                    std::iter_swap(i, i + gap);
                    swapped = true;
                }
            }
        }
    }

    template <class RandomIt, class Compare>
    void merge_sort(RandomIt first, RandomIt last, Compare comp)
    {
        if (std::distance(first, last) <= 30)
        {
            insertion_sort(first, last, comp);
            return;
        }

        auto middle = first + (last - first) / 2;
        merge_sort(first, middle, comp);
        merge_sort(middle + 1, last, comp);
        merge(first, middle, last, comp);
    }

    template <class RandomIt, class Compare>
    void merge(RandomIt first, RandomIt middle, RandomIt last, Compare comp)
    {
        std::vector<typename std::iterator_traits<RandomIt>::value_type> left(first, middle);
        std::vector<typename std::iterator_traits<RandomIt>::value_type> right(middle + 1, last);

        auto it_left = left.begin();
        auto it_right = right.begin();
        auto it_merged = first;

        while (it_left != left.end() && it_right != right.end())
        {
            if (comp(*it_left, *it_right))
            {
                *it_merged++ = *it_left++;
            }
            else
            {
                *it_merged++ = *it_right++;
            }
        }

        while (it_left != left.end())
        {
            *it_merged++ = *it_left++;
        }

        while (it_right != right.end())
        {
            *it_merged++ = *it_right++;
        }
    }

    template <class RandomIt, class Compare>
    void quick_sort(RandomIt first, RandomIt last, Compare comp)
    {
        if (first < last)
        {
            auto pi = alg::qs_partition(first, last, comp);

            if (std::distance(first, pi) <= 30)
            {
                comb_sort(first, pi, comp);
            }
            else
            {
                quick_sort(first, pi, comp);
            }

            if (std::distance(pi + 1, last) <= 30)
            {
                comb_sort(pi + 1, last, comp);
            }
            else
            {
                quick_sort(pi + 1, last, comp);
            }
        }
    }

    template <class RandomIt, class Compare>
    void sort(RandomIt first, RandomIt last, Compare comp)
    {
        if (first == last)
            return;

        auto distance = std::distance(first, last);

        if (distance <= 30)
        {
            comb_sort(first, last, comp);
        }
        else
        {
            quick_sort(first, last, comp);
        }
    }

    template <class RandomIt, class Compare>
    void stable_sort(RandomIt first, RandomIt last, Compare comp)
    {
        if (first == last)
        {
            return;
        }

        auto distance = std::distance(first, last);

        if (distance <= 30)
        {
            insertion_sort(first, last, comp);
        }
        else
        {
            merge_sort(first, last, comp);
        }
    }

    template <class ForwardIt, class Compare>
    bool is_sorted(ForwardIt first, ForwardIt last, Compare comp)
    {
        if (first == last)
        {
            return true;
        }
        auto it = first;
        ++first;
        while (first != last)
        {
            if (!comp(it, first))
            {
                return false;
            }
            ++first;
        }
        return true;
    }

    template <typename RandomIt, typename Compare>
    void nth_element(RandomIt first, RandomIt nth, RandomIt last, Compare comp)
    {
        if (first == last)
        {
            return;
        }

        while (first < last)
        {
            auto pivot = partition(first, last, comp);

            if (pivot == nth)
            {
                return;
            }
            else if (nth < pivot)
            {
                last = pivot;
            }
            else
            {
                first = pivot + 1;
            }
        }
    }

    template <class ForwardIt, class T, class Compare>
    ForwardIt lower_bound(ForwardIt first, ForwardIt last,
                          const T &value, Compare comp)
    {
        while (first != last)
        {
            auto middle = first + std::distance(first, last) / 2;

            if (comp(*middle, value))
            {
                first = middle + 1;
            }
            else
            {
                last = middle;
            }
        }

        return first;
    }

    template <class ForwardIt, class T, class Compare>
    ForwardIt upper_bound(ForwardIt first, ForwardIt last,
                          const T &value, Compare comp)
    {
        while (first != last)
        {
            auto middle = first + std::distance(first, last) / 2;

            if (!comp(value, *middle))
            {
                first = middle + 1;
            }
            else
            {
                last = middle;
            }
        }

        return first;
    }

    template <class ForwardIt, class T, class Compare>
    std::pair<ForwardIt, ForwardIt>
    equal_range(ForwardIt first, ForwardIt last,
                const T &value, Compare comp)
    {
        return std::make_pair(alg::lower_bound(first, last, value, comp),
                              alg::upper_bound(first, last, value, comp));
    }

    template <class ForwardIt, class T>
    bool binary_search(ForwardIt first, ForwardIt last,
                       const T &value)
    {
        if (first == last)
        {
            return false;
        }

        while (first < last)
        {
            auto middle = first + std::distance(first, last) / 2;

            if (*middle == value)
            {
                return true;
            }

            if (*middle < value)
            {
                first = middle + 1;
            }
            else
            {
                last = middle - 1;
            }
        }

        return false;
    }

    template <class InputIt1, class InputIt2, class Compare>
    bool includes(InputIt1 first1, InputIt1 last1,
                  InputIt2 first2, InputIt2 last2, Compare comp)
    {
        for (; first2 != last2; ++first1)
        {
            if (first1 == last1 || comp(*first2, *first1))
            {
                return false;
            }
            if (!comp(*first1, *first2))
            {
                ++first2;
            }
        }
        return true;
    }

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare>
    OutputIt set_union(InputIt1 first1, InputIt1 last1,
                       InputIt2 first2, InputIt2 last2,
                       OutputIt d_first, Compare comp)
    {
        for (; first1 != last1; ++d_first)
        {
            if (first2 == last2)
            {
                return alg::copy(first1, last1, d_first);
            }

            if (comp(*first2, *first1))
            {
                *d_first = *first2++;
            }
            else
            {
                *d_first = *first1;
                if (!comp(*first1, *first2))
                    ++first2;
                ++first1;
            }
        }
        return alg::copy(first2, last2, d_first);
    }

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare>
    OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2,
                              OutputIt d_first, Compare comp)
    {
        while (first1 != last1 && first2 != last2)
        {
            if (comp(*first1, *first2))
            {
                ++first1;
            }
            else
            {
                if (!comp(*first2, *first1))
                {
                    *d_first++ = *first1++;
                }
                ++first2;
            }
        }
        return d_first;
    }

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare>
    OutputIt set_difference(InputIt1 first1, InputIt1 last1,
                            InputIt2 first2, InputIt2 last2,
                            OutputIt d_first, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2)
            {
                return std::copy(first1, last1, d_first);
            }

            if (comp(*first1, *first2))
            {
                *d_first++ = *first1++;
            }
            else
            {
                if (!comp(*first2, *first1))
                    ++first1;
                ++first2;
            }
        }
        return d_first;
    }

    template <class InputIt1, class InputIt2,
              class OutputIt, class Compare>
    OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
                                      InputIt2 first2, InputIt2 last2,
                                      OutputIt d_first, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2)
                return alg::copy(first1, last1, d_first);

            if (comp(*first1, *first2))
                *d_first++ = *first1++;
            else
            {
                if (comp(*first2, *first1))
                    *d_first++ = *first2;
                else
                    ++first1;
                ++first2;
            }
        }
        return alg::copy(first2, last2, d_first);
    }
}

#endif // ALGORITHM_TPP

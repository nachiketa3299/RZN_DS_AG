#include <cstddef>
#include <algorithm>
#include <iterator>
#pragma once

// OLogN
template <class ForwardIterator, class T, class Compare>
bool BinarySearch(ForwardIterator first, ForwardIterator last, const T& val, Compare compare)
{

    ForwardIterator lower_bound = first;
    ForwardIterator upper_bound = last;

    while (lower_bound < upper_bound)
    {
        ForwardIterator mid_bound = lower_bound + std::distance(lower_bound, upper_bound) / 2;
        if (!compare(val, *mid_bound) && !compare(*mid_bound, val))
            return true;
        else if (compare(val, *mid_bound))
            upper_bound = mid_bound;
        else if (compare(*mid_bound, val))
            lower_bound = ++mid_bound;
    }
    return false;
}

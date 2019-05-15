#ifndef VSH_NUMERIC_HPP
#define VSH_NUMERIC_HPP

#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>

namespace vsh {

template<typename ForwardIt, typename T, typename C = std::less<typename std::iterator_traits<ForwardIt>::value_type>>
T median(const ForwardIt first, const ForwardIt last, T init = T( ), C cmp = C( ))
{
    if (first != last)
    {
        typedef typename std::iterator_traits<ForwardIt>::difference_type difference_t;
        typedef typename std::vector<difference_t>                        indexes_t;
        typedef typename indexes_t::size_type                             indexes_size_t;

        difference_t length(std::distance(first, last));
        indexes_t    indexes(static_cast<indexes_size_t>(length), typename indexes_t::value_type( ));

        std::iota(indexes.begin( ), indexes.end( ), *indexes.begin( ));

        typename indexes_t::iterator medianIndexIterator(indexes.begin( ) + (length >> 1U));

        std::function<bool(indexes_size_t, indexes_size_t)> indexesComparator = [&first, &cmp](indexes_size_t lhs,
                                                                                               indexes_size_t rhs) {
            ForwardIt lit(first), rit(first);
            return cmp(*std::next(lit, static_cast<difference_t>(lhs)),
                       *std::next(rit, static_cast<difference_t>(rhs)));
        };

        std::nth_element(indexes.begin( ), medianIndexIterator, indexes.end( ), indexesComparator);

        ForwardIt median_rit(first);

        if (length & 1U)
        {
            init = std::move(init) + *std::next(median_rit, *medianIndexIterator);
        }
        else
        {
            ForwardIt median_lit(first);
            init = std::move(init)
                   + (*std::next(median_rit, *medianIndexIterator)
                      + *std::next(median_lit,
                                   *std::max_element(indexes.begin( ), medianIndexIterator, indexesComparator)))
                         * .5;
        }
    }
    return init;
}

}    // namespace vsh

#endif    // VSH_NUMERIC_HPP

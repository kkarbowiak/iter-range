/*
    Copyright 2017 Krzysztof Karbowiak
*/

#ifndef ITER_RANGE_H__DDK
#define ITER_RANGE_H__DDK

#include <algorithm>


namespace iter
{
namespace detail
{
    template<typename C>
    class ranger
    {
        public:
            class iterator
            {
                public:
                    iterator(C start, C stop, C step)
                        : mValue(start)
                        , mStop(stop)
                        , mStep(step)
                    {
                    }

                    auto operator!=(iterator const & other) const -> bool
                    {
                        return (mValue != other.mValue);
                    }

                    auto operator*() const -> C
                    {
                        return mValue;
                    }

                    auto operator++() -> iterator &
                    {
                        mValue = (mStop + mStep >= mStop)
                            ? std::min(static_cast<C>(mValue + mStep), mStop)
                            : std::max(static_cast<C>(mValue + mStep), mStop);

                        return *this;
                    }

                private:
                    C mValue;
                    C const mStop;
                    C const mStep;
            };

        public:
            ranger(C start, C stop, C step)
                : mStart(start)
                , mStop(stop)
                , mStep(step)
            {
            }

            auto begin() const -> iterator
            {
                return iterator(mStart, mStop, mStep);
            }

            auto end() const -> iterator
            {
                return iterator(mStop, mStop, mStep);
            }

        private:
            C const mStart;
            C const mStop;
            C const mStep;
    };
}
}

namespace iter
{   
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline auto range(C start, C stop, C step = 1) -> detail::ranger<C>
{
    return detail::ranger<C>(start, stop, step);
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline auto range(C stop) -> detail::ranger<C>
{
    return range(static_cast<C>(0), stop);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* ITER_RANGE_H__DDK */

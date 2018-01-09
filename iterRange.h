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

                    bool operator!=(iterator const & other) const
                    {
                        return (mValue != other.mValue);
                    }

                    C operator*() const
                    {
                        return mValue;
                    }

                    iterator & operator++()
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
            ranger()
                : mStart(0)
                , mStop(0)
                , mStep(0)
            {
            }

            explicit ranger(C stop)
                : mStart(0)
                , mStop(stop)
                , mStep(1)
            {
            }

            ranger(C start, C stop, C step = 1)
                : mStart(start)
                , mStop(stop)
                , mStep(step)
            {
            }

            iterator begin() const
            {
                return iterator(mStart, mStop, mStep);
            }

            iterator end() const
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
inline detail::ranger<C> range(C stop)
{
    return detail::ranger<C>(stop);
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline detail::ranger<C> range(C start, C stop, C step = 1)
{
    return detail::ranger<C>(start, stop, step);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* ITER_RANGE_H__DDK */

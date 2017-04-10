#ifndef ITER_RANGE_H__DDK
#define ITER_RANGE_H__DDK


namespace iter
{
    template<typename C>
    class range_helper
    {
        public:
            typedef C counter_type;

        public:
            range_helper();
            explicit range_helper(counter_type stop);
            range_helper(counter_type start, counter_type stop);

        private:
            counter_type const mStart;
            counter_type const mStop;
    };
}

namespace iter
{
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C>::range_helper()
    : mStart(0)
    , mStop(0)
{
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C>::range_helper(counter_type stop)
    : mStart(0)
    , mStop(stop)
{
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C>::range_helper(counter_type start, counter_type stop)
    : mStart(start)
    , mStop(stop)
{
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* ITER_RANGE_H__DDK */

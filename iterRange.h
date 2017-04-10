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
            class iterator
            {
                public:
                    iterator(counter_type value, counter_type step);
                    
                    bool operator!=(iterator const & other) const;
                    
                    counter_type operator*() const;
                    
                    iterator & operator++();
                    
                private:
                    counter_type mValue;
                    counter_type const mStep;
            };

        public:
            range_helper()
                : mStart(0)
                , mStop(0)
                , mStep(0)
            {
            }
            
            explicit range_helper(counter_type stop)
                : mStart(0)
                , mStop(stop)
                , mStep(1)
            {
            }
            
            range_helper(counter_type start, counter_type stop, counter_type step = 1)
                : mStart(start)
                , mStop(stop)
                , mStep(step)
            {
            }
            
            iterator begin() const
            {
                return iterator(mStart, mStep);
            }
            
            iterator end() const
            {
                return iterator(mStop, mStep);
            }

        private:
            counter_type const mStart;
            counter_type const mStop;
            counter_type const mStep;
    };
}

namespace iter
{   
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C> range(C stop)
{
    return range_helper<C>(stop);
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C> range(C start, C stop, C step = 1)
{
    return range_helper<C>(start, stop, step);
}
////////////////////////////////////////////////////////////////////////////////
}


namespace iter
{
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C>::iterator::iterator(counter_type value, counter_type step)
    : mValue(value)
    , mStep(step)
{
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline bool range_helper<C>::iterator::operator!=(range_helper<C>::iterator const & other) const
{
    return (mValue != other.mValue);
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline typename range_helper<C>::counter_type range_helper<C>::iterator::operator*() const
{
    return mValue;
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline typename range_helper<C>::iterator & range_helper<C>::iterator::operator++()
{
    mValue += mStep;
    
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* ITER_RANGE_H__DDK */

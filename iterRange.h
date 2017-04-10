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
                    explicit iterator(counter_type value);
                    
                    bool operator!=(iterator const & other) const;
                    
                    counter_type operator*() const;
                    
                    iterator & operator++();
                    
                private:
                    counter_type mValue;
            };

        public:
            range_helper();
            explicit range_helper(counter_type stop);
            range_helper(counter_type start, counter_type stop);
            
            iterator begin() const;
            iterator end() const;

        private:
            counter_type const mStart;
            counter_type const mStop;
    };
    
    template<typename C>
    range_helper<C> range(C stop);
    
    template<typename C>
    range_helper<C> range(C start, C stop);
}


namespace iter
{
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C>::iterator::iterator(counter_type value)
    : mValue(value)
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
    ++mValue;
    
    return *this;
}
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
template<typename C>
inline typename range_helper<C>::iterator range_helper<C>::begin() const
{
    return iterator(mStart);
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline typename range_helper<C>::iterator range_helper<C>::end() const
{
    return iterator(mStop);
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C> range(C stop)
{
    return range_helper<C>(stop);
}
////////////////////////////////////////////////////////////////////////////////
template<typename C>
inline range_helper<C> range(C start, C stop)
{
    return range_helper<C>(start, stop);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* ITER_RANGE_H__DDK */

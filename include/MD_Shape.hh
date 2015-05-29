#ifndef MD__SHAPE
#define MD__SHAPE

#include <array>
#include <functional>
#include <numeric>

namespace MD
{
    
    // Shape type.

    template< size_t N >
    using shape_type = std::array< size_t, N >;

    // Compute size from shape.

    template< size_t N >
    inline size_t shape_size( const shape_type< N >& shape )
    {
        return std::accumulate( shape.begin(), shape.end(), 1, std::multiplies< size_t >() );
    }

    // Some useful specializations.

    template<> 
    inline size_t shape_size( const shape_type< 1 >& shape ) 
    { 
        return shape[ 0 ]; 
    }

    template<> 
    inline size_t shape_size( const shape_type< 2 >& shape ) 
    { 
        return shape[ 0 ] * shape[ 1 ]; 
    }

    template<> 
    inline size_t shape_size( const shape_type< 3 >& shape ) 
    { 
        return shape[ 0 ] * shape[ 1 ] * shape[ 2 ]; 
    }

    template<> 
    inline size_t shape_size( const shape_type< 4 >& shape ) 
    { 
        return shape[ 0 ] * shape[ 1 ] * shape[ 2 ] * shape[ 3 ]; 
    }

    template<> 
    inline size_t shape_size( const shape_type< 5 >& shape ) 
    { 
        return shape[ 0 ] * shape[ 1 ] * shape[ 2 ] * shape[ 3 ] * shape[ 4 ]; 
    }

}

#endif

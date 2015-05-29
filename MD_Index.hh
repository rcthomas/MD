#ifndef MD__INDEX
#define MD__INDEX

#include "MD_Shape.hh"

namespace MD
{

    // Array ordering.

    struct ColumnMajor {};
    struct RowMajor    {};

    //

    template< size_t N, class Order = ColumnMajor >
    struct Index {};

    //

    template< size_t N >
    struct Index< N, ColumnMajor >
    {
        static size_t address( const shape_type< N >& coord, const shape_type< N >& shape )
        {
            auto ii = coord.rbegin();
            size_t result = *(ii++);
            for( auto ni = shape.rbegin(); ii < coord.rend(); ++ii, ++ni ) result = *ii + *ni * result;
            return result;
        }
    };

    template<>
    struct Index< 1, ColumnMajor >
    {
        static size_t address( const shape_type< 1 >& coord, const shape_type< 1 >& shape ) 
        { 
            return coord[ 0 ]; 
        }
    };

    template<> 
    struct Index< 2, ColumnMajor >
    {
        static size_t address( const shape_type< 2 >& coord, const shape_type< 2 >& shape ) 
        { 
            return coord[ 0 ] + shape[ 0 ] * coord[ 1 ]; 
        }
    };

    template<> 
    struct Index< 3, ColumnMajor >
    {
        static size_t address( const shape_type< 3 >& coord, const shape_type< 3 >& shape )
        { 
            return coord[ 0 ] + shape[ 0 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 2 ] ); 
        }
    };

    template<> 
    struct Index< 4, ColumnMajor >
    {
        static size_t address( const shape_type< 4 >& coord, const shape_type< 4 >& shape )
        { 
            return coord[ 0 ] + shape[ 0 ] * ( coord[ 1 ] + shape[ 1 ] * ( coord[ 2 ] + shape[ 2 ] * coord[ 3 ] ) ); 
        }
    };

    template<> 
    struct Index< 5, ColumnMajor >
    {
        static size_t address( const shape_type< 5 >& coord, const shape_type< 5 >& shape )
        { 
            return coord[ 0 ] + shape[ 0 ] * ( coord[ 1 ] + shape[ 1 ] * ( coord[ 2 ] + shape[ 2 ] * ( coord[ 3 ] + shape[ 3 ] * coord[ 4 ] ) ) ); 
        }
    };

    //

    template< size_t N >
    struct Index< N, RowMajor >
    {
        static size_t address( const shape_type< N >& coord, const shape_type< N >& shape )
        {
            auto ii = coord.begin();
            size_t result = *(ii++);
            for( auto ni = shape.begin(); ii < coord.rend(); ++ii, ++ni ) result = *ii + *ni * result;
            return result;
        }
    };

    template<>
    struct Index< 1, RowMajor >
    {
        static size_t address( const shape_type< 1 >& coord, const shape_type< 1 >& shape ) 
        { 
            return coord[ 0 ]; 
        }
    };

    template<> 
    struct Index< 2, RowMajor >
    {
        static size_t address( const shape_type< 2 >& coord, const shape_type< 2 >& shape ) 
        { 
            return coord[ 1 ] + shape[ 1 ] * coord[ 0 ]; 
        }
    };

    template<> 
    struct Index< 3, RowMajor >
    {
        static size_t address( const shape_type< 3 >& coord, const shape_type< 3 >& shape )
        { 
            return coord[ 2 ] + shape[ 2 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 0 ] ); 
        }
    };

    template<> 
    struct Index< 4, RowMajor >
    {
        static size_t address( const shape_type< 4 >& coord, const shape_type< 4 >& shape )
        { 
            return coord[ 3 ] + shape[ 3 ] * ( coord[ 2 ] + shape[ 2 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 0 ] ) ); 
        }
    };

    template<> 
    struct Index< 5, RowMajor >
    {
        static size_t address( const shape_type< 5 >& coord, const shape_type< 5 >& shape )
        { 
            return coord[ 4 ] + shape[ 4 ] * ( coord[ 3 ] + shape[ 3 ] * ( coord[ 2 ] + shape[ 2 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 0 ] ) ) ); 
        }
    };

    //

    template< class Order, size_t N >
    inline size_t index( const shape_type< N >& coord, const shape_type< N >& shape )
    {
        return Index< N, Order >::address( coord, shape );
    }

}

#endif

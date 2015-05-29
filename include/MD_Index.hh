#ifndef MD__INDEX
#define MD__INDEX

#include "MD_Shape.hh"

namespace MD
{

    // Array ordering.

    struct ColumnMajor {};
    struct RowMajor    {};

    // Array format.

    struct Canonical  {};   ///< Rows first then columns.
    struct Transposed {};   ///< Columns first then rows.

    //

    template< class Order, size_t N >
    struct Index {};

    //

    template< size_t N >
    struct Index< ColumnMajor, N >
    {
        static size_t address( const shape_type< N >& coord, const shape_type< N >& shape )
        {
            auto ii = coord.rbegin();
            size_t result = *(ii++);
            for( auto ni = ++shape.rbegin(); ni < shape.rend(); ++ni, ++ii ) result = *ii + *ni * result;
            return result;
        }
    };

    template<>
    struct Index< ColumnMajor, 1 >
    {
        static size_t address( const shape_type< 1 >& coord, const shape_type< 1 >& shape ) 
        { 
            return coord[ 0 ]; 
        }
    };

    template<> 
    struct Index< ColumnMajor, 2 >
    {
        static size_t address( const shape_type< 2 >& coord, const shape_type< 2 >& shape ) 
        { 
            return coord[ 0 ] + shape[ 0 ] * coord[ 1 ]; 
        }
    };

    template<> 
    struct Index< ColumnMajor, 3 >
    {
        static size_t address( const shape_type< 3 >& coord, const shape_type< 3 >& shape )
        { 
            return coord[ 0 ] + shape[ 0 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 2 ] ); 
        }
    };

    template<> 
    struct Index< ColumnMajor, 4 >
    {
        static size_t address( const shape_type< 4 >& coord, const shape_type< 4 >& shape )
        { 
            return coord[ 0 ] + shape[ 0 ] * ( coord[ 1 ] + shape[ 1 ] * ( coord[ 2 ] + shape[ 2 ] * coord[ 3 ] ) ); 
        }
    };

    template<> 
    struct Index< ColumnMajor, 5 >
    {
        static size_t address( const shape_type< 5 >& coord, const shape_type< 5 >& shape )
        { 
            return coord[ 0 ] + shape[ 0 ] * ( coord[ 1 ] + shape[ 1 ] * ( coord[ 2 ] + shape[ 2 ] * ( coord[ 3 ] + shape[ 3 ] * coord[ 4 ] ) ) ); 
        }
    };

    //

    template< size_t N >
    struct Index< RowMajor, N >
    {
        static size_t address( const shape_type< N >& coord, const shape_type< N >& shape )
        {
            auto ii = coord.begin();
            size_t result = *(ii++);
            for( auto ni = ++shape.begin(); ni < shape.end(); ++ni, ++ii ) result = *ii + *ni * result;
            return result;
        }
    };

    template<>
    struct Index< RowMajor, 1 >
    {
        static size_t address( const shape_type< 1 >& coord, const shape_type< 1 >& shape ) 
        { 
            return coord[ 0 ]; 
        }
    };

    template<> 
    struct Index< RowMajor, 2 >
    {
        static size_t address( const shape_type< 2 >& coord, const shape_type< 2 >& shape ) 
        { 
            return coord[ 1 ] + shape[ 1 ] * coord[ 0 ]; 
        }
    };

    template<> 
    struct Index< RowMajor, 3 >
    {
        static size_t address( const shape_type< 3 >& coord, const shape_type< 3 >& shape )
        { 
            return coord[ 2 ] + shape[ 2 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 0 ] ); 
        }
    };

    template<> 
    struct Index< RowMajor, 4 >
    {
        static size_t address( const shape_type< 4 >& coord, const shape_type< 4 >& shape )
        { 
            return coord[ 3 ] + shape[ 3 ] * ( coord[ 2 ] + shape[ 2 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 0 ] ) ); 
        }
    };

    template<> 
    struct Index< RowMajor, 5 >
    {
        static size_t address( const shape_type< 5 >& coord, const shape_type< 5 >& shape )
        { 
            return coord[ 4 ] + shape[ 4 ] * ( coord[ 3 ] + shape[ 3 ] * ( coord[ 2 ] + shape[ 2 ] * ( coord[ 1 ] + shape[ 1 ] * coord[ 0 ] ) ) ); 
        }
    };

    //

    template< class Format, class Order >
    struct ActualOrder { using type = Order; };

    template<> struct ActualOrder< Transposed, RowMajor    > { using type = ColumnMajor; };
    template<> struct ActualOrder< Transposed, ColumnMajor > { using type = RowMajor;    };

    template< class Format, class Order, size_t N >
    inline size_t index( const shape_type< N >& coord, const shape_type< N >& shape )
    {
        return Index< typename ActualOrder< Format, Order >::type, N >::address( coord, shape );
    }

}

#endif

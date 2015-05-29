#ifndef MD__ARRAY
#define MD__ARRAY

#include "MD_Index.hh"

namespace MD
{

    template< typename T, size_t N, typename Order = ColumnMajor >
    class Array
    {

        public :

            using shape_type = shape_type< N >;                 ///< Shape type.
            using size_type  = typename shape_type::value_type; ///< Index, coordinate, offset type.
            using value_type = T;                               ///< Content type.

        public :

            /// Constructor.
            explicit Array( const shape_type& shape ) noexcept;

            /// Copy constructor.
            Array( const Array& array ) noexcept;

            /// Move constructor.
            Array( Array&& array ) noexcept;

            /// Copy assignment.
            Array& operator = ( const Array& array ) noexcept;

            /// Move assignment.
            Array& operator = ( Array&& array ) noexcept;

            /// Destructor.
            ~Array();

            /// Linear value access.
            ///@{
                  value_type& operator [] ( const size_type pos )       { return _data[ pos ]; }
            const value_type  operator [] ( const size_type pos ) const { return _data[ pos ]; }
            ///@}

            /// Multi-dimensional coordinate access.
            ///@{
                  value_type& operator () ( const shape_type coord )       { return _data[ index< Order >( coord, _shape ) ]; }
            const value_type  operator () ( const shape_type coord ) const { return _data[ index< Order >( coord, _shape ) ]; }
            ///@}

            /// Total elements.
            size_type size() const { return _size; }

            /// Length of each axis.
            shape_type shape() const { return _shape; }

            /// Length of one axis.
            size_type shape( const size_type axis ) const { return _shape[ axis ]; }

            /// Native C++ array access.
            ///@{
                  value_type* data()       { return _data; }
            const value_type* data() const { return _data; }
            ///@}

            /// Offset native C++ array access.
            ///@{
                  value_type* data( const size_t offset )       { return _data + offset; }
            const value_type* data( const size_t offset ) const { return _data + offset; }
            ///@}

            /// Start of native C++ array.
            ///@{
                  value_type* begin()       { return _data; }
            const value_type* begin() const { return _data; }
            ///@}

            /// End of native C++ array.
            ///@{
            const value_type* end() const { return _data + _size; }
                  value_type* end()       { return _data + _size; }
            ///@}

        private :

            size_type   _size;  ///< Total elements.
            shape_type  _shape; ///< Length of each axis.
            value_type* _data;  ///< Content.

    };

}

#include "MD_Array.inl.hh"

#endif


namespace MD
{

    // Constructor.
   
    template< typename T, size_t N, typename Order >
    inline Array< T, N, Order >::Array( const shape_type& shape ) noexcept :
        _shape( shape                                  ), 
        _size ( shape_size( shape )                    ), 
        _data ( new value_type [ shape_size( shape ) ] ) 
    {}

    // Copy constructor.

    template< typename T, size_t N, typename Order >
    inline Array< T, N, Order >::Array( const Array& array ) noexcept :
        _shape( array.shape()                   ), 
        _size ( array.size()                    ), 
        _data ( new value_type [ array.size() ] )
    { 
        std::copy( array.begin(), array.end(), begin() ); 
    }

    // Move constructor.

    template< typename T, size_t N, typename Order >
    inline Array< T, N, Order >::Array( Array&& array ) noexcept :
        _shape( array.shape()                   ), 
        _size ( array.size()                    ), 
        _data ( new value_type [ array.size() ] )
    {
        array._shape.fill( 0 );
        array._size = 0;
        array._data = nullptr;
    }

    // Copy assignment.

    template< typename T, size_t N, typename Order >
    inline Array< T, N, Order >& Array< T, N, Order >::operator = ( const Array< T, N, Order >& array ) noexcept
    {
        if( this != &array )
        {
            value_type* tmp = new value_type [ array.size() ];
            std::copy( array.begin(), array.end(), tmp );
            delete [] _data;
            _shape = array.shape();
            _size  = array.size();
            _data  = tmp;
        }
        return *this;
    }

    // Move assignment.

    template< typename T, size_t N, typename Order >
    inline Array< T, N, Order >& Array< T, N, Order >::operator = ( Array< T, N, Order >&& array ) noexcept
    {
        if( this != &array )
        {
            _shape = array.shape();
            _size  = array.size();
            _data  = array.data();
            array._shape.fill( 0 );
            array._size = 0;
            array._data = nullptr;
        }
        return *this;
    }

    // Destructor.

    template< typename T, size_t N, typename Order >
    inline Array< T, N, Order >::~Array() 
    { 
        delete [] _data; 
    }

}

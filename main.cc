
#include <iostream>

#include "MD.hh"

int main()
{

    for( size_t nframes = 64; nframes < 128; nframes *= 2 )
    {

        std::cerr << nframes << std::endl;

        MD::Array< float, 3 > array( { nframes, 2048, 4096 } );
        std::cerr << array.size() * 4 / 1024.0 / 1024.0 / 1024.0 << " GB" << std::endl;

        std::cerr << "    fill" << std::endl;

        float num = 0.0; 
        for( size_t k = 0; k < array.shape( 2 ); ++ k )
        {
            for( size_t j = 0; j < array.shape( 1 ); ++ j )
            {
                for( size_t i = 0; i < array.shape( 0 ); ++ i )
                {
                    array( { i, j, k } ) = num;
                    num += 0.001;
                }
            }
        }

        std::cerr << "    sum" << std::endl;

        num = 0.0; 
        for( size_t k = 0; k < array.shape( 2 ); ++ k )
        {
            for( size_t j = 0; j < array.shape( 1 ); ++ j )
            {
                for( size_t i = 0; i < array.shape( 0 ); ++ i )
                {
                    num += array( { i, j, k } );
                }
            }
        }
        std::cerr << "    " << num << std::endl;

    }


    return 0;
}


#include "gtest/gtest.h"

#include "MD.hh"

TEST( ArrayTest, Dummy )
{
    EXPECT_EQ( 1, 1 );
}

int main( int argc, char* argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    ::testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}

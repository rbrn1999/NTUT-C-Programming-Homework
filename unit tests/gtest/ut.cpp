#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cstdlib>
#include <gtest/gtest.h>
#include "BMI.h"

TEST(BMItest, HandleNoneZeroInput){
    ASSERT_EQ(0, computeBMI(0,1));
    ASSERT_EQ(0, computeBMI(1,0));
    ASSERT_EQ(-1, computeBMI(30,190));
    ASSERT_EQ(-2, computeBMI(150,150));
    ASSERT_EQ(19.53, computeBMI(50,160));
}

int main(int argc, char **argv){
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}

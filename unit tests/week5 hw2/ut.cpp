#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cstdlib>
#include <gtest/gtest.h>
double computeBMI(int kg, int height) {
    double BMI = 0.0, M = height/100.0;
    if (kg<=0 || height<=0)
        return 0;
    BMI = round(100*kg/(M*M))/100;
    if (BMI <18.5)
        return -1;
    if (BMI >24)
        return -2;
    return BMI;
}

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

//#include <cstdlib>
//#include <gtest/gtest.h>
//int mul( int a , int b ) {
//    return a * b ;
//}
//TEST( multest , HandleNoneZeroInput ) {
//    ASSERT_EQ( 21 , mul( 3 , 7 ) ) ;
//    ASSERT_EQ( -24 , mul( -6 , 4 ) ) ;
//}
//int main( int argc , char **argv ){
//    testing :: InitGoogleTest( &argc , argv ) ;
//    return RUN_ALL_TESTS( ) ;
//}

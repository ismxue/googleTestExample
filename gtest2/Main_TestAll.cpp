#include "Addition_Test.cpp"
#include "Multiply_Test.cpp"
#include <gtest/gtest.h>
int main(int argc,char ** argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

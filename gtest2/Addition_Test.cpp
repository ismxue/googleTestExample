#include "Addition.cpp"
#include <gtest/gtest.h>

class AdditionTest : public ::testing::Test{
protected:
    virtual void SetUp(){};
    virtual void TearDown(){};
};

TEST_F(AdditionTest,twoValues){
    const int x=4;
    const int y=5;
    Addition addition;
    EXPECT_EQ(9,addition.twoValues(x,y));
    EXPECT_EQ(5,addition.twoValues(2,3));
}
//int main(int argc,char ** argv){
//    testing::InitGoogleTest(&argc,argv);
//    return RUN_ALL_TESTS();
//}
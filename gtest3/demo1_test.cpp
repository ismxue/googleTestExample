#include <gtest/gtest.h>
//加法函数
int add(int x, int y) {
    return x+y;
}

TEST(Addition, CanAddTwoNumbers){
    EXPECT_TRUE(add(2,2)==4); // 调用加法函数

//    如果产生错误，则输出相关的错误信息
//    如EXPECT_EQ(２, add(2,2)) << "Two plus two must equal four";　因为２!=4,则输出"Two plus two must equal four"
    EXPECT_EQ(4, add(2,2)) << "Two plus two must equal four";
}

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <gtest/gtest.h>
#include <ostream>

using namespace std;

//========================TEST()的使用=========================

//构建一个账户类。余额初始话为０，该账户有存取款功能
struct BankAccount {
    int balance = 0;

    BankAccount() {}

    explicit BankAccount(const int balance) : balance(balance) {}

//    存款后，余额增加
    void deposit(int amount) {
        balance += amount;
    }

//    如果取款金额小于余额，则取款成功，返回true.否则返回false
    bool withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};
//测试账户初始余额是否为０
TEST(AccountTest, BankAccountStartsEmpty) {
    BankAccount account;
    EXPECT_EQ(0, account.balance);
}
//========================TEST_F()的使用=========================

//想重复使用BankAccount类。于是构建一个BankAccountTest，并继承testing::Test
struct BankAccountTest : public testing::Test {
    BankAccount *account;

//    新建账户
    BankAccountTest() {
        account = new BankAccount;
    }

//    删除账户
    virtual ~BankAccountTest() {
        delete account;
    }

};
//第一个参数必须是类名。测试账户余额是否初始化为０
TEST_F(BankAccountTest, BankAccountStartsEmpty) {
    EXPECT_EQ(0, account->balance);
}
//第一个参数必须是类名。测试是否存钱成功
TEST_F(BankAccountTest, CanDepositMoney) {
    account->deposit(100);
    EXPECT_EQ(100, account->balance);
}

//========================TEST_P()的使用=========================

//构建一个账户状态的类（结构体）
struct account_state {
    int initial_balance; // 初始金额
    int withdraw_amount; //　取钱金额
    int final_balance; //　　　最终金额
    bool success; // 　　是否取钱成功

    friend ostream &operator<<(ostream &os, const account_state &state) {
        os << "initial_balance: " << state.initial_balance
           << " withdraw_amount: " << state.withdraw_amount
           << " final_balance: " << state.final_balance
           << " success: " << state.success;
        return os;
    }
};

//继承BankAccountTest类，以便使用account
//继承testing::WithParamInterface<参数>　，这里的参数指定为账户状态account_state
struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state> {
    WithdrawAccountTest() {
        account->balance = GetParam().initial_balance;　//GetParam()来调用相应的账户状态
    }
};

//第一个参数必须是类名。测试最终余额
TEST_P(WithdrawAccountTest, FinalBalance) {
    auto as = GetParam();
    auto success = account->withdraw(as.withdraw_amount);//    需要取出　as.withdraw_amount　块钱，测是是否成功
    EXPECT_EQ(as.final_balance, account->balance);
    EXPECT_EQ(as.success, success);
}

//TEST_P不能直接运行，需要用INSTANTIATE_TEST_CASE_P给它指定相应的参数
INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest,
                        testing::Values(
                                account_state{100, 50, 50, true},
                                account_state{100, 200, 100, false}
                        )); // 可以从100中取出50；不可以从100中取出200.这里没有用到final_balance


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
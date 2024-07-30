#include "gtest/gtest.h"
#include "Money.h"
#include "Expression.h"
#include "Bank.h"
#include "Sum.h"
#include <string>

TEST(moneyTest, testCurrency){
    // arrange
    EXPECT_EQ(std::string("USD"), Money::dollar(1).currency());
    EXPECT_EQ(std::string("CHF"), Money::franc(2).currency());
    // clear
}

TEST(moneyTest, multiplicationTest) {
    //arrange
    Money five = Money::dollar(5);
    Expression * ten = five.times(2);
    Expression * fiften = five.times(3);
    //act
    //assert
    EXPECT_EQ (dynamic_cast<const Money &>(*ten), Money::dollar(10));
    EXPECT_EQ (dynamic_cast<const Money &>(*fiften), Money::dollar(15));
    //clear
    delete ten;
    delete fiften;
}

TEST(moneyTest, equalTest) {
    //arrange
    //assert
    EXPECT_TRUE(Money::dollar(5).equals(Money::dollar(5)));
    EXPECT_FALSE(Money::dollar(5).equals(Money::dollar(6))); 
    EXPECT_FALSE(Money::dollar(5).equals(Money::franc(5)));
    //clear
}

TEST(moneyTest, testSimpleAddition) {
    //arrange
    Money five = Money::dollar(5);
    Expression * sum = five.plus(five);
    Bank bank;
    Money reduced = bank.reduce(*sum, "USD");
    //assert
    EXPECT_EQ(reduced, Money::dollar(10)); 
    //clear
    delete sum;   
}

TEST(moneyTest, testPlusReturnsSum){
    Money five = Money::dollar(5);
    Expression * result = five.plus(five);
    Sum * sum = dynamic_cast<Sum *>(result);
    //assert
    EXPECT_EQ(dynamic_cast<const Money &>(sum->augend), five);
    EXPECT_EQ(dynamic_cast<const Money &>(sum->addend), five);
    //clear
    delete sum;
}

TEST(moneyTest, testReduceSum){
    Money three = Money::dollar(3);
    Money four = Money::dollar(4);
    Sum sum_of_thre_and_four = Sum(three, four);
    Expression & sum = sum_of_thre_and_four;
    Bank bank;
    Money reduced = bank.reduce(sum, "USD");
    EXPECT_EQ(Money::dollar(7), reduced);
}

TEST(moneyTest, testReduceMoney){
    Bank bank;
    Money reduced = bank.reduce(Money::dollar(1), "USD");
    EXPECT_EQ(reduced, Money::dollar(1));
}

TEST(moneyTest, testreduceMoneyDifferentCurrency){
    Bank bank;
    bank.addRate("CHF", "USD", 2);
    Money result = bank.reduce(Money::franc(2), "USD");
    EXPECT_EQ(result, Money::dollar(1));
}

TEST(moneyTest, testIdentityRate){
    Bank bank;
    EXPECT_EQ(1, bank.rate("USD", "USD"));
}

TEST(moneyTest, testMixedAddition){
    Money fiveBucks = Money::dollar(5);
    Money tenFranks = Money::franc(10);
    Expression * fiveBucks_ex = &fiveBucks;
    Expression * tenFranks_ex = &tenFranks;
    Bank bank;
    bank.addRate("CHF", "USD", 2);
    Money result = bank.reduce(*(fiveBucks_ex->plus(*tenFranks_ex)), "USD");
    EXPECT_EQ(Money::dollar(10), result);
}

TEST(moneyTest, testSumPlusMoney){
    //arrange
    Money fiveBucks = Money::dollar(5);
    Money tenFranks = Money::franc(10);
    Expression * fiveBucks_ex = &fiveBucks;
    Expression * tenFranks_ex = &tenFranks;
    Bank bank;
    bank.addRate("CHF", "USD", 2);
    Expression * sum = new Sum(*fiveBucks_ex, *tenFranks_ex);
    Expression * sum_plus_five = sum->plus(*fiveBucks_ex);
    Money reduced = sum_plus_five->reduce(bank, "USD");
    //assert
    EXPECT_EQ(reduced, Money::dollar(15));
    //clear
    delete sum;
    delete sum_plus_five;
}

TEST(moneyTest, testSumTimes){
    //arrange
    Money fiveBucks = Money::dollar(5);
    Money tenFranks = Money::franc(10);
    Expression * fiveBucks_ex = &fiveBucks;
    Expression * tenFranks_ex = &tenFranks;
    Bank bank;
    bank.addRate("CHF", "USD", 2);
    Expression * sum = new Sum(*fiveBucks_ex, *tenFranks_ex);
    Expression * sum_times_two = sum->times(2);
    Money reduced = sum_times_two->reduce(bank, "USD");
    //assert
    EXPECT_EQ(reduced, Money::dollar(20));
    //clear
    delete sum;
    delete sum_times_two;   

}
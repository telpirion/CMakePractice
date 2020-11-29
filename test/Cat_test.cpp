#include "gtest/gtest.h"
#include "Cat.h"
#include <iostream>
#include <string>

using namespace std;

TEST(CatTest, emitsMeowWithGreeting)
{
    //arrange
    //act
    //assert
    string expectedStr = "Meow, hello Bob";
    EXPECT_EQ(Cat::Meow("Bob"), expectedStr);
}

TEST(CatTest, returnsCorrectNumberOfPaws)
{
    EXPECT_EQ(Cat::GetNumberOfPaws(), 4);
}
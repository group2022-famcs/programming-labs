#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "declarations.h"

TEST(Public, Task1)
{
  ASSERT_EQ(leastMissingDigit(120), 3);
  ASSERT_EQ(leastMissingDigit(0), 1);
}

TEST(Public, Task2)
{
  std::vector<int> a{1, 0, 0, 2, 0, 3, 0};
  filterArray(a);
  ASSERT_THAT(a, ::testing::ElementsAre(1, 2, 3));
}

TEST(Public, Task3)
{
  std::vector<int> a{0, 1, 2, 3};
  reverseArray(a);
  ASSERT_THAT(a, ::testing::ElementsAre(3, 2, 1, 0));
}

TEST(Public, Task4)
{
  ASSERT_EQ(numberOfCommonElements({0, 2, 3, 5, 11}, {2, 4, 5, 6}), 2);
}

TEST(Public, Task5)
{
  ASSERT_TRUE(isPermutation({2, 1, 3}));
  ASSERT_FALSE(isPermutation({0, 3, 1, 2}));
}

TEST(Public, Task6)
{
  std::vector<int> a{1, 2, 3, 4, 5, 6};
  cyclicShift(a, 2);
  ASSERT_THAT(a, ::testing::ElementsAre(3, 4, 5, 6, 1, 2));
}

TEST(Public, Task7)
{
  std::vector<int> a{0, 2, -5, 4, -6, 3, 0};
  partitionBySign(a);
  ASSERT_THAT(a, ::testing::ElementsAre(-5, -6, 0, 0, 2, 4, 3));
}

TEST(Public, Task8)
{
  const auto result = multiplyMatrices(
    {{1, 0, 2}},
    {
      {2, 1},
      {11, -5},
      {1, -1},
    }
  );
  ASSERT_THAT(result, ::testing::ElementsAre(::testing::ElementsAre(4, -1)));
}

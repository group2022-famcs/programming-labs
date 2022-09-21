#include "adviser.h"

#include <gtest/gtest.h>

TEST(Adviser, AlwaysPass) {
  EXPECT_TRUE(true);
}

TEST(Adviser, CryptoAdvice) {
  Adviser adviser;
  EXPECT_EQ(adviser.Advice(), "Buy Bitcoin!");
}
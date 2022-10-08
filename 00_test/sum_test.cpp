#include "declarations.h"
#include <gtest/gtest.h>

TEST(Public, Sum) {
  ASSERT_EQ(sum(1, -1), 0);
}

#include "eval_expression.h"
#include "eval_min_max.h"

#include <gtest/gtest.h>

TEST(Public, EvalMinMax) {
    EXPECT_EQ(evalMinMaxExpression("8"), 8);
    EXPECT_EQ(evalMinMaxExpression("min(4, 3)"), 3);
    EXPECT_EQ(evalMinMaxExpression("max(4, min(3, 5))"), 4);
    EXPECT_EQ(evalMinMaxExpression("min(min(3, 5), max(2, max(3, 4)))"), 3);
}

TEST(Public, EvalExpression) {
    EXPECT_EQ(evaluateExpression("0"), 0);
    EXPECT_EQ(evaluateExpression("2+2*2"), 6);
    EXPECT_EQ(evaluateExpression("6&((98)*3>>1)"), 6 & ((98) * 3 >> 1));
    EXPECT_EQ(evaluateExpression("(94+16)/10%3"), (94 + 16) / 10 % 3);
    EXPECT_EQ(evaluateExpression("(1-2)^64"), (1 - 2) ^ 64);
    EXPECT_EQ(evaluateExpression("1^4&1|8<<3>>2"), (1 ^ (4 & 1)) | 8 << 3 >> 2);
    EXPECT_ANY_THROW(evaluateExpression("3/(1-1)"));
}

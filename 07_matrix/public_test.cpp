// Tests added to this file won't run on GitHub

#include "matrix.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using Vector2D = std::vector<std::vector<int>>;

TEST(Public, Construction) {
    const Matrix a1(2, 2);
    const Matrix a2(2, 2, 0);
    [[maybe_unused]] const Matrix copy1 = a1;
    const Matrix copy2(a1.data());
    EXPECT_ANY_THROW(Matrix({{1, 0}, {0}}));
}

TEST(Public, Elements) {
    Matrix mut(2, 2);
    mut.set(0, 1, 4);
    mut.set(1, 0, -1);
    EXPECT_ANY_THROW(mut.set(0, 2, 0));
    EXPECT_THAT(mut.data(), ::testing::ContainerEq(Vector2D{{0, 4}, {-1, 0}}));
}

TEST(Public, Resize) {
    Matrix matrix(2, 2, 1);
    matrix.resize(1, 3);
    EXPECT_THAT(matrix.data(), ::testing::ContainerEq(Vector2D{{1, 1, 0}}));
}

TEST(Public, Transpose) {
    Matrix matrix({{0, 1, 2}, {3, 4, 5}});
    matrix.transpose();
    ASSERT_EQ(matrix.rows(), 3);
    ASSERT_EQ(matrix.columns(), 2);
    EXPECT_THAT(matrix.data(), ::testing::ContainerEq(Vector2D{{0, 3}, {1, 4}, {2, 5}}));
}

TEST(Public, FlipHorizontally) {
    Matrix matrix({{0, 1, 2}, {3, 4, 5}});
    matrix.flipHorizontally();
    EXPECT_THAT(matrix.data(), ::testing::ContainerEq(Vector2D{{2, 1, 0}, {5, 4, 3}}));
}

TEST(Public, FlipVertically) {
    Matrix matrix({{0, 1, 2}, {3, 4, 5}});
    matrix.flipVertically();
    EXPECT_THAT(matrix.data(), ::testing::ContainerEq(Vector2D{{3, 4, 5}, {0, 1, 2}}));
}

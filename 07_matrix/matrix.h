#pragma once

#include <string>
#include <vector>

class Matrix {
public:
    Matrix(int n, int m, int value = 0);
    Matrix(std::vector<std::vector<int>>);
    Matrix(const Matrix&);

    int rows() const;
    int columns() const;
    std::vector<std::vector<int>> data() const;

    void resize(int n, int m);
    void set(int i, int j, int value);

    void transpose();
    void flipHorizontally();
    void flipVertically();
};

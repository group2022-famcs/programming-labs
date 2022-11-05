#include "matrix.h"
#include "helpers/lab_helpers.h"
#include <not_implemented.h>

Matrix::Matrix(int n, int m, int value) {
    NOT_IMPLEMENTED(n, m, value);
}

Matrix::Matrix(std::vector<std::vector<int>> data) {
    NOT_IMPLEMENTED(data);
}

Matrix::Matrix(const Matrix& rhs) {
    NOT_IMPLEMENTED(rhs);
}

int Matrix::rows() const {
    NOT_IMPLEMENTED(0);
}

int Matrix::columns() const {
    NOT_IMPLEMENTED(0);
}

std::vector<std::vector<int>> Matrix::data() const {
    NOT_IMPLEMENTED(0);
}

void Matrix::resize(int n, int m) {
    NOT_IMPLEMENTED(n, m);
}

void Matrix::set(int i, int j, int value) {
    NOT_IMPLEMENTED(i, j, value);
}

void Matrix::transpose() {
    NOT_IMPLEMENTED(0);
}

void Matrix::flipHorizontally() {
    NOT_IMPLEMENTED(0);
}

void Matrix::flipVertically() {
    NOT_IMPLEMENTED(0);
}

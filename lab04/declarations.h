#pragma once
#include <vector>

int leastMissingDigit(int);

void filterArray(std::vector<int>&);

void reverseArray(std::vector<int>&);

int numberOfCommonElements(const std::vector<int>&, const std::vector<int>&);

bool isPermutation(const std::vector<int>&);

void cyclicShift(std::vector<int>&, int n);

void partitionBySign(std::vector<int>&);

std::vector<std::vector<int>> multiplyMatrices(
  const std::vector<std::vector<int>>&,
  const std::vector<std::vector<int>>&
);

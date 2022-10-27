#pragma once

#include <string>
#include <vector>

using BigInteger = std::vector<int>;

enum CompareResult {
    Less,
    Equal,
    Greater,
};

BigInteger fromInt(int);
BigInteger fromString(const std::string&);

std::string toString(const BigInteger&);

CompareResult compare(const BigInteger&, const BigInteger&);

BigInteger add(const BigInteger&, const BigInteger&);
BigInteger subtract(const BigInteger&, const BigInteger&);
BigInteger multiply(const BigInteger&, const BigInteger&);

#pragma once

#include <map>
#include <string>

struct Country {
    std::string toString() const;

    std::string name;
    std::string code;
    std::map<int, int64_t> yearPopulation;
};

#pragma once

#include <stdexcept>

#define NOT_IMPLEMENTED(...)                                                                       \
    throw std::runtime_error("Not implemented");                                                   \
    (void)sizeof(__VA_ARGS__);

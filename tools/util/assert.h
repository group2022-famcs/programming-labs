#include <stdexcept>
#define ASSERT(expr)                                                                               \
    if (!(expr))                                                                                   \
        throw std::runtime_error("Assertion failed: " #expr);

#pragma once

#define assert_eq(lhs, rhs) \
    if (lhs != rhs) \
        exit(1)

#define assert_ne(lhs, rhs) \
    if (lhs == rhs) \
        exit(1)

#include "gtest/gtest.h"
#include "absum.hpp"

namespace
{

  // Test absum function with same inputs in functions a and b.
  TEST(absum, ab_use_same_inputs)
  {

    double z;
    z = a(2.5, 10.0) + b(2.5, 10.0);
    // equal to with test value and expected value
    EXPECT_EQ(absum(2.5, 10.0), z);
  }

  // Test absum function with different inputs in functions a and b.
  TEST(absum, ab_use_different_inputs)
  {

    double z;
    z = a(2.5, 8.7) + b(2.5, 10.0);

    EXPECT_NE(absum(2.5, 10.0), z);
  }
}

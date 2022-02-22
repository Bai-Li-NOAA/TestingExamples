#include "gtest/gtest.h"
#include "gmock/gmock.h" // Brings in gMock.
#include "examples/deviations.hpp"
#include <math.h>

namespace
{
  // Test fixture class: set up common data for SumToZero tests. Use test fixture if you find yourself writing two or more tests that operate on similar data.
  class SumToZeroTest : public ::testing::Test
  {
  protected:
    void SetUp() override
    {
      // could load a file of values here
    }

    // void TearDown() override {}

    std::vector<double> zero_vector{0.5, 0.3, -0.3, -0.5};
    std::vector<double> not_zero_vector{0.5, 0.3, -0.3, 1.5};
    std::vector<double> forced_zero_vector{0.0, -0.2, -0.8, 1.0};
  };

  // Set up a mock recruitment object.
  class MockRecruitment : public examples::IRecruitment
  {
  public:
    MOCK_METHOD(std::vector<double>, getRecruitment, (), (override)); // return type, method name, (args...), (specs...); here marks the method with override: overriding a virtual method.
  };

  // Test fixture application.
  TEST_F(SumToZeroTest, true_if_sum_to_zero)
  {
    EXPECT_EQ(examples::sum_to_zero(zero_vector), true);
  }
  // Test fixture application.
  TEST_F(SumToZeroTest, force_sum_to_zero)
  {
    EXPECT_EQ(examples::force_sum_to_zero(not_zero_vector), forced_zero_vector);
  }

  // gMock object and real object comparison.
  using ::testing::AtLeast;
  using ::testing::Return;

  // Use gMock object for testing.
  TEST(PredictedRecruitment, call_mock_recruitment)
  {
    std::vector<double> not_zero_vector{0.5, 0.3, -0.3, 1.5};
    std::vector<double> init_recruitment{1000.0, 900.0, 850.4, 10020};
    std::vector<double> expect_recruitment{1000.0 * exp(0.0), 900.0 * exp(-0.2), 850.4 * exp(-0.8), 10020 * exp(1.0)}; // Multiply inti_recruitment with exp(forced_zero_vector)

    MockRecruitment mock_recruitment;
    EXPECT_CALL(mock_recruitment, getRecruitment())
        .Times(AtLeast(1))
        .WillOnce(Return(init_recruitment));

    EXPECT_EQ(examples::deviate_recruitment(&mock_recruitment, not_zero_vector), expect_recruitment);
  }

  // Use real object for testing.
  TEST(PredictedRecruitment, call_real_recruitment)
  {
    std::vector<double> not_zero_vector{0.5, 0.3, -0.3, 1.5};
    std::vector<double> init_recruitment{1000.0, 900.0, 850.4, 10020};
    std::vector<double> expect_recruitment{1000.0 * exp(0.0), 900.0 * exp(-0.2), 850.4 * exp(-0.8), 10020 * exp(1.0)}; // Multiply inti_recruitment with exp(forced_zero_vector)

    examples::IRecruitment *r = examples::create_recruitment(init_recruitment);
    EXPECT_EQ(examples::deviate_recruitment(r, not_zero_vector), expect_recruitment);
    delete r;
  }

}

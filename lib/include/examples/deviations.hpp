#include <vector>
#include "examples/irecruitment.hpp"

namespace examples
{

    /**
     * Checks that a vector sums to zero.
     *
     * @param x A vector of double values.
     * @returns True if the vector sums to zero, false otherwise.
     */
    bool sum_to_zero(std::vector<double> x);

    /**
     * Make a vector sums to zero.
     *
     * @param x A vector of double values.
     * @returns A new vector that sums to zero.
     */
    std::vector<double> force_sum_to_zero(std::vector<double> x);

    /**
     * Recruitment with deviations.
     *
     * @param x A vector of double values.
     * @returns A new vector that sums to zero.
     */
    std::vector<double> deviate_recruitment(IRecruitment *r, std::vector<double> x);

}

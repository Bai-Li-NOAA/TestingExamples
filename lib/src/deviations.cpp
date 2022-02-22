#include "examples/deviations.hpp"
#include <numeric> // invisible to users of the sum_to_zero.h; good interface seperation.
#include <iostream>
#include <math.h>

namespace examples
{

    bool sum_to_zero(std::vector<double> x)
    {
        double sum = std::accumulate(x.begin(), x.end(), 0.0);
        return sum == 0.0;
    }

    std::vector<double> force_sum_to_zero(std::vector<double> x)
    {

        if (sum_to_zero(x))
        {
            return x;
        }

        double mean = (std::accumulate(x.begin(), x.end(), 0.0) / x.size()); // using 0.0 or 0 makes a difference

        for (int i = 0; i < x.size(); i++)
        {
            x[i] -= mean;
        }
        return x;
    }

    std::vector<double> deviate_recruitment(IRecruitment *r, std::vector<double> x)
    {
        std::vector<double> devs = force_sum_to_zero(x);
        std::vector<double> recruitment_vector = r->getRecruitment();
        std::vector<double> predicted_recruitment;

        for (int i = 0; i < recruitment_vector.size(); i++)
        {
            predicted_recruitment.push_back(recruitment_vector[i] * exp(devs[i]));
        }
        return predicted_recruitment;
    }

}

#include "examples/internal/recruitment.hpp"

namespace examples
{
  Recruitment::Recruitment(std::vector<double> recruitment)
  {
    m_recruitment = recruitment;
  }

  std::vector<double> Recruitment::getRecruitment()
  {
    return m_recruitment;
  };

  IRecruitment* create_recruitment(std::vector<double> r)
  {
    return new Recruitment(r);
  }

}

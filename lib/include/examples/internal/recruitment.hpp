#include "examples/irecruitment.hpp"

namespace examples
{

  /**
   * Simple recruitment object.
   */
  class Recruitment : public IRecruitment
  {
  public:
    /**
     * Construct a default recruitment object.
     */
    Recruitment(std::vector<double> recruitment);
    ~Recruitment() = default;

    virtual std::vector<double> getRecruitment() override; // override means this is the definition for the declaration in the IRecruitment interface.

  private: // Do not want people to directly access member variable.
    std::vector<double> m_recruitment;
  };

}

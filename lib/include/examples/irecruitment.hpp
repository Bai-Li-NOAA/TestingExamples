#include <vector>

namespace examples
{

  /**
   * Simple recruitment object interface.
   */
  class IRecruitment // Pure virtual interface
  {
  public:
    /**
     * Return a vector of doubles
     *
     * @returns A vector of values.
     */
    virtual std::vector<double> getRecruitment() = 0; // =0 means pure virtual method that has no default implementation.
    virtual ~IRecruitment(){};                        // virtural destructure needed to prevent memory leak.
  };

  IRecruitment *create_recruitment(std::vector<double> r);

}

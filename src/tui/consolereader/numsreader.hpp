#pragma once
#include "istandartreader.hpp"

namespace hw
{
  class NumsReader final : public IStandartReader<short>
  {
  public:
    NumsReader(short left_border, short right_border) noexcept;
    virtual short read_input() const override;
    virtual void error_message(short choice) const override;
  private:
    short left_border_ = 0;
    short right_border_ = 0;
  };

} // namespace hw

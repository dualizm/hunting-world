#pragma once
#ifndef NUMSREADER_HPP_QPED7FJH
#define NUMSREADER_HPP_QPED7FJH
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
    short left_border_;
    short right_border_;
  };

}

#endif /* end of include guard: NUMSREADER_HPP_QPED7FJH */

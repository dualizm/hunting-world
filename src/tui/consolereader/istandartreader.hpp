#pragma once

namespace hw
{
  template < typename T >
  class IStandartReader
  {
  public:
    virtual T read_input() const = 0;
    virtual void error_message(T error) const = 0;

    virtual ~IStandartReader () {}
  private:
    /* data */
  };
} // namespace hw

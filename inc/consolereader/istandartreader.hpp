#pragma once
#ifndef ISTANDARTREADER_HPP_QI8VQWZK
#define ISTANDARTREADER_HPP_QI8VQWZK

namespace hw
{
  template < typename T >
  class IStandartReader
  {
  public:
    virtual T read_input() const = 0;

    virtual ~IStandartReader () {}
  private:
    /* data */
  };
}

#endif /* end of include guard: ISTANDARTREADER_HPP_QI8VQWZK */

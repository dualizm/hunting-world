#pragma once
#ifndef IUSERMEMBERS_HPP_0QDZVHWW
#define IUSERMEMBERS_HPP_0QDZVHWW
#include "istandartreader.hpp"
#include <string>
#include <memory>
#include <tuple>
#include <vector>

namespace hw
{
  template < typename T >
  class UserMembers
  {
  protected:
    std::vector<std::tuple<T, std::string>> choices_;
    // Reads user select input
    std::unique_ptr<IStandartReader<T>> reader_;
    std::string menu_name_;
  };
}

#endif /* end of include guard: IUSERMEMBERS_HPP_0QDZVHWW */

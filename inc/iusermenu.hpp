#pragma once
#ifndef IUSERMENU_HPP_4GMB8APR
#define IUSERMENU_HPP_4GMB8APR
#include <vector>
#include <string>

namespace hw
{
  class IUserMenu
  {
  protected:
    virtual void display() = 0;
    virtual void read_input() = 0;
    virtual void display_info() = 0;
    virtual ~IUserMenu() {}
    
    std::vector<std::string> choices_;
  };
}

#endif /* end of include guard: IUSERMENU_HPP_4GMB8APR */

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

    // Displays the screen interface to the user
    virtual void display_interface() const = 0;

    // Reads user select input
    virtual void read_input() const = 0;
    
    std::vector<std::string> choices_;
  public:
    virtual ~IUserMenu() {}
  };
}

#endif /* end of include guard: IUSERMENU_HPP_4GMB8APR */

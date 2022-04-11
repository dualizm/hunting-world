#pragma once
#ifndef IUSERMENU_HPP_4GMB8APR
#define IUSERMENU_HPP_4GMB8APR
#include <string>
#include "istandartreader.hpp"

namespace hw
{
  class IUserMenu
  {
  protected:

    // Displays the screen interface to the user
    virtual void display_interface() const = 0;

    // title, body, select
    virtual void print_title(std::string title_name) const;
    virtual void print_body() const;
    virtual void print_select() const;

  public:
    virtual ~IUserMenu() {}
  };
}

#endif /* end of include guard: IUSERMENU_HPP_4GMB8APR */

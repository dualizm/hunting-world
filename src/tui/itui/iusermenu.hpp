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
    virtual void print_body() const = 0;
    virtual void print_reader() const = 0;
    virtual void print_line() const;
    virtual void print_indent_eight() const;
    virtual void print_indent_four() const;
    virtual void print_indent_twelve() const;

  public:
    virtual ~IUserMenu() {}
  };
}

#endif /* end of include guard: IUSERMENU_HPP_4GMB8APR */

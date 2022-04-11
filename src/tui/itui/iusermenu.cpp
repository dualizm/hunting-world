#include "iusermenu.hpp"
#include <iostream>

namespace hw
{
  void IUserMenu::print_title(std::string title_name) const
  {
    std::cout << "+" << title_name << std::endl;
  }

  void IUserMenu::print_body() const
  {
    // ***
  }

  void IUserMenu::print_select() const
  {
    // ***
  }
}

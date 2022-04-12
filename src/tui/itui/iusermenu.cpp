#include "iusermenu.hpp"
#include "constants.hpp"
#include <iostream>

namespace hw
{
  void IUserMenu::print_title(std::string title_name) const
  {
    print_line();
    print_indent_four();
    std::cout << title_name << std::endl;
    print_indent_four();
  }

  void IUserMenu::print_indent_eight() const
  {
    for (size_t i = 0; i < 8; i++)
      std::cout << "\n";
  }

  void IUserMenu::print_indent_four() const
  {
    for (size_t i = 0; i < 4; i++)
      std::cout << "\n";
  }

  void IUserMenu::print_indent_twelve() const
  {
    for (size_t i = 0; i < 12; i++)
      std::cout << "\n";
  }

  void IUserMenu::print_line() const
  {
    std::cout << "+";
    for (size_t i = 0; i < constants::width_screen; ++i) 
    {
      std::cout << '-';  
    }
    std::cout << "+" << std::endl;
  }

}

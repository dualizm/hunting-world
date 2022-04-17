#include "consoleprinter.hpp"
#include "constants.hpp"
#include <iostream>

namespace hw
{
  ConsolePrinter::ConsolePrinter(std::shared_ptr<IUserMenu> screen) noexcept
    : screen_{screen} {}

  void ConsolePrinter::print_title() const
  {
    print_indent(4);
    size_t middle_screen_for_txt{
      (constants::width_screen / 2) - (screen_->get_title_name().size() / 2)
    };

    for(size_t i{}; i < middle_screen_for_txt; ++i)
      std::cout << ' ';
    std::cout << screen_->get_title_name() << std::endl;
    print_indent(4);
  }

  void ConsolePrinter::display_interface() const
  {
    print_line();
    print_title();
    print_line();
    print_body();
    print_line();
    print_reader();
  }

  void ConsolePrinter::print_indent(size_t count) const
  {
    for(size_t i{}; i < count; ++i)
    {
      std::cout << "\n";
    }
  }

  void ConsolePrinter::print_line() const
  {
    std::cout << "+";
    for (size_t i = 0; i < constants::width_screen; ++i) 
    {
      std::cout << '-';  
    }
    std::cout << "+" << std::endl;
  }

  void ConsolePrinter::print_reader() const
  {
    std::cout << " > ";
  }

  void ConsolePrinter::print_body() const
  {
    std::cout << screen_->get_body_choices() << std::endl;
  }


} // namespace hw

#pragma once
#include <memory>
#include "iusermenu.hpp"

namespace hw
{

  class ConsolePrinter final
  {
  public:
    ConsolePrinter(std::shared_ptr<IUserMenu> screen) noexcept;
    // Displays the screen interface to the user
    void display_interface() const;

    ~ConsolePrinter() {}

  private:
    void print_line() const;
    void print_indent(size_t count) const;
    void print_title() const;
    void print_body() const;
    void print_reader() const;

  private:
    std::shared_ptr<IUserMenu> screen_;
  };

} // namespace hw

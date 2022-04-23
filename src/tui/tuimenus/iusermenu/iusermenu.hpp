#pragma once
#include <string>

namespace hw
{
  class IUserMenu
  {
  public:
    virtual std::string get_title_name() const = 0;
    virtual std::string get_body_choices() const = 0;

    virtual ~IUserMenu() {}
    std::string menu_name_;
  };
} // namespace hw

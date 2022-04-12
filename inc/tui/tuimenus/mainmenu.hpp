#pragma once
#ifndef MAINMENU_HPP_XIGTBCS8
#define MAINMENU_HPP_XIGTBCS8
#include "iusermenu.hpp"
#include "usermembers.hpp"

namespace hw
{
  class MainMenu final : public IUserMenu,
    public UserMembers<short>
  {
  public:
    MainMenu()  noexcept;
    virtual void display_interface() const override;
    virtual void print_body() const override;
    virtual void print_select() const override;
  
  private:
  /* UserMembers
   // std::vector<std::tuple<T, std::string>> choices_;
   // std::unique_ptr<IStandartReader<T>> reader_;
   // std::string menu_name_;
  */
  };
}

#endif /* end of include guard: MAINMENU_HPP_XIGTBCS8 */

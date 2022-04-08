#pragma once
#ifndef TUIGAMEMENU_HPP_K3UV7YSR
#define TUIGAMEMENU_HPP_K3UV7YSR
#include "iusermenu.hpp"

namespace hw
{
  class GameMenu final : public IUserMenu 
  {
  public:
    GameMenu() noexcept;
    virtual void display_interface() override;
    virtual void read_input() override;
    virtual void display_info() override;
  
  private:
    // std::vector<std::string> choices_ /* IUserMenu */
  };
}

#endif /* end of include guard: TUIGAMEMENU_HPP_K3UV7YSR */

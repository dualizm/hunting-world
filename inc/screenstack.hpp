#pragma once
#ifndef SCREENSTACK_HPP_J1EHXUR4
#define SCREENSTACK_HPP_J1EHXUR4
#include "iusermenu.hpp"
#include <initializer_list>
#include <memory>
#include <stack>

namespace hw
{
  class ScreenStack final
  {
  public:
    ScreenStack() noexcept = delete;
    explicit ScreenStack(std::shared_ptr<IUserMenu> user_menu);
    explicit ScreenStack(std::initializer_list
        <std::shared_ptr<IUserMenu>> &list_menu);

  private:
    std::stack<std::shared_ptr<IUserMenu>> screens_;
  };
}

#endif /* end of include guard: SCREENSTACK_HPP_J1EHXUR4 */

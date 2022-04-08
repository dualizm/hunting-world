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
    explicit ScreenStack(std::initializer_list
        <std::unique_ptr<IUserMenu>> &list_menu);

    void push(std::unique_ptr<IUserMenu> &screen);
    void pop();
    const IUserMenu& now() const;
    bool empty() const;

  private:
    std::stack<std::unique_ptr<IUserMenu>> screens_;
  };
}

#endif /* end of include guard: SCREENSTACK_HPP_J1EHXUR4 */

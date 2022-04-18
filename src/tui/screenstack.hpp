#pragma once

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
        <std::shared_ptr<IUserMenu>> &list_menu);

    void push(std::shared_ptr<IUserMenu> &screen);

    std::shared_ptr<const IUserMenu> current_screen() const;

    bool empty() const;

    void pop();

  private:
    std::stack<std::shared_ptr<IUserMenu>> screens_;
  };
} // namespace hw

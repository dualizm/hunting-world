#include "screenstack.hpp"
#include <algorithm>
#include <initializer_list>
#include <memory>

namespace hw
{
  ScreenStack::ScreenStack(std::initializer_list
      <std::shared_ptr<IUserMenu>> &list_menu)
  {
    for (auto element : list_menu) 
    {
      screens_.emplace(element); 
    }
  }

  void ScreenStack::push(std::shared_ptr<IUserMenu> &screen)
  {
    screens_.emplace(screen);
  }

  std::shared_ptr<const IUserMenu> ScreenStack::current_screen() const
  {
    return const_pointer_cast<const IUserMenu>(screens_.top());
  }

  bool ScreenStack::empty() const
  {
    return screens_.empty();
  }

  void ScreenStack::pop()
  {
    screens_.pop();
  }
}

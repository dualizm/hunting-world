#include "screenstack.hpp"
#include <initializer_list>
#include <memory>

namespace hw
{
  ScreenStack::ScreenStack(std::initializer_list
      <std::unique_ptr<IUserMenu>> &list_menu)
  {
    for (auto& element : list_menu) 
    {
      screens_.emplace(std::move(element.get())); 
    }

  }

  void ScreenStack::push(std::unique_ptr<IUserMenu> &screen)
  {
    screens_.emplace(std::move(screen));
  }

  const IUserMenu& ScreenStack::now() const
  {
    return reinterpret_cast<const IUserMenu&>(*screens_.top().get());
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

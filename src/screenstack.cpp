#include "screenstack.hpp"
#include <initializer_list>
#include <memory>

namespace hw
{
  ScreenStack::ScreenStack(std::shared_ptr<IUserMenu> user_menu)
  {
    screens_.emplace(user_menu);
  }

  ScreenStack::ScreenStack(std::initializer_list
      <std::shared_ptr<IUserMenu>> &list_menu)
  {
    for (auto element : list_menu) 
    {
      screens_.emplace(element); 
    }

  }

}

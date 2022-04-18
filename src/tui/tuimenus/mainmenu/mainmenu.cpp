#include "mainmenu.hpp"
#include "numsreader.hpp"
#include "constants.hpp"
#include <memory>
#include <iostream>

namespace hw
{
  MainMenu::MainMenu() noexcept
  {
    // Init choices
    choices_ = std::vector<std::tuple<short, std::string>>{
      std::make_tuple<short, std::string>(1, "Start"),
      std::make_tuple<short, std::string>(2, "Continue"),
      std::make_tuple<short, std::string>(3, "History"),
      std::make_tuple<short, std::string>(4, "Instruction"),
      std::make_tuple<short, std::string>(5, "Exit"),
    };

    // Init location name
    menu_name_ = "Game menu";
  }

  std::string MainMenu::get_title_name() const 
  {
    return menu_name_;
  }

  std::string MainMenu::get_body_choices() const
  {
    std::string temp_buff;
    for(const auto& choice:choices_)
    {
      temp_buff.append(std::to_string(std::get<0>(choice)) + "] ");
      temp_buff.append(std::get<1>(choice) + '\n');
    }
    return temp_buff;
  }
}

#include "mainmenu.hpp"
#include "numsreader.hpp"
#include <memory>
#include <iostream>

namespace hw
{
  MainMenu::MainMenu() noexcept
  {
    // Init reader choices
    reader_ = std::make_unique<NumsReader>();

    // Init choices
    choices_ = std::vector<std::tuple<short, std::string>>{
      std::make_tuple<short, std::string>(1, "Start"),
      std::make_tuple<short, std::string>(2, "Continue"),
      std::make_tuple<short, std::string>(3, "History"),
      std::make_tuple<short, std::string>(4, "Inctruction"),
      std::make_tuple<short, std::string>(5, "Exit"),
    };

    // Init location name
    menu_name_ = "Game menu";
  }

  void MainMenu::display_interface() const
  {
    print_title();
    print_body();
    print_select();
  }

}

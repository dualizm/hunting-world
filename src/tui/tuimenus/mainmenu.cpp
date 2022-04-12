#include "mainmenu.hpp"
#include "numsreader.hpp"
#include <memory>
#include <iostream>

namespace hw
{
  MainMenu::MainMenu() noexcept
  {
    // Init reader choices
    reader_ = std::make_unique<NumsReader>(1, 5);

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
    print_title(menu_name_);
    print_body();
    print_reader();
  }

  void MainMenu::print_body() const
  {
    print_line();
    for(const auto& choice:choices_)
    {
      std::cout 
        << std::get<0>(choice) << "] "
        << std::get<1>(choice) 
      << std::endl;
    }
  }

  void MainMenu::print_reader() const
  {
    print_line();
    std::cout << " > ";
  }

}

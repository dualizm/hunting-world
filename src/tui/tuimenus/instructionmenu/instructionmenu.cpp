#include "instructionmenu.hpp"

namespace hw
{

  InstructionMenu::InstructionMenu() noexcept
  {
    menu_name_ = "Instruction menu";
  }

  std::string InstructionMenu::get_body_choices() const
  {
    std::string info{"TEST INFO"};
    return info;
  }

  std::string InstructionMenu::get_title_name() const
  {
    return menu_name_;
  }
} // namespace hw

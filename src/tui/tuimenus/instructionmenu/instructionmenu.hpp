#pragma once
#include "iusermenu.hpp"

namespace hw
{
  class InstructionMenu final : public IUserMenu
  {
  public:
    InstructionMenu() noexcept;

    virtual std::string get_title_name() const override;
    virtual std::string get_body_choices() const override;

  private:
  };
} // namespace hw

#include "numsreader.hpp"
#include <iostream>

namespace hw
{
  NumsReader::NumsReader(short left_border, short right_border) noexcept
    : left_border_{left_border}, right_border_{right_border} {}

  short NumsReader::read_input() const
  {
    short choice{};
    try 
    {
      std::cin >> choice;

      if ( choice < left_border_ 
          || choice > right_border_)
      {
        throw choice;
      }
    }
    catch(...) 
    {
      error_message(choice);
    }
    return choice;
  }

  void NumsReader::error_message(short choice) const
  {
    std::cerr << 
      "Error : There is no such command - " <<
      choice <<
      "\nYou need [" << left_border_ <<
      "-" << right_border_ << "]"
    << std::endl;
    
  }
}

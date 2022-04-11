#include "numsreader.hpp"
#include <iostream>

namespace hw
{
  short NumsReader::read_input() const
  {
    std::string str; 
    std::cin >> str;

    if (str[0] >= '0' || str[0] <= '9')
      return static_cast<short>(str.at(0));
    else 
      error_message();

    return 0;
  }

  void NumsReader::error_message() const
  {
    std::cerr << 
      "Error : There is no such command. [0-9]" 
    << std::endl;
    
  }
}

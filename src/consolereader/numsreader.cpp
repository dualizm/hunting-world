#include "numsreader.hpp"

namespace hw
{
  short NumsReader::read_input() const
  {
    std::string str; 
    std::cin >> str;

    if (str[0] >= '0' || str[0] <= '9')
      return str[0] - '0';
    else 
      error_message();

    return 0;
  }

}

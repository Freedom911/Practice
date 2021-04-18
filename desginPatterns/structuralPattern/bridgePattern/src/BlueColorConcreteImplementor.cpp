#include "BlueColorConcreteImplementor.h"


std::string BlueColorConcreteImplementor::GetColorString(const std::string &field)
{
  return "\033[1;34m" + field + "\033[0m\n";
}


#include "RedColorConcreteImplementor.h"


std::string RedColorConcreteImplementor::GetColorString(const std::string &field)
{
  return "\033[1;31m" + field + "\033[0m\n";
}

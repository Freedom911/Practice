//Implementation Interface - This provide the interface for implementation class
#pragma once
#include <string>
class ColorImplementor
{
  public:
    virtual std::string GetColorString(const std::string &field) = 0;
    virtual ~ColorImplementor() {}
};

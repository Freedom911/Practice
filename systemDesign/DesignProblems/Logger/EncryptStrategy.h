#pragma once
#include <string>

class EncryptStrategy
{
 public:
  virtual std::string Encrypt(std::string plainText) = 0;
  virtual std::string Decrypt(std::string encText) = 0;
};
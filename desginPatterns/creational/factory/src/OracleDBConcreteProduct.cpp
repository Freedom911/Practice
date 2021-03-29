#include "OracleDBConcreteProduct.h"
#include <string>



void OracleDBConcreteProduct::executeQuery(const std::string &query)
{
  std::cout << "\n SENDING Query To Oracle DATABASE = " << query << "\n";
}

std::vector<int> OracleDBConcreteProduct::getResult()
{
  std::cout << "\n Executing Query in Oracle DATABASE \n";
  result.push_back(100);
  result.push_back(200);
  result.push_back(300);
  result.push_back(400);
  result.push_back(500);
  return result;
}

int OracleDBConcreteProduct::getTotalRowCount()
{
  return result.size();
}

#include "PSQLDBConcreteProduct.h"
#include <string>



void PSQLDBConcreteProduct::executeQuery(const std::string &query)
{
  std::cout << "\n SENDING Query To PSQL DATABASE = " << query << "\n";
}

std::vector<int> PSQLDBConcreteProduct::getResult()
{
  std::cout << "\n Executing query in PSQL DATABASE\n";
  result.push_back(100);
  result.push_back(200);
  result.push_back(300);
  result.push_back(400);
  result.push_back(500);
  return result;
}

int PSQLDBConcreteProduct::getTotalRowCount()
{
  return result.size();
}

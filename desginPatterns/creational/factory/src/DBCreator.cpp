#include "DBCreator.h"

void DBCreator::runQuery(const std::string &query)
{
  DBInterfaceProduct *db = getProduct();
  if(db)
  {
    db->executeQuery(query);
    std::vector<int> result = db->getResult();

    std::cout << "\n Total Rows = " << db->getTotalRowCount() << "\n";

    int count = db->getTotalRowCount(); 

    for(int i = 0; i < count; i++)
    {
      std::cout << "\n Row No = " << i + 1 << " = " << result[i] << "\n";
    }


  }
  

  delete db;
}

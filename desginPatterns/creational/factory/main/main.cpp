#include <iostream>
#include "DBCreator.h"

#if 0
  #include "OracleCreator.h"
#else
  #include "PSQLCreator.h"
#endif

int main()
{
   DBCreator *db = nullptr;

#if 0
   db = new OracleCreator();
#else
   db = new PSQLCreator();
#endif

   db->runQuery("SELECT userid FROM USER_DETAILS");

   delete db;
}

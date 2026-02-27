#include "PostgresDBConnectionLibrary.h"
#include "EncryptedDB.h"
#include "DBConnectionCompositionAdapter.h"
#include "DBConnectionInheritanceAdapter.h"

void Execute(DBConnection *db, std::string query)
{
    if (db)
    {
        db->InitConnection("SRA", "JAN");
        db->executeQuery(query);
        for (auto it : db->getResults())
        {
            std::cout << it << "\n";
        };
    }
}

void ExecuteEncrypted(EncryptedDB*db,std::string query )
{
     if (db)
    {
        db->CheckSSLAndConnect("SRA","JAN");
        std::vector<std::string> results;
        db->ExecuteQuery(query,results);
        
        for (auto it : results)
        {
            std::cout << it << "\n";
        };
    }
}

int main()
{
    // We have used this eery in our class
    PostgresDBConnectionLibrary *db = new PostgresDBConnectionLibrary();
    Execute(db,"select * from challan_details");


    // Now we have been told to encrypt user related tables
    //ISSUE
    EncryptedDB *e_db = new EncryptedDB();
    ExecuteEncrypted(e_db,"select * from user_details");

    //SOLUTION we make an interface which
    //1.Soljution Using CompositionAdapter
    DBConnectionCompositionAdapter *compo = new DBConnectionCompositionAdapter(e_db);

    //Now we can use same function yippi
    Execute(compo,"select * from user_details");


    //Solution 2 Inheritance ADapter
    DBConnectionInheritanceAdapter *obj = new DBConnectionInheritanceAdapter();
    //Yiip again we canuse the same
    Execute(obj,"select * from user_details");

}
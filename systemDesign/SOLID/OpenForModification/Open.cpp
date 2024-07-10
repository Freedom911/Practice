#include <iostream>

//Taking Example from Previous one
//
//Currently this class saves to DB. but let us say we want to add functionality for saving tofile
//then we have to modify the existing code
class Save
{
    public:
        void SaveToDB()
        {
            //Savesto DB
        }

      // Violating Open/closed  Principle
      // void SaveToFile()
      // {

      // }
};

//Solution

class SaveInterface
{
   public
       virtual void Save() = 0;
};

class SaveDB: public SaveInterface
{
    public:
        void Save() override
        {
            //save to db
        }
};

class SaveFile: public SaveInterface
{
    public:
        void Save() override
        {
            //save to File
        }
};

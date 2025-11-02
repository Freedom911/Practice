#include <iostream>
#include <mutex>

//For A Single Ton Class we need to ensure only one instance of
//a class is there . This is a type of object creational design pattern
//Example This a Game world class of a game engine
//we need to ensure only one game world is there
using  Actors = int;
class GameWorld
{
  public:
    static GameWorld *GetInstance()
    {
      std::call_once(initInstanceFlag,initSingleTon);
      return Instance;
    }

    //Other Mechnaism



    //Need To Make Copy Constructor private or delete to avoid copying
    GameWorld(const GameWorld &world) =delete;
    GameWorld & operator = (const GameWorld &rightObj) = delete;


    static int SpawnActors(int totalActorsToSpawn)
    {
        if(Instance)
        {
            return Instance->ISpawnActors(totalActorsToSpawn);
        }
        else
        {
            return -1;
        }
    }

  private:
    GameWorld() = default;

    static void initSingleTon()
    {
        std::cout << "\n Here \n";
        Instance = new GameWorld();
    }

    //NOT PART OF SINGLETON-------------------------------------------
    //I Means Implmentationi
    int ISpawnActors(int totalActorsToSpawn)
    {
      for(int i = 0; i <  totalActorsToSpawn; i++)
      {
         Actors a;
         totalActorsInWorld++;
      }
      return totalActorsToSpawn;
    }
    //using int Actors;
    int totalActorsInWorld;
    //NOT PART OF SINGLETON-------------------------------------------


    static std::once_flag initInstanceFlag;
    static GameWorld *Instance;


};

GameWorld * GameWorld::Instance;
std::once_flag GameWorld::initInstanceFlag;

int main()
{
  //This will Give Error
   GameWorld *world = GameWorld::GetInstance(); // Here we are returning reference but this will call copy constructor
   //GameWorld &world = GameWorld::GetInstance(); //works Just hiding to make it more convient to call functions
  std::cout << GameWorld::SpawnActors(100);
}


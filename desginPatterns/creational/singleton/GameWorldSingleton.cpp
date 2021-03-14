#include <iostream>

//For A Single Ton Class we need to ensure only one instance of
//a class is there . This is a type of object creational design pattern
//Example This a Game world class of a game engine
//we need to ensure only one game world is there
using  Actors = int;
class GameWorld
{
  public:
    //1st Thing Provide a function to get the instance of object
    //Need to make it static so that it can be called without object
    //
    //NEW CONCEPT IN C++11 already in gcc (C++03)
    //if we have static variable in  a function then it will be thread safe
    //that is other variable will wait
    static GameWorld &GetInstance()
    {
      static GameWorld instance;
      return instance;
    }

    GameWorld(){}

    //Need To Make Copy Constructor private or delete to avoid copying
    GameWorld(const GameWorld &world) =delete;
    GameWorld & operator = (const GameWorld &rightObj) = delete;


    static int SpawnActors(int totalActorsToSpawn)
    {
        return GetInstance().ISpawnActors(totalActorsToSpawn);
    }

  private:

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

};

int main()
{
  //This will Give Error
   //GameWorld world = GameWorld::GetInstance(); // Here we are returning reference but this will call copy constructor
   //GameWorld &world = GameWorld::GetInstance(); //works Just hiding to make it more convient to call functions
  std::cout << GameWorld::SpawnActors(100);
}


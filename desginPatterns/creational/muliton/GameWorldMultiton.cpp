//This is a multi class which creates unique instance for 
//each Key Type
#include <iostream>
#include <map>
#include <string>

using  Actors = int;
class GameWorld
{
  public:
    static GameWorld *GetInstance(std::string key)
    {
      if(instances.find(key) != instances.end())
        return instances[key];

      GameWorld *instance = new GameWorld;
      instances[key] = instance;
      return instance;
    }


    //Need To Make Copy Constructor private or delete to avoid copying
    GameWorld(const GameWorld &world) =delete;
    GameWorld & operator = (const GameWorld &rightObj) = delete;

  private:
    GameWorld(){}

    static std::map<std::string,GameWorld*>instances;

};

std::map<std::string,GameWorld*> GameWorld::instances;

int main()
{
   GameWorld *world = GameWorld::GetInstance("Monster");
   GameWorld *world1 = GameWorld::GetInstance("Hero");
   GameWorld *world2 = GameWorld::GetInstance("Monster");

   std::cout << "\n Address of monster 1= " << world << "\n";
   std::cout << "\n Address of monster 2= " << world2 << "\n";
   std::cout << "\n Address of hero  = " << world1 << "\n";


}


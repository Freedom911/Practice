//Enum class is type safe and it gives more freedom oin underlying type
#include <iostream>

enum class Gender
{
    Male,
    Female
};

enum class Car
{
    Bike,
    Cycle
};

enum class Color:char
{
    Red,
    Blue,
    Color
};

int main()
{
  Gender g = Gender::Male;
  Car c = Car::Bike;

//this will give error
#if 0  
  if(c == g)
  {
      std::cout << "\n Equal \n";
  }
#endif
  std::cout << sizeof(Color) << "\n";
}

//Enum vs Enum classes
#include <iostream>

//1.Enum has weakness as it is not type safe
//2. Enum value cant be used else where

enum Gender
{
    Male,
    Female
};

#if 0
enum Gender2
{
   Male,  //This will give error
   Female // as it is being used in Gender
};
#endif

enum Color
{
   Red,
   Green
};
int main()
{
    Gender g = Male;
    Color col = Red;
    
    //type unsafe
    if(g == col)
    {
        //this is just plainly obsurd
        std::cout << "\n EQUAL \n";
    }
}


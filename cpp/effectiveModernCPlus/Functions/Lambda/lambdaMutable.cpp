//Mutable is used when value are cpatured by value and we want to modiy
//by default call to lambda is const
//lambda by default enfornces consteness for call by value to aovid modifying
#include <iostream>

int main()
{
    int x  = 5;
    int y;
    //will giver error
    //auto lamb = [x]()  {x = 10; return x + 5;};
    auto lamb = [x]() mutable {x = 10; return x + 5;};

    //if we passed by reference then value will be reflected
    y = lamb();
    std::cout << x << "\n"; //x value is still 5. Only when passed by reference then value is updated
    std::cout << y << "\n";

}

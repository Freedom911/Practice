//Capture in Lambda
#include <iostream>

int main()
{
    int x  = 5;
    int y;
    auto lamb = [x]()  {return x + 5;};
    //auto lamb = [&x](){return x + 5;};

    y = lamb();

    std::cout << y << " " << x << "\n";

    x = 20; //even we modified x still the below print will output y as 10
    //reason is x is captured in lamb and at that time x value was 5
    //think of it as when we declared lamb then unamed class was created with member value x as 5
    y = lamb();
    std::cout << y << " " << x << "\n";


    //if we passed by reference then value will be reflected

}

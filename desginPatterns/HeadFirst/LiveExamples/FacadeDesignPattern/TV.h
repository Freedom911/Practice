#pragma once
#include <string>
#include <iostream>
class TV
{
    public:
    TV() = default;

    void SwitchOn()
    {
        std::cout << "\n Bravia 95 cm TV";
    }

    void SetMovie(std::string movieName)
    {
        std::cout << "\n SETTING UP = " << movieName << "\n";
    }

    void SwitchOff()
    {
        std::cout << "\n SWITCHING OFF TV \n";
    }
};
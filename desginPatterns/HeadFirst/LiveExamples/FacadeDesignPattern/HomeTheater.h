#pragma once
#include <string>
#include <iostream>
class HomeTheater
{
    public:
    HomeTheater() = default;

    void SwitchOn()
    {
        std::cout << "\n Sony WIreless Hometheater 9.1";
    }

    void SetVolume(int volume)
    {
        std::cout << "\n SETTING Volume = " << volume << "\n";
    }

    void SwitchOff()
    {
        std::cout << "\n SWITCHING OFF HomeTheater \n";
    }
};
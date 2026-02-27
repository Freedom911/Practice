#pragma once
#include <string>
#include <iostream>
class PhilipsLight
{
    public:
    PhilipsLight() = default;

    void SwitchOn()
    {
        std::cout << "\n Philips Hue Light";
    }

    void SetBrightness(int brightness)
    {
        std::cout << "\n SETTING Brightness = " << brightness << "\n";
    }

    void SetColor(std::string Color)
    {
        std::cout << "\n SETTING Color = " << Color << "\n";
    }

    void SwitchOff()
    {
        std::cout << "\n SWITCHING OFF PhilipsLight \n";
    }
};
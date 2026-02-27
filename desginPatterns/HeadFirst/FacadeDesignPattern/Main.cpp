#include "HomeTheater.h"
#include "PhilipsLight.h"
#include "TV.h"
#include "Facade.h"
#include <iostream>


int main()
{
    //Without Facade
    #if 0

        m_tv->SwitchOn();
        m_tv->SetMovie(movieName);
        m_homeTheater->SwitchOn();
        m_homeTheater->SetVolume(29);

        m_light->SwitchOn();
        m_light->SetBrightness(90);
        m_light->SetColor("Blue");

         m_tv->SwitchOff();
        m_homeTheater->SwitchOff();
        m_light->SwitchOff();
    #endif

    //With Facade
    TV tv;
    HomeTheater theater;
    PhilipsLight light;
    Facade obj(&tv,&theater,&light);

    obj.WatchMovie("Walter Mitty");

    obj.EndMovie();
}
#include "HomeTheater.h"
#include "PhilipsLight.h"
#include "TV.h"


class Facade
{
    public:
    Facade(TV * tv,HomeTheater *homeTheater,PhilipsLight *light)
    {
        m_tv = tv;
        m_homeTheater = homeTheater;
        m_light = light;
    }

    void WatchMovie(std::string movieName)
    {
        m_tv->SwitchOn();
        m_tv->SetMovie(movieName);
        m_homeTheater->SwitchOn();
        m_homeTheater->SetVolume(29);

        m_light->SwitchOn();
        m_light->SetBrightness(90);
        m_light->SetColor("Blue");
    }

    void EndMovie()
    {
        m_tv->SwitchOff();
        m_homeTheater->SwitchOff();
        m_light->SwitchOff();
    }


    private:
    TV *m_tv;
    HomeTheater *m_homeTheater;
    PhilipsLight *m_light;
};
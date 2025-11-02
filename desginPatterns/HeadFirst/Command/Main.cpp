#include <iostream>
#include <vector>
#include <string>

//3rd Party IOT Deviceds ---------------------------------------------------------------------------
class Light
{
    public:
    Light(std::string LightName)
    {
        m_lightName = LightName;
    }
    void SwitchOn()
    {
        std::cout << "\n Switching On Light = " << m_lightName << "\n";
    }
    void SetBrightness(int brightness)
    {
        std::cout << "\n Setting Brightness = " << brightness << "\n";
    }
    void SwitchOff()
    {
        std::cout << "\n Switching Off Light = " << m_lightName << "\n";
    }

    private:
    std::string m_lightName;
};

class Fan
{
    public:
    Fan(std::string name)
    {
        m_fanName = name;
    }
    void SwitchOnFan()
    {
        std::cout << "\n Switching On Fan = " << m_fanName << "\n";
    }
    void SetSpeed(int speed)
    {
        std::cout << "\n Setting Speed = " << speed << "\n";
    }
    void SwitchOffFan()
    {
        std::cout << "\n Switching Off Fan = " << m_fanName << "\n";
    }
    
    private:
    std::string m_fanName;
};

class Geyser
{
    public:

    Geyser(std::string name)
    {
        m_name = name;
    }

    void SwitchOnGeyser()
    {
        std::cout << "\n Switching On Geyser = " << m_name << "\n";
    }
    void SetTemperature(int temperature)
    {
        std::cout << "\n Setting Temperature = " << temperature << "\n";
    }
    void SwitchOffGeyser()
    {
        std::cout << "\n Switching Off Geyser = " << m_name << "\n";
    }

    private:
    std::string m_name;
};

//3rd Party IOT Deviceds ---------------------------------------------------------------------------END


//Solution 1 Poor Design
//bakwas App
//ISSUE App
#if 0
class BakwasApp
{
    public:

    void On()
    {
        if(Product == "LIGHT")
        {
            SwitchOn();
        }
        else if(Product == "FAN")
        {
            SwitchOnFan();
        }
    }

};
#endif


//Solution 2

//We create command Object for Every Device

class Command
{
    public:
    virtual void ExecuteOn() = 0;
    virtual void ExecuteOff() = 0;
};

class FanCommand : public Command
{
    public:
    FanCommand(Fan *obj)
    {
        m_obj = obj;
    }

    void ExecuteOn() override
    {
        m_obj->SwitchOnFan();
        m_obj->SetSpeed(3);
    }

    void ExecuteOff() override
    {
        m_obj->SwitchOffFan();
    }

    private:
    Fan *m_obj;
};

class LightCommand : public Command
{
    public:
    LightCommand(Light *obj)
    {
        m_obj = obj;
    }

    void ExecuteOn() override
    {
        m_obj->SwitchOn();
        m_obj->SetBrightness(100);
    }

    void ExecuteOff() override
    {
        m_obj->SetBrightness(10);
        m_obj->SwitchOff();
    }

    private:
    Light* m_obj ;
};


class GeyserCommand : public Command
{
    public:
    GeyserCommand(Geyser *obj)
    {
        m_obj = obj;
    }

    void ExecuteOn() override
    {
        m_obj->SwitchOnGeyser();
        m_obj->SetTemperature(35);
    }

    void ExecuteOff() override
    {
        m_obj->SwitchOffGeyser();
    }

    private:
    Geyser* m_obj ;
};



//The Call to Specific Product is decoupled yippe
class GoodApp
{
    public:

    GoodApp(std::vector<Command*> commands)
    {
        m_commands = commands;
    }

    void SwitchOn(int No)
    {
        if(No < m_commands.size())
        {
            m_commands[No]->ExecuteOn();
        }
    }

    void SwitchOff(int No)
    {
        if(No < m_commands.size())
        {
            m_commands[No]->ExecuteOff();
        }
    }

    private:
    std::vector<Command*>m_commands;

};

int main()
{
    Light BedRoomLight("BedRoom");
    Light DrawingRoomLight("Drawing Room");
    Fan BedRoomFan("Bed Room");
    Fan DrawingRoomFan("Drawing Room");
    Geyser MainGeyser("Bathroom Geyser");
    
    LightCommand BedRoomLightCommand(&BedRoomLight);
    LightCommand DrawingRoomLightCommand(&DrawingRoomLight);
    FanCommand BedRoomFanCommand(&BedRoomFan);
    FanCommand DrawingRoomFanCommand(&DrawingRoomFan);
    GeyserCommand MainGeyserCommand(&MainGeyser);

    std::vector<Command*> commands;
    commands.push_back(&BedRoomLightCommand);
    commands.push_back(&DrawingRoomLightCommand);
    commands.push_back(&BedRoomFanCommand);
    commands.push_back(&DrawingRoomFanCommand);
    commands.push_back(&MainGeyserCommand);

    GoodApp goodApp(commands);

    goodApp.SwitchOn(0);
    goodApp.SwitchOn(1);
    goodApp.SwitchOn(2);
    goodApp.SwitchOn(3);
    goodApp.SwitchOn(4);


    goodApp.SwitchOff(0);
    goodApp.SwitchOff(1);
    goodApp.SwitchOff(2);
    goodApp.SwitchOff(3);
    goodApp.SwitchOff(4);
}


## Principle of Least Knowledge or Law of Demeter

The Principle Says to Talk to your immediate friends

That is to reduce interactions between objects

like this shouldnt be the case

float GetTemp()
{
    return GetCity()->GetSector()->GetSociety()->GetFlat()->GetRoom()->GetWall()->GetSensor()->GetThermometer()->GetTemperature();
}

WE are doing chain of operation. But Why this is bad
1. First we have to Keep All the Headers of the object in our calling calss thus increasing coupling
2. Any change in the order will require changing out code

Rather we should try to encapsulate

Like in our City Class we Define a function which returns the temperature

float GetTemp()
{
    return GetCity()->GetMainRoomTemperature();
}

GetMainRoomTemperature()
{
    GetSector()->GetMainRoomTemperature();
}

//and so on
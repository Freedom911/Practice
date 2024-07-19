#include <iostream>

//Consider Following Example

#if 0
class Duck
{
    public:
    virtual void Quack()
    {
        std::cout << "\n I am Quacking \n";
    }
    virtual void Swim()
    {
        std::cout << "\n I am Swimming \n";
    }
    virtual void Display() = 0;
};

class MallardDuck:public Duck
{
    public:
    void Display() override
    {
        std::cout << "\n Displaying MAllard Duck \n";
    }

};


class RedHeadDuck:public Duck
{
    public:
    void Display() override
    {
        std::cout << "\n Displaying RedHead Duck \n";
    }

};
#endif

//Now we want to add Fly functionality and a new duck type of toy duck
//we can do 

//SOLUTION 1 - Adding Fly Method to Duck ---------------------------------------------------------
class Duck
{
    public:
    virtual void Quack()
    {
        std::cout << "\n I am Quacking \n";
    }
    virtual void Swim()
    {
        std::cout << "\n I am Swimming \n";
    }
    virtual void Display() = 0;
    virtual void Fly()
    {
        std::cout << "\n Duck Can Fly \n";
    }
};

class MallardDuck:public Duck
{
    public:
    void Display() override
    {
        std::cout << "\n Displaying MAllard Duck \n";
    }
    void Fly() override
    {
        std::cout << "\n Fly Mallard Duck \n";
    }

};


class RedHeadDuck:public Duck
{
    public:
    void Display() override
    {
        std::cout << "\n Displaying RedHead Duck \n";
    }
    void Fly() override
    {
        std::cout << "\n Fly RedHead Duck \n";
    }

};

class ToyDuck:public Duck
{

    public:
    void Display() override
    {
        std::cout << "\n Displaying Toy Duck \n";
    }
    void Fly() override
    {
        //Do Nothing
    }
};

//Issue with above is we have to implement uncessary functions for classes that dont
//require those functions

//SOLUTION 2 - Adding Interfaces ---------------------------------------------------------

class FlyInterface
{
    public:
    virtual void Fly() = 0;
};

//now the issue is if 100 ducks are there and using fly interface
//then code duplicay would be there



int main()
{


}


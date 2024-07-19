#include <iostream>


//Solution - Strategy Pattern
//Pull Varying element that is flying behavior in a different class. We pull Flying Interface
//and we will use composition over inheritance as composition is more flexible

//the behaviors flying is also called as set of algorithms
//with this pattern we can change pattern at runtime

class FlyingInterface
{
    public:
    virtual void Fly() = 0;
};


class Flyable:public FlyingInterface
{
    public:
    virtual void Fly() override
    {
        std::cout << "\n I canFly \n";
    }
};

class NonFlyable:public FlyingInterface
{
    public:
    virtual void Fly() override
    {
        std::cout << "\n I cant Fly \n";
    }
};

class Duck
{
    public:
    Duck(FlyingInterface *interface)
    {
        flying = interface;
    }
    ~Duck()
    {
        delete flying;
        flying = nullptr;
    }
    virtual void Quack()
    {
        std::cout << "\n I am Quacking \n";
    }
    virtual void Swim()
    {
        std::cout << "\n I am Swimming \n";
    }

    void SetFlyingBehavior(FlyingInterface *interface)
    {
        if(flying)
        {
            delete flying;
        }
        flying = interface;
    }
    virtual void Display() = 0;

    void Fly()
    {
        flying->Fly();
    }
    private:
    FlyingInterface *flying;
};

class MallardDuck:public Duck
{
    public:
    MallardDuck():Duck(new Flyable()){}
    void Display() override
    {
        std::cout << "\n Displaying MAllard Duck \n";
    }

};


class RedHeadDuck:public Duck
{
    public:
    RedHeadDuck():Duck(new Flyable()){}
    void Display() override
    {
        std::cout << "\n Displaying RedHead Duck \n";
    }

};

class ToyDuck:public Duck
{

    public:
    ToyDuck():Duck(new NonFlyable()){}
    void Display() override
    {
        std::cout << "\n Displaying Toy Duck \n";
    }
};

int main()
{
  
  MallardDuck duck;
  duck.Display();
  duck.Fly();

  ToyDuck toy;
  toy.Display();
  toy.Fly();
  toy.SetFlyingBehavior(new Flyable()); //Changing Behavior at runtime
  toy.Fly();

}


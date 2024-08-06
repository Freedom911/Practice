//Factory Method encapsulates object creation such that 
//subclasses decided which classto instantiate.
#include <iostream>
#include <vector>
#include <string>

class Pizza
{
    public:
    void prepare()
    {
       std::cout << "\n Start Preparing ";
    }
    void   bake()
    {
        std::cout << "\n Adding = ";
        for(auto &e : toppings)
        {
            std::cout << e << ",";
        }
    }

    void  serve()
    {
        std::cout << "\n Serving \n";
    }

    protected:
    std::vector<std::string> toppings;
};

class NoidaCheeseBurst : public Pizza
{
    public:
    NoidaCheeseBurst()
    {
        toppings.push_back("cheese");
        toppings.push_back("mayonaise");
        toppings.push_back("onion");
    }
};

class DelhiCheeseBurst : public Pizza
{
    public:
    DelhiCheeseBurst()
    {
        toppings.push_back("mayonaise");
        toppings.push_back("onion");
        toppings.push_back("sweet corn");
    }
};


class NoidaHandTossed : public Pizza
{
    public:
    NoidaHandTossed()
    {
        toppings.push_back("onion");
    }
};

class DelhiHandTossed : public Pizza
{
    public:
    DelhiHandTossed()
    {
        toppings.push_back("tomato");
    }
};

//Problem consider following. Here the object creation is hardcoded here
//and whenever we have to add new pizza we have to change here.
class NormalPizzaStore
{
    public:
    void OrderPizza(std::string type)
    {
        Pizza * ptr ;
       if(type == "cheese")
       {
          //create cheese pizza
          ptr = new NoidaCheeseBurst();
       }

       else if (type == "hand tossed")
       {
           //creates hand tossed pizza
          ptr = new NoidaHandTossed();
       }
       
       ptr->prepare();
       ptr->bake();
       ptr->serve();
    }
};


//Solution 1 . Simple Factory Method
//We enapsulate creation method in a method
//which is known as simple factory method
//here create Pizza is simplefactory method

class NormalPizzaStore1
{
    public:
    void OrderPizza(std::string type)
    {
       Pizza * ptr = CreatePizza(type);

       if(!ptr)
       {
           return;
       }
       
       ptr->prepare();
       ptr->bake();
       ptr->serve();
    }

    Pizza * CreatePizza(std::string type)
    {
       
       if(type == "cheese")
       {
          //create cheese pizza
          return new NoidaCheeseBurst();
       }

       else if (type == "hand tossed")
       {
           //creates hand tossed pizza
          return new NoidaHandTossed();
       }

       return nullptr;
    }
};

//FACTORY METHOD PATTERN ===============================================================================


//Solution 2 . Use Factory Method pattern. we make create pizza method pure virtual 
//and let subclasses decide which class to make. This gives more flexibility

class PizzaStore
{
    public:
    void OrderPizza(std::string type)
    {
       Pizza * ptr = CreatePizza(type);

       if(!ptr)
       {
           return;
       }
       
       ptr->prepare();
       ptr->bake();
       ptr->serve();
    }
    
    //makig it pure virtual
    virtual Pizza * CreatePizza(std::string type) = 0;
};

class NoidaPizzaStore : public PizzaStore
{
    public:
    Pizza *CreatePizza(std::string type)
    {
       if(type == "cheese")
       {
          //create cheese pizza
          return new NoidaCheeseBurst();
       }

       else if (type == "hand tossed")
       {
           //creates hand tossed pizza
          return new NoidaHandTossed();
       }

       return nullptr;
    }
};


class DelhiPizzaStore : public PizzaStore
{
    public:
    Pizza *CreatePizza(std::string type)
    {
       if(type == "cheese")
       {
          //create cheese pizza
          return new DelhiCheeseBurst();
       }

       else if (type == "hand tossed")
       {
           //creates hand tossed pizza
          return new DelhiHandTossed();
       }

       return nullptr;
    }
};


int main()
{
    NoidaPizzaStore* noida = new NoidaPizzaStore();

    std::cout << "\n Preparing Noida Pizza style\n";
    noida->OrderPizza("cheese");

    DelhiPizzaStore* delhi = new DelhiPizzaStore();
    std::cout << "\n Preparing Delhi Pizza style\n";
    delhi->OrderPizza("cheese");

}

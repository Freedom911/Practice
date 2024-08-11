#include <iostream>

//In abstractory we have
//abstract factory,abstract product and client entities

//We are opening our own choto pizza company
//we are setting up factory in delhi and noida for pizza ingredients

//Product No 1
//Dough
class Dough
{

};

class AttaDough : public Dough
{
    public:
    AttaDough()
    {
        std::cout << " Atta Dough \n";
    }
};


class MaidaDough : public Dough
{
    public:
    MaidaDough()
    {
        std::cout << " Maida Dough \n";
    }
};


//Product No 2
//Cheese

class Cheese
{

};

class Mozzarella : public Cheese
{
    public:
    Mozzarella()
    {
        std::cout << " Mozzarella Cheese \n";
    }
};


class Parmesan : public Cheese
{
    public:
    Parmesan()
    {
        std::cout << " Parmesan Cheese \n";
    }
};

//Product 3 topping

class Toppings
{

};

class Achari : public Toppings
{
   public:
   Achari()
   {
       std::cout << " Achari Flavour \n";
   }
};

class Jalapeno : public Toppings
{
    public:
    Jalapeno()
    {
        std::cout << " Jalapeno \n";
    }
};



//Our so called abstract Factories
class PizzaIngredientFactory
{
    public:
    virtual Dough * createDough() = 0;
    virtual Cheese * addCheese() = 0;
    virtual Toppings * addTopping() = 0;
};


class NoidaFactory : public PizzaIngredientFactory
{
    public:

    NoidaFactory()
    {
        std::cout << "\n\n ====Noida Factory==== \n\n";
    }

    Dough * createDough() override
    {
        return new MaidaDough();
    }

    Cheese * addCheese() override
    {
        return new Mozzarella();
    }

    Toppings * addTopping() override
    {
        return new Jalapeno();
    }



};


class DelhiFactory : public PizzaIngredientFactory
{
    public:
    DelhiFactory()
    {
        std::cout << "\n\n===== Delhi Factory =====\n\n";
    }
    Dough * createDough() override
    {
        return new AttaDough();
    }

    Cheese * addCheese() override
    {
        return new Parmesan();
    }

    Toppings * addTopping() override
    {
        return new Achari();
    }
};


//Client Code ---------------------------------------------------
class Pizza
{
    public:
    void Bake()
    {
        std::cout << "\n Baking at 250 o C";
    }

    void Cut()
    {
        std::cout << "\n Cutting in circle Shape";
    }

    void Serve()
    {
        std::cout << "\n Serving Garma Garm Pizza";
    }

    virtual void Prepare() = 0;

    protected:
    Dough *dough {nullptr};
    Cheese *cheese {nullptr};
    Toppings * topping {nullptr};
};

class MexicanGreenWave : public Pizza
{
    public:
    MexicanGreenWave(PizzaIngredientFactory *fact)
    {
        factory = fact;
    }
    void Prepare() override
    {
        std::cout << "\n Preparing mexican Green Wave";
        dough = factory->createDough();
        cheese = factory->addCheese();
    }
    private:
    PizzaIngredientFactory *factory;
};


class AchariPyaza : public Pizza
{
    public :
    AchariPyaza(PizzaIngredientFactory *fact)
    {
        factory = fact;
    }
    void Prepare() override
    {
        std::cout << "\n Preparing Achari Pyaza Pizza";
        dough = factory->createDough();
        cheese = factory->addCheese();
        topping = factory->addTopping();
    }
    private:
    PizzaIngredientFactory *factory;
};
//------------------------------------------------------------

int main()
{
    //this itself can be moved to factory method. Check that pattern
    Pizza * pizza = new MexicanGreenWave(new NoidaFactory());
    pizza->Prepare();
    pizza->Bake();
    pizza->Cut();
    pizza->Serve();


    Pizza *pizza1 = new MexicanGreenWave(new DelhiFactory);
    pizza1->Prepare();
    pizza1->Bake();
    pizza1->Cut();
    pizza1->Serve();

    
    //Achari Style

    //this itself can be moved to factory method. Check that pattern
    Pizza * pizza2 = new AchariPyaza(new NoidaFactory());
    pizza2->Prepare();
    pizza2->Bake();
    pizza2->Cut();
    pizza2->Serve();


    Pizza *pizza3 = new AchariPyaza(new DelhiFactory);
    pizza3->Prepare();
    pizza3->Bake();
    pizza3->Cut();
    pizza3->Serve();

}


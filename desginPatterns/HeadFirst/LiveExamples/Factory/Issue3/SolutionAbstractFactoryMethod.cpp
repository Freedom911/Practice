//Abstract Factory Is Responible For Creating Multiple Products.Basically It contains Factories
//In Factory pattern we are basically creating single product

#include <iostream>
#include <vector>

//Not Really Part of Abstract Factory 
//But instead of String this is better
enum class BurgerType
{
    Cheese,
    Nacho,
    Momo,
    Fit
};

enum class FriesType
{
    Cheese,
    Peri-Peri,
};

enum class BeverageType
{
    Suger,
    SugarFree
};

//-------------------------------------PRODUCTS------------------------------------
class Burger
{

};

class USPBurger : public Burger
{

};

class PappehBurger : public Burger
{

};

class FriedMomoBurger : public Burger
{

};


class WrapperBurger : public Burger
{

};

class NachoBurger : public Burger
{

};

class MomoBurger : public Burger
{

};


class Fries
{

};

class HotShockCheeseFries:public Fries
{

};

class Dilly6Fries:public Fries
{

};

class MexicanSauceFries:public Fries
{

};

class PeriPeriFries:public Fries
{

};

//-------------------------------------PRODUCTS------------------------------------

//Abstract Factory is responible for creating multiple type of products
class AbstractFactory
{
    public:

    virtual Burger* GetBurger(const BurgerType &burgerType) = 0;
    virtual Fries* GetFries(const FriesType &burgerType) = 0;
    //virtual Beverage* GetBeverage(const BeverageType &burgerType) = 0;
};

//Concrete Faxtory 1
class BurgerSinghFactory public AbstractFactory
{
    public:

    Burger* GetBurger(const BurgerType &burgerType) override
    {
        if(burgerType == BurgerType::Cheese)
        {
            return new USPBurger();
        }
        else if(burgerType ==  BurgerType::Nacho)
        {
            return new PappehBurger();
        }
        else if(burgerType == BurgerType::Momo)
        {
            return new FriedMomoBurger();
        }
        else
        {
            std::cout << "\n Not A valid Burger \n";
        }

        return nullptr;

    }

    Fries* GetFries(const FriesType &friesType) override
    {
        if(friesType == FriesType::Cheese)
        {
            return new HotShockCheeseFries();
        }
        else if(friesType ==  Fries::Peri-Peri)
        {
            return new Dilly6Fries();
        }
        else
        {
            std::cout << "\n Not A Valid Fries \n";
        }

        return nullptr;
            
    }

};

//Concrete Factory 2
class BurgerKingFactory public AbstractFactory
{
    public:

    Burger* GetBurger(const BurgerType &burgerType) override
    {
        if(burgerType == BurgerType::Cheese)
        {
            return new WrapperBurger();
        }
        else if(burgerType ==  BurgerType::Nacho)
        {
            return new NachoBurger();
        }
        else if(burgerType == BurgerType::Momo)
        {
            return new MomoBurger();
        }
        else
        {
            std::cout << "\n Not A valid Burger \n";
        }

        return nullptr;

    }

    Fries* GetFries(const FriesType &friesType) override
    {
        if(friesType == FriesType::Cheese)
        {
            return new MexicanSauceFries();
        }
        else if(friesType ==  Fries::Peri-Peri)
        {
            return new PeriPeriFries();
        }
        else
        {
            std::cout << "\n Not A Valid Fries \n";
        }

        return nullptr;
            
    }

};


//Elegant Solution each concrete creator handles specfic concrete product. Very GOod we are only encapuslating the varying part 
//that is the varying function getBaseScren
int main()
{
#if 1
    BurgerKingFactory *burgerFactory = new BurgerKingFactory();
#endif
    menu->PreviewPrintScreen("HISTORY");
}

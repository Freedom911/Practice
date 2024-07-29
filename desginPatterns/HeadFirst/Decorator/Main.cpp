
#include <iostream>

//Parent class
class Beverage
{
	public:
	virtual double getCost() = 0;
	
	virtual std::string getDescription() = 0;
};

class Tea: public Beverage
{
	public:
	double getCost() override
	{
		return 15.0;
	}
	
	std::string getDescription() override
	{
		return "Chai";
	}
};

class GreenTea: public Beverage
{
	public:
	double getCost() override
	{
		return 20.0;
	}
	
	std::string getDescription() override
	{
		return "Green Tea";
	}
};

class LemonTea: public Beverage
{
	public:
	double getCost() override
	{
		return 20.0;
	}
	
	std::string getDescription() override
	{
		return "Lemon Tea";
	}
};

//now what if we want to add elaichi tea,masala tea,double masala tea,
//masala green tea etc
//then we can have multiple classes inheriting from beverage but this will make_heap
//too manyh classes and what if we want double masala tea or double masala tripple elachi
//tea. Also if elachi cost changes then we have to double changes in multiple classes.
//First it breaks S single responisbiliy principle,O - open for extension and closedir
//for modification as we have to alter existing classes for new condiments.

//Solution 1 what if in beverage class we define cost for mutiple condiments
//then also O principle is broken and also I - interface segmentation princpiple is 
//broken as the child classes will have to inherit functions which donot make sense
//like lemon elaichi tea etc
//Solution 2 we decorate with decorator pattern. Decorator pattern adds behavior 
//dynamically before/after forwarding the calls to the object.like
//if want double elachitea then first decorate tea with elachi then again take
//that object and decorate with elachi. We call the outer most function which 
//forwards call to inner objects. Decorator are deriving from same parent but they use
//composition to achieve the functionality. The objects can be decorated dynamically.

class CondimentDecorator: public Beverage
{
	public:
	virtual double getCost() = 0;
	virtual std::string getDescription() = 0;
	
	protected:
	Beverage *beverage{nullptr};
};


class Elaichi : public CondimentDecorator
{
	public:
	Elaichi(Beverage *lBeverage)
	{
		beverage = lBeverage;
		std::cout << "\n Adding Elaichi \n";
	}
	double getCost() override
	{
		if(beverage == nullptr)
			return -1;
		return 5 + beverage->getCost();
	}
	
	std::string getDescription()
	{
		if(beverage == nullptr)
			return "";
		return "elachi " + beverage->getDescription();
	}
};

class Masala : public CondimentDecorator
{
	public:
	Masala(Beverage *lBeverage)
	{
		beverage = lBeverage;
		std::cout << "\n Adding Masala \n";
	}
	double getCost() override
	{
		if(beverage == nullptr)
			return -1;
		return 10 + beverage->getCost();
	}
	
	std::string getDescription()
	{
		if(beverage == nullptr)
			return "";
		return "masala " + beverage->getDescription();
	}
};



int main()
{
	//we want elaichi tea
	Tea Chai;
	std::cout << "\n" << Chai.getDescription() << " Cost = " << Chai.getCost() << "\n";
	Elaichi  elaichi (&Chai);
	//shoudl give 20
    std::cout << "\n " << elaichi.getDescription() << " Cost = " << elaichi.getCost() << "\n";
	
	//we want double masala elaichi lemon tea
	LemonTea lemon;
	std::cout << "\n" << lemon.getDescription() << " Cost = " << lemon.getCost() << "\n";
	Elaichi  elaichi1 (&lemon);
	Elaichi elaichi2(&elaichi1);
	Masala masala (&elaichi2);
	
	//shoudl give 45
	std::cout << "\n " << masala.getDescription() << " Cost = " << masala.getCost() << "\n";
	
}

#include <iostream>
#include <memory> // for std::shared_ptr
#include <string>

/**
 * 
 * std::weak_ptr was designed to solve the “cyclical ownership” problem described in the problem i wrote in circular dependcy.
 *  A std::weak_ptr is an observer -- it can observe and access the same object as a std::shared_ptr (or other std::weak_ptrs) 
 * but it is not considered an owner. Remember, when a 
 * std::shared pointer goes out of scope, it only considers whether other std::shared_ptr 
 * are co-owning the object. std::weak_ptr does not count!
 * 
 * But i say it is a simple raw pointer. nah. it does have special thingy that allows it to get notified if the underlying object has been
 * deleted not raw pointer. it doesnt have. 
 * It uses observer pattern
 * 
 * To use weak ptr we cant use directly
 * if (std::shared_ptr<int> tempShared = weak.lock()) {
    std::cout << *tempShared; // Safe to use
} else {
    std::cout << "Object is already dead!";
}
 */

class Person
{
	std::string m_name;
	std::weak_ptr<Person> m_partner; // initially created empty

public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") }; // create a Person named "Lucy"
	auto ricky { std::make_shared<Person>("Ricky") }; // create a Person named "Ricky"

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

    //Check for your self the destructor is not called
    //see when lucy goes out of scope it says are there any one refering lucy yes ricky bhaiya
    //so it waits for ricky when it goes out of scope it asks any one owns ricky bhaiya yes lucy
    //so neither is deleted

	return 0;
}
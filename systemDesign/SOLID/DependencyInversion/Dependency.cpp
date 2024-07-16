//classes should depend on interfaces rather than concrete classes
#include <iostream>

//example of class depending on concrete classes
class Keyboard
{

};

class WirelessKeyboard:public Keyboard
{
   public:
   WirelessKeyboard()
   {
       std::cout << "\n It is a wireless keyboard \n";
   }
};

class WiredKeyboard:public Keyboard
{
   public:
   WiredKeyboard()
   {
       std::cout << "\n it is a wired keyboard \n";
   }
};

//the following class is directly depending on the concrete classes
//tomorrow if we want to add wireless keyboard we have to do code change in the class
class MacBook
{
    public:
    MacBook()
    {
        wired = new WiredKeyboard();
    }
    private:
    WiredKeyboard * wired;
};

//solution
//the class is using interface instead of concrete classes
//we can change behavior of keyboard without changing the class
class MacBookUpdated
{
    public:
    MacBookUpdated(Keyboard*keyboard)
    {
        this->keyboard = keyboard;
    }
    private:
    Keyboard* keyboard{nullptr};
};


int main()
{
    MacBookUpdated newMacBook(new WirelessKeyboard());
    MacBookUpdated oldMacBook(new WiredKeyboard());
}

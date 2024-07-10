#include <iostream>

//Example of class violating single responsibility
//here there are three reasons to change the class
//Whenever there is change in logic of any 3 function then
//we have to change the class
class DisplayScreen
{
    public:

        void DisplayToScreen()  //Reason 1 for Change
        {
            std::cout << "\n Display To Screen";
        }

        void Print() //Reason 2 for Change
        {
            //Send command to printer for printing
        }

        void SaveToDB() // Reason 3 For Change
        {
            //Execute query for saving todb
        }
};


//SOlution
//we split the functionality into different classes

class DisplayScreenImproved
{
    public:

        void DisplayToScreen()  //Reason 1 for Change
        {
            std::cout << "\n Display To Screen";
        }

};


class PrintPaper
{
    public:
        void Print()
        {
            //Print Logic
        }

};

class Save
{
    public:
        void SaveToDB()
        {

        }
};



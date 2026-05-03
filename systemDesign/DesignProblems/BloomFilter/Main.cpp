#include "BloomFilter.h"
#include <iostream>
#include <string>


int main()
{

    BloomFilter filter(10);
 

    std::string input;
    do 
    {
        std::cout << "Enter UserName  (empty line to quit): ";
        std::getline(std::cin, input);

        if (!input.empty()) 
        {
            std::cout << "\nYou typed: " << input << "\n";
        }
        if(filter.Check(input))
        {
            std::cout << "\n User Already Taken \n";
        }
        else
        {
            std::cout << "\n User Registered \n";
            filter.Add(input);
        }

    } while (!input.empty()); // loop stops when input is empty

    std::cout << "Goodbye!\n";
}

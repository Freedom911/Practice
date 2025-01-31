//Stringstream allows to read from a string as it was stream
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iterator>

int main()
{

    //splitting multiple delimieter case
    std::string splitString = "hello.Srajan,This";
    //delimit via,. and space
    std::regex re("[,.]");
    std::sregex_token_iterator it(splitString.begin(),splitString.end(),re,-1);
    const std::sregex_token_iterator end;

    for(it; it != end; it++)
    {
        std::cout << "[" << *it << "]" << ",";
    }


   // std::vector<std::string>tokenized{it,{}};
   // std::cout << "\n Token Content = ";
   // std::for_each(tokenized.begin(),tokenized.end(),[](const std::string &elem){
   //         std::cout << elem << ",";
   //         });

    std::cout << "\n";



    



}

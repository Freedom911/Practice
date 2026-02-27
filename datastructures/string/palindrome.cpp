#include <iostream>
#include <string>

bool isAlphabeticPalindrome(std::string code) 
{
    int i = 0;
    int j = code.length() - 1;
    while(i < j)
    {
        
        if(std::isalpha(code[i]) == false)
        {
            i++;
            continue;
        }

        if(std::isalpha(code[j]) == false)
        {
            j--;
            continue;
        }

        if(std::tolower(code[i]) != std::tolower(code[j]))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int main()
{
    std::cout << std::boolalpha << isAlphabeticPalindrome("abc123cba");
}
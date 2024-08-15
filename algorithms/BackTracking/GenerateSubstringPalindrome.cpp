//Generall all substrings such that they are palindrome
//eg inp = aab
//output [a,a,b], [aa,b] string in each array is palindrome
//using backtracking
//we start with index = 0. if any point we dont get palindrome we dont proceed further
//index is incremented only if the string is plaindrome

#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(std::string str)
{
    int i = 0;
    int j = str.size() - 1;

    while(i <= j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;

}


void solve(std::string &inp,std::vector<std::string> &temp,int index)
{
    if(index == inp.size())
    {
        std::cout << "\n";
        for(int j = 0; j < temp.size(); j++)
        {
            std::cout << temp[j] << ",";
        }

        std::cout << "\n";

        return;
    }

    std::string pal;
    for(int i = index; i < inp.size(); i++)
    {
        pal += inp[i];
        if(isPalindrome(pal))
        {
            temp.push_back(pal);
            solve(inp,temp,index+1);
            temp.pop_back();
        }
    }
}


int main()
{
    std::string str = "aab";
    std::vector<std::string>temp;
    solve(str,temp,0);
}

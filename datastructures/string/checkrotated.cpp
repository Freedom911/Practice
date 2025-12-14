/**
 * https://www.geeksforgeeks.org/dsa/check-string-can-obtained-rotating-another-string-2-places/
 *
 * Given two strings, str1 and str2, the task is to determine if 
 * str2 can be obtained by rotating str1 exactly 2 places in 
 * either a clockwise or anticlockwise direction.
 *
 *     Input: str1 = "amazon", str2 = "azonam"
    Output: Yes
    Explanation: Rotating string1 by 2 places in anti-clockwise gives the string2.

    Input: str1 = "amazon", str2 = "onamaz"
    Output: Yes
    Explanation: Rotating string1 by 2 places in clockwise gives the string2.

    //I will present 2 solution .
    Solution 1 rotates string two times and checks if it is same
    so 2 times clockwise and 2 times anti

    Solution 2 is best
    so basically it compares 
    i+2 with i or i with i + 2 in case of clock and anti clock respectively

 */ 

#include <iostream>
#include <string>

//Rotate clockwise
//eg 
//a b c d
//b c d a
//arr[i] = ar[i+1]
//at[n-1] = temp
//where temp is pointing tofirst
void clockwise(std::string &str)
{
    if(str.size() == 0)
    {
        return ;
    }
    char tempChar = str[0];

    for(int i = 0; i < str.size() - 1; i++)
    {
        str[i] = str[i+1];
    }

    str[str.size() - 1] = tempChar;

}


//Rotate AntiClockwise
//eg 
//a b c d
//d a b c
//arr[i] = ar[i-1]
//and we start from last
//at[0] = temp
//where temp is pointing to last
void anticlockwise(std::string &str)
{
    if(str.size() == 0)
    {
        return ;
    }
    char tempChar = str[str.size() - 1];

    for(int i = str.size() - 1; i > 0; i--)
    {
        str[i] = str[i-1];
    }

    str[0] = tempChar;

}

bool isRotated(std::string str1,std::string str2)
{
    if(str1.size() == 0 && str2.size() == 0)
    {
        return true;
    }

    if(str1.size() != str2.size())
    {
        return false;
    }
    std::string strCopy = str1;
    clockwise(strCopy);
    clockwise(strCopy);

    if(strCopy == str2)
    {
        std::cout << "\n Clockwise\n";
        return true;
    }
    strCopy = str1;
    anticlockwise(strCopy);
    anticlockwise(strCopy);

    if(strCopy == str2)
    {
        std::cout << "\n Anti Clockwise\n";
        return true;
    }

    return false;
}

bool isRotatedOptimized(std::string &str1,std::string &str2)
{
    if(str1.size() == 0 && str2.size() == 0)
    {
        return true;
    }

    if(str1.size() != str2.size())
    {
        return false;
    }
    //for clockwise
    //amazon
    //azonam
    //basically i+2 of str1 is compared with i of str2
    //similarly for anti clockwise
    //i ofstr1 is compared with i+2 of str2
    //eg amazon
    //onamaz

    //for clockwise
    bool bisRotated = true;
    for(int i = 0; i < str1.size(); i++)
    {

        if(str1[(i+2)%str1.size()] != str2[i])
        {
            bisRotated = false;
            break;
        }
    }

    if(bisRotated == true)
    {
        return true;
    }
    
    for(int i = 0; i < str2.size(); i++)
    {

        if(str1[i] != str2[(i+2)%str2.size()])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string str1 = "amazon";
    std::string str2 = "azonam";

    if (isRotatedOptimized(str1, str2))
    {
        std::cout << "True" << std::endl;
    } 
    else 
    {
        std::cout << "False" << std::endl;
    }

    str1 = "amazon";
    str2 = "onamaz";
    if (isRotatedOptimized(str1, str2)) 
    {
        std::cout << "True" << std::endl;
    } 
    else 
    {
        std::cout << "False" << std::endl;
    }
}

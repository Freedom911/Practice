#include <iostream>
#include <string>

//s1 = abcde
//s2 = cdeab true
//s2 = deabc true
//NOt COrrect ALthough very close
bool isNonTrivialRotation(std::string s1, std::string s2) 
{
    if(s1 == s2 || s1.size() != s2.size())
    {
        return false;
    }

    //First find position of the first character of s2
    //Fails in case of duplicate
    //abac
    //acab
    int pos = -1;
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == s2[0])
        {
            pos = i;
            break;
        }
    }

    //check for clockwise and anti
    bool bIsRotated = true;
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[(i+pos) % s1.size()] != s2[i])
        {
            bIsRotated = false;
            break;
        }
    }

    if(bIsRotated == true)
    {
        return true;
    }

    for(int i = 0; i < s2.length(); i++)
    {
        if(s2[(i+pos) % s2.size()] != s1[i])
        {
            return false;
        }
    }

    return true;


}

//better logic
bool isNonTrivialRotation(std::string s1, std::string s2) 
{
    // 1. Length check and "Non-Identical" check
    if (s1.size() != s2.size() || s1 == s2) {
        return false;
    }

    // 2. Concatenate s1 with itself
    std::string combined = s1 + s1;

    // 3. Check if s2 is a substring of the combined string
    // string::npos is returned if the substring is not found
    if (combined.find(s2) != std::string::npos) 
    {
        return true;
    }

    return false;
}

int main()
{
    std::cout << std::boolalpha << isNonTrivialRotation("a","b") << "\n";
}
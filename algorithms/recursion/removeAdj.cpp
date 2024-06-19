#include <iostream>
#include <string>

//We use IBH method to remove adjacent_difference.
//Any time we find adjacent we remove the adjacent and restart 
//from 0th index
//Hypothesis
std::string RemoveAdjacent(std::string str,int i)
{
	//Base conditions
	if(str.empty() || i >= str.length())
	{
		return str;
	}
	
	//Induction step
	int j = i + 1;
	bool erased = false;
	while(j < str.length() && str[i] == str[j])
	{
		j++;
		erased = true;
	}
	
	if(erased)
	{
		str.erase(i,j -i);
		return RemoveAdjacent(str,0);
	}
	else
	{
		return RemoveAdjacent(str,i+1);
	}
}

int main()
{
	std::string str = "bbbcccbd";
	
	std::cout << "\n Original String = " << str << "\n";
	
	//RemoveAdjacent(str,0);
	
	//std::cout << "After removing adjacent = " << str << "\n";
	
	
	
	char str1[] = "geeksforgeeg";
    std::cout << "This is it =	" << RemoveAdjacent("abbbccaba",0) << std::endl;

    char str2[] = "azxxxzy";
    std::cout << RemoveAdjacent("azxxxzy",0) << std::endl;

    char str3[] = "caaabbbaac";
    std::cout << RemoveAdjacent("caaabbbaac",0) << std::endl;

    char str4[] = "gghhg";
    std::cout << RemoveAdjacent("gghhg",0) << std::endl;

    char str5[] = "aaaacddddcappp";
    std::cout << RemoveAdjacent("aaaacddddcappp",0) << std::endl;

    char str6[] = "aaaaaaaaaa";
    std::cout << RemoveAdjacent("aaaaaaaaaa",0) << std::endl;

    char str7[] = "qpaaaaadaaaaadprq";
    std::cout << RemoveAdjacent("qpaaaaadaaaaadprq",0) << std::endl;

    char str8[] = "acaaabbbacdddd";
    std::cout << RemoveAdjacent("acaaabbbacdddd",0) << std::endl;

    char str9[] = "acbbcddc";
    std::cout << RemoveAdjacent("acbbcddc",0) << std::endl;
}
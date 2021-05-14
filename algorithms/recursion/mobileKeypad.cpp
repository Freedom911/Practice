//Given a set of digits find all the stirngs that can be formed
// 2->abc,
//3 def
//4 ghi
//5 jkl,6 mno 7 pqrs 8 tuv 9 wxyz

#include <iostream>
#include <string>
#include <map>

std::string output;
std::map<std::string,std::string> map;

void findSequence(std::string currList,std::string digits)
{
  if(digits.empty())
  {
    output += currList + ",";
    return;
  }
  else
  {
    std::string digit = digits.substr(0,1);
    std::string letters = map[digit];

    for(int j = 0; j < letters.length(); j++)
    {
      std::string letter(1,letters[j]);
      findSequence(currList + letter,digits.substr(1));
    }

  }

}
int main()
{
  map["2"] = "abc";
  map["3"] = "def";
  map["4"] = "ghi";
  map["5"] = "jkl";
  map["6"] = "mno";
  map["7"] = "pqrs";
  map["8"] = "tuv";
  map["9"] = "wxyz";

  findSequence("","34567");

  std::cout << "\n RESULT = = " << output << "\n";
}

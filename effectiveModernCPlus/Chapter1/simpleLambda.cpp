#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

void ForEach(std::vector<int> elem,const std::function<void(int)> &func)
{
  for(int value:elem)
   func(value);
}

int main()
{
  std::vector<int> vec {2,3,4,5,1,100};
  int a = -1;
  
  //[] -is called caputre
  //[&] means call by ref
  //[=] pass everything by value
  //
  //used when we want to send value from outside
  //auto lambda = [&](int value){a = 5; if (a < value) std::cout << "a " << a << " is bigger \n"; else std::cout << "value " << value << "is bigger \n";}
  //Tis will give error To modify we specify mutable
  //auto lambda = [=](int value){a = 5; if (a < value) std::cout << "a " << a << " is bigger \n"; else std::cout << "value " << value << "is bigger \n";};
  auto lambda = [=](int value) mutable {a = 5; if (a > value) std::cout << "a " << a << " is bigger \n"; else std::cout << "value " << value << "is bigger \n";};

  ForEach(vec,lambda);

  for(int value:vec)
    std::cout << "\n BEFORE VALUE is = " << value << "\n";
   
  vec.erase(std::remove_if(vec.begin(),vec.end(),[](int value){return (value %2) == 0 ?true:false;}),vec.end());
  std::cout << "\n HEY HEY \n";
  for(int value:vec)
    std::cout << "\n VALUE is = " << value << "\n";

  

  
  

}

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
  int a = 0;
  
  //1.[] -is called caputre
  //2.[&] means call by ref
  //3.[=] pass everything by value
  //4.mutable allows captured value to be modified. Here it is a
  //5.throw. we can use noexcept expcetion specification. This is optinoal
  //6.return type - Return type is automaticall deduced

  //used when we want to send value from outside
  //auto lambda = [&](int value){a = 5; if (a < value) std::cout << "a " << a << " is bigger \n"; else std::cout << "value " << value << "is bigger \n";}
  //Tis will give error To modify we specify mutable
  //auto lambda = [=](int value){a = 5; if (a < value) std::cout << "a " << a << " is bigger \n"; else std::cout << "value " << value << "is bigger \n";};
  //1st Example
  auto lambda = [=](int value) mutable {a = 5; if (a > value) std::cout << "a " << a << " is bigger \n"; else std::cout << "value " << value << "is bigger \n";};

  ForEach(vec,lambda);

  std::cout << "\n A Vlaue after 1st lambda = " << a << "\n";//a value wont be modifed as passed by value
  
  //2nd Example
  for(int value:vec)
    std::cout << "\n BEFORE VALUE is = " << value << "\n";
   
  vec.erase(std::remove_if(vec.begin(),vec.end(),[](int value){return (value %2) == 0 ?true:false;}),vec.end());
  std::cout << "\n HEY HEY \n";
  for(int value:vec)
    std::cout << "\n VALUE is = " << value << "\n";

  //3rd Example showcasing call by value and reference
  auto lambda2 = [&]() mutable{a++;};
  lambda2();
  std::cout << "\n A Vlaue after 2nd lambda = " << a << "\n";

  int b = 3;
  std::cout << "\n Before Lambda Value of A = " << a << " B = " << b << "\n";
  auto lambda3 = [&,a]() mutable{a++;b++;}; // this means all value passed by reference except a
  lambda3();
  std::cout << "\n After Lambda Value of A = " << a << " B = " << b << "\n";


  std::cout << "\n Before Lambda Value of A = " << a << " B = " << b << "\n";
  auto lambda4 = [=,&a]() mutable{a++;b++;}; // this means all value passed by value except a
  lambda4();
  std::cout << "\n After Lambda Value of A = " << a << " B = " << b << "\n";


  //4th Example specifying return type
  auto lambda5 = [=](int x,int y)->std::vector<int>{x = x + a;y = y + b;return {x,y};};
  std::vector<int>vecRes;
  vecRes = lambda5(5,6);
  std::cout << "\n Vector Content after lambda \n";
  std::cout << vecRes[0] << " " << vecRes[1] << "\n";
  
  //sizeof
  //Size depends on the value captured
  char c,d,e;
  auto lambda6 = [c,d,e]()mutable{c='a';};
  std::cout << "SIZE OF LAMBDA 6 = " << sizeof(lambda6) << "\n";

  
  

}

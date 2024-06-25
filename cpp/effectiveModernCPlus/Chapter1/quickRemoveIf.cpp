#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int>vec{2,3,4,5};
  for(int value:vec)
    std::cout << "\n BEFORE VALUE is = " << value << "\n";
  //Remeove all element from vector which are even
  //REMOVE function rearranges a container so that element that 
  //wouldnt be removed will be at the starting of the function
  //Releative order of the elements that are not removed remains same
  //physical size of the cotain remains same
  //find_if,remove_if for predicats
  ////REMOVE uses move function to shift elements
  std::remove(vec.begin(),vec.end(),3);

  std::cout << "\n \n \n";
  for(int value:vec)
    std::cout << "\n AFTER VALUE is = " << value << "\n";


  
  std::vector<int>vec1{2,3,4,5};

  std::cout << "\n \n \n";
  vec1.erase(std::remove(vec1.begin(),vec1.end(),3),vec1.end());
  for(int value:vec1)
    std::cout << "\n AFTER ERASE VALUE is = " << value << "\n";

}

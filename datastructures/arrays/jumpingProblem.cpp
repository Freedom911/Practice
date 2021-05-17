#include <iostream>
#include <vector>

int returnJump(std::vector<int> arr)
{
  int a = arr[0];
  int b = arr[0];

  //we are taking 1st jump when we reach starting
  int jump = 1;

  for(int i = 0; i < arr.size(); i++)
  {
    if(i + 1 == arr.size())
      return jump;

    if(b < arr[i])
    {
      b = arr[i];
    }

    if(a == 0)
    {
      a = b;
      jump++;
    }

    a--;
    b--;

  }

  return jump;
}

int main()
{
  std::vector<int> arr{1,3,5,8,9,2,6,7,6,8,9};

  std::cout << "\n Total Jumps = " << returnJump(arr) << "\n";


}

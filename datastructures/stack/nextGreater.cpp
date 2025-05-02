//Program TO Find Next Greater element for each element on the right side
//https://www.geeksforgeeks.org/next-greater-element/
//if element not present then it shoudl print -1
//eg 4 5 1 2 8 - Answer -> 5,8,8,8,-1
//Using Two loops we can simply do in o(n2) 
//TO improve this we will use stack for this
//we will insert element in stack and then when next element comes
//check if the next element is bigger if yess then pop and print the bigger element. will keep on
//doing till smaller number is there on stack and then finally push the bigger number
#include <iostream>
#include <vector>
#include <stack>

void findNextGreater(std::vector<int> no)
{
  std::stack<int> s;
  s.push(no[0]);

  for(int i = 1; i < no.size(); i++)
  {
    while(s.empty() == false && s.top() < no[i])
    {
      std::cout << "\n Next Greater of = " << s.top() << " is = " << no[i] << "\n";
      s.pop();
    }

    s.push(no[i]);

  }


  while(s.empty() == false)
  {
    std::cout << "\n Next Greater of = " << s.top() << " is = -1 \n";
    s.pop();
  }

}

//Here the logic is we will traverse from end 
//and will keep poping the stack until the stack top is bigger than array
//then this no is the next greatest and we store in array
//for right side we can do also in order. we can keep and index in stack as well
//when popping we fill Next greater for that element
void findNGEInOrder(std::vector<int> no)
{
  std::cout << "\n IN ORDER \n"; 
  std::stack<int> s;
  std::vector<int> v(no.size(),-1);

  for(int i = no.size() - 1; i >= 0; i--)
  {
    while(s.empty() == false && s.top() <= no[i])
      s.pop();

    //means no element
    if(s.empty())
      v[i] = -1;
    else
      v[i] = s.top();

    s.push(no[i]);

  }

  for(int i = 0; i < v.size(); i++)
  {
    std::cout << "\n Next Greater Element of " << no[i] << " is " << v[i] << "\n";
  }

}


int main()
{
  std::vector<int> no{4,5,1,2,8};

  for(auto &elem:no)
  {
      std::cout << elem << " ";
  }

  findNextGreater(no);
  findNGEInOrder(no);

  std::cout << "\n";
}

//Recursive Program To Print Number from one to N
//We will use induction base and hypothesis
//Step 1 HYPOTHESIS - void print(int n) -> This Function Will Print number from 1 - N
//                                         This Function Sould also Print Number if we reduce the input to N-1
//
//Step 2  Base Condition - If the Condition Reaches to smallest valid input i.e 1 it should return

//Step 3  print(N-1) this will print from 1 to N-1. So we need to append only N

#include <iostream>

void print(int n)
{
  //Base Condition
  if(n <= 1)
  {
    std::cout << 1 << " ";
    return ;
  }

  //Induction
  print(n-1);
  std::cout << n << " ";

}

//Print Number N - 1 
//Step 1 Hypthoesis - void printRev(int n) - This will print from n to 1
//                                           Will also work from n-1 to 1
//Step 2 Base Condition - When We reach smallest value that is 1 we will stop

//Step 3 printRev(N-1) this will print from N-1 to 1. so we need to append N

void printRev(int n)
{

  //Base Condition
  if(n <= 1)
  {
    std::cout << 1 << " ";
    return;
  }

  //Induction
  std::cout << n << " ";
  printRev(n-1);


}

int main()
{
  print(100);

  std::cout << "\n IN REVERSE \n";
  printRev(100);
}

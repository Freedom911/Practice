//Given a sorted array task is to insert an element at its right place using recursion
//Will use induction base hypothesis
//Step1  Hypothesis void insert(int arr[],int element) - This function will insert an element at its
//right place. It will work when last element from array is also removed and so on. 
//Step 2 Deciding Base condition. When there is no element in array then just push the element. also
//if the element is greater than last element just push in last without going for induction step
//Step 3 Induction - Remove the last element and just push back after insert this will push all the lemenet which 
//are gereater than element
#include <iostream>
#include <vector>
#include <random>

//Hypothesis
void insertAtPlace(std::vector<int> &ar,int elementToInsert)
{
  //Base Condition
  int size  = ar.size();
  if(size == 0 || ar[size-1] <= elementToInsert)
  {
    ar.push_back(elementToInsert);
    return;
  }
  
  //reduce size of input
  int val = ar[size-1];
  ar.pop_back();
  insertAtPlace(ar,elementToInsert);
  ar.push_back(val);


}

std::ostream &operator << (std::ostream &os,const std::vector<int> &ar)
{
  for(auto &e:ar)
  {
    os << e << " ";
  }

  return os;
}

int main()
{
  std::default_random_engine generator(std::random_device{}());
  std::uniform_int_distribution<int> distribution(1,100);
  std::vector<int> ar;

  for(int i = 0; i < 10;i++)
  {
    int no = distribution(generator);
    std::cout << "\n Insert No " << no << " IN ARRAY = " << ar << "\n";
    insertAtPlace(ar,no);
    std::cout << "\n AFTER INSERT = " << ar << "\n";
  }
}

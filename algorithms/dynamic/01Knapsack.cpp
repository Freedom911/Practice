//Program For Solving 01 Knapsack using both memoization and top down approach
//for dp first step is to identify its a dp problem.Generally if there are two are more
//recursive calls then we can apply dp . Also We need to make the solution optimial is a second requirement
#include <iostream>
#include <vector>

int t[4][51];

int knapsackRec(std::vector<int> wt,std::vector<int> val,int capacity,int itemsLeft)
{
  //Base Condition
  if(capacity <= 0 || itemsLeft <= 0)
    return 0;

  //Check if the result is already present
  if(t[itemsLeft][capacity] != -1)
    return t[itemsLeft][capacity] ;


  //Now at each step we have choices. If the weight of the last element is greater than capcity then there is only
  //one choice to not include but if less then we have two option 
  if(capacity < wt[itemsLeft -1])
  {
    return  t[itemsLeft][capacity] = knapsackRec(wt,val,capacity,itemsLeft - 1);
  }

  else
  {
    return  t[itemsLeft][capacity] = std::max(knapsackRec(wt,val,capacity,itemsLeft - 1),//when we dont include the last element
        val[itemsLeft - 1] + knapsackRec(wt,val,capacity - wt[itemsLeft - 1] ,itemsLeft - 1)); //when we include the last element then reduce the capacity of bag and
    //also reduce the total items left
  }

}

int knapsackTopDown(std::vector<int> wt,std::vector<int> val,int capacity)
{
   int mt[4][51];

   //This is the base condition of the recurisve method.
   //We are initializing with 0
   for(int i = 0; i < 4; i++)
   {
     for(int j = 0; j < 51; j++)
     {
       if(i == 0 || j == 0)
       {
         mt[i][j] = 0;
       }
     }
   }

   //Similarly we have two conditions here
   for(int i = 1; i < 4; i++)
   {
     for(int j = 1; j < 51; j++)
     {

       if(wt[i-1] <= j)
       {
                             //INclude                    //dont include
         mt[i][j] = std::max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
       }
       //weight of the bag at i - 1 is greater than j i.e capacity
       else
       {
         mt[i][j] = t[i-1][j];
       }

     }
   }

   return mt[3][50];
}


int main()
{
  for(int i = 0; i < 4;i++)
  {
    for(int j = 0; j < 51; j++)
    {
      t[i][j] = -1;
    }
  }
  std::cout << "\n Maximum Profit = " << knapsackRec({10,20,30},{60,100,120},50,3);
  std::cout << "\n Maximum Profit = " << knapsackTopDown({10,20,30},{60,100,120},50);
}

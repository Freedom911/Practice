//Print Matrix in Diagonal Format
// ex   1  2  3  4
//      5  6  7  8
//      9 10 11 12
//     13 14 15 16

//Ans 1 5 2 9 6 3 13 10 7 4 14 11 8 15 12 16
#include <iostream>

void printDiagonally(int arr[4][4],int m,int n)
{

  int i,j;
  for(int k = 0; k < m; k++)
  {
    i = k;
    j = 0;

    //here we are checking i because
    //here in this case we need to go till 0 of i
    while(i >= 0)
    {
      std::cout << arr[i][j] << " ";
      i--;
      j++;
    }
  }
  
  for(int k = 1; k < n; k++)
  {
    j = k;
    i = m -1;

    //we are using j here instead of i because
    //here in this we need to check j reaches end
    while(j < n)
    {
      std::cout << arr[i][j] << " ";
      i--;
      j++;

    }
  }
}
int main()
{
  int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

  printDiagonally(arr,4,4);
}

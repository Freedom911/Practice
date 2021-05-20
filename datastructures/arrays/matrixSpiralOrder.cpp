#include <iostream>
#include <vector>

void spiralPrintMatrix(int arr[4][4],int c,int r)
{


  int j = 0,i = 0,k = 0,n = 0;
  while(r > n && c > k )
  {

    i = k;
    for(j = k; j < c; j++)
    {
      std::cout << arr[i][j] << " ";
    }

    j = c;

    for(i = n;i < r; i++)
    {
      std::cout << arr[i][j] << " ";
    }
    i = r;
    for(j = c;j > k; j--)
    {
      std::cout << arr[i][j] << " ";
    }
    j = k;
    for(i = r;i > n; i--)
    {
      std::cout << arr[i][j] << " ";
    }

    k++;c--;r--;n++;


  }

}

int main()
{
  int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  spiralPrintMatrix(arr,3,3);
}

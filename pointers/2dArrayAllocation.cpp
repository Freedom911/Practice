//https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/ 
//Different type of ways to allocate 2d array
#include <iostream>


int main()
{

  //Using single pointer
  std::cout << "\n Using Single Pointer \n";

   int r = 3, c = 4;
    int *arr = new int[r*c];

    int i, j, count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         *(arr + i*c + j) = ++count;

    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         std::cout << *(arr + i*c + j) << " ";


  delete []arr;


  std::cout << "\n Using POinter to array Method \n";
  int *arr1[r];
  for(i = 0; i < r; i++)
  {
    arr1[i] = new int[c];
  }


    count = 1;
    for (i = 0; i <  r; i++)
    {
      for (j = 0; j < c; j++)
      {
        arr1[i][j] = count;
        count++;
      }
    }
    for (i = 0; i <  r; i++)
    {
      for (j = 0; j < c; j++)
      {  
        std::cout << arr1[i][j] << " ";
        //or
        // std::cout << *(*(arr1 + i) + j) << " ";
      }
    }
  for(i = 0; i < r; i++)
  {
    delete arr1[i];
  }

  std::cout << "\n Using pointer to a pointer \n";

  int **arr2 = new int*[r];

  for(int i = 0; i < r; i++)
  {
     arr2[i] = new int [c];
  }

    count = 1;
    for (i = 0; i <  r; i++)
    {
      for (j = 0; j < c; j++)
      {
        arr2[i][j] = count;
        count++;
      }
    }
  for (i = 0; i <  r; i++)
  {
    for (j = 0; j < c; j++)
    {  
      std::cout << arr2[i][j] << " ";
      //or
      // std::cout << *(*(arr1 + i) + j) << " ";
    }
  }

  //delte happens in reverse order
  for(i = 0; i < r; i++)
  {
    delete arr2[i];
  }
  delete []arr2;

}

//Print Matrix in Diagonal Format
// ex   1  2  3  4
//      5  6  7  8
//      9 10 11 12
//     13 14 15 16

//Ans 13 9 14 5 10 15 16 11 16 2 7 12 3 8 4
#include <iostream>

void printDiagonally(int arr[4][4], int m, int n)
{

    for (int k = m-1;k >= 0; k--)
    {
        int i = k;
        int j = 0;

        while (i < m)
        {
            std::cout << arr[i][j] << " ";
            i++;
            j++;
        }
    }
    
    for (int k = 1; k < n; k++)
    {
        int j = k;
        int i = 0;

        while (j < n)
        {
            {
                std::cout << arr[i][j] << " ";
                i++;
                j++;
            }
        }

    }
  
}
int main()
{
    int arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };

    printDiagonally(arr, 4, 4);
}

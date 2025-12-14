//Given a square matrix mat[][] of size n x n.
// The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 


/*
Examples:

Input: mat[][] = [[0, 1, 2], 
                  [3, 4, 5], 
                  [6, 7, 8]] 
Output: [[2, 5, 8],
        [1, 4, 7],
        [0, 3, 6]]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: [[2, 4],
        [1, 3]]

If we observe we can solve this  by using our preiovus knowledge of transpose
//so first we calculate transpose or original matrix
0,1,2,
3,4,5
6,7,8

Tranpose = 
0 3 6
1 4 7
2 5 8

then we reverse column wise
2 5 8 
1 4 7
0 3 6

We Can Rotate multiple times or anti clock wise in this manner
or even anti clock wise

*/
#include <iostream>
#include <vector>
#include <algorithm>

void PrintMatrix(const std::vector<std::vector<int>> &mat)
{
    if(mat.size() == 0 || mat[0].size() == 0)
    {
        std::cout << "\n Empty Matrix \n";
    }

    int tr = mat.size();
    int tc = mat[0].size();
    std::vector<std::vector<int>> transpose(tr,std::vector<int> (tc,0));
    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            std::cout << mat[i][j] << "|";
        }
        std::cout << "\n";
    }

}



void TransposeMatrixSol(std::vector<std::vector<int>> &mat)
{

    if(mat.size() == 0 || mat[0].size() == 0)
    {
        std::cout << "\n Empty Matrix \n";
    }

    //both are same size
    int tr = mat.size();
    int tc = mat[0].size();

    for(int i = 0; i < tr - 1; i++)
    {
        for(int j = i + 1; j < tc; j++)
        {
            std::swap(mat[i][j],mat[j][i]);
        }
    }


}

void ReverseMatrixColWise(std::vector<std::vector<int>> &mat)
{
    if(mat.size() == 0 || mat[0].size() == 0)
    {
        std::cout << "\n Empty Matrix \n";
    }

    //both are same size
    int tr = mat.size();
    int tc = mat[0].size();
    for(int i = 0; i < tc; i++)
    {
        int startRow = 0;
        int endRow = tc - 1;

        while(startRow <= endRow)
        {
            std::swap(mat[startRow][i],mat[endRow][i]);
            startRow++;
            endRow--;

        }
    }
}


void RotateImage(std::vector<std::vector<int>> &mat)
{
    TransposeMatrixSol(mat);
    ReverseMatrixColWise(mat);

    std::cout << "\n After Rotation \n";
    PrintMatrix(mat);
}



int main()
{
    std::vector<std::vector<int>> v { {0,1,2},{3,4,5},{6,7,8}};
    PrintMatrix(v);
    RotateImage(v);

}
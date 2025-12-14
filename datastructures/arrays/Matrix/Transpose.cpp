//Program for transposing matrix
// 1 2 3
// 4 5 6
// 7 8 9
//Transpose
// 1 4 7
// 2 5 8
// 3 6 9
//I am presenting two solution
//solution 1 using extra space
//so if we observe the element mat[i][j] is swapped with mat[j][i]
//so in new array we copy that
//time and space o(n2)
//solution 2 inplace   but only works with square matrix
// so if we observe we see elements above diagnoal are swapped with below diagnol
//and element across main diagnoal is not changed
//so how will we traverse upper triangle
//as usual we have i and j
//if we observe i which runs for row works from 0 to second last row means the element at main diagnoal
//which is the bottom most right most element is not to be included
//j will depend on i see for 1st row it starts from 1st for 2nd row it starts 3rd column 
//so basically j runs from i + 1 to n


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

void TransposeMatrixSol1(std::vector<std::vector<int>> &mat)
{
    std::cout << "\n SOL 1 Extra Space \n";
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
            transpose[j][i] = mat[i][j];
        }
    }

    PrintMatrix(transpose);
}

void TransposeMatrixSol2(std::vector<std::vector<int>> &mat)
{
    std::cout << "\n SOL 2 In Place \n";
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

    PrintMatrix(mat);

}



int main()
{
    std::vector<std::vector<int>> v { {1,2,3},{4,5,6},{7,8,9}};
    PrintMatrix(v);
    TransposeMatrixSol1(v);
    TransposeMatrixSol2(v);

}
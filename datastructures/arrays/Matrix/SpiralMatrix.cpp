// Program to print matrix in spiral format
// eg 1 2 3
//    4 5 6
//    7 8 9
//  1 2 3 6 9 8 7 4 5
// the logic is we first take 4 index top points to top row
// right points to right most column ,bottom to bottom most row and left to left most column
// so first we print top most row then right most then bottom most row then left most column
// after moving we increment and decrement the indexes

#include <iostream>
#include <vector>

void PrintSpiral(const std::vector<std::vector<int>> &mat)
{
    if (mat.size() == 0 || mat[0].size() == 0)
    {
        std::cout << "\n Empty Matrix \n";
    }

    int tr = mat.size();
    int tc = mat[0].size();
    int top = 0;
    int left = 0;
    int bottom = tr - 1;
    int right = tc - 1;

    // 1st print top most row

    while (left <= right && top <= bottom)
    {

        for (int i = left; i <= right; i++)
        {
            std::cout << mat[top][i] << "|";
        }
        top++;

        // 2nd print right most column
        for (int i = top; i <= bottom; i++)
        {
            std::cout << mat[i][right] << "|";
        }
        right--;

        // 3rd print bottom most row
        if (top <= bottom)
        {

            for (int i = right; i >= left; i--)
            {
                std::cout << mat[bottom][i] << "|";
            }
            bottom--;
        }

        if (left <= right)
        {

            // 4th print left most column
            for (int i = bottom; i >= top; i--)
            {
                std::cout << mat[i][left] << "|";
            }
            left++;
        }

        // now repeat
    }
}

int main()
{
    std::vector<std::vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    PrintSpiral(v);
}
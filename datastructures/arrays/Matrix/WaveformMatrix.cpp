//Program to print matrix in waveform format
//eg 1 2 3
//   4 5 6
//   7 8 9
// 1,4,7,8,5,2,3,6,9
//the logic we print in column wise . we switch order if j is even where j is current column index

#include <iostream>
#include <vector>

void PrintWaveform(const std::vector<std::vector<int>> &mat)
{
    if(mat.size() == 0 || mat[0].size() == 0)
    {
        std::cout << "\n Empty Matrix \n";
    }

    int tr = mat.size();
    int tc = mat[0].size();
    for(int j = 0; j < tc; j++)
    {
        if(j % 2 == 0)
        {
            for(int i = 0; i < tr; i++)
            {
                std::cout << mat[i][j] << ",";
            }
        }
        else
        {
            for(int i = tr - 1; i >= 0; i--)
            {
                std::cout << mat[i][j] << ",";
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> v { {1,2,3},{4,5,6},{7,8,9}};
    PrintWaveform(v);

}
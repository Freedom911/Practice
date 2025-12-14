#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidRow(const std::vector<std::vector<int>> &mat, const int &particularRow)
{
    
    std::unordered_set<int> s;

    // Iterate over all columsn
    for (int i = 0; i < 9; i++)
    {
        if(mat[particularRow][i] == 0)
        continue;

        if (s.find(mat[particularRow][i]) != s.end())
        {
            std::cout << "\n HERE for =" << particularRow << " " << i << "\n";
            return false;
        }
        else
        {
            
            s.insert(mat[particularRow][i]);
            
        }
    }
    return true;
}

bool isValidColumn(const std::vector<std::vector<int>> &mat, const int &particularColumn)
{
    std::unordered_set<int> s;

    // Iterate over all columsn
    for (int i = 0; i < 9; i++)
    {
        if(mat[i][particularColumn] == 0)
        continue;
        
        if (s.find(mat[i][particularColumn]) != s.end())
        {
            
            return false;
        }
        else
        {
            
            s.insert(mat[i][particularColumn]);
            
        }
    }
    return true;
}

bool isValidSub(const std::vector<std::vector<int>> &mat, const int &particularRow, const int &particularColumn)
{
    std::unordered_set<int> s;

    // Iterate over all Rows
    for (int i = particularRow; i < particularRow + 3; i++)
    {
        for (int j = particularColumn; j < particularColumn + 3; j++)
        {
            if(mat[i][j] == 0)
            continue;
        
            if (s.find(mat[i][j]) != s.end())
            {
                return false;
            }
            else
            {
                 s.insert(mat[i][j]);
            }
        }
    }

    return true;
}

bool isValid(std::vector<std::vector<int>> &mat)
{
    if (mat.size() == 0 || mat[0].size() == 0)
    {
        return false;
    }

    //For Each Column.validate for each row
    for (int j = 0; j < 9; j++)
    {
        if (isValidRow(mat, j) == false)
        {
            return false;
        }
    }
    

    //For Each Row. Validate for each column
    for(int i = 0; i < 9; i++)
    {
        if (isValidColumn(mat, i) == false)
        {
            return false;
        }        
    }
    

    for(int i = 0; i <= 6; i+= 3)
    {
        for(int j = 0; j <= 6; j+= 3)
        {
            if(isValidSub(mat,i,j) == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    std::vector<std::vector<int>> mat = {
        {9, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 5, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    std::cout << (isValid(mat) ? "true" : "false") << std::endl;
    return 0;
}
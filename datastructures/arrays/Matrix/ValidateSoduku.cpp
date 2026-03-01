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

    //We need not do three loops for row checking
    //0 to 9 we do 
    //for(int i = 0; i < 9;i++)
    //mat[row][i] 
    //mat[i][col]
    //and for submatrix we 3 * (row /3) will get the starting of submatrix and i/3 will increment by 0,1,2
    //same for col


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

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        //Check if same row and column

        //Check for same sub matrix
        //the forumula is simple
        //idi = 3*(i/3)
        //idj = 3*(j/3)
        //these are the base offset pf the grid
        //Dont memorie the forumula rather derive it is quick
        //so in the problenm we are basically make sure that in a submatrix
        //only one number is there . so total submatrix would be 0-8
        //and we number it by idi + idj
        //basically this is row major we are merging into 1d array:Q

        std::vector<std::vector<int>> rowMatrix(10,std::vector<int>(10,0));
        std::vector<std::vector<int>> colMatrix(10,std::vector<int>(10,0));
        std::vector<std::vector<int>> subMatrix(10,std::vector<int>(10,0));

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                int val = board[i][j] - '0';
                //for Same row
                if(rowMatrix[i][val] == 1)
                {
                   return false;
                }
                rowMatrix[i][val] = 1;

                //for Same column
                if(colMatrix[j][val] == 1)
                {
                   return false;
                }
                colMatrix[j][val] = 1;

                //for sub matrix
                int idi = 3*(i/3);
                int idj = (j/3);
                int idt = idi+idj;

                //for Same column
                if(subMatrix[idt][val] == 1)
                {
                   return false;
                }
                subMatrix[idt][val] = 1;

            }
        }

        return true;


    }
};


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

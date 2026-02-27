
/**
 * Have Taken Though from GridDP. it is same here we can take 4 steps.
 * the other difference is since we can move 4 dir. to avoid up down down up 
 * infinitelly we take vis array
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isValid(std::vector<std::vector<int>> &mat,std::vector<std::vector<int>> &vis,int r,int c)
{
    if(r < 0 || c < 0 || r>= mat.size() || c >= mat[0].size() || vis[r][c] == 1 || mat[r][c] == 0)
    {
        return false;
    }
    return true;
}


//Hypothesis - This Function Returns Total number of unique till 0 till curr row
void TotalRec(std::vector<std::vector<int>> &mat,std::vector<std::vector<int>> &vis,int currRow,int currCol,std::string &ans)
{
    //Base Conditions
    if(currRow < 0 || currCol < 0 || mat[currRow][currCol] == 0)
    {
        return;
    }
    if (currRow == 0 && currCol == 0)
    {
        std::string s1 = ans;
        std::reverse(s1.begin(),s1.end());
        std::cout << s1 << "\n";
        return;
    }

    vis[currRow][currCol] = 1;
    if(isValid(mat,vis,currRow-1,currCol))
    {
        ans.push_back('D');
        TotalRec(mat,vis,currRow-1,currCol,ans);
        ans.pop_back();
    }

    if(isValid(mat,vis,currRow,currCol-1))
    {
        ans.push_back('R');
        TotalRec(mat,vis,currRow,currCol-1,ans);
        ans.pop_back();
    }

    if(isValid(mat,vis,currRow+1,currCol))
    {
        ans.push_back('U');
        TotalRec(mat,vis,currRow+1,currCol,ans);
        ans.pop_back();
    }

    if(isValid(mat,vis,currRow,currCol+1))
    {
        ans.push_back('L');
        TotalRec(mat,vis,currRow,currCol+1,ans);
        ans.pop_back();
    }

    //Backtrack
    vis[currRow][currCol] = 0;

}


int main() 
{
    std::vector<std::vector<int>> maze = 
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();
    std::vector<std::vector<int>> vis(n,std::vector<int>(n,0));
    std::string ans;
    TotalRec(maze,vis,n-1,n-1,ans);
}


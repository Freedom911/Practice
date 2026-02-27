/**
 * Given N X N board we need to place N queens in such a manner
 * 1. in A row there can be only one queen
 * 2. in a column there can be only one queen
 * 3. Queen cannot attach another queen
 * Queen can move in 8 directions
 *  \  |  /
 *  ---Q---
 *  /  |  \
 *  8 Directions
 *
 *
 *  Solution so we try to do recursive solutions
 *
 *  Basically we fix a column and try for each row if we can place queen based on the rules
 *  if we can then push back the result
 *  
 *  so for a particular col we do
 *  for(int i = 0; i < N; i++) //for each row
 *  if(IsPossible())
 *  {
 *    place queen
 *    move to next column
 *    backtack placing queen
 *  }
 *
 *  IsPossible for is possible we need not check all 8 directions
 *  we only need to check left top left and bottom left rest right side are not explored till now
 *  so we havent moved to next column as we are moving from left to right. neither up and down as for a column 
 *  we only place once
 *  so only 3.
 *
 *  Optimization
 *  We can optimize the posible checking because we are doing iteration to check if one is placed
 *  so we take 3 arrays
 *  1st array is for a row if we place a one in a row we cant put queen in whole row
 *  so we take leftArray of size n as soon as we place a queen at a row we place 1 in a row so we cant place 
 *
 *  For up lefft direction we say if any queen placed at a poisition then we cant place at row + col position
 *  For Down Left direction we do ulta col - row this results in negative index so we add n - 1
 *
 *  The array size is n + n - 1 in all three cases
 */ 

class Solution
{
public:

    //we check for 3 directions
    bool IsPossible(const std::vector<std::vector<char>> &currentBoard,int row,int col,int n)
    {
        if(n == 0)
        {
            return false;
        }

        //for same left row
        int dupRow = row;
        int dupCol = col;

        while(dupCol >= 0)
        {
            if(currentBoard[dupRow][dupCol] == 'Q')
                return false;
            dupCol--;
        }

        //for top left
        dupRow = row;
        dupCol = col;

        while(dupCol >= 0 && dupRow >= 0)
        {
            if(currentBoard[dupRow][dupCol] == 'Q')
                return false;
            dupCol--;
            dupRow--;
        }

        //for bottom left
        dupRow = row;
        dupCol = col;

        while(dupCol >= 0 && dupRow < n)
        {
            if(currentBoard[dupRow][dupCol] == 'Q')
                return false;
            dupCol--;
            dupRow++;
        }

        return true;

    }

    //Hypothesis
    //the function returns the ans containing board which has n queens placed
    void solve1(std::vector<std::vector<char>> &currentBoard,std::vector<std::vector<std::string>> &ans,
               int n,int col)
    {
        //Base condition
        // means we are at last column and we have placed all queens why n and not n+1 because we start from 0
         if(col == n)
        {
            std::vector<string> temp;
            for(int i = 0; i < n; i++)
            {
              std::string row(currentBoard[i].begin(),currentBoard[i].end());
              temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }


        //Induction step
        for(int i = 0; i < n; i++)
        {
            if(IsPossible(currentBoard,i,col,n))
            {
                currentBoard[i][col] = 'Q';
                solve1(currentBoard,ans,n,col + 1);//move to next column
                //Baclk track
                currentBoard[i][col] = '.';
            }
        }

    }

        //Hypothesis
    //the function returns the ans containing board which has n queens placed
    void solve(std::vector<std::vector<char>> &currentBoard,std::vector<std::vector<std::string>> &ans,
               std::vector<int> &left,std::vector<int> &upLeft,std::vector<int> &downLeft,
               int n,int col)
    {
        //Base condition
        // means we are at last column and we have placed all queens why n and not n+1 because we start from 0
         if(col == n)
        {
            std::vector<string> temp;
            for(int i = 0; i < n; i++)
            {
              std::string row(currentBoard[i].begin(),currentBoard[i].end());
              temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        //Induction step
        for(int i = 0; i < n; i++)
        {
            if(left[i] == 0 && upLeft[i+col] == 0 && downLeft[n - 1 + col - i] == 0)
            {
                currentBoard[i][col] = 'Q';
                left[i] = 1;
                upLeft[i+col] = 1;
                downLeft[n-1 + col - i] = 1;
                solve(currentBoard,ans,left,upLeft,downLeft,n,col + 1);//move to next column
                //Baclk track
                currentBoard[i][col] = '.';
                left[i] = 0;
                upLeft[i+col] = 0;
                downLeft[n-1 + col - i] = 0;
            }
        }

    }


    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        if(n == 0)
        {
            return {};
        }
        std::vector<std::vector<char>> currentBoard(n,std::vector<char>(n,'.'));
        std::vector<std::vector<std::string>> ans;
        std::vector<int> left((2 * n) - 1,0);
        std::vector<int> upleft((2*n) - 1,0);
        std::vector<int> downleft((2*n) - 1,0);
        solve(currentBoard,ans,left,upleft,downleft,n,0);
        return ans;
    }
};


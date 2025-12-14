/**
 * A Tic-Tac-Toe board is given after some moves are played.
 *  Find out if the given board is valid, i.e., is it possible to reach this board position
 *  after some moves or not.
    Note that every arbitrary filled grid of 9 spaces isn't valid 
    e.g. a grid filled with 3 X and 6 O isn't valid situation because each player needs to take alternate turns.
 */

#include <iostream>
#include <vector>

//To Check if the board is valid we have multiple condition
//1st is since X is starting first then at a time t either number of X will be equal to O or
//X will be +1 than O.
//2nd If X won then X will be +1 then O
//if O won then cound of x will be = count of 0
//two players cant win at same time

bool CheckWon(std::vector<std::vector<char>> &board,int row,int col,char ch)
{
    if(board.size() == 0 || board[0].size() == 0 || row >= board.size() || col >= board[0].size())
    {
        return false;
    }

    int tr = board.size();
    int tc = board[0].size();

    //Check for right
    //Check for Down
    //Check for diagnoal
    //for right
    if(col + 2 < tc)
    {
        if(board[row][col] == ch && board[row][col + 1] == ch && board[row][col + 2] == ch)
        {
            return true;//Won
        }
    }

    //for Down
    if(row + 2 < tr)
    {
        if(board[row][col] == ch && board[row + 1][col] == ch && board[row + 2][col] == ch)
        {
            return true;//Won
        }
    }

    //for Diagnoal
    if(row + 2 < tr && col + 2 < tc)
    {
        if(board[row][col] == ch && board[row + 1][col + 1] == ch && board[row + 2][col + 2] == ch)
        {
            return true;//Won
        }
    }

    return false;
    
}

bool isValid(std::vector<std::vector<char>> &board )
{
    //Calulcate Couint
    int tr = board.size();
    int tc = board[0].size();
    int noX = 0;
    int noO = 0;
    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            if(board[i][j] == 'X')
            {
                noX++;
            }
            else if(board[i][j] == 'O')
            {
                noO++;
            }
        }
    }

    //Means invalid
    if(noX != noO && noX != noO + 1)
    {
        return false;
    }

    //Check who won
    bool Xwon = false;
    bool OWon = false;
     for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            if(board[i][j] == 'X' && CheckWon(board,i,j,'X'))
            {
                Xwon = true;;
            }
            else if(board[i][j] == 'O' && CheckWon(board,i,j,'O'))
            {
                 OWon = true;
            }
        }
    }

    //if both won then fishy 
    if(OWon && Xwon)
    {
        return false; // not valid
    }

    //3rd Check if x won then the count of x should be just be + 1 than X
    if(Xwon && noX != noO + 1)
    {
        return false;
    }

    //IF O Won then No of O should be equal to be X
    if(OWon && noO != noX)
    {
        return false;
    }

    //We have validated all
    return true;

}

int main()
{
    std::vector<std::vector<char>> board = {{'X', 'O', 'X'},
                    {'O', 'O', 'O'},
                    {'X', ' ', 'X'}
                    };

std::cout << "\n IS GIVEN BOARD VALID = ? = " << isValid(board);

return 0;
}
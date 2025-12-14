/**
 *
 * Given a square matrix mat[][] of size n x n, where mat[i][j] == 1
 * means person i knows person j, and mat[i][j] == 0 means person i does not know person j, find the celebrity person where,
 * A celebrity is defined as someone who:
 * Is known by everyone else
 * Does not know anyone (except themselves)
 * Return the index of the celebrity if one exists, otherwise return -1.
 * Note: It is guaranteed that mat[i][i] == 1 for all i
 * Examples:
 * Input: mat[][] = [[1, 1, 0],
                             [0, 1, 0],
                             [0, 1, 1]]
                             Output: 1
                             Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.
                             Input: mat[][] = [[1, 1],
                             [1, 1]
                             Output: -1
                             Explanation: The two people at the party both know each other. None of them is a celebrity.
                             Input: mat[][] = [[1]]
                             Output: 0

    Solution 1 using Graphs
    So if we look veryyyy closely we say a person is celebrity if it has indegree equal to n - 1 people and
    out degree as 0. assume this is a adjacent matrix

    Solution 2 Uses two pointer
    WE know there can be 0 or 1 celebrity. we use top pointer and bottom pointer. we try to eliminate who is not the celebrity
    so we check does top know bottom if yes then top cant be celebrity then top++ else bottom cant be celebtiy as it is not know by top
    so bottom --
 */

#include <iostream>
#include <vector>

int Sol1(const std::vector<std::vector<int>> &mat)
{
    int tr = mat.size();
    int tc = mat[0].size();

    std::vector<int> indegree(tr, 0);
    std::vector<int> outdeg(tr, 0);

    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            int val = mat[i][j]; // can be 0 or one
            indegree[j] += val;  // if j is 1 means i know j then indegree will be 1 for j
            outdeg[i] += val;    // outdegree for that i will be 1 then i se nikal ra h
        }
    }

    // now just check indegee

    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == tr && outdeg[i] == 1) // why tr because we are including self node
        {
            return i;
        }
    }

    return -1;
}

int Sol2(const std::vector<std::vector<int>> &mat)
{
    int tr = mat.size();
    int tc = mat[0].size();

    int top = 0;
    int bottom = tr - 1;
    while (top < bottom)
    {
        if (mat[top][bottom] == 1)
        {
            // top know bottom so top cant be celeb
            top++;
        }
        else
        {
            bottom--; // as bottom is not known
        }
    }

    //now we need to be sure that top is celeb
    for(int i = 0; i < tc; i++)
    {
        //iognore self
        if(i == top)
        {
            continue;
        }

        if(mat[i][top] == 0 || mat[top][i] == 1) //means i knows top ya top knows i then def top cant be celeb
        {
            return -1;
        }
    }

    return top;

}

int main()
{
    std::vector<std::vector<int>> mat = {{1, 1, 0},
                                         {0, 1, 0},
                                         {0, 1, 1}};

    std::cout << "\n CELEB = " << Sol1(mat) << "\n";
    std::cout << "\n CELEB = " << Sol2(mat) << "\n";

    return 0;
}
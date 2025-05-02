/**
 *
 * Given A bInary Matrix we need to find the maximum area we get
 * Eg
 * [[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]
 *
 * Output: 6
 *
 * We get form rectablr of {1,2},{1,3},{1,4},{2,2},{2,3},{2,4}
 * 
 *
 * https://takeuforward.org/data-structure/maximum-rectangle-area-with-all-1s-dp-on-rectangles-dp-55/
 *
 * The Problem is similar to Finding Maximum area in histogram. There we had 1d array here we have 2d aray
 *
 * To Convert we take each row and add the height from previous row and then send to maximum area histogram func
 *
 * when the current row is 0 we skip as the building cant be in hava or rater
 * the 1s should be continuis
 * eg 1,1,1
 *    1,1,0
 * So MAH(1,1,1) - 1st row
 * for 2nd row we add to 1st one
 * 2,2,0 and not one
 * that it
 * If this question comes in interview. we will discuss all the 3 solutions
 * Her ei am presenting to most optimal one
 */
#include <iostream>
#include <stack>
#include <vector>

//finding MAximim area histogram
int MAH(std::vector<int> &in)
{
    if(in.size() == 0)
    {
        return 0;
    }

    //finding NSR from Right Side first . then on the fly we compute NSL
    std::stack<std::pair<int,int>> st;
    int maxArea = -1;

    for(int i = 0; i < in.size(); i++)
    {
        //Finding All the elements which are largetr then current one for them in[i] is NSR
        while(st.empty() == false && st.top().second >= in[i])
        {
            int currentTowerHeight = st.top().second;
            int currentTowerIndex = st.top().first;

            st.pop();

            int NSR = i;
            int NSL = st.empty() ? -1 : st.top().first;

            maxArea = std::max(maxArea,currentTowerHeight * (NSR - NSL - 1));

        }

        st.push({i,in[i]});
    }

    //Adding Remaining One
    //1,2,3
    while(st.empty() == false)
    {
        int currentTowerHeight = st.top().second;
        int currentTowerIndex = st.top().first;
        st.pop();

        int NSR = in.size(); //means no NSR present
        int NSL = st.empty() ? -1 : st.top().first;

        maxArea = std::max(maxArea,currentTowerHeight * (NSR - NSL - 1));

    }
    return maxArea;
}

//take Each Column and Run MAH on each of them
//get the maximum area of them
int findMaxAreaInBinaryMatrix(std::vector<std::vector<int>> &mat)
{
    if(mat.size() == 0 || mat[0].size() == 0)
    {
        return -1;
    }
    int tr = mat.size();
    int tc = mat[0].size();
    std::vector<int> height(tc,0);
    int maxArea = -1;
    for(int i = 0; i < tr; i++)
    {
        for(int j = 0; j < tc; j++)
        {
            if(mat[i][j] == 1)
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }
        maxArea = std::max(maxArea,MAH(height));
    }
    return maxArea;
}

int main()
{
    std::vector<std::vector<int>> mat = 
    {
        {1, 0, 1, 0, 0}, {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}
    };
    int maxArea = findMaxAreaInBinaryMatrix(mat);
    std::cout << "The maximum area is: " << maxArea << "\n";
    return 0;
}



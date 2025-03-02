/**
 * https://takeuforward.org/data-structure/g-37-path-with-minimum-effort/
 *
 *
 * Problem Description - you are a hiker preparing for an upcoming hike. 
 * You are given heights, a 2D array of size rows x columns, where 
 * heights[row][col] represents the height of the cell (row, col).
 * You are situated in the top-left cell, (0, 0), and you hope to travel to the
 * bottom-right cell, (rows-1, columns-1) (i.e.,0-indexed). You can move up,
 * down, left, or right, and you wish to find a route that requires the minimum effort.
 *
 * A route's effort is the maximum absolute difference in heights between two consecutive cells of the route
 *
 * I have explained in one note. Please check.
 *
 * The main thing is we try to minimuze the effort like we did in minimizing the cost in dijkstra
 *
 * and instead of distance array we have best effor
 * Time Complexity: O( 4*N*M * log( N*M) ) 
 * { N*M are the total cells, for each of which we also check 4 
 * adjacent nodes for the minimum effort and additional log(N*M) for 
 * insertion-deletion operations in a priority queue } 
 */

#include <iostream>
#include <vector>
#include <queue>


int MinimumEffort(std::vector<std::vector<int>> &heights)
{
    //min heap
    std::priority_queue<std::pair<int,std::pair<int,int>>,std::vector<std::pair<int,std::pair<int,int>>>,std::greater<std::pair<int,std::pair<int,int>>>>pq;

    int tr = heights.size();
    int tc = heights[0].size();
    std::vector<std::vector<int>> bestEffort(tr,std::vector<int>(tc,1e9));

    //adj list will be for directions
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    //Initialization part
    pq.push({0,{0,0}});
    bestEffort[0][0] = 0;

    //start processing
    while(pq.empty() == false)
    {
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int currentEffort = pq.top().first;

        pq.pop();

        //as told earlier and i have explaiend in one note
        //that we stop when we pop the element from ququq and we get the destination
        //because this means we have got the best effort till now for the destination
        //and aage koi mai ka lal nahi h ise better hone ka
        if(row == tr - 1 && col == tc - 1)
        {
            return currentEffort; //this will automatically be having the max effort which is the minimum one
        }

        for(int i = 0; i < 4; i++)
        {
            int ar = row + dr[i];
            int ac = col + dc[i];

            //check validity
            if(ar >= 0 && ac >=0 && ar < tr && ac < tc)
            {
                int effort = std::abs(heights[ar][ac] - heights[row][col]);

                //now we need to pick the max 
                effort = std::max(effort,currentEffort);

                //we need to update in the bestaffort array if it is better
                //also we wont explore if the best effort array is less
                //there is no point. as we ill keep on looping
                if(effort < bestEffort[ar][ac])
                {
                    bestEffort[ar][ac] = effort;
                    //also add in pq
                    pq.push({effort,{ar,ac}});
                }

            }
        }
    }
    return -1;
}


int main()
{
    // Driver Code.

    std::vector<std::vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    int ans = MinimumEffort(heights);

    std::cout << ans;
    std::cout << "\n";

    return 0;
}

/**
 *
 * https://takeuforward.org/graph/g-39-minimum-multiplications-to-reach-end/
 * Problem is same. Print parent as well
 * G-39: Minimum Multiplications to Reach End
 * Given start, end, and an array arr of n numbers. At each step, 
 * the start is multiplied by any number in the array and then a 
 * mod operation with 100000 is done to get the new start.
 * Your task is to find the minimum steps in which the end can be
 * achieved starting from the start. If it is not possible to reach the end, then return -1.
 *
 * Solution - 
 * The problem is much like cheapest flight in k stops where we applied dijkstra algo to minimize steps
 * Here also we minimize the steps
 *
 * For Dijsktra we require queue and dist array
 * Here the queue will contain <steps,product>
 *
 * The steps array would be equivalent of dist aray. Total Number of nodes = 100000 whY?
 * Because he product can go from 0 - that range. nothing beyond.
 * Do we reuqire steps array of size 10^5? Yes. If we had kept dist array till target only then
 * we will miss many answers
 *
 *
 * eg start = 2,target = 7,module = 65,arr=[6]
 * 2-12-72
 * from 12 onyl we are getting to 72 (modulo 65 = 7). if we had kept till size of steps = target then 
 * we had not got the answer.
 *
 * Think of them as graphs 2->12->72->7
 *
 * Steps array stores the best steps we require to get to the answer
 * and queue stores steps,to node modulo 10^5
 * The adjaceny list here is given as arr which is same for everyone
 *
 * Also note that steps are increasing in constant manner so no need of pq
 * we return the answer as soon as we get target and we try to push in queue.
 * because that is minimum
 *
 *
 * Here we keep a parent array 
 */
#include <iostream>
#include <vector>
#include <queue>

//Applyind gDijkstra uncle
int minimumMultiplications(std::vector<int> &arr,int start,int end)
{
  if(start == end)
  {
      return 0;
  }
  int maxRange = 100000;
  std::queue<std::pair<int,int>>q;//steps,node
  std::vector<int> bestSteps(maxRange,1e9);
  std::vector<int> parent(end + 1,-1);

  q.push({0,start});
  parent[start] = start;

  while(q.empty() == false)
  {
      int node = q.front().second;
      int steps = q.front().first;
      q.pop();


      //adjancey list is arr
      for(auto &elem : arr)
      {
          int prod = (node * elem) % maxRange;//adj node
                                              //0-node + node to prod takes 1 step
          if(bestSteps[prod] > steps + 1)
          {
              bestSteps[prod] = steps + 1;

              parent[prod] = node;//parent

              if(node == end) //we can return here  as soon as we get the answer
              {
                  while(parent[end] != end)
                  {
                      std::cout << end << "-";
                      end = parent[end];
                  }
                  std::cout << start << "\n"; //answer in reverse
                   
                  return steps;
              }
              q.push({steps + 1,prod});
          }
      }
  }
 
 return -1;
}

int main()
{
    // Driver Code.
    int start = 3, end = 30;

    std::vector<int> arr = {2, 5, 7};


    int ans = minimumMultiplications(arr, start, end);

    std::cout << ans;
    std::cout << std::endl;

    return 0;
}




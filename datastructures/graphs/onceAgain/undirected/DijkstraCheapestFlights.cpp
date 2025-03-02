/**
 * G-38: Cheapest Flights Within K Stops
 * https://takeuforward.org/data-structure/g-38-cheapest-flights-within-k-stops/
 *
 * there are n cities and m edges connected by some number of flights.
 * You are given an array of flights where flights[i] = [ fromi, toi, pricei]
 * indicates that there is a flight from city fromi to city toi with cost price.
 * You have also given three integers src, dst, and k, and return the cheapest 
 * price from src to dst with at most k stops. If there is no such route, return -1.
 *
 * Brute Force approach will be to Go from source to destination with each path
 * and exclude if stops greate rthan k
 *
 * or we can try to minimize the k. using dijkstra we prefer paths where we have minimum k
 * we exlplore them first. Here the rate of increasing k is constant so there is no requirement for
 * ordering as entries will be itself in order. so we can use normal queue
 *
 * We are minimizing K and not cost. because if we try to minimize the cost user will get frustrated with no of stops
 *
 * queue will store stops,totalCostTillnow,node
 *
 * and bestCost will store the best cost we can get to travel to a node
 *
 * When to stop 1->2->3 takes only 1 stoppage
 * we start from 0 stoppage in queue while at 1. when we reach node 2 we have stoppage = 1
 * 1 stoppage allowed we move to 3 . we have 2 stoppage now so we break
 */

#include <iostream>
#include <vector>
#include <queue>

//K denotes max stops allowed
int CheapestFlight(int Nodes,std::vector<std::vector<int>> &flights,int source,int dest,int K)
{
    if(source == dest || flights.size() == 0)
    {
        return 0;
    }

   //we need adjacent list
   std::vector<std::pair<int,int>> adj[Nodes];
   for(auto it : flights)
   {
       adj[it[0]].push_back({it[1],it[2]});
   }
   std::queue<std::pair<int,std::pair<int,int>>>q;//stops,totalCost,node
   std::vector<int> bestCost(Nodes,1e9);
   bestCost[source] = 0;

   q.push({0,{0,source}});

   while(q.empty() == false)
   {
       int node = q.front().second.second;
       int cost = q.front().second.first;
       int stops = q.front().first;
       q.pop();

       //if exceeded the stops then constinue for next entry
       if(stops > K) //if equal to is used we wont get the answer as for destionation we dont consider it as stop
       {
           continue;
       }

       for(auto it: adj[node])
       {
          int transitAirport = it.first;
          int costTillTransitAirport = it.second;

          //Check Cost
          if((bestCost[transitAirport] > cost + costTillTransitAirport) && (stops  <= K))
          {
              bestCost[transitAirport] = cost + costTillTransitAirport;
              q.push({stops + 1,{cost + costTillTransitAirport,transitAirport}});
          }
       } 
   }

   if(bestCost[dest] == 1e9)
   {
       return -1;
   }
   return bestCost[dest];
}

int main()
{
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    std::vector<std::vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};


    int ans = CheapestFlight(n, flights, src, dst, K);

    std::cout << ans;
    std::cout << std::endl;

    return 0;
}

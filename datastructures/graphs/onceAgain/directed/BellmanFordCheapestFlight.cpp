/**
 * G-38: Cheapest Flights Within K Stops WIth Bellman Ford
 * https://takeuforward.org/data-structure/g-38-cheapest-flights-within-k-stops/
 *
 * We use bellman ford. we keep dist and well as stops in dist vectoe
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int CheapestFlightBell(int Nodes,std::vector<std::vector<int>> &flights,int source,int dest,int K)
{
	std::pair<int,int> def;
	def = std::make_pair(1e9,0);
	//2nd parameter stores stops
	std::vector<std::pair<int,int>> dist(Nodes,def);
	dist[source] = {0,0};
	
	for(int i = 0; i < Nodes -1; i++)
	{
		int stops = 0;
		for(auto it : flights)
		{
			
			int u = it[0];
			int v = it[1];
			int w = it[2];
			
			if(dist[u].first != 1e9 && dist[v].first > dist[u].first + w)
			{
				stops = dist[it[0]].second;
				if(stops > K)
				break;
				dist[v].first = dist[u].first + w;
			
				
				dist[v].second = stops + 1;
				
			}
		}
	}
	std::for_each(dist.begin(),dist.end(),[](const std::pair<int,int> &elem){
	std::cout << elem.first << ",";});
	std::cout << "\n";
	return dist[dest].first;
}


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

    std::vector<std::vector<int>> flights = {{0, 1, 100}, {1, 2, 100},  {1, 3, 600},
    {2, 3, 200}};


    int ans = CheapestFlightBell(n, flights, src, dst, K);

    std::cout << ans;
    std::cout << std::endl;

    return 0;
}
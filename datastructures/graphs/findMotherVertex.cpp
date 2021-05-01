//Find Vertex from which we can reach all vertex
//Here we will follow simple approach of looping through each
//vertex so its complexity would be O(V(E+V))
//We will do DFS 

#include <iostream>
#include <vector>
#include <stack>

void addEdge(std::vector<int> v[],int a,int b)
{
  v[a].push_back(b);
}

std::vector<int> findMotherVertex(std::vector<int> vec[],int V)
{
 std::vector<int> res;

 for(int i = 0 ; i < V; i++)
 {
   std::stack<int>st;
   st.push(i);
   std::vector<bool>visited(V,false);
   int count = 1;

   while(!st.empty())
   {
     int element = st.top();
     st.pop();

     if(visited[element] == false)
       visited[element] = true;

     for(int j = 0; j < vec[element].size(); j++)
     {
       int e = vec[element][j];

       if(visited[e] == false)
       {
         st.push(e);
         count++;
       }
     }

   }

   if(count == V)
     res.push_back(i);
 }

 return res;

}


int main()
{
  int v = 4;
  std::vector<int> vec[4];
  addEdge(vec,0,1);
  addEdge(vec,1,2);
  addEdge(vec,2,0);
  addEdge(vec,3,2);

  for(auto elem : findMotherVertex(vec,v))
  {
    std::cout << "\n MOTHER VERTEX IS = " << elem << "\n";
  }

}

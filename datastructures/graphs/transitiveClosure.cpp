//Find Transitive closure of a ver

#include <iostream>
#include <vector>
#include <stack>

void addEdge(std::vector<int> v[],int a,int b)
{
  v[a].push_back(b);
}

void printTransitveClosure(std::vector<int> vec[],int V)
{
 std::vector<int> res;

 for(int i = 0 ; i < V; i++)
 {
   std::stack<int>st;
   std::vector<int> tcl;
   st.push(i);
   tcl.push_back(i);
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
         tcl.push_back(e);
         count++;
       }
     }

   }

   std::cout << "\n Transitive CLosure of " << i << " iS === \n";
   for(auto &elem:tcl)
   {
     std::cout << elem << " ";
   }

 }

}


int main()
{
  int v = 4;
  std::vector<int> vec[4];
  addEdge(vec,0,1);
  addEdge(vec,1,2);
  addEdge(vec,2,0);
  addEdge(vec,2,3);
  addEdge(vec,3,3);
  printTransitveClosure(vec,v);


}

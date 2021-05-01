//We will use set to store the edges of a graph.
//Using set doesn't allow parllel graph.
//parallel graph     
//
//
//                A-----------B
//                \__________/
//https://www.geeksforgeeks.org/graph-representations-using-set-hash/

#include <iostream>
#include <unordered_set>


class Graph
{
  public:
    Graph(int V)
    {
      this->V = V;
      graph = new std::unordered_set<int>[V];
    }
    ~Graph()
    {
      delete [] graph;
      graph = nullptr;
    }

    void AddEdge(const int &src,const int&dest)
    {
      graph[src].insert(dest);
    }

    void PrintGraph()
    {
      for(int i = 0; i < V; i++)
      {
        std::cout << "\n Head = " << i << " ---\n";

        for(auto &elem : graph[i])
        {
          std::cout << elem << "\n";
        }
      }
    }

    void SearchEdge(const int &start,const int &end)
    {
      if(graph[start].find(end) != graph->end())
      {
        std::cout << "\n Edge found between = " << start << " " << end << "\n";
      }
      else
        std::cout << "\n Edge NOT found between = " << start << " " << end << "\n";
    }


    std::unordered_set<int> *graph;
    int V;
};

int main()
{
  Graph g(3);
  g.AddEdge(0,1);
  g.AddEdge(1,0);
  g.AddEdge(1,2);
  g.AddEdge(2,1);
  g.PrintGraph();
  g.SearchEdge(0,1);
  g.SearchEdge(0,2);
}

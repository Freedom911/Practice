#include <iostream>
#include <vector>
#include <limits>

int **t;

//Hypothesis
int mcm(std::vector<int> v,int i,int j)
{
    //Base conditions
    if(i == j || i + 1 ==j )
    {
        return 0;
    }


    //Choices
    int minCost = std::numeric_limits<int>::max();
    for(int k = i + 1; k <= j-1; k++)
    {
        int totalCost =mcm(v,i,k) + mcm(v,k,j) + v[i] * v[k] * v[j];
        minCost = std::min(minCost,totalCost);
    }

    return minCost;
}

//Hypothesis
int dpMcm(std::vector<int> v,int i,int j)
{
    //Base conditions
    if(i == j || i + 1 == j)
    {
        return 0;
    }
    
    //check if result already present
    if(t[i][j] != -1)
    {
        return t[i][j];
    }


 
    //Choices
    int minCost = std::numeric_limits<int>::max();
    for(int k = i + 1; k <= j-1; k++)
    {
#if 1
        int c1,c2,c3;
        if(t[i][k] != -1)
        {
          c1 = t[i][k];
        }
        else
        {
            c1 = dpMcm(v,i,k);
        }
        if(t[k][j] != -1)
        {
          c2 = t[k][j];
        }
        else
        {
            c2 = dpMcm(v,k,j);
        }

        c3 = v[i]*v[k]*v[j];

        int totalCost = c1 + c2 + c3;
#endif
       // int totalCost = dpMcm(v,i,k) + dpMcm(v,k,j); + v[i]*v[k]*v[j];;
        minCost = std::min(minCost,totalCost);
    }

    return minCost;
}
int main()
{
    std::vector<int> v{40, 20, 30, 10, 30};



    t = new int*[v.size() + 1];
    for(int i = 0; i < v.size() + 1; i++)
        t[i] = new int[v.size() + 1];

    for(int i = 0; i < v.size() + 1; i++)
    {
        for(int j = 0; j < v.size() + 1; j++)
        {
            t[i][j] = -1;
        }
    }
    std::cout << mcm(v,0,4) << "\n";
    std::cout << dpMcm(v,0,4) << "\n";
}

//Fraction Knapsack is a problem that asks how to maximize the profit
//of objects with weights that we can put a bag with capacity n
//BY simply being greedy for weight(to minimize) or profit(to maximize)
//we cannot achieve the maximum result . Instead we calculate profit to 
// weight result

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>





float getMaxProfit(const std::vector<std::tuple<int,int> > &objectsInfo,int n)
{
  //This will contain the profit and object no
  std::vector<std::tuple<float,int>> profitByWeight;


  int i = 0;
  for(const auto &elem:objectsInfo)
  {
    int profit,weight;
    std::tie(profit,weight) = elem;
    profitByWeight.push_back({(float)profit/(float)weight,i});


    i++;
  }
  std::sort(profitByWeight.begin(),profitByWeight.end(),
      [](std::tuple<float,int> a,std::tuple<float,int> b)->bool
      {
        //comparing profits
        return std::get<0>(a) > std::get<0>(b);
      }
      );


  float finalProfit = 0.f;
  i = 0;
  for(i = 0; i < profitByWeight.size(); i++)
  {
    int profitWeight,index;
    std::tie(profitWeight,index) = profitByWeight[i];

    int profit,weight;
    std::tie(profit,weight) = objectsInfo[index];

                //means weight of the object at index 
    if(n > 0 && weight <= n)
    {
      n = n - weight;
      finalProfit += profit;
    }
    else
      break;
  }

  if(n > 0 && i < profitByWeight.size())
  {
    int profitWeight,index;
    std::tie(profitWeight,index) = profitByWeight[i];

    int profit,weight;
    std::tie(profit,weight) = objectsInfo[index];

    finalProfit += profit * ((float)n/weight);
  }

  return finalProfit;

}


int main()
{
  std::vector<std::tuple<int,int> > objectsInfo;
  objectsInfo.push_back({10,2});
  objectsInfo.push_back({5,3});
  objectsInfo.push_back({15,5});
  objectsInfo.push_back({7,7});
  objectsInfo.push_back({6,1});
  objectsInfo.push_back({18,4});
  objectsInfo.push_back({3,1});

  int n;
  std::cout << "\n Enter Capacity Of bag \n";
  std::cin >> n;

  std::cout << "\n Max Profit = " << getMaxProfit(objectsInfo,n) << "\n";


}

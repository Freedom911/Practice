//https://just4once.gitbooks.io/leetcode-notes/content/leetcode/binary-search/774-minimize-max-distance-to-gas-station.html
//Similiar to allocate minimum number of pages
#include <iostream>
#include <vector>
#include <cmath>

//This function will checks if total required station to cover is less than or equal to 
//total allowed stations
bool checkIsPossible(const double &maxDistanceBwEachSt,const std::vector<int> &stations,
                     const int &totalAddStations)
{
  //This is a simple math function
  int totalRequiredSt = 0;
  int size = stations.size();
  for(int i = 0; i < size - 1; i++)
  {
    totalRequiredSt += std::ceil((stations[i+1] - stations[i])/maxDistanceBwEachSt) - 1;
  }

  return totalRequiredSt <= totalAddStations; //if we are able to cover everything by using maxDistanceBwEachSt distance b/w each stations then we try to decrease
                                              //more as we are trying to minimize maxDistanceBwEachSt hence we returrn true
}


double getMinMaxDistance(const std::vector<int> &stations,const int &totalAddStations)
{
  double l = 0;
  int s = stations.size();
  double r = stations[s-1] - stations[0];
  double deltaDiff = 1e-6;


  while(r - l > deltaDiff)
  {
    double mid = l + (r-l)/2;
    std::cout << mid << "\n";

    //If we are able to achieve the mid distance by utiltizing totalAddStations or less than it
    //then we try to move left to reduce more distance
    if(checkIsPossible(mid,stations,totalAddStations))
      r = mid;//not mid-1 as we can have distance which is much smaller than 1.by using mid we take care of that
    else
      l = mid;
  }

  return l;//can return r also will be same

}

int main()
{
  std::cout << "\n Minimum Distance is = " << getMinMaxDistance({1,5,10},2) << "\n";
  //std::cout << "\n Minimum Distance is = " << getMinMaxDistance({1,2,3,4,5,6,7,8,9,10},9) << "\n";
}


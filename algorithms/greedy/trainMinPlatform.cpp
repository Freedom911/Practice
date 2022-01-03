//Given arrival and departure time of trains
//find total platform needed if waiting is not allowed
//We will stort departure array and incrment platform if 
//arrival time of train is less than previous departure time
#include <iostream>
#include <vector>
#include <algorithm>

int minPlatformNeeded(std::vector<int> arrivalTime,std::vector<int> departureTime)
{
  int maxPlatform = -1;
  int i = 0;
  int j = 0;
  int platform = 0;
  std::sort(departureTime.begin(),departureTime.end());

  while( i< arrivalTime.size() && j < departureTime.size())
  {
    //means another train is still standing
    if(arrivalTime[i] < departureTime[j])
    {
      platform++;
      i++;

      if(maxPlatform < platform)
        maxPlatform = platform;
    }

    else
    {
      platform--;
      j++;
    }
  }

  return maxPlatform;
}

int main()
{
  std::vector<int> arrival{60,100,110,120,135,240};
  std::vector<int> dep{70,140,150,180,195,360};

  std::cout << "\n MIN PLATFORM REQUIRED = " << minPlatformNeeded(arrival,dep) << "\n";
}


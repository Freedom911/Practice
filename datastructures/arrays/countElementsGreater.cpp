/**
 * https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/count-elements-greater-than-previous-average/problem?isFullScreen=true
 * 
 */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countResponseTimeRegressions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY responseTimes as parameter.
 */

int countResponseTimeRegressions(vector<int> responseTimes) 
{
    if(responseTimes.size() <= 1)
    {
        return 0;
    }

    
    long long int currentSum = responseTimes[0];
    int count = 0;

    for(size_t i = 1; i < responseTimes.size(); i++)
    {
        if(responseTimes[i] > (double)currentSum/(i))
        {
            count++;
        }
       currentSum += responseTimes[i];
    }
    return count;
}

int main()
{
  
    int result = countResponseTimeRegressions({100,0});

    cout << result << "\n";

    return 0;
}

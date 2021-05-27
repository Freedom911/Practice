//https://leetcode.com/problems/k-th-symbol-in-grammar/
#include <iostream>
#include <cmath>


//Hypothesis
int getKthSymbol(int N,int K)
{
  if(N == 1 && K == 1)
    return 0;

  //Length of each string will be 2^N-1
  int mid = pow(2,N-1)/2;

  if(K <= mid)
    return getKthSymbol(N-1,K);

  else
    return !getKthSymbol(N-1,K-mid);
}

int main()
{
  std::cout << getKthSymbol(3,3) << "\n";
}


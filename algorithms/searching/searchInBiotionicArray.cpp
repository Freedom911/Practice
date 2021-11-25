#include <iostream>
#include <vector>

int findPeakIndex(std::vector<int> v)
{
  int p = 0;
  int q = v.size() - 1;
  int mid = -1;
  while(p <= q)
  {
    mid = p + (q-p)/2;

    int prev = mid - 1;
    int next = mid + 1;

    if(prev < 0 && next >= v.size())
      return 0;

    if((prev < 0 && v[mid] > v[next]) ||(next >= v.size() && v[mid] >= v[0]))
      return mid;
    else if(v[mid] < v[next])
      p = mid + 1;
    else if(v[mid] < v[prev])
      q = mid - 1;
    else if(v[mid] > v[prev] && v[mid] > v[next])
      return mid;

  }
  return 0;
}
//1 2 3 4
int bsa(std::vector<int> v,int p,int q,int elem)
{

  int mid = -1;
  while(p <= q)
  {
    mid = p + (q-p)/2;

    if(mid == elem)
      return mid;
    else if(v[mid] < elem)
      p = mid + 1;
    else
      q = mid - 1;

  }
  return -1;
}
//4 3 2 1
int bsd(std::vector<int> v,int p,int q,int elem)
{

  int mid = -1;
  while(p <= q)
  {
    mid = p + (q-p)/2;

    if(mid == elem)
      return mid;
    else if(v[mid] < elem)
      q = mid - 1;
    else
      p = mid + 1;

  }
  return -1;
}
int findPeakElem(std::vector<int>v,int peak)
{
  int peakIndex = findPeakIndex(v);
  if(peakIndex <= 0)
    return v[0];
  
  int a = bsa(v,0,peakIndex,peak);
  int b = bsd(v,peakIndex + 1,v.size(),peak);

  if(a == -1 && b == -1)
    return -1;
  else if(a == -1)
    return b;
  else
    return a;


}
int main()
{
  std::cout << findPeakElem({1,3,8,12,4,2},4) << "\n";
}

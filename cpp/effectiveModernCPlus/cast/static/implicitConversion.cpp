//Static cast can be used for implicit conversion
#include <iostream>
#include <vector>
int main()
{
  //For Double to int
  double d = 3.4;
  int j = static_cast<int>(d) + 5;
  std::cout << "\n J Value = " << j << "\n";

  //For int to double
  double dd = static_cast<double>(j) + 0.5;
  std::cout << "\n DD Value = " << dd << "\n";

  std::vector<double> v = static_cast<std::vector<double> >(10);

  std::cout << "\n Vector Size = " << v.size() << " And Element 1st = " << v[0] << "\n";


  //inverse implicit conversion
  void *n = &d;
  double *dp = static_cast<double*>(n);
  std::cout << "\n DOUBLE = " << *dp;

  //Array Degrading to pointer conersion
  int a[3];

  a[0] = 1;
  a[1] = 2;
  a[2] = 3;

  int *b = static_cast<int*>(a);

  std::cout << "\n B VALUE = " <<  *b << " " << *(b+1) << "\n";

  //Static Cast Can be used to add constantness
  int jj = 4;

  const int k = static_cast<const int>(jj);
  //k = 10;
  
  //Will not work:
  //error: conversion from ‘std::vector<int>’ to non-scalar type ‘std::vector<double>’ requested
  //std::vector<int> vi;
  //std::vector<double> vd = static_cast<std::vector<int> >(vi);

}

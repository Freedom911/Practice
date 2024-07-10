## Tail Recursion
In Tail Recursion  we dont perform any operation after recursion call.
Basically in non tail recursion we have to do two passes. eq

**Non Tail Recursion**

```
int fact(int n)
{
  if(n == 1)
   return 0;
   
   return n * fact(n-1);
}
```

>fact(4) -> 4 * fact(3)\
>fact(3) -> 3 * fact(2)\
>fact(2) -> 2 * fact(1)\
>fact(1) -> 1

Here For fact(4) we go down first till fact 1. Then we return value to each function call
.So here there are two passes one down and one up.

Tail Recursion is like iteration.In tail recursion we get value in one pass itself that is while going downwards.Compiler optimize the tail recursion. This is one of the reason quicksort is faster than merge sort.
```
int fact(int n,int curr)
{
  if(n == 1)
  return curr;
  
  return fact(n,n * curr);
  
}
```

## BackTracking
Backtracking is like recursion but it follows certain criteria

1. In Backtracking we use call by reference.
2. In Backtracking we restrict the number of branches.

For Backtracking problems these 6 traits are visible
1. Generate All combinations.
2. Controlled Recursion/Prune branches.
3. Choice/Decisions to make.
4. Number of choices are large.
5. SIze of constraint is there to avoid exploring all branches for online platforms.
6. Greedy Approach fails as we have to explore all branches.



Following is the general Structure

```
void solve(std::string &inp,int startIndex)
{
  if(isSolved(inp))//base condition
  { 
    std::cout << inp << "\n";
    return true;
  }
  
  //Choices
  for(int i = startIndex; i < inp.size(); i++)
  {
    //Controlled Recursion/Prune
	if(isValid(inp[i]))
	{
	   std::swap(inp[i],somevalue);
	   solve(inp,startIndex++);
	   //Backtrack/revert changes
	   std::swap(inp[i],somevalue);
	   
	}
  }
}
```

/**
 * 
 * Fibonacci Series using recurion ,dp tabular and space oiptimized
 *
 */
 #include <iostream>
 #include <vector>
 
 //Recursive Solution
 //Hypothesis - This function returns the sum till nth term in fib series
 int fibRec(int n)
 {
	 //Base case
	 if(n <= 2)
	 {
		 return 1;
	 }
	 
	 //Induction Step
	 return fibRec(n-1) + fibRec(n-2);//Returns sum of till n-1 and n-2 term
 }
 
 int fibDPTop(int n,std::vector<int> &dp)
 {
	  //Base case
	 if(n <= 2)
	 {
		 return 1;
	 }
	 
	 if (dp[n] != -1)
	 {
		 return dp[n];
	 }
	 
	 
	 //Induction Step
	 dp[n] = fibDPTop(n-1,dp) + fibDPTop(n-2,dp);//Returns sum of till n-1 and n-2 term
	 return dp[n];
 }
 
 int fibBottomUp(int n)
 {
	  //Base case
	 if(n <= 2)
	 {
		 return 1;
	 }
	 
	 std::vector<int> dp(n+1,0);
	 dp[0] = 0;
	 dp[1] = 1;
	 
	 for(int i = 2; i < n + 1; i++)
	 {
		 dp[i] = dp[i-1] + dp[i-2];
	 }
	 return dp[n];
 }
 
 int fibOptimized(int n)
 {
	 if(n <= 2)
	 {
		 return 1;
	 }
	 
	 int a = 0;
	 int b = 1;
	 int c = 1;
	 
	 for(int i = 2; i < n + 1; i++)
	 {
		 c = a + b;
		 a = b;
		 b = c;
	 }
	 return c;
 }
 
 int main()
 {
	 int n ;
	 std::cout << "\n ENTER n = ";
	 std::cin >> n;
	 
	 std::vector<int> dp(n+1,-1);
	 
	 std::cout << "\n FIB REC = " << fibRec(n) << "\n";
	 std::cout << "\n FIB DP TOP = " << fibDPTop(n,dp) << "\n";
	 std::cout << "\n FIB DP Bottom = " << fibBottomUp(n) << "\n";
	 std::cout << "\n FIB OPTI = " << fibOptimized(n) << "\n";
 }
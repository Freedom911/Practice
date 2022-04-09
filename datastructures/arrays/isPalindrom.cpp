//leetcode 9
class Solution {
public:
    bool isPalindromeUnoptimized(int x) {
        std::string str = std::to_string(x);
        std::string rev = str;
        std::reverse(rev.begin(),rev.end());
        return str == rev ? true:false;
    }
  bool isPalindrome(int x) {
    
    //negative no cant be palindrome
    if(x < 0)
      return false;
    int digits;
    long int rev=0;
    {
    int temp = x;
    while(temp != 0)
    {
      digits = temp%10;
      rev = rev*10 + digits;
      temp = temp/10;
    }
    }
    return rev == x ? true:false;
    
    }
};

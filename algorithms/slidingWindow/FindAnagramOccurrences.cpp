#include <iostream>
#include <unordered_map>
#include <string>

int countAnagram(std::string text,std::string word)
{
    int k = word.size();
    int ans = 0;
    std::unordered_map<char,int> us;

    for(int i = 0; i < word.size(); i++)
    {
        us[word[i]]++;
    }
    int count = us.size();
    int n = text.size();
    int j = 0;
    int i = 0;
    while(j < n)
    {
        //calculation part
        if(us.find(text[j]) != us.end())
        {
            us[text[j]]--;

            if(us[text[j]] == 0)
                count--;
        }


        //hitting slidding window
        if(j - i + 1 == k)
        {
            //calculate ans
            if(count == 0)
            {
                ans++;
            }

            //revert and slide
            if(us.find(text[i]) != us.end())
            {
                us[text[i]]++;
                if(us[text[i]] == 1)
                    count++;
            }

            i++;//slidding
        }
        j++;//slidding
    }

    return ans;

}

int main()
{
    std::cout << countAnagram("aabaabaa","aaba") << "\n";
}

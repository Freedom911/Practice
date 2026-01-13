#pragma once
#include <string>
#include <vector>
#include <unordered_set>

class Tags
{
    public:
    void AddTag(std::string str)
    {
        m_set.insert(str);
    }

    std::vector<std::string> GetTags()
    {
        std::vector<std::string> vec;
        for(auto it : m_set)
        {
            vec.push_back(it);
        }

        return vec;
    }

    private:
    std::unordered_set<std::string> m_set;
};

#pragma once
#include "TrieNode"
#include <string>
class TrieClass
{
    public:
    TrieClass()
    {
        m_trie = new TrieNode();
    }

    ~TrieClass()
    {
        delete m_trie;
    }

    void Insert(const std::string &str)
    {
        TrieNode *Root = m_trie;
        for(const char &ch : str)
        {
            if(Root->GetLink(ch) == nullptr)
            {
                TrieNode *node = new TrieNode();
                Root->PutNode(ch,node);
            }
        }

        Root->EndWord();
        Root->IncreaseEndsWithCount();
    }

    

    private:
    TrieClass *m_trie;
};

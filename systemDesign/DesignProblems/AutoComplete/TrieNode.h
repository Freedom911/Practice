#pragma once

constexpr unsigned int TOTAL_NODES = 27; //0-25 for small char ,26 for space
constexpr unsigned int SPACE_CODE = 26;

struct TrieNode
{
    TrieNode *NextNodes[TOTAL_NODES] = {};
    bool isLeaf = false;
    unsigned int endsWithCount = 0;

    ~TrieNode()
    {
        for(unsigned int i = 0; i < TOTAL_NODES; i++)
        {
            if(NextNodes[i] != nullptr)
            {
                delete NextNodes[i];
                NextNodes[i] = nullptr;
            }
        }
    }


    unsigned int GetIndex(char ch)
    {
        if(ch == ' ')
        {
            return SPACE_CODE;
        }

        return ch - 'a';
    }

    TrieNode *GetLink(char ch)
    {
        unsigned int val = GetIndex(ch);
        if(val >= TOTAL_NODES)
        {
            return nullptr;
        }

        return NextNodes[val];
    }

    void PutNode(char ch,TrieNode *Node)
    {
        unsigned int val = GetIndex(ch);
        if(val >= TOTAL_NODES)
        {
            return nullptr;
        }

        NextNodes[val] = Node;
    }

    void EndWord()
    {
        isLeaf = true;
    }

    void IncreaseEndsWithCount()
    {
        endsWithCount++;
    }
};

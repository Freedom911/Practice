#include <iostream>
#include <vector>
#include <string>

constexpr int MAX_NODES = 27;//0-25 a-z and last for space
struct TrieNode
{
    TrieNode *Nodes[MAX_NODES] = {};

    bool isEnd = false;

    int freq = 0;

    int GetIndex(char value)
    {
        return value - 'a';
    }


    void PutNode(char value,TrieNode *Node)
    {
        int Index = GetIndex(value);

        if(Index < 0)
        {
            return;
        }
        Nodes[Index] = Node;
    }

    TrieNode *GetNode(char value)
    {
         int Index = GetIndex(value);

        if(Index < 0)
        {
            return nullptr;
        }
        return Nodes[Index];
    }

    void EndWord()
    {
        isEnd = true;
    }

    void AddFrequency()
    {
        freq++;
    }
    
};


class Trie
{
    public:
    Trie()
    {
        Root = new TrieNode;
    }
    void InsertWord(std::string str)
    {
        TrieNode *RootCopy = Root;
        for(char ch : str)
        {
            if(RootCopy->GetNode(ch) == nullptr)
            {
                TrieNode *node = new TrieNode();
                RootCopy->PutNode(ch,node);
            }

            RootCopy = RootCopy->GetNode(ch);//move to next
        }
        if(RootCopy)
        {
            RootCopy->EndWord();
        RootCopy->AddFrequency();
        }
        
    }

    void InsertWord(std::vector<std::string> str)
    {
        for(std::string ch : str)
        {
          InsertWord(ch);
        }
        
    }

    void Print(TrieNode *Head,std::string &ans)
    {
        if(Head->isEnd)
        {
            std::cout << ans << " WITH FREQ = " << Head->freq << "\n";
        }
        
        if(Head)
        {
            for(int i = 0; i < MAX_NODES; i++)
            {
                char ch = 'a' + i;
                if(Head->GetNode(ch) != nullptr)
                {
                    ans.push_back(ch);
                    
                    Print(Head->GetNode(ch),ans);

                    ans.pop_back();
                }
            }
        }
    }


    void PrintWordMatching(std::string str)
    {
        TrieNode *RootCopy = Root;
        for(char ch : str)
        {

            if(RootCopy->GetNode(ch) == nullptr)
            {
                return;
            }
            else
            {
                 RootCopy = RootCopy->GetNode(ch);//move to next
            }

        }

        if(RootCopy)
        {
            std::cout << str ;
            std::string ans;
            Print(RootCopy,ans);
        }

    }
    private:
    TrieNode *Root = {};
};

int main()
{
    Trie trie;
    trie.InsertWord({"hellothisisit","hellohowareyou","hellohowareyou",
        "hellohowareyoudoing","hellohowareyoudoing"});
    std::cout << "\n PRINTING\n";
    trie.PrintWordMatching("hello");
    
    
}



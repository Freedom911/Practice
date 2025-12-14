/**
 *
 * https://takeuforward.org/data-structure/implement-trie-ii/
 *
 * Problem Statement: Implement "TRIE” data structure from scratch with the following functions.
 * Trie(): Initialize the object of this “TRIE” data structure.
 * insert(“WORD”): Insert the string “WORD” into this “TRIE” data structure.
 * countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
 * countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
 * erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.
 
 */

#include <iostream>

struct TrieNode
{
    // 26 Characters Large 26 small
    TrieNode *Nodes[27] = {};
    // from 0-25 large after that small

    bool isLeaf = false;
    unsigned int starts = 0; //used when we want to find out matching prefix
    unsigned int ends = 0; //only used when we want to find count for exact word

    int GetIndex(char val)
    {
        return val - 'a';
    }

    char GetChar(int val)
    {
        if(val == 26)
        return ' ';
        return static_cast<char>(val + 'a');
    }

    bool CheckLinkExists(char val)
    {

        // For small only
        // return Nodes[val - 'a'] != nullptr; //means link exists

        // eg a- A =
        int index = GetIndex(val);

        if (index == -1)
        {
            return false;
        }

        return Nodes[index] != nullptr; // means link exists
    }

    void PutNode(char val, TrieNode *node)
    {
        int index = GetIndex(val);

        if (index == -1)
        {
            return;
        }
        Nodes[index] = node;
    }

    TrieNode *GetNode(char val)
    {
        int index = GetIndex(val);

        if (index == -1)
        {
            return nullptr;
        }

        return Nodes[index];
    }
    



    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (Nodes[i] != nullptr)
            {
                // This Calls Recursive destructor which is what we want
                delete Nodes[i];
            }
            Nodes[i] = nullptr;
        }
    }
};

class Trie
{
public:
    Trie()
    {
        m_trie = new TrieNode();
    }

    ~Trie()
    {
        delete m_trie;
    }

    void Insert(const std::string &str)
    {
        TrieNode *Root = m_trie;
        for (const char &ch : str)
        {
            // Link Not exists
            if (Root->CheckLinkExists(ch) == false)
            {
                // So WE Create Link
                TrieNode *node = new TrieNode;
                Root->PutNode(ch, node);
            }
            
            // Move to next Link
            Root = Root->GetNode(ch);
            Root->starts = Root->starts + 1;
        }
        // After Moving to last work mark the root as end word
        Root->isLeaf = true;
        Root->ends = Root->ends + 1;
    }

    void Erase(const std::string &str)
    {
        TrieNode *Root = m_trie;
        for (const char &ch : str)
        {
            if (Root->CheckLinkExists(ch) == false)
            {
                return;
            }

            Root = Root->GetNode(ch);
            Root->starts = Root->starts - 1;
        }
        // After Moving to last work mark the root as end word
        
        Root->ends = Root->ends - 1;
    }

    bool CheckStringExists(const std::string &str)
    {
        TrieNode *Root = m_trie;
        for (const char &s : str)
        {
            if (Root->CheckLinkExists(s) == false)
            {
                return false;
            }

            Root = Root->GetNode(s);
        }

        if(Root && Root->isLeaf == true)
        {
            std::cout << "\n String " << str << " Exists with total count = " << Root->ends << "\n";;
            return true;
        }
        return false;

        
    }

    bool CheckPrefixExists(const std::string &str)
    {
        TrieNode *Root = m_trie;
        for (const char &s : str)
        {
            if (Root->CheckLinkExists(s) == false)
            {
                return false;
            }

            Root = Root->GetNode(s);
        }

        if(Root)
        {
            std::cout << "\n Prefix String " << str << " Exists with total count = " << Root->starts << "\n";; 
        }
        std::string res;
        
        PrintTrie(m_trie,res);
        return true;
    }



    void Print()
    {
        std::cout << "\n Printing Trie \n";
        std::string res;
        PrintTrie(m_trie,res);

    }



private:

    void PrintTrie(TrieNode *Root,std::string &res)
    {
        if(Root->isLeaf == true)
        {
            std::cout << res << "\n";
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (Root->Nodes[i] != nullptr)
            {
                char ch = Root->GetChar(i);

                res += ch;                
                PrintTrie(Root->GetNode(ch),res);
                res.pop_back();
                
            }
        }
    }
    TrieNode *m_trie;
};

int main()
{
    Trie trie;
    trie.Insert("aloo");
    //trie.Insert("bangan");
    //trie.Insert("ki");
    //trie.Insert("shaadimai");
    //trie.Insert("alooparantha");
    trie.Insert("alooparantha");
    trie.Insert("aloochaat");
    trie.Print();
    return 0;

    trie.CheckStringExists("alooparantha");
    trie.CheckStringExists("hat");

    trie.CheckPrefixExists("aloo");
    return 0;

    std::cout << "\n Prefix sha exists = " << trie.CheckPrefixExists("sha");
    std::cout << "\n Prefix bans exists = " << trie.CheckPrefixExists("bans");

    std::cout << "\n Prefix Alo exists = " << trie.CheckPrefixExists("Alo");
    trie.Insert("AlooChat");
    std::cout << "\n Prefix Alo exists = " << trie.CheckPrefixExists("Alo");
}

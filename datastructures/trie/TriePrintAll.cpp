/**
 *
 * https://takeuforward.org/data-structure/implement-trie-1/
 *
 * and attach to l
 *          Root
 *         /  |   \   \    \
 *        a
 *       l
 *      l
 */

#include <iostream>

struct TrieNode
{
    // 26 Characters
    TrieNode *Nodes[26] = {};
    // from 0-25 large after that small

    bool isLeaf = false;

    int GetIndex(char val)
    {
        return val - 'a';
    }

    char GetChar(int val)
    {
        return static_cast<char>(val + 'a');
    }

    bool CheckLinkExists(char val)
    {

        // For small only
        // return Nodes[val - 'a'] != nullptr; //means link exists

        int index = GetIndex(val);
        return Nodes[index] != nullptr; // means link exists
    }

    void PutNode(char val, TrieNode *node)
    {
        int index = GetIndex(val);
        Nodes[index] = node;
    }

    TrieNode *GetNode(char val)
    {
        int index = GetIndex(val);
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
        }
        // After Moving to last work mark the root as end word
        Root->isLeaf = true;
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
    trie.Insert("bangan");
    trie.Insert("ki");
    trie.Insert("shaadimai");
    trie.Insert("alooparantha");

    trie.Print();
}

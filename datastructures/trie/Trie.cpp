/**
 *
 * https://takeuforward.org/data-structure/implement-trie-1/
 *
 * Trie is a tree like structure with multiple links
 * It allows efficient retrieval and storage of keys. Helpful in prefix search
 * ,string searching,spell checking. It can be seens as determiniistic finite state of automata
 * as each node can be viewed as a state. Forms the basics of burst sorting which is the fastest
 * Trie Store the value unlike Tree
 *
 * Problem Statement: Implement the Trie class:
 * Trie(): Initializes the trie object. void insert (String word): Inserts the string word into the trie.
 * boolean search (String word): Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
 * boolean startsWith (String prefix): Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 *
 * Insert ALgo
 * We try to create a link to the next node. if the node already exists then we use that link
 * eg . Insert alli. so we check from top if the link to next character a exists if yes then we move
 * down that path. so when we reach a->l->l then we check i is there from l no it is not so we create a new trie node
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
    // 26 Characters Large 26 small
    TrieNode *Nodes[52] = {};
    // from 0-25 large after that small

    bool isLeaf = false;

    int GetIndex(char val)
    {
        int index = 0;

        if (val >= 'A' && val <= 'Z')
        {
            index = val - 'A'; // 90(Z) - 65(A) = 25
        }
        else if (val >= 'a' && val <= 'z')
        {
            index = val - 'a' + 26; // 97 -97 + 26 = 26th index
        }
        else
        {
            return -1;
        }
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
        for (int i = 0; i < 52; i++)
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
        return Root && Root->isLeaf == true;
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

        return true;
    }

private:
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
    trie.Insert("alooparantha");

    std::cout << "\n aloo exists = " << trie.CheckStringExists("aloo");
    std::cout << "\n hat exists = " << trie.CheckStringExists("hat");

    std::cout << "\n Prefix sha exists = " << trie.CheckPrefixExists("sha");
    std::cout << "\n Prefix bans exists = " << trie.CheckPrefixExists("bans");

    std::cout << "\n Prefix Alo exists = " << trie.CheckPrefixExists("Alo");
    trie.Insert("AlooChat");
    std::cout << "\n Prefix Alo exists = " << trie.CheckPrefixExists("Alo");
}

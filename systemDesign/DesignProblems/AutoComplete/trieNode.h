/**
 * Manages the particular node of a trie
 */
constexpr int MAX_NODES = 27;//0-25 for a-z and for spafe
struct TrieNode
{
    TrieNode *Nodes[MAX_NODES] = {};

    
    int endsWith = 0;

};

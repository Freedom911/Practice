//Trie is a ordered tree which allows very fast O(M) searching of
//string from a text where m is the length of key to be searched
//Each Trie node can have at 26 nodes i.e for english language
//example words (ad,ae,af,b,c)
//Root Node is EMpty 
//                  -
//                / | \
//               a  b  c //each level is ordered
//              /|\
//             / | \
//            d  e  f

#include <iostream>
#include <vector>
#include <string>
#define MAXALPHABETS 26

//assumption all character in small

struct TrieNode
{
  TrieNode *Nodes[MAXALPHABETS]; //each node will have these many nodes
  bool isEndOfTheWord;
};

TrieNode * createNode()
{
  TrieNode * node = new TrieNode();
  node->isEndOfTheWord = false;
  for(int i = 0; i < MAXALPHABETS; i++)
  {
    node->Nodes[i] = NULL;
  }

  return node;
}

void insertNode(TrieNode* root,std::string key)
{

  TrieNode*currentNode = root;
  for(int i = 0;i < key.size(); i++)
  {
    int index = key[i] - 'a';
    if(currentNode->Nodes[index] == NULL)
      currentNode->Nodes[index] = createNode();

    currentNode = currentNode->Nodes[index];
  }

  if(currentNode)
    currentNode->isEndOfTheWord = true;
}

bool searchKeyword(TrieNode *root,std::string key)
{
  TrieNode*currentNode = root;
  for(int i = 0;i < key.size(); i++)
  {
    int index = key[i] - 'a';
    if(currentNode->Nodes[index] == NULL)
      return false;

    currentNode = currentNode->Nodes[index];
  }

  if(currentNode != NULL && currentNode->isEndOfTheWord == true)
    return true;
 
  return false;
}



int main(int argc,char **argv)
{
  if(argc < 2)
  {
    std::cout << "\n Enter Key word to search \n";
    return 0;
  }

  std::vector<std::string> keys = {"the", "a", "there","answer", "any", "by","bye", "their" };

   TrieNode *rootNode = createNode();

   for(int i = 0; i < keys.size(); i++)
   {
     insertNode(rootNode,keys[i]);
   }

   std::string search = argv[1];

   std::cout << "\n Is the string = " << search << " Found in Trie ? " << searchKeyword(rootNode,search);



}

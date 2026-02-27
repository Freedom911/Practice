## Designing an Auto Complete solution

### Step 1 - Gathering Requirement
1. Should the autocomplete be case sensitive or insensitive ? INSENSITIVE
2. How Many results should be returned.? It will be configurable
3. On what basis shall the results should be returned. ? By Frequency or alphabetically order? Needs to be configurable
4. Is the dictionary static or dynamic ?  It will be dynamic

**Functional Requirement**
1. Given a string the appliction should output strings into the same prefix
2. It should output N Strings
3. The order of string could vary


**Non Functional Requirement**
1. Should allow more strings that is it should update its dictionary dynamic
2. Should be scaleable


### Step 2 - Identifing Identities
1. Trie Node class represent a trie node containing links to next node.
2. Trie class is responible for managing trie nodes.
3. A singleton auto complete class will be responible fpor ineracting with the client. It will allow dictionary
   Updation as well as returing the top N results.
4. Will Have Ranking class ,alphabetically and frequency bassed classes that return results
based on the algo.

### Step 3 - Identifying relationships
1. Trie Class has a trie node.
2. Autocomplete has a trie class
3. Trie class has Ranking Strategy 
4. Alphabetically and Frequency Based inherits RankingStrategy class.


### Step 4 Implementation

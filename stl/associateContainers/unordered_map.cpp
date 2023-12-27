//Implementing Unordered Map . It uses Linked list internally
//it uses hash table to store data
//O(1) for insert,delete,find amortized
#include <iostream>
#include <list>

class UnorderedMap
{
	public:
	UnorderedMap(int bs = 3,int mlf = 1):bucketSize(bs),maxLoadFactor(mlf)
	{
		bucket = new std::list<std::pair<int,int>>(bs);
	}
	
	~UnorderedMap()
	{
		delete bucket;
	}
	
	std::list<std::pair<int,int>>::iterator Find(int key);
	
	void Insert(int key,int val);
	
	void Delete(int key);
	
	size_t Size();
	
	std::list<std::pair<int,int>>::iterator End(int key);
	
	void DisplayAll();
	
	
	private:
	
	void Rehash();
	
	int Hash(int key);
	
	//array of list
	std::list<std::pair<int,int>> *bucket;
	int bucketSize;
	int totalElements;
	float maxLoadFactor;
	
};

std::list<std::pair<int,int>>::iterator UnorderedMap::Find(int key)
{
	

	for(std::list<std::pair<int,int>>::iterator iter = bucket[Hash(key)].begin(); iter != bucket[Hash(key)].end(); iter++)
	{
		
		if(iter->first == key)
		{
			std::cout << "\n INserted\n" << std::endl;
			return iter;
		}
	}
	std::cout << "\n INserted\n" << std::endl;
	
	return bucket[Hash(key)].end();
}

std::list<std::pair<int,int>>::iterator UnorderedMap::End(int key)
{
 return bucket[Hash(key)].end();
}

void UnorderedMap::Insert(int key,int val)
{
	auto it = Find(key);
	std::cout << "\n Pushing Back \n";
	if(it != bucket[Hash(key)].end())
	{
		it->second = val;
		return;
	}
	
	bucket[Hash(key)].push_back(std::make_pair(key,val));
	
	totalElements++;
	
	Rehash();
}

void UnorderedMap::Delete(int key)
{
	auto it = Find(key);
	
	if(it != bucket[Hash(key)].end())
	{ 
       bucket[Hash(key)].erase(it);
	   totalElements--;
	}
	
	
}

size_t UnorderedMap::Size()
{
	return totalElements;
}

void UnorderedMap::DisplayAll()
{
	for(int i = 0; i < bucketSize/2; i++)
	{
		for(auto &iter:bucket[i])
		{
			std::cout << iter.first << "->" << iter.second << "\n";
		}
	}
}

void UnorderedMap::Rehash()
{
	//Hashing not required
	if(totalElements/bucketSize <= maxLoadFactor)
	{
		return;
	}
	bucketSize *= 2;
	
	auto newbucket = new std::list<std::pair<int,int>>(bucketSize);
	
	for(int i = 0; i < bucketSize/2; i++)
	{
		for(auto &iter:bucket[i])
		{
			newbucket[Hash(iter.first)].push_back(std::make_pair(iter.first,iter.second)); //re calucate hash and insert into new bucket
		}
	}
	delete [] bucket;
	bucket = newbucket;
}

int UnorderedMap::Hash(int key)
{
	int hashed = key % 2;
	
	return hashed % bucketSize;
	
}

int main()
{
	UnorderedMap us;
	us.Insert(1,1);
	return 0;
	us.Insert(2,3);
	us.Insert(3,4);
	us.Insert(4,8);
	us.Insert(5,16);
	
	if(us.Find(3) != us.End(3))
	{
		std::cout << us.Find(3)->second << "\n";
	}
	
	us.Delete(4);
	std::cout << "\n Size = " << us.Size() << "\n";
	
	us.Insert(3,5);
	
	us.DisplayAll();
}
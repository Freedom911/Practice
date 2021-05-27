//Program to design a datastructure which allows insertion,deletion,searching,random access
//in o (1) .https://www.geeksforgeeks.org/design-a-data-structure-that-supports-insert-delete-search-and-getrandom-in-constant-time/
//unodered map allows o(1) oepration for insertion deletion and searching but for random access we require array
//This Doesn't allow duplicate although
#include <iostream>
#include <vector>
#include <unordered_map>

class DataStructure
{

  public:

    void insertElement(const int &item)
    {
      if(umap.find(item) != umap.end())
      {
        std::cout << "\n Duplicates not allowed \n";
        return;
      }
      
      arr.push_back(item);
      umap[item] = index;

      index++;
    }

    void deleteElement(const int &itemToDelete)
    {
      //means no element present
      if(umap.find(itemToDelete) == umap.end())
      {
        std::cout << "\n Item Not PResent \n";
        return;
      }

      int lastIndex = arr.size() - 1;

      if(lastIndex < 0)
        return;

      int ind = umap[itemToDelete];
      umap.erase(itemToDelete);

      //check if it'snt the last element

      if(itemToDelete != arr[ind])
      
      {
        int lastElement = arr[lastIndex];
        umap[lastElement] = ind;

        std::swap(arr[ind],arr[lastIndex]);
      }


      arr.resize(lastIndex);


    }

    int searchElement(const int &itemToSearch)
    {
      if(umap.find(itemToSearch) == umap.end())
      {
        return -1;
      }
        
      return umap[itemToSearch];



      
    }

    int getRandomElement()
    {
      int ind = rand() % arr.size();

      return arr[ind];
    }

    void print()
    {
      for(auto &e : arr)
      {
        std::cout << e << " ";
      }
    }

  private:
    std::vector<int> arr;
    std::unordered_map<int,int> umap;
    int index{0};
};

int main()
{
  DataStructure d;
  d.insertElement(10);
  d.insertElement(20);
  d.insertElement(30);
  d.insertElement(40);
  d.insertElement(50);

  std::cout << "\n Data = ";
  d.print();

  std::cout << "\n Element = 50 is at = " << d.searchElement(50) << "\n";

  d.deleteElement(50);
  
  std::cout << "\n After deleting Element = 50 is at = " << d.searchElement(50) << "\n";
  std::cout << "\n Data = ";
  d.print();
  d.deleteElement(40);
  d.deleteElement(30);
  d.deleteElement(20);
  std::cout << "\n Element = 10 is at = " << d.searchElement(10) << "\n";
  d.deleteElement(10);
  std::cout << "\n After deleting Element = 10 is at = " << d.searchElement(10) << "\n";



}

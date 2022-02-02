#include <iostream>
int main()
{
  int *arr = new (std::nothrow) int;//by default if new cannot allocate memory it throws
                                    //std::bad_alloc but if we use nothrow then we can check for null
  if(!arr)
    std::cout << "\n ERROR \n";

 
  free(arr); //this will only destory memory but we need to deallocate all the memory allocated inside the class
  delete(arr); //this ensures destructor is called


}

#include <iostream>
#include <string>
#include <cstdlib>

int totalAllocated = 0;


void *operator new(size_t size)
{
  size_t *p = (size_t*)(malloc(size + sizeof(size_t)));
  p[0] = size;
  totalAllocated += size;
  std::cout << "\n Allocating == " << totalAllocated << "\n";
  return (void*)(&p[1]);
}

void operator delete(void *p)
{
  size_t *ptr = (size_t*)p;
  size_t size = ptr[-1];
  totalAllocated -= size;
  std::cout << "\n TotalLeft == " << totalAllocated << "\n";
  void *p2 = (void*)(&ptr[-1]);
  free(p2);
}
void operator delete(void *p,size_t size)
{
  totalAllocated -= size;
  std::cout << "\n Deallocating == " << totalAllocated << "\n";
  free(p);
}

void exiting()
{
  if(totalAllocated != 0)
  {
    std::cout << "\n THERE IS SOME MEMORY LEAK \n";
  }
}

int main()
{
  std::atexit(exiting);
  //std::string str = "ELLO";
  int *str = new int();

  delete str;

}

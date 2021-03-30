#include <iostream>
#include <pthread.h>

void *threadFunc(void *ptr)
{
  std::cout << "\n = " << (char*)(ptr) << std::endl;
}

int main()
{
  pthread_t thread1;
  const char*message = "Hello";
  int id = pthread_create(&thread1,NULL,threadFunc,(void*)message);

  pthread_join(thread1,NULL);

}

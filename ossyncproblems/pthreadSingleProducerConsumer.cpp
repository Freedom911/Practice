//This Program shows he use casse of counting semaphore
//through the usage of producer consumer
//Single Producer Single Consumer Problem 

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <queue>
#include <stdlib.h>
#include <unistd.h>

std::queue<int>queue;

sem_t emptyCount,fillCount;

void *producer(void *data)
{
  int j = 10;

  while(j >= 0)
  {
    j--;
    int randData = rand() % 1000;
    //wait on empty queue.This will decrease empty count
    sem_wait(&emptyCount);
    std::cout << "\n Producer produced = " << randData << "\n";
    queue.push(randData);
    //Signal fillCount to be consumed
    sem_post(&fillCount);

    int randVal = rand() % 3;
    sleep(randVal);
    

  }
}


void *consumer(void *data)
{
  
  int j = 10;

  while(j >= 0)
  {
    j--;
    //decrease fill count by 1
    sem_wait(&fillCount);
    std::cout << "\n Consumer Consumed = " << queue.front() << "\n";
    queue.pop();
    //increase empty count by 1
    sem_post(&emptyCount);

  }
}

int main()
{
  srand ( time ( NULL));
  //10 telling the initial value of semaphore
  sem_init(&emptyCount,0,10);
  sem_init(&fillCount,0,0);

  pthread_t producerThread,consumerThread;
  pthread_create(&producerThread,NULL,producer,NULL);
  pthread_create(&consumerThread,NULL,consumer,NULL);
 

  pthread_join(producerThread,NULL);
  pthread_join(consumerThread,NULL);


}

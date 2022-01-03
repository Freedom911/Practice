//This Program shows he use casse of counting semaphore
//through the usage of producer consumer
//Multi Producer Single Consumer Problem 
//In Single Producer Consumer problem for case of multiproducers
//it can happen then multi producers might try to insert at same position in queue
//std queue is not thread safe. This may not be relevant here but is relevant 
//in general case while inserting data at an empty position. For example
//both producer key see empty position at index 0 and both will overwrite
//to overcome this we use mutex
//same with case of multi producers

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <queue>
#include <stdlib.h>
#include <unistd.h>

std::queue<int>queue;

sem_t emptyCount,fillCount;
pthread_mutex_t  queue_protector_mutex;

void *producer(void *data)
{

  while(true)
  {
    int randData = rand() % 1000;
    //wait on empty queue.This will decrease empty count
    sem_wait(&emptyCount);
    pthread_mutex_lock(&queue_protector_mutex);
    std::cout << "\n Producer produced = " << randData << "\n";
    queue.push(randData);
    pthread_mutex_unlock(&queue_protector_mutex);
    //Signal fillCount to be consumed
    sem_post(&fillCount);

    int randVal = rand() % 3;
    sleep(randVal);
    

  }
}

void *consumer(void *data)
{
  

  while(true)
  {
    //decrease fill count by 1
    sem_wait(&fillCount);
    pthread_mutex_lock(&queue_protector_mutex);
    std::cout << "\n Consumer " << (char*)(data) << " Consumed = " << queue.front() << "\n";

    queue.pop();
    pthread_mutex_unlock(&queue_protector_mutex);
    //increase empty count by 1
    sem_post(&emptyCount);

  }
}

int main()
{
  if(pthread_mutex_init(&queue_protector_mutex,NULL) != 0)
  {
    std::cout << "\n Error while initializing Mutex \n";
    return 1;
  }


  srand ( time ( NULL));
  //10 telling the initial value of semaphore
  sem_init(&emptyCount,0,10);
  sem_init(&fillCount,0,0);

  pthread_t producerThread,producerThread1,producerThread2,consumerThread1,consumerThread2,consumerThread3;
  const char *msg1 = "1";
  const char *msg2 = "2";
  const char *msg3 = "3";
  pthread_create(&producerThread,NULL,producer,NULL);
  pthread_create(&producerThread1,NULL,producer,NULL);
  pthread_create(&producerThread2,NULL,producer,NULL);
  pthread_create(&consumerThread1,NULL,consumer,(void*)(msg1));
  //pthread_create(&consumerThread2,NULL,consumer,(void*)(msg2));
  //pthread_create(&consumerThread3,NULL,consumer,(void*)(msg3));
 

  pthread_join(producerThread,NULL);
  pthread_join(consumerThread1,NULL);
  pthread_join(producerThread2,NULL);
  pthread_join(producerThread1,NULL);
 // pthread_join(consumerThread2,NULL);
  //pthread_join(consumerThread3,NULL);


}

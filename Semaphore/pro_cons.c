#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>

#define max 10

int products;
sem_t mutex, empty, full;

void produce()
{
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("\nProducer produces a product");
        products++;
        printf("\n%d", products);
        sem_post(&full);
        sem_post(&mutex);
        // if(products==max)
        // {
        //     sem_post(&mutex);
        //     return 0;
        // }
        // else
        // {
        //     printf("\nProducer produces a product");
        //     products++;
        //     printf("\n%d", products);
        //     sem_post(&mutex);
        // }
   
    
}


void consume()
{
   
        sem_wait(&full);
        sem_wait(&mutex);
        printf("\nConsumer consumes a product");
        products--;
        printf("\n%d", products);
        sem_post(&empty);
        sem_post(&mutex);
        // if(products==0)
        // {
        //     sem_post(&mutex);
        //     return 0;
        // }
        // else{
        //     printf("\nConsumer consumes a product");
        //     products--;
        //     printf("\n%d", products);
        //     sem_post(&mutex);
        // }
  
}

void* producer(void *n)
{
    while(1)
    {
        produce();
    }
}

void* consumer(void* n)
{
    while(1)
    {
        consume();
    }
}

void main()
{
    pthread_t pro, cons;
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, 10);
    sem_init(&full, 0, 0);
    pthread_create(&pro, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(pro, NULL);
    pthread_join(cons, NULL);
}

// void * prod_cons(void* i)
// {
//     int* j=i;
//     sleep(1);
//     if(j==0)
//     {
//         produce(*j);
//         printf("Hii");
//     }
//     else
//     {
//         consume(*j);
//         printf("Helloo");
//     }
// }

// void main()
// {
//     pthread_t procons[2];
//     sem_init(&mutex, 0, 1);
//     for(int i=0; i<2; i++)
//     {
//         pthread_create(&procons[i], NULL, prod_cons, &i);
//     }
//     for(int i=0; i<2; i++)
//     {
//         pthread_join(procons[i], NULL);
//     }
// }
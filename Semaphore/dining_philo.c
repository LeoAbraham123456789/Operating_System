#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#define N 5
#define Thinking 2
#define Hungry 1
#define Eating 0
#define Left (phnum+4) % N
#define Right (phnum+1) % N

int State[N];
int phil[N]={0,1,2,3,4};
sem_t mutex;
sem_t S[N];

void test(int phnum)
{
    if(State[phnum]==Hungry && State[Left]!=Eating && State[Right]!=Eating)
    {
        State[phnum]=Eating;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n", phnum+1, phnum, phnum+1);
        printf("Philosopher %d is eating\n", phnum+1);
        sem_post(&S[phnum]);
        sleep(1);
    }
}

void take_fork(int phnum)
{
    sem_wait(&mutex);
    State[phnum]=Hungry;
    printf("Philospher %d is hungry\n", phnum+1);
    test(phnum);
    sem_post(&mutex);
    sem_wait(&S[phnum]);
    sleep(1);
}

void put_fork(int phnum)
{
    sem_wait(&mutex);
    State[phnum]=Thinking;
    printf("Philosopher %d puts down forks %d and %d", phnum+1, phnum, phnum+1);
    printf("Philosopher %d is thinking", phnum+1);
    test(Left);
    test(Right);
    sem_post(&mutex);
}


void *philosopher(void * num)
{
    
        int * i=num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    
}

int main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0,1);
    for(i=0; i<N; i++)
        sem_init(&S[i], 0, 0);
    for(i=0; i<N; i++)
    {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is Thinking\n", i+1);
    }
    for(i=0; i<N; i++)
        pthread_join(thread_id[i], NULL);   
}
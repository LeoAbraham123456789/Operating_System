#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>

void main()
{
    void* shared_memory;
    int shmid;
    shmid=shmget((key_t)2345, 1024, 066);
    shared_memory=shmat(shmid, NULL, 0);
    printf("The data in memory is %s", (char *)shared_memory);
}
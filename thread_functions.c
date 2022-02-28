#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *myThreadFunc(void *arg){

    sleep(1);
    printf("Thread created \n");
    return NULL;
}

int main(){

    pthread_t thread_id;
    printf("Before thread\n");
    pthread_create(&thread_id, NULL, myThreadFunc, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);

}
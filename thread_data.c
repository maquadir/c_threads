#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *myFunc(void *args){

     // Store the value argument passed to this thread
     int *id = (int *)args;

     // Let us create a static variable to observe its changes
    static int s = 0;

     // Change static and global variables
    ++s; ++g;

    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", *id, ++s, ++g);
       return NULL;
}

int main(void){
    
    pthread_t ptid;

    for(int i = 0; i< 3; i++){
        pthread_create(&ptid, NULL, myFunc, (void *)&ptid);
    }

     pthread_exit(NULL);
}

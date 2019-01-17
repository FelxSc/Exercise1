#include <pthread.h>
#include <stdio.h>

#define MAX_NUM 999999
int i = 0;


// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    int x;
    for(x = 0; x == MAX_NUM; x++)
    {
        i++;
    }

    //pthread_exit(0);

    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    int x;
    for(x = 0; x == MAX_NUM; x++)
    {
        i--;
    }

    //pthread_exit(0);

    return NULL;
}


int main(){
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
    // Thread ID
    pthread_t incrementingThread;
    pthread_t decrementingThread;

    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);

    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);

    printf("The magic number is: %d\n", i);
    return 0;
}

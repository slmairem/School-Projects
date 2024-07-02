#include <stdio.h>
#include <pthread.h>

/* Define a global variable to store the current water level in a reservoir.
You need to create two functions named filler() and drainer()
Set initial water level to 0 units.
The filler function should work only if the water level is equal to or less than 20 units. It should increase the water level by 10 units and fills until the water level reaches 100 units.
The drainer function should work if the water level is greater than 0 units.
Define your mutex object to manage concurrent access to the water level variable.
Create and join threads using your filler() and drainer() functions 100 times to simulate the reservoir's continuous operation. */

int current_level = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for protecting the counter

void* filler(void* arg) {
    pthread_mutex_lock(&mutex);

    int i = 0;
    if(current_level <= 20){
        while (current_level < 100) {
            current_level += 10;
            if (current_level > 100)
                current_level = 100;
            i++; 
            printf("%d. Filler = %d \n", i, current_level);
        }
    }

    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void* drainer(void* arg) {
    pthread_mutex_lock(&mutex);
    
    if (current_level > 0)
        current_level -= 10;
        
    printf("Drainer = %d \n", current_level);
    

    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t filler_thread, drainer_thread;
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 100; i++) {
        pthread_create(&filler_thread, NULL, filler, NULL);
        pthread_create(&drainer_thread, NULL, drainer, NULL);

        pthread_join(filler_thread, NULL);
        pthread_join(drainer_thread, NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}

//21070001028 Selma Irem Ozdemir

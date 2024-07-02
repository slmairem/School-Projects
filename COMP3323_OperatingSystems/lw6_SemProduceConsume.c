#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define N 10 // Buffer size

typedef int semaphore;
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

int buffer[N];
int next_in = 0;
int next_out = 0;

void enter_item(int item) {
    buffer[next_in] = item;
    next_in = (next_in % N) + 1;
}

void remove_item(int *item) {
    *item = buffer[next_out];
    buffer[next_out] = 0;
    next_out = (next_out % N) + 1;
}

void sem_waitc(semaphore *s) {
    while (*s <= 0) {
        // wait until semaphore becomes positive
    }
    *s -= 1;
}

void sem_signalc(semaphore *s) {
    *s += 1;
}

void *producer(void *arg) {
    int item = 1;
    while (1) {
        sem_waitc(&empty);
        sem_waitc(&mutex);
        enter_item(item);

        printf("Producer produced item, placed on %d.shelf\n", next_in);
        for (int i = 0; i < N; i++) {
            printf(" %d\t", buffer[i]);
        }
        printf("\n");

        sem_signalc(&mutex);
        sem_signalc(&full);
        sleep(1);
    }
}

void *consumer(void *arg) {
    int item = 0;
    while (1) {
        sem_waitc(&full);
        sem_waitc(&mutex);
        remove_item(&item);

        printf("Consumer consumed item from %d.shelf\n", next_out);
        for (int i = 0; i < N; i++) {
            printf(" %d\t", buffer[i]);
        }

        printf("\n");
        sem_signalc(&mutex);
        sem_signalc(&empty);
        sleep(1);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    sleep(10); // it gives time for producer to do all
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

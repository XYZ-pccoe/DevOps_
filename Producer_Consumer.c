// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>

// #define BUFFER_SIZE 5   

// int buffer[BUFFER_SIZE];
// int in = 0;   
// int out = 0;  

// sem_t empty;  
// sem_t full;    
// sem_t mutex;   


// void* producer(void* arg) {
//     int item;

//     for(int i = 0; i < 10; i++) {
//         item = rand() % 100; 

//         sem_wait(&empty); 
//         sem_wait(&mutex);  

//         buffer[in] = item;
//         printf("Producer produced: %d at position %d\n", item, in);

//         in = (in + 1) % BUFFER_SIZE;

//         sem_post(&mutex);  
//         sem_post(&full);  

//         sleep(1);
//     }
//     return NULL;
// }

// void* consumer(void* arg) {
//     int item;

//     for(int i = 0; i < 10; i++) {

//         sem_wait(&full);   
//         sem_wait(&mutex);  

//         item = buffer[out];
//         printf("Consumer consumed: %d from position %d\n", item, out);

//         out = (out + 1) % BUFFER_SIZE;

//         sem_post(&mutex);  
//         sem_post(&empty);  

//         sleep(2);
//     }
//     return NULL;
// }

// int main() {
//     pthread_t p1, p2, c1, c2;

    
//     sem_init(&empty, 0, BUFFER_SIZE); 
//     sem_init(&full, 0, 0);            
//     sem_init(&mutex, 0, 1);           
  

//     pthread_create(&p1, NULL, producer, NULL);
//     pthread_create(&p2, NULL, producer, NULL);
//     pthread_create(&c1, NULL, consumer, NULL);
//     pthread_create(&c2, NULL, consumer, NULL);

   
//     pthread_join(p1, NULL);
//     pthread_join(p2, NULL);
//     pthread_join(c1, NULL);
//     pthread_join(c2, NULL);

    
//     sem_destroy(&empty);
//     sem_destroy(&full);
//     sem_destroy(&mutex);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in =0;
int out =0;
sem_t empty;
sem_t full;
sem_t mutex;

void* producer(void* args){
    int item;
    for(int i=0;i<10;i++){
        item = rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in]=item;
        printf("producer produce %d at position %d\n",item,in);
        in=(in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}
void* consumer(void* args){
    int item;
    for(int i=0;i<10;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        item=buffer[out];
        printf("consumer consume %d from position %d\n",item,out);
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    return NULL;
}
int main(){
    pthread_t p1,p2,c1,c2;
    srand(time(NULL));
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);
    pthread_create(&p1,NULL,producer,NULL);
    pthread_create(&p2,NULL,producer,NULL);
    pthread_create(&c1,NULL,consumer,NULL);
    pthread_create(&c2,NULL,consumer,NULL);

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(c1,NULL);
    pthread_join(c2,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}

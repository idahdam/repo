#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define THREAD_NUM 11

int sum;

void*routine(void* arg){
	int iter = *(int*)arg;
	sum += iter;
	printf("%d ", iter);
}

int main(int argc, char* argv[]){
	pthread_t th[THREAD_NUM];
	int i;
	for(i = 0; i< THREAD_NUM; i++){
		if(pthread_create(&th[i], NULL, &routine, &i) !=0){
			perror("Failed to create thread");
		}
	}
	for(i = 0; i< THREAD_NUM; i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed to join thread");
		}
	}
	printf("sum of all nubmers is %d\n", sum);
	return 0;
}

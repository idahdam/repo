#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define THREAD_NUM 4
#define LOOP_NUM 1000000

int mails = 0;

void*routine(){
	for(int i = 0; i<LOOP_NUM; i++){
		mails++;
	}
}

int main(int argc, char* argv[]){
	pthread_t tid[THREAD_NUM];
	for(int i = 0; i<THREAD_NUM; i++){
		if(pthread_create(&tid[i], NULL, &routine, NULL) != 0)
		{
			return 1;
		}
	}
	for(int i = 0; i < THREAD_NUM; i++){
		if(pthread_join(tid[i], NULL) != 0) {return 2;}
	}

	printf("number of mails: %d\n", mails);
	return 0;
}

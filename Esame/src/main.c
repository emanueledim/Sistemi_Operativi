#include "prodcons.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void * Produttore(void *);
void * Consumatore(void *);

int main() {

    /* TBD: Avviare i thread produttore e consumatore */
	pthread_t pthreads[2];
	pthread_attr_t attr;
	MonitorStreaming *ms;
	
	ms = (MonitorStreaming *)malloc(sizeof(MonitorStreaming));
	
	inizializza(ms);	
	
	ms->testa = 0;
	ms->coda = 0;
	ms->contatore = 0;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	
	for(int i=0; i<2; i++){
		if(i==0) //Produttore
			pthread_create(&pthreads[i], &attr, Produttore, (void *)ms);
		else //Consumatore
			pthread_create(&pthreads[i], &attr, Consumatore, (void *)ms);
	}
	
	for(int i=0; i<2; i++){
		pthread_join(pthreads[i], NULL);
	}
	
	pthread_attr_destroy(&attr);
	distruggi(ms);
	free(ms);
	exit(0);
}

void * Produttore(void * p) {
 	
 	MonitorStreaming *ms = (MonitorStreaming *)p;
   
    for(int i=0; i<10; i++) {

        Frame f;
        f[0][0] = rand() % 11;
        f[0][1] = rand() % 11;
        f[1][0] = rand() % 11;
        f[1][1] = rand() % 11;

        /* TBD: Chiamare il metodo "produci()" del monitor */
       
		produci(ms, f);
        sleep(1);
    }

    pthread_exit(NULL);
}

void * Consumatore(void * p) {

    /* TBD: Chiamare il metodo "bufferizza()" del monitor */
	MonitorStreaming *ms = (MonitorStreaming *)p;
	bufferizza(ms, 4);
    for(int i=0; i<10; i++) {

        Frame f;

        /* TBD: Chiamare il metodo "consuma()" del monitor */
        consuma(ms, f);

        sleep(1);
    }

    pthread_exit(NULL);
}

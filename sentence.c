#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ANSI-color-codes.h"

void typist(char sentence[150]){
	
	
	int sentence_length;
	char nextLetter;
	
	sentence_length = strlen(sentence);
	
	for (int i=0; i < sentence_length; i++) {
		
		if (sentence[i] == ',' || sentence[i] == '.'){
			printf("%c", sentence[i]);
			//printf("%c", sentence[i+1]);
			fflush(stdout);
			usleep(1075000);
			fflush(stdout);
		} else {	
		
		printf("%c", sentence[i]);
		usleep(75000);
		fflush(stdout);
		}
	}
	
	//printf(" ");
	usleep(1175000);
	printf("\n");
}

void typist_fast(char sentence[150]){
	
	
	int sentence_length;
	char nextLetter;
	
	sentence_length = strlen(sentence);
	
	for (int i=0; i < sentence_length; i++) {
		
		printf("%c", sentence[i]);
		usleep(75000);
		fflush(stdout);
	
	}
	
	//printf(" ");
	usleep(1175000);
	printf("\n");
}

void rabbitHole(){

	typist_fast("Tell me, does the Matrix have you...? ");
	//printf("\n");
	typist(GRN "The Matrix has us, we are lost..." reset);
	typist("Hold on a bit longer, we are on the way.");
	typist(GRN "It's too late, everything is fading. I'm pretty sure this is it, if it is then tell command tha" reset);
	sleep(1);
	typist_fast("... BHT are you there?");
	typist("Initiating forced communication relay. Standby. How long until we reach the core?");
	sleep(2);
	printf("\n");
	
}


void menu(){
	fflush(stdout);
	int a;
	fflush(stdout);
    typist("What would you like to do?:\n");
    fflush(stdout);
    typist("1) Go down the Rabbit Hole\n");
    fflush(stdout);
    typist("2) Restart this application\n");
    printf("\n");
    fflush(stdout);
    typist("The choice is yours: ");
    fflush(stdout);
    scanf("%d", &a);
    fflush(stdout);
    //printf("You entered: %d\n", a);
	printf("\n");
	fflush(stdout);
    
	if (a == 1) {
		rabbitHole();
	} else if (a == 2) {
		menu();
	} else {
		menu();
	}
	
}






void main(){
	
	while (1){
		menu();
	}
}

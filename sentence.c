#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ANSI-color-codes.h"
#include <stdlib.h>
#include <stdbool.h>

/*	Fun little CTF-style text game, focus on user io over network by serving the binary on an exposed port via nc
 * also just brushing up on simple C and writing some neat functions.
 * 
 * 
 * Todo: Put buffer checks on every input
 *			-Need to figure out appropriate buffer size for the typist functions in general
 * 
 * 		Try and make it overall portable or at least very multi-terminal friendly
 * 
 * 		Enable the boolean parameter for toggling the typo feature
 * 			-Re-factor the code to fit into a typos/no typos algorithm
 * 
 *		KNOWN BUGS:
 * 			-The typo function clashes with the terminal colour commands
 * 				*Probably need to increase the safe-zone for typos at the beginning and end of strings by a bit to fix this.s
 * 				** FIXED? April 6 2021
 */







void clrscr()		//Is this the best portable way to clear the terminal... lol?
{
    system("cls 2>/dev/null");	//windows command, linux stderr redirection (in case you call cls on a *nix system, it will hide the error)
    system("clear 2> nul");		//vice versa to above.
}


void typist(char sentence[250]){
	
	int sentence_length;
	char nextLetter;
	
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	char typoLetter;
	sentence_length = strlen(sentence);
	int backspaces;				// This is the number of times the delete button will be hit to go back and fix a typo, makes it feel natural
	int mistakePercent;			// I want this to be an int, 0 - 99, if it is <5 (so a 5% chance) then a typo will be made
	int whichLetter;			// which letter the typo will be
	
	for (int i=0; i < sentence_length; i++) {
		
		mistakePercent = rand() % 99;	// random 0 - 99, see mistakePercent above

		if ("%c", sentence[i] == ' '){
			printf("%c", sentence[i]);
			continue;
		}
		
		if ("%c", sentence[i] == '.' || "%c", sentence[i] == ','){
			printf("%c", sentence[i]);
			fflush(stdout);
			usleep(1075000);
			continue;
		}
		
		if (mistakePercent < 4 && i > 8 && i < sentence_length-9) {
			
			whichLetter = rand() % 25;
		
			backspaces = (rand() % 70)/10;
			printf("%c", alphabet[whichLetter]);		//print the letter the typo will be
			//printf("\nMISTAKE\n");
			//printf("%i", i);
			//printf("\nMISTAKE\n");
			
			fflush(stdout);
			usleep(75000);
			fflush(stdout);
			i++;		// increment i so the next letter is still accurate
			
			for (int x=0; x < backspaces; x++){		// This is the very next letter for backspaces number of letters
				printf("%c", sentence[i]);
				usleep(75000);
				fflush(stdout);
				i++;
			}
				
			for (int y=backspaces+1; y > 0; y--){
				printf("\b \b");
				usleep(100000);
				fflush(stdout);
				i--;
			}
			
		}
		
		printf("%c", sentence[i]);
		usleep(75000);
		fflush(stdout);
	}

	usleep(1175000);
	printf("\n");
}



void typist_fast(char sentence[250]){
	
	int sentence_length;
	char nextLetter;

	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	char typoLetter;
	sentence_length = strlen(sentence);
	int backspaces;				// This is the number of times the delete button will be hit to go back and fix a typo, makes it feel natural
	int mistakePercent;			// I want this to be an int, 0 - 99, if it is <5 (so a 5% chance) then a typo will be made
	int whichLetter;			// which letter the typo will be
	
	for (int i=0; i < sentence_length; i++) {
		
		mistakePercent = rand() % 99;	// random 0 - 99, see mistakePercent above
		
		
		//printf("%i", mistakePercent);
		//printf("\n");
		//printf("%i", backspaces);
		//printf("\n");
		//printf("%i", whichLetter);
		//printf("\n");
		
		if ("%c", sentence[i] == ' '){
			printf("%c", sentence[i]);
			continue;
		}
		
		if (mistakePercent < 4 && i > 8 && i < sentence_length-9) {
			
			whichLetter = rand() % 25;
		
			backspaces = (rand() % 70)/10;
			printf("%c", alphabet[whichLetter]);		//print the letter the typo will be
			//printf("\nMISTAKE\n");
			//printf("%i", i);
			//printf("\nMISTAKE\n");
			
			fflush(stdout);
			usleep(75000);
			fflush(stdout);
			i++;		// increment i so the next letter is still accurate
			
			for (int x=0; x < backspaces; x++){		// This is the very next letter for backspaces number of letters
				printf("%c", sentence[i]);
				usleep(75000);
				fflush(stdout);
				i++;
			}
				
			for (int y=backspaces+1; y > 0; y--){
				printf("\b \b");
				usleep(125000);
				fflush(stdout);
				i--;
			}
			
		}
		
		printf("%c", sentence[i]);
		usleep(25000);
		fflush(stdout);
	}
	
	usleep(1175000);
	printf("\n");
}


void typist_urgent(char sentence[250], bool typos, bool lineBreak){
	
	int sentence_length;
	char nextLetter;
	
	
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	char typoLetter;
	sentence_length = strlen(sentence);
	int backspaces;				// This is the number of times the delete button will be hit to go back and fix a typo, makes it feel natural
	int mistakePercent;			// I want this to be an int, 0 - 99, if it is <5 (so a 5% chance) then a typo will be made
	int whichLetter;			// which letter the typo will be
	
	for (int i=0; i < sentence_length; i++) {
		
		mistakePercent = rand() % 99;	// random 0 - 99, see mistakePercent above
		
		
		//printf("%i", mistakePercent);
		//printf("\n");
		//printf("%i", backspaces);
		//printf("\n");
		//printf("%i", whichLetter);
		//printf("\n");
		
		if ("%c", sentence[i] == ' '){
			printf("%c", sentence[i]);
			continue;
		}
		
		if (mistakePercent < 4 && i > 8 && i < sentence_length-9) {
			
			whichLetter = rand() % 25;
		
			backspaces = (rand() % 70)/10;
			printf("%c", alphabet[whichLetter]);		//print the letter the typo will be
			//printf("\nMISTAKE\n");
			//printf("%i", i);
			//printf("\nMISTAKE\n");
			
			fflush(stdout);
			usleep(25000);
			fflush(stdout);
			i++;		// increment i so the next letter is still accurate
			
			for (int x=0; x < backspaces; x++){		// This is the very next letter for backspaces number of letters
				printf("%c", sentence[i]);
				usleep(25000);
				fflush(stdout);
				i++;
			}
				
			for (int y=backspaces+1; y > 0; y--){
				printf("\b \b");
				usleep(75000);
				fflush(stdout);
				i--;
			}
			
		}
		
		printf("%c", sentence[i]);
		usleep(25000);
		fflush(stdout);
	}
	
	usleep(875000);
	if (lineBreak){
		printf("\n");
	}
}

void colourFade(){
	
	for (int i=16; i < 22; i++) {

		printf("\033[38;5;");
		printf("%i",i);
		printf(";82m");
		printf("a");
		printf("\033[0m");
		//printf("\n");
		usleep(7500);
		fflush(stdout);
	}
	
	for (int x=21; x > 15; x--) {
	
		printf("\033[38;5;");
		printf("%i",x);
		printf(";82m");
		printf("a");
		printf("\033[0m");
		//printf("\n");
		usleep(7500);
		fflush(stdout);
	}
		
}


void rabbitHole(){

	typist_fast(HWHT "				Tell me, does the Matrix have you...? " reset);
	printf("\n");
	typist_urgent(GRN "		        	The Matrix has us, we are lost..." reset, true, true);
	printf("\n");
	typist(HWHT "				Just hold on a bit longer, we are on the way." reset);
	printf("\n");
	typist(GRN "				It's probably too late, everything is fading. I'm pretty sure this is it, if it is then tell command tha" reset);
	printf("\n");
	sleep(1);
	typist(HWHT "				... BHT are you there?" reset);
	printf("\n");
	typist_urgent(HWHT "				Initiating forced communication relay. " reset, false, true);
	printf("\n");
	typist_urgent(HWHT "				Standby... " reset, false, true);
	printf("\n");
	sleep(1);
	typist(HWHT "				Lieutenant, how long until we reach the core?" reset); 
	printf("\n");
	sleep(2);
	//printf("\n");
	
}


void menu(){
	
	
	
	clrscr();
	
//	printf(RED "Hello" reset);
	printf(RED "     )                            )      )               )                   (    (       \n" reset);  
	printf(RED "  ( /(        (       *   )    ( /(   ( /(     *   )  ( /(         (  (      )\\ ) )\\ )    \n" reset);  
	printf(RED "  )\\()) (     )\\    ` )  /(    )\\())  )\\())  ` )  /(  )\\()) (      )\\))(   '(()/((()/( (  \n" reset);
	printf(RED " ((_)\\  )\\ ((((_)(   ( )(_))  ((_)\\  ((_)\\    ( )(_))((_)\\  )\\    ((_)()\\ )  /(_))/(_)))\\ \n" reset);  
	printf(RED " _((_)((_) )\\ _ )\\ (_(_())     ((_)  _((_)  (_(_())  _((_)((_)   _(())\\_)()(_)) (_)) ((_)\n" reset);
	printf(GRN "| || || __|  )_\\(  |_   _|    / _ \\ | \\| |  |_   _| | || || __|  \\ \\ \\/ / /|_ _|| _ \\| __|\n" reset);
	printf(GRN "| __ || _|  / _ \\    | |     | (_) || .` |    | |   | __ || _|    \\ \\/\\/ /  | | | - /| _|  \n" reset);
	printf(GRN "|_||_||___|/_/ \\_\\   |_|      \\___/ |_|\\_|    |_|   |_||_||___|    \\_/\\_/  |___||_|_\\|___|\n" reset);

	
	fflush(stdout);
	int a;
	fflush(stdout);
    typist_urgent("\n				What would you like to do?:\n", false, true);
    fflush(stdout);
    typist_urgent("				1) Go down the Rabbit Hole\n", false, true);
    fflush(stdout);
    typist_urgent("				2) Restart this application\n", false, true);
    fflush(stdout);
    typist_urgent("				3) Quit", false, true);
    fflush(stdout);
    typist_urgent("\n				The choice is yours: ", false, false);
    fflush(stdout);
    printf("\n");
    colourFade();
    colourFade();
    colourFade();
    colourFade();
    colourFade();
    colourFade();
    colourFade();
    colourFade();
    printf("\n");
    scanf("%d", &a);
    fflush(stdout);
    //printf("You entered: %d\n", a);
	//printf("\n");
	fflush(stdout);
    
	if (a == 1) {
		rabbitHole();
	} else if (a == 2) {
		menu();
	} else if (a ==3) {
		exit(3);
	} else {
		menu();
	}
	
}



void main(){
	
	while (1){
		menu();
	}
}

// Project 1 - Scanner
// p1.c - main program
// Tan Nguyen
// ntnhmc@umsystem.edu
// Mar 7, 2022



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <errno.h>

#include "scanner.h"
#include "testScanner.h"

void help();  // display information about how to run program

int main(int argc, char **argv) {

	if (argc > 2) {
		printf("Error: Expected 1 or no arguments\n");
		printf("Try './scanner -h' for more information.\n");
		return EXIT_FAILURE;
	}

	int opt;
        while((opt = getopt(argc, argv, "h")) != -1){
        	switch(opt)
        	{
			case 'h':
                		help();
                		exit(EXIT_SUCCESS);
                		break;
			case '?':
				printf("Unknown option: %c\n", opt);
                		break;
            		default:
                		perror("oss.c: error: invalid argument");
                		help();                		
				break;
       		}
        }

   	FILE *inFilePtr = NULL;
    	char *fileName = NULL;

	//Read from file if argument = 2 and Read from the keyboard
    	if (argc == 2) {
        	const char fileExt[] = ".txt";
        	fileName = (char *) malloc(sizeof(argv[1]));
        	strcpy(fileName, argv[1]);
        	char inFile[strlen(fileName) + strlen(fileExt)];	// add ".txt" into fileName : fileName.txt
        	strcpy(inFile, fileName);
        	strcat(inFile, fileExt);

		inFilePtr = fopen(inFile, "r");
		// if file error, abort with appropriate message 
		if (!inFilePtr) {
			printf("Error: File %s could not be opened\n", inFile);
			return (EXIT_FAILURE);
		}
	}
	//Read from Keyboard until EOF, the CTRL + D
	else {
		inFilePtr = stdin;
		if (inFilePtr == NULL){
			fprintf(stderr, "Unable To Start stdin: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

    	testScanner(inFilePtr);
    	fclose(inFilePtr);
	free(fileName);
	return ( 0 );
}

//Print how to run program
void help(){
	printf("\n------------------------------------------------------------------------------------\n");
	
	printf("How to implement program::  \n");
	printf("Invocation:  ./scanner [file]  \n");
	printf("There are three ways to run the program: \n");
	printf("1. ./scanner to prompt user to enter from keyboard. \n");
	printf("2. ./scanner < [filename] to direct inout file to scanner exectuable program. \n");
	printf("3. ./scanner [filename] // without .input suffix in file name. \n");

	printf("--------------------------------------------------------------------------------------\n\n");

}










// Project 1 - Scanner
// testScanner.c
// Tan Nguyen
// ntnhmc@umsystem.edu
// Mar 7, 2022



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"
#include "scanner.h"
#include "testScanner.h"

char *tokenNames[28] = {
	"END OF FILE", "ERROR", "IDENTIFIER TOKEN", "DIGIT TOKEN","COMMENT - IGNORE",
	
	"AGAIN KEYWORD", "IF KEYWORD", "ASSIGN KEYWORD", "MOVE KEYWORD", "SHOW KEYWORD", "FLIP KEYWORD", 
	"NAME KEYWORD", "HOME KEYWORD", "DOTS KEYWORD", "SPOT KEYWORD","PLACE KEYWORD", "HERE KEYWORD", "THERE KEYWORD", 

	"OPERATOR AND '&'", "OPERATOR ADD '+'", "OPERATOR DIVISION '/'", "OPERATOR MODULUS '%'", "OPERATOR DOTS '.'", "OPERATOR BRACKET LEFT '{'", 
	"OPERATOR BRACKET RIGHT '}'", "OPERATOR LEFTSHIFT '<<'", "OPERATOR SMALLER MINUS '<-'"
	
};

//function call scanner, it will return 1 token at 1 time
void testScanner(FILE *inputFile) {
    	token tempToken;
	int lineNum = 1;

    	do{
        	tempToken = scanner(inputFile, &lineNum);
		if(strcmp(tokenNames[tempToken.type], "Error") == 0){
			printf("Scanner Error: %s Not Allowed At Line: %i.\n", tempToken.instance, tempToken.lineNum);
			printf("Exiting\n");
			exit(EXIT_FAILURE);
		}
		else{
			printf("TokenID: %s | Instance: %s | Line#: %i \n", tokenNames[tempToken.type], tempToken.instance, tempToken.lineNum);
		}
    	} while(!feof(inputFile));
}


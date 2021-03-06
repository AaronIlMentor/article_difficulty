// Aaron Bager
// CIS 343-02
// Project 1
#include <stdio.h>
#include <stdlib.h>

double getAverageWordSize(char *fileName) {
	int wordSize = 0;
	double average = 0;
	int numberOfWords = 0;
	FILE *fp;
       	char tempChar;

	fp = fopen(fileName, "r"); // open file for reading
	if (fp == NULL) {
		printf("%s does not exist. Exiting...\n", fileName);
		exit(0);
	}
	
	while( !feof(fp) ) {
	      tempChar = fgetc(fp);
		if( tempChar == ' ' ) {
			average += wordSize;
		       	wordSize = 0;
			numberOfWords++;
		}
		else {
			wordSize++;
		}
	}
	if(average == 0) {
		average = wordSize; 
	}
	if(numberOfWords == 0 && average > 0) {
		numberOfWords = 1;
	}
	fclose(fp);
	if(average != 0 || numberOfWords != 0) {
		average = average / numberOfWords;
		return average;
	}
	else
	{
		return 0;
	}
	
}


int main (int argc, char **argv) {
	double smallestWordSize = 10000; // used to keep track of smallest file thus far, intially 1
	double largestWordSize = 0; // used to keep track of largest file size thus far, initially 0
	double tempDouble; // used for comparing file sizes
	int smallestFile; // index of smallest file in arguments given
	int largestFile; // index number of largest file in arguments given
	if ( argc == 1) {
		printf("Please provide file names");
	}
	else if ( argc == 2) {
			FILE *fp; 
			fp = fopen(argv[1], "r");

			if ( fp != NULL ) {
				printf("\nMost difficult document: %s\nLeast difficult document: %s\n", argv[1], argv[1]);
			}
			else {
				printf("Error: %s does not exist.\n", argv[1]);
			}
	}
	else {
		for (int i = 1; i < argc; i++) {
			tempDouble = getAverageWordSize(argv[i]);
			if (tempDouble > largestWordSize) {
				largestWordSize = tempDouble;
				largestFile = i;
			}

			if (tempDouble < smallestWordSize) {
				smallestWordSize = tempDouble;
				smallestFile = i;
			}
		}

		printf("Most difficult document: %s\nLeast difficult document: %s\n", argv[largestFile], argv[smallestFile]);
	}
}

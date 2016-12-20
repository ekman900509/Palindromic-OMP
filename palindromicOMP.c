#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define _WORDS 25143
#define WORD_LENGTH 20
#define _THREADS 10

int threads;
char* lowerCase(char*);
int palindrome(char*);
int palindromic(char*,char*[],int);

int main(int argc, char *argv[]){
	threads = (argc > 1)? atoi(argv[1]) : _THREADS;
	if(threads > _THREADS) threads = _THREADS;
	omp_set_num_threads(threads);	/*Set number of threads*/
	
	int i;
	char *words[_WORDS];
	
	FILE *fp,*result;
	fp = fopen("words.txt","r");	/*Open read filestream*/
	result = fopen("result.txt","w");	/*Open write filestream*/

	/*Start timer*/
	double start_time, end_time;
	start_time = omp_get_wtime();
	
	/*Load word.txt into array*/
	/*Concurrent Section #1*/
	#pragma omp parallel for
		for(i = 0;i < _WORDS;i++){
			words[i] = malloc(WORD_LENGTH);	/*Allocate a potential word length*/
			fscanf(fp,"%s",words[i]);	/*Read a string from file into array*/
			words[i] = realloc(words[i],strlen(words[i]));	/*Avoid hoging unused space*/
			words[i] = lowerCase(words[i]);	/*To avoid checks like Aa fails*/
		}
	
	/*Concurrent Section #2*/
	#pragma omp parallel for
		for (i = 0; i < _WORDS; i++){
			if(palindromic(words[i], words, i)){
				fprintf(result,"%s\n",words[i]);
			}
		}
	/*Free system resources*/
	/*Concurrent Section #3*/
	#pragma omp parallel for
		for(i = 0; i < _WORDS; i++)
			free(words[i]);
			
	/*Stop Timer*/
	end_time = omp_get_wtime();
	fclose(fp);	/*Close filestream*/
	fclose(result);
	printf("Load words into array & check took\n%g seconds\n", end_time - start_time);
	return 0;
}

/*Takes a paramteter and converts any capital letters to small*/
char* lowerCase(char* arg1){
	int i, j = strlen(arg1);
	for(i = 0;i < j;i++){
		if(arg1[i] >= 65 && arg1[i] <= 90)	/*Capital letter*/
			arg1[i] += 32;	/*Convert to small letter*/
	}
	return arg1;
}

/*Checks if palindrome*/
int palindrome(char *arg1){
	/*Decrement j with 1 to match index number*/
	int i, j = strlen(arg1) - 1;

	for(i = 0;i <= j/2;i++)
		if(arg1[i] != arg1[j-i])	/*Symbols differ => Not palindrome*/
			return 0;
	return 1;
}

/*Checks if the reversed word is in the list*/
int palindromic(char *arg1, char *arg2[], int arg3){
	if(palindrome(arg1) == 1)	/*Check for palindrome*/
		return 1;
	char* tmp = malloc(sizeof(arg1));	/*Allocate space for local string*/
	int i, j = strlen(arg1) - 1;
	
	
	for(i = 0;i <= j;i++)	/*Create the word reversed*/
		tmp[i] = arg1[j-i];
		
	/*Alternative solution insteed of if(palindrome(arg1) == 1) return 1;*/
	/*if(strcmp(tmp,arg1) == 0) return 1;*/	
		
	for(i = 0; i < _WORDS;i++){
		if(i == arg3)	/*Avoid checking against self*/
			continue;	/*Skip this lap and continue on next*/
		if(strcmp(tmp,arg2[i]) == 0){	/*Check if string is equal to current string in array*/
			free(tmp);	/*Free system resource*/
			return 1;	/*Palindromic word found*/
		}
	}
	return 0;	/*Word is not palindromic*/
}
HOW-TO-PALINDROMIC OPENMP



********************************************************************************************
********************************************************************************************
********************************************************************************************
***					Makefile compiles a exe file. 			 ***	***											 ***
***			If other format is needed compile the program with the line	 ***	***											 ***
***					gcc -fopenmp palindromicOMP.c			 ***	***							 				 ***
********************************************************************************************
********************************************************************************************
********************************************************************************************

1.Locate the palindromicOMP folder with your command-prompt
2.Type "make"
3.
a)If no input is given:
If the program is executed without any input given then the program will execute 
10 threads

b)If input is given:
if program is given input then the first argument is how many threads
Thread count can not exceed 12(if higher value is set then number of threads is set to 12.

To increase maxmimum amount of threads change #define value at row 8 in palindromicOMP.c

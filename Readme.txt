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


************************************************STATISTIC******************************************
Computer 1:
CPU:		AMD Phenom II X6 1000T	(6 core, 6 threads)
OS:		Windows 7 Professional 64bit
Full Words.txt:
-6 thread:	1.657418	sec
-1 thread:	4.739906	sec
-Speed-up:	2.85
Med Words.txt:	
-6 thread: 	1.210774	sec
-1 thread: 	3.2496		sec
-Speed-up:	2.68
Min Words.txt:	
-6 thread:	0.8268936	sec
-1 thread:	1.58138		sec
-Speed-up:	1.9

Computer 2:
CPU:		AMD A10-6800K		(2 core, 4 thread)
OS:		Windows 8.1		64bit
Full Words.txt:
-4 thread:	1.38222		sec
-1 thread:	3.3548		sec
-Speed-up:	2.45
Med Words.txt:	
-4 thread: 	1.03973		sec
-1 thread: 	2.24774		sec
-Speed-up:	2.08
Min Words.txt:	
-4 thread:	0.821079
-1 thread:	1.10789
-Speed-up:	1.09

Computer 3:
CPU:		AMD FX-8350		(8core,8core)
OS:		Windows 7
Full Words.txt:	
-8 thread:	3.365006	sec
-1 thread:	0.8658806	sec
-Speed-up:	3.88
Med Words.txt:
-8 thread:	2.315514	sec
-1 thread:	0.7081182
-Speed-up:	3.26
Min Words.txt:
-8 thread:	1.11194		sec
-1 thread:	0.5992038	sec
-Speed-up:	3.8904

Computer 4:
CPU:		2xAMD Opteron 6172	(12core/CPU)
OS:		RHEL5
Full words.txt:
-12 thread:	0.6434842	sec
-1 thread:	6.271108	sec
-Speed up:	9.74
Med words.txt:
-12 thread:	0.3365588	sec
-1 thread:	2.776122	sec
-Speed-up:	8.24
Min words.txt:
-12 thread:	0,0623836	sec
-1 thread:	0,4499832	sec
-Speed-up:	7.21

Conclusion:

From studying of the computer its possible to see that as the amount of cores goes up
the execution time of the threaded program goes down. What also could be seen is that
fewer cores does not always mean slower execution. This is because of the speed of each
core in the processor. Therefore the conclusion can be drawn that if amount of cores 
increase the speed of each core can decrease in order to compute at the same amount of 
execution time.

The conclusion to environmental aspect is that when the speed goes down less energy is
required to power the CPU, also the amount of unnecessery energy that is created(heat) 
during execution is lowered. Therefore one can argue that it's more effective to have
more CPUs since it's more efficient. But that would cause problems in the operating systems
runtime as it would run alot slower. So in terms of efficiency in programs a higher CPU
speed is needed for a smoother system.

CO-processors systems are a mix of the best of both sides(but more problematic in terms
of programming).

You can also draw the conclusion that the bigger each program gets the more time you earn
on making a parallell program as the speed-up increases with the size of the program.
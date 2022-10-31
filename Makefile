ccp: ccp.c
	gcc -pthread -g -Wall ccp.c -o ccp
	
threads: threads.c
	gcc -pthread -g -Wall threads.c -o threads
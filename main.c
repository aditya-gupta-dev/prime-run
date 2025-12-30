#include<stdio.h> 
#include<unistd.h> 

#define SUCCESS 0 
#define FAILURE 1 

int main(int argc, const char **argv) { 
	if(argc == 1){ 
		printf("\tprime-run\npass your program to run them on nvidia gpu.\n");
	        return SUCCESS;	
	} 


	return SUCCESS; 
}

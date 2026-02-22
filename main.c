#include<stdio.h> 
#include <stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("\tprime-run\nrun your programs on nvidia gpu.\n");
	        return 0;	
	} 

  pid_t pid = fork(); 

  if (pid < 0) { 
    perror("failed to fork"); 
    return 1; 
  }

  if (pid == 0) { 
    setenv("__NV_PRIME_RENDER_OFFLOAD", "1", 1); 
    setenv("__GLX_VENDOR_LIBRARY_NAME", "nvidia", 1);

    char* args[] = { argv[1], NULL };
    execvp(args[0], args);

    perror("failed to launch program."); 
  } else { 
    printf("exiting..."); 
  }
	return 0; 
} 

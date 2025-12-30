#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("\tprime-run\nrun your programs on nvidia gpu.\n");
	        return 0;	
	} 
	
	char *env[] = { 
		"__NV_PRIME_RENDER_OFFLOAD=1",
		"__GLX_VENDOR_LIBRARY_NAME=nvidia",
		"__VK_LAYER_NV_optimus=NVIDIA_only" 
	};  

	char **proc = &argv[1]; 

	execve(proc[0], proc, env);

	return 0; 
} 
